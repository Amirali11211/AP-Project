#include "bank.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> tokenize(const std::string& line) {
    std::vector<std::string> tokens;
    size_t i = 0;

    while (i < line.size()) {
        while (i < line.size() && std::isspace((unsigned char)line[i])) {
            i++;
        }
        if (i >= line.size()) break;

        std::string token;

        if (line[i] == '"') {
            i++;
            while (i < line.size() && line[i] != '"') {
                token += line[i];
                i++;
            }
            i++;
        } else {
            while (i < line.size() && !std::isspace((unsigned char)line[i])) {
                token += line[i];
                i++;
            }
        }

        tokens.push_back(token);
    }

    return tokens;
}

void dispatch(const std::vector<std::string>& tokens, Bank& bank) {
    if (tokens.empty()) return;

    const std::string& cmd = tokens[0];

    if (cmd == "create_branch" && tokens.size() == 2) {
        bank.createBranch(tokens[1]);
    }
    else if (cmd == "list_branches" && tokens.size() == 1) {
        bank.listBranches();
    }
    else if (cmd == "create_account" && tokens.size() == 2) {
        bank.createAccount(std::stoi(tokens[1]));
    }
    else if (cmd == "close_account" && tokens.size() == 2) {
        bank.closeAccount(tokens[1]);
    }
    else if (cmd == "delete_account" && tokens.size() == 2) {
        bank.deleteAccount(tokens[1]);
    }
    else if (cmd == "list_accounts" && tokens.size() == 1) {
        bank.listAccounts();
    }
    else if (cmd == "deposit" && tokens.size() == 3) {
        bank.deposit(tokens[1], std::stod(tokens[2]));
    }
    else if (cmd == "withdraw" && tokens.size() == 3) {
        bank.withdraw(tokens[1], std::stod(tokens[2]));
    }
    else if (cmd == "transfer" && tokens.size() == 4) {
        bank.transfer(tokens[1], tokens[2], std::stod(tokens[3]));
    }
    else if (cmd == "get_balance" && tokens.size() == 2) {
        bank.getBalance(tokens[1]);
    }
    else if (cmd == "get_history" && tokens.size() == 2) {
        bank.getHistory(tokens[1]);
    }
    else if (cmd == "get_transaction" && tokens.size() == 2) {
        bank.getTransaction(std::stoi(tokens[1]));
    }
    else if (cmd == "clear_history" && tokens.size() == 2) {
        bank.clearHistory(tokens[1]);
    }
    else if (cmd == "reset_all" && tokens.size() == 1) {
        bank.resetAll();
    }
    else {
        std::cout << "Error: Unknown command or wrong number of arguments.\n";
    }
}

int main() {
    Bank bank;
    std::string line;
    while (true) {
        std::cout << "> " << std::flush;
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;

        dispatch(tokenize(line), bank);
    }

    return 0;
}
