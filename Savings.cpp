#include <iostream>
#include "Savings.h"
#include "Bank.h"
#include "CheckingAccount.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	SavingsAccount sa1("Evangelos Athanasakis", "GR2143254546");
	SavingsAccount sa2("Polychronis Athanasakis", "GR568589789", 1000.0, "6974560836");
	
	cout << "Deposit 99 euros to sa1:" << endl;
	sa1.deposit(99);
	sa1.show();
	cout << "Withdraw 96 euros from sa1:" << endl;
	sa1.withdraw(96);
	sa1.show();
	
	cout << "Withdraw 1200 euros from sa2:" << endl;
	sa2.withdraw(1200);
	sa2.show();
	
	cout << "Change sa2 contact phone:" << endl;
	sa2.setContactPhone("6978945690");
	
	sa2.show();
	
	Bank b;
	b.insertAccount(sa1);
	b.insertAccount(sa2);
	
	cout << "Search an account" << endl;
	int index = b.findAccount("GR568589789");
	cout << "Account position: " << index << endl;
	cout << "delete the account" << endl;
	b.deleteAccount("GR568589789");
	cout << "Search account again" << endl;
	int index2 = b.findAccount("GR568589789");
	cout << "Account position: " << index2 << endl;
	
	cout << "\nChecking account without bank registry:\n" << endl;
	CheckingAccount sa3("Evangelos Athanasakis", "GR2143254546");
	
	cout << "Deposit 99 euros to sa3:" << endl;
	sa3.deposit(99);
	sa3.show();
	cout << "Withdraw 96 euros from sa3:" << endl;
	sa3.withdraw(96);
	sa3.show();
	
	cout << "Deposit 50 euros to sa3:" << endl;
	sa3.deposit(50);
	sa3.show();
	cout << "Withdraw 30 euros from sa3:" << endl;
	sa3.withdraw(30);
	sa3.show();
	cout << "Withdraw 21 euros from sa3:" << endl;
	sa3.withdraw(21);
	sa3.show();
	
	return 0;
}
