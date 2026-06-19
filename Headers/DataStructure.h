#include <string>
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

class Branch{
private:
	std::string name;
	int id;

public:
	Branch();
	Branch(int branchId, const std::string& branchName);
		
	//rule of 5 if needed;
		
	int getId()const;
	const std::string& getName()const;
	void setName(const std::string& newName);
};

class Account{
private:
	std::string name;
	std::string number;
	std::string password_hash;
	int id;
	int branch_id;		// which branch
	double balance;		// open or closed
	bool active;

public:
	Account();
	Account(
		int accId,
		const std::string& accName,
		const std::string& accNumber,
		const std::string& accPassword,
		int accBranchId,
		double accBalance,
		bool accActive
	);

	void setName(const std::string& newName);

	const std::string& getName()const;
	const std::string& getNumber()const;
	const std::string& getPasswordHash() const;

	int getId()const;
	int getBranchId()const;
	double getBalance()const;
	bool isActive()const;
};

enum class TransactionType {Deposit, Withdrawal, Transfer};

class Transaction {
private:
   	int id;

   	TransactionType type;          // DEPOSIT, WITHDRAWAL, TRANSFER
   	std::string from_account;
   	std::string to_account;
   	std::string timestamp;     // "2026-11-21 09:15:32"

   	double amount;
   	double balance_after;

public:
	Transaction(
    	int txId,
    	TransactionType txType,
    	const std::string& from,
    	const std::string& to,
    	double txAmount,
    	const std::string& txTimestamp,
    	double txBalanceAfter
	);
	int getId() const;
	TransactionType getType() const;
	std::string getFrom() const;
	std::string getTo() const;
	double getAmount() const;
	std::string getTimestamp() const;
	double getBalanceAfter() const;
};

#endif
