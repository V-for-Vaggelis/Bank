#ifndef SAVINGS
#define SAVINGS //ensures class does not get defined twice which could create errors
class SavingsAccount{
	double balance;
	int numberOfTransactions;
	std::string Owner,IBAN,contactPhone;
	public:
		static double minBalance; //static defines something whose value is inherited by every new object, it gets initialized in the global scope though
		static double cost;
		SavingsAccount() {
			Owner = "";
			IBAN = "";
			balance = 0;
			contactPhone = "";
			numberOfTransactions = 0;
		}
		SavingsAccount(std::string name, std::string number) {
			Owner = name;
			IBAN = number;
			balance = 0;
			contactPhone = "";
			numberOfTransactions = 0;
		}
		SavingsAccount(std::string name, std::string number, double money, std::string phone) {
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
			calcCost();
			numberOfTransactions++;
		}
		void withdraw(double ammount) {
			if (ammount <= balance) {
				balance -= ammount;
				calcCost();
				numberOfTransactions++;
			}
			else {
				std::cout << "The amount you requested is larger than your balance: (" << balance << " euros)\n" << std::endl;
			}
		}
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
		void show() {
			std::cout << "Name: " << Owner << std::endl;
			std::cout << "IBAN: " << IBAN << std::endl;
			std::cout << "balance: " << balance << std::endl;
			std::cout << "contact: " << contactPhone << "\n" <<std::endl;
		}
};
double SavingsAccount::minBalance = 100.0;
double SavingsAccount::cost = 2.0;
#endif
