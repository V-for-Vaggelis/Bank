#ifndef CHECKINGACCOUNT
#define CHECKINGACCOUNT //ensures class does not get defined twice which could create errors
#include "Account.h"
#include <iostream>

class CheckingAccount:public Account {
public:
	CheckingAccount() : Account() {}
	CheckingAccount(Person per, std::string number) : Account(per, number) {}
	CheckingAccount(Person per, std::string number, double money) :	Account(per, number, money) {}

	static double costPerTransaction; //static defines something whose value is inherited by every new object, it gets initialized in the global scope though
	void calcCost() {
		if (numberOfTransactions > 2) {
			double cost = costPerTransaction*(numberOfTransactions-2);
			double estimatedBalance = balance - cost;
			if (estimatedBalance > 0) {
				balance = estimatedBalance;
			}
			else {
				balance = 0;
			}
		}
	}

};
double CheckingAccount::costPerTransaction = 0.5;
#endif
