#include <iostream>
#include "Stive_dinamic.h"

using namespace std;

int main(void)
{
	int optiune;
	Atom x;
	Stack *s;
	initStack(s);

	do {
		cout << endl << "ALEGETI O OPTIUNE:\n1.PUSH\n2.POP\n3.TOP\n4.IS_EMPTY\n5.PARASIRE PROGRAM\n";
		cin >> optiune;
		switch (optiune)
		{
		case 1:
			cout << endl << "Introduceti elementul de adaugat in stiva: ";
			cin >> x;
			Push(s, x);
			break;
		case 2:
			if (!isEmpty(s))
			{
				cout << endl << "Am scos din stiva elementul " << Pop(s) << "." << endl;
			}
			else
			{
				cerr << endl << "Stiva este goala!" << endl;
			}
			break;
		case 3:
			if (!isEmpty(s))
			{
				cout << endl << "Varful stivei este " << Top(s) << "." << endl;
			}
			else
			{
				cerr << endl << "Stiva este goala!" << endl;
			}
			break;
		case 4:
			if (!isEmpty(s))
			{
				cout << endl << "Stiva nu este goala." << endl;
			}
			else
			{
				cout << endl << "Stiva este goala!" << endl;
			}
			break;
		}
	} while (optiune >= 1 && optiune <= 4);

	return 0;
}