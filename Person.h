#ifndef PERSON
#define PERSON //ensures class does not get defined twice which could create errors#include <iostream>
class Person{
	int age;
	std::string name, contactAddress, contactPhone;
	public:
		Person() {
		}
		Person(int x, std::string y, std::string z, std::string k) {
			age = x;
			name = y;
			contactAddress = z;
			contactAddress = k;
		}
		void setName(std::string y) {
			name = y;
		}
		std::string getName() {
			return name;
		}
		void setAge(int x) {
			age = x;
		}
		int getAge() {
			return age;
		}
		void setContactAddress(std::string adr) {
			contactAddress = adr;
		}
		std::string getContactAddress() {
			return contactAddress;
		}
		void setContactPhone(std::string ph) {
			contactAddress = ph;
		}
		std::string getContactPhone() {
			return contactPhone;
		}
		void printPerson() {
			std::cout << "Name: " << name << std::endl;
			std::cout << "Age: " << age << std::endl;
			std::cout << "contact address: " << contactAddress << std::endl;
			std::cout << "contact phone: " << contactPhone << std::endl;
		}
};
#endif
