#include <iostream>
#include <conio.h>
#include "palindrom.h"

using namespace std;

int main(void)
{
	int nrElem=0;
	Nod* cap;
	cap = 0;

	cout << "Introduceti valori nenule in lista liniara simplu inlantuita: ";
	cap = CreateList_Rec(nrElem);

	/*
	if (nrElem < 6)
	{
		cout << "Reluati programul si introduceti cel putin 6 elemente in lista.";
		_getch();
		exit(EXIT_FAILURE);
	}
	*/

	PrintList(cap);
	cout << endl;

	int ok;
	//if (palindrom(cap, nrElem))
	palindrom2(cap, cap, ok);
	if (ok)
	{
		cout << endl << "Lista este palindroma.";
	}
	else
	{
		cout << endl << "Lista nu este palindroma.";
	}
	_getch();

	return 0;
}