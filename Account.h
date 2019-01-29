#ifndef ACCOUNT
#define ACCOUNT //ensures class does not get defined twice which could create errors#include <iostream>
#endif
class Account {
protected:
  double balance;
  int numberOfTransactions;
  std::string Owner,IBAN,contactPhone;
public:
  Account() {
    Owner = "";
    IBAN = "";
    balance = 0;
    numberOfTransactions = 0;
    contactPhone = "";
  }
  Account(std::string name, std::string number) {
    Owner = name;
    IBAN = number;
    balance = 0;
    contactPhone = "";
    numberOfTransactions = 0;
  }
  Account(std::string name, std::string number, double money, std::string phone) {
    Owner = name;
    IBAN = number;
    balance = money;
    contactPhone = phone;
    numberOfTransactions = 0;
  }
  void setContactPhone(std::string phone) {
    contactPhone = phone;
  }
  std::string getContactPhone() {
    return contactPhone;
  }
  std::string getOwner() {
    return Owner;
  }
  std::string getIBAN() {
    return IBAN;
  }
  double getBalance() {
    return balance;
  }
  void deposit(double ammount) {
    balance += ammount;
    // calcCost();
    numberOfTransactions++;
  }
  void withdraw(double ammount) {
    if (ammount <= balance) {
      balance -= ammount;
      // calcCost();
      numberOfTransactions++;
    }
    else {
      std::cout << "The amount you requested is larger than your balance: (" << balance << " euros)\n" << std::endl;
    }
  }
  void show() {
    std::cout << "Name: " << Owner << std::endl;
    std::cout << "IBAN: " << IBAN << std::endl;
    std::cout << "balance: " << balance << std::endl;
    std::cout << "contact: " << contactPhone << "\n" <<std::endl;
  }
};
