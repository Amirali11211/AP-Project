#include "DataStructure.h"
#include <string>
using namespace std;

Branch::Branch(){}
Branch::Branch(int branchId,string branchName):id(branchId),name(branchName){}
int Branch::getId()const{
	return id;
}

const string Branch::getName()const{
	return name;
}
void Branch::setName(string newName){
	name = newName;
}


Account::Account(){}
Account::Account(int accId, string accName, string accNumber, string accPassword, int accBranchId, double accBalance, bool accActive):
	id(accId),
	name(accName),
	number(accNumber),
	password_hash(accPassword),
	branch_id(accBranchId),
	balance(accBalance),
	active(accActive)
{}

int Account::getId()const{
	return id;
}

const string Account::getName()const{
	return name;
}

void Account::setName(string newName){
	name = newName;
}

const string Account::getNumber()const{
	return number;
}
