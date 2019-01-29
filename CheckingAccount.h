#ifndef CHECKINGACCOUNT
#define CHECKINGACCOUNT //ensures class does not get defined twice which could create errors
class CheckingAccount{
	double balance;
	int numberOfTransactions;
	std::string Owner,IBAN,contactPhone;
public:
	static double costPerTransaction; //static defines something whose value is inherited by every new object, it gets initialized in the global scope though
	CheckingAccount() {
		Owner = "";
		IBAN = "";
		balance = 0;
		contactPhone = "";
		numberOfTransactions = 0;
	}
	CheckingAccount(std::string name, std::string number) {
		Owner = name;
		IBAN = number;
		balance = 0;
		contactPhone = "";
		numberOfTransactions = 0;
	}
	CheckingAccount(std::string name, std::string number, double money, std::string phone) {
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
		numberOfTransactions++;
		balance += ammount;
		calcCost();
	}
	void withdraw(double ammount) {
		if (ammount <= balance) {
			numberOfTransactions++;
			balance -= ammount;
			calcCost();
		}
		else {
			std::cout << "The amount you requested is larger than your balance: (" << balance << " euros)\n" << std::endl;
		}
	}
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
	void show() {
		std::cout << "Name: " << Owner << std::endl;
		std::cout << "IBAN: " << IBAN << std::endl;
		std::cout << "balance: " << balance << std::endl;
		std::cout << "contact: " << contactPhone << "\n" <<std::endl;
	}
};
double CheckingAccount::costPerTransaction = 0.5;
#endif
