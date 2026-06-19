#include "Headers/DataStructure.h"
#include "json.hpp"
#include <fstream>
#include <vector>

using json = nlohmann::json;


void saveBranches(const std::vector<Branch>& branches) {
    json j = json::array();
    
    for (const auto& b : branches) {
        j.push_back({
            {"id", b.getId()},
            {"name", b.getName()}
        });
    }
    
    std::ofstream file("branches.json");
    file << j.dump(2);
}

std::vector<Branch> loadBranches() {
    std::ifstream file("branches.json");
    if (!file) return {}; 
    
    json j;
    file >> j;
    
    std::vector<Branch> result;
    for (const auto& item : j) {
        result.push_back(Branch(
            item["id"],
            item["name"]
        ));
    }
    return result;
}

void saveAccounts(const std::vector<Account>& accounts) {
    json j = json::array();
    
    for (const auto& a : accounts) {
        j.push_back({
            {"id", a.getId()},
            {"name", a.getName()},
            {"number", a.getNumber()},
            {"password_hash", a.getPasswordHash()},
            {"branch_id", a.getBranchId()},
            {"balance", a.getBalance()},
            {"active", a.isActive()}
        });
    }
    
    std::ofstream file("accounts.json");
    file << j.dump(2);
}

std::vector<Account> loadAccounts() {
    std::ifstream file("accounts.json");
    if (!file) return {};
    
    json j;
    file >> j;
    
    std::vector<Account> result;
    for (const auto& item : j) {
        result.push_back(Account(
            item["id"],
            item["name"],
            item["number"],
            item["password_hash"],
            item["branch_id"],
            item["balance"],
            item["active"]
        ));
    }
    return result;
}

static std::string typeToString(TransactionType t) {
    switch (t) {
        case TransactionType::Deposit: return "DEPOSIT";
        case TransactionType::Withdrawal: return "WITHDRAWAL";
        case TransactionType::Transfer: return "TRANSFER";
    }
    return "";
}

static TransactionType stringToType(const std::string& s) {
    if (s == "DEPOSIT") return TransactionType::Deposit;
    if (s == "WITHDRAWAL") return TransactionType::Withdrawal;
    return TransactionType::Transfer;
}


void saveTransactions(const std::vector<Transaction>& transactions) {
    json j = json::array();
    
    for (const auto& t : transactions) {
        j.push_back({
            {"id", t.getId()},
            {"type", typeToString(t.getType())},
            {"from_account", t.getFrom()},
            {"to_account", t.getTo()},
            {"amount", t.getAmount()},
            {"timestamp", t.getTimestamp()},
            {"balance_after", t.getBalanceAfter()}
        });
    }
    
    std::ofstream file("transactions.json");
    file << j.dump(2);
}

std::vector<Transaction> loadTransactions() {
    std::ifstream file("transactions.json");
    if (!file) return {};
    
    json j;
    file >> j;
    
    std::vector<Transaction> result;
    for (const auto& item : j) {
        result.push_back(Transaction(
            item["id"],
            stringToType(item["type"]),
            item["from_account"],
            item["to_account"],
            item["amount"],
            item["timestamp"],
            item["balance_after"]
        ));
    }
    return result;
}