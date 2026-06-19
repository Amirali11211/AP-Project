#ifndef STORAGE_H
#define STORAGE_H

#include "Headers/DataStructure.h"
#include <vector>
#include <string>

std::vector<Branch> loadBranches();
void saveBranches(const std::vector<Branch>& branches);

std::vector<Account> loadAccounts();
void saveAccounts(const std::vector<Account>& accounts);

std::vector<Transaction> loadTransactions();
void saveTransactions(const std::vector<Transaction>& transactions);

#endif