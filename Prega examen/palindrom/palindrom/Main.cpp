#include <iostream>
#include <conio.h>
#include "palindrom.h"

using namespace std;

int main(void)
{
	int x;
	Queue q;
	stack s;
	bool palindrom=true;

	initQ(q);
	initStack(s);

	cout << "Introduceti sirul de numere (0 termina citirea): ";
	cin >> x;
	while (x)
	{
		Put(q, x);
		Push(s, x);
		cin >> x;
	}

	while (!isEmpty(q))
	{
		if (Pop(s) != Get(q))
		{
			palindrom = false;
			break;
		}
	}

	if (palindrom)
	{
		cout << endl << "Sirul de numere este palindrom.";
	}
	else
	{
		cout << endl << "Sirul de numere nu este palindrom.";
	}

	_getch();

	return 0;
}