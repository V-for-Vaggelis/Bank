#ifndef ACCOUNT
#define ACCOUNT //ensures class does not get defined twice which could create errors#include <iostream>
#include "Person.h"
#include <iostream>

class Account {
protected:
  Person p;
  double balance;
  int numberOfTransactions;
  std::string IBAN;
public:
  Account(Person per, std::string number, double money) {
    p = per;
    IBAN = number;
    balance = money;
    numberOfTransactions = 0;
  }

  virtual void calcCost() {
  }

  void setContactPhone(std::string phone) {
    p.setContactPhone(phone);
  }

  std::string getContactPhone() {
    return p.getContactPhone();
  }

  std::string getOwner() {
    return p.getName();
  }

  std::string getIBAN() {
    return IBAN;
  }

  double getBalance() {
    return balance;
  }

  void deposit(double ammount) {
    balance += ammount;
    numberOfTransactions++;
  }

  void withdraw(double ammount) {
    if (ammount <= balance) {
      balance -= ammount;
      numberOfTransactions++;
    }
    else {
      std::cout << "The amount you requested is larger than your balance: (" << balance << " euros)\n" << std::endl;
    }
  }

  void show() {
    p.printPerson();
    std::cout << "IBAN: " << IBAN << std::endl;
    std::cout << "balance: " << balance << std::endl;
  }
};
#endif
