#ifndef BANK
#define BANK //ensures class does not get defined twice which could create errors#include <iostream>
#include <vector>
#include "Savings.h"
#include "Person.h"
#include "CheckingAccount.h"
#include "Account.h"
#include <iostream>

class Bank {
	std::vector<Account*> accounts;
public:
	Bank() {

	}
	~Bank() {
		std::cout << "\nDestructor called" << std::endl;
		int end = accounts.size();
		for (int i=0; i<end; i++) {
			delete accounts[i]; //deletes the object
			accounts.erase(accounts.begin() + i); //erases the pointer
		}
	}

	void createAccount(Person per, std::string iban, double ammount, int type) {
		Account* a;
		if (type == 1) {
			a = new SavingsAccount(per, iban, ammount);
		}
		if (type == 2) {
			a = new CheckingAccount(per, iban, ammount); //polymorphism, a is a pointer of type Account pointing to object of type CheckingAccount
		}
		accounts.push_back(a);
	}

	int findAccount(std::string iban) {
		int end = accounts.size();
		for (int i=0; i<end; i++) {
			// Account* checkPointer = accounts.at(i); //pointer to account i
			// Account account_ref = *checkPointer; //dereferences the pointer so we can use a reference to the actual object
			// std::string check = account_ref.getIBAN();
			std::string check = accounts.at(i) -> getIBAN(); //a simpler way than depointing
			if (check == iban) {
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
			delete accounts[index]; //deletes the object
			accounts.erase(accounts.begin() + index); //erases the pointer
//			std::cout << "Account deleted\n" << std::endl;
		}
	}

	void depositToAccount(std::string iban, double ammount) {
		int index = findAccount(iban);
		accounts.at(index) -> deposit(ammount);
	}

	void withdrawFromAccount(std::string iban, double ammount) {
		int index = findAccount(iban);
		accounts.at(index) -> withdraw(ammount);
	}

	void showAll() {
		int end = accounts.size();
		for (int i=0; i<end; i++) {
			accounts.at(i) -> show();
		}
	}

	void calcTotalCost() {
		int end = accounts.size();
		for (int i=0; i<end; i++) {
			accounts.at(i) -> calcCost();
		}
	}
};
#endif
