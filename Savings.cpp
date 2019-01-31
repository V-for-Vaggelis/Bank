#include <iostream>
#include <stdlib.h>
#include "Person.h"
#include "Bank.h"
#include <time.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Bank b;
	Person p1(29, "Polychronis Athanasakis", "Karamanlh 38, Serres", "6976470259");
	Person p2(25, "Evangelos Athanasakis", "Redestou 38, Serres", "6978940387");
	b.createAccount(p1, "GR23u343045", 100, 1);
	b.createAccount(p1, "GR4645030", 100, 2);
	b.createAccount(p2, "GR98769525", 3000, 1);
	b.createAccount(p2, "GR93405589", 3000, 2);
	
	//Create random transactions
	for (int i=1; i<15; i++) {
		/* initialize random seed: */
  		srand (time(NULL));

  	/* generate random number between 1 and 200: */
		double rand1 = rand() % 200 + 1;
		double rand2 = rand() % 200 + 1;
		b.depositToAccount("GR23u343045", rand1);
		b.withdrawFromAccount("GR23u343045", rand2);
		b.depositToAccount("GR4645030", rand1);
		b.withdrawFromAccount("GR4645030", rand2);
		b.depositToAccount("GR98769525", rand1);
		b.withdrawFromAccount("GR98769525", rand2);
		b.depositToAccount("GR93405589", rand1);
		b.withdrawFromAccount("GR93405589", rand2);

	}
	cout << "\nBefore cost calculation:\n" << endl;
	b.showAll();
	b.calcTotalCost();
	cout << "\nAfter cost calculation:\n" << endl;
	b.showAll();
	b.deleteAccount("GR23u343045");
	cout << "\nAfter deleting the first\n" << endl;
	b.showAll();
	return 0;
}
