#ifndef SAVINGS
#define SAVINGS //ensures class does not get defined twice which could create errors
#include "Account.h"
class SavingsAccount:public Account {
public:
	SavingsAccount() {
		Account();
	}
	SavingsAccount(Person per, std::string number) {
		Account(per, number);
	}
	SavingsAccount(Person per, std::string number, double money) {
		Account(per, number, money);
	}
	static double minBalance; //static defines something whose value is inherited by every new object, it gets initialized in the global scope though
	static double cost;
	void calcCost() {
		if (balance < minBalance) {
			if (balance < cost) {
				balance = 0;
			}
			else {
				balance = balance - cost;
			}
		}
	}
};
double SavingsAccount::minBalance = 100.0;
double SavingsAccount::cost = 2.0;
#endif
