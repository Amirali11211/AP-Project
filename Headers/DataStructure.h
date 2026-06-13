#include <string>
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
class Branch{
	private:
		std::string name;
		int id;
	public:
		Branch();
		Branch(int branchId,std::string branchName);
		
		//rule of 5 if needed;
		
		const int getId()const;
		const std::string getName()const;
		const void setName(std::string newName);
};
class Account{
	private:
		std::string name;
		std::string number;
		int id;
	public:
		Account();
		Account(int accId,std::string accName, std::string accNumber);
		
		//rule of 5 if needed;
		
		const int getId()const;
		const std::string getName()const;
		const void setName(std::string newName);
		const std::string getNumber()const;
};
#endif
