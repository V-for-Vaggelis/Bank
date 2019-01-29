#ifndef BANK
#define BANK //ensures class does not get defined twice which could create errors#include <iostream>
#include <vector>
#include "Savings.h"

class Bank {
	std::vector<Account*> accounts;
public:
	void insertAccount(SavingsAccount sa) {
		accounts.push_back(sa);
	}

	int findAccount(std::string iban) {
		int end = accounts.size();
		for (int i=0; i<end; i++) {
			std::string check = accounts.at(i).getIBAN();
			if (check == iban) {
				//				accounts.at(i).show();
				return i;
			}
		}
		return -1;
	}

	void deleteAccount(std::string iban) {
		int index = findAccount(iban);
		if (index == -1) {
			std::cout << "Account not found\n" << std::endl;
		}
		else {
			accounts.erase(accounts.begin() + index);
			std::cout << "Account deleted\n" << std::endl;
		}
	}
	//	void createAccount(std::string Owner0, std::string IBAN0, double Balance0, ) {

};
#endif
