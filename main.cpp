#include "bank/bank.h"
#include "storage/storage.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// ─── Parse a line into tokens, respecting "quoted strings" ───────────────────
static std::vector<std::string> tokenize(const std::string& line) {
    std::vector<std::string> tokens;
    size_t i = 0, n = line.size();
    while (i < n) {
        // skip whitespace
        while (i < n && std::isspace((unsigned char)line[i])) i++;
        if (i >= n) break;
        std::string tok;
        if (line[i] == '"') {
            i++; // skip opening quote
            while (i < n && line[i] != '"') tok += line[i++];
            if (i < n) i++; // skip closing quote
        } else {
            while (i < n && !std::isspace((unsigned char)line[i])) tok += line[i++];
        }
        if (!tok.empty()) tokens.push_back(tok);
    }
    return tokens;
}

// ─── Dispatch a command ───────────────────────────────────────────────────────
static void dispatch(const std::vector<std::string>& t) {
    if (t.empty()) return;
    const std::string& cmd = t[0];

    if      (cmd == "create_branch"   && t.size()==2) cmd_create_branch(t[1]);
    else if (cmd == "list_branches"   && t.size()==1) cmd_list_branches();
    else if (cmd == "create_account"  && t.size()==2) cmd_create_account(std::stoi(t[1]));
    else if (cmd == "close_account"   && t.size()==2) cmd_close_account(t[1]);
    else if (cmd == "delete_account"  && t.size()==2) cmd_delete_account(t[1]);
    else if (cmd == "list_accounts"   && t.size()==1) cmd_list_accounts();
    else if (cmd == "deposit"         && t.size()==3) cmd_deposit(t[1], std::stod(t[2]));
    else if (cmd == "withdraw"        && t.size()==3) cmd_withdraw(t[1], std::stod(t[2]));
    else if (cmd == "transfer"        && t.size()==4) cmd_transfer(t[1], t[2], std::stod(t[3]));
    else if (cmd == "get_balance"     && t.size()==2) cmd_get_balance(t[1]);
    else if (cmd == "get_history"     && t.size()==2) cmd_get_history(t[1]);
    else if (cmd == "get_transaction" && t.size()==2) cmd_get_transaction(std::stoi(t[1]));
    else if (cmd == "clear_history"   && t.size()==2) cmd_clear_history(t[1]);
    else if (cmd == "reset_all"       && t.size()==1) cmd_reset_all();
    else std::cout << "Error: Unknown command or wrong number of arguments.\n";
}

// ─── Load data and initialize counters ───────────────────────────────────────
static void initCounters() {
    for (auto& b : g_branches)
        if (b.id >= g_next_branch_id) g_next_branch_id = b.id + 1;
    for (auto& t : g_transactions)
        if (t.id >= g_next_transaction_id) g_next_transaction_id = t.id + 1;
}

// ─── main ─────────────────────────────────────────────────────────────────────
int main() {
    // Load persisted data
    g_branches     = loadBranches();
    g_accounts     = loadAccounts();
    g_transactions = loadTransactions();
    initCounters();

    std::string line;
    while (true) {
        std::cout << "> " << std::flush;
        if (!std::getline(std::cin, line)) break;   // EOF
        if (line.empty()) continue;
        dispatch(tokenize(line));
    }
    return 0;
}
