#include <iostream>
#include "Cozi_static.h"

using namespace std;

int main(void)
{
	int optiune;
	Atom x;
	Queue q;
	initQ(q);

	do {
		cout << endl << "ALEGETI O OPTIUNE:\n1.PUT\n2.GET\n3.IS_EMPTY\n4.PARASIRE PROGRAM\n";
		cin >> optiune;
		switch (optiune)
		{
		case 1:
			cout << endl << "Introduceti elementul de adaugat in coada: ";
			cin >> x;
			Put(q, x);
			break;
		case 2:
			if (!isEmpty(q))
			{
				cout << endl << "Am scos din coada elementul " << Get(q) << "." << endl;
			}
			else
			{
				cerr << endl << "Coada este goala!" << endl;
			}
			break;
		case 3:
			if (!isEmpty(q))
			{
				cout << endl << "Coada nu este goala." << endl;
			}
			else
			{
				cout << endl << "Coada este goala!" << endl;
			}
			break;
		}
	} while (optiune >= 1 && optiune <= 3);

	return 0;
}