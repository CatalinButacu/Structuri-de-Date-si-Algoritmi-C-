#include <iostream>
#include "cozi_dinamic.h"

using namespace std;

int main(void)
{
	Queue q;
	initQ(q);

	Atom x;
	int optiune;

	do {
		cout << endl << "Alegeti o optiune:\n1.PUT\n2.GET\n3.FRONT\n4.IS_EMPTY\n5.PARASIRE PROGRAM\n";
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
				cout << endl << "Am extras din coada elementul " << Get(q) << "." << endl;
			}
			else
			{
				cerr << endl << "Coada este goala!" << endl;
			}
			break;
		case 3:
			if (!isEmpty(q))
			{
				cout << endl << "Capul cozii este " << Front(q) << "." << endl;
			}
			else
			{
				cerr << endl << "Coada este goala!" << endl;
			}
			break;
		case 4:
			if (isEmpty(q))
			{
				cout << endl << "Coada este goala!" << endl;
			}
			else
			{
				cout << endl << "Coada nu este goala." << endl;
			}
			break;
		}
	} while (optiune>=1 && optiune<=4);

	return 0;
}