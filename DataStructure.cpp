#include "DataStructure.h"
#include <string>
using namespace std;

Branch::Branch(){}
Branch::Branch(int branchId,string branchName):id(branchId),name(branchName){}
const int Branch::getId()const{
	return id;
}
const string Branch::getName()const{
	return name;
}
const void Branch::setName(string newName){
	name = newName;
}


Account::Account(){}
Account::Account(int accId,string accName, string accNumber):id(accId),name(accName),number(accNumber){}
const int Account::getId()const{
	return id;
}
const string Account::getName()const{
	return name;
}
const void Account::setName(string newName){
	name = newName;
}
const string Account::getNumber()const{
	return number;
}
