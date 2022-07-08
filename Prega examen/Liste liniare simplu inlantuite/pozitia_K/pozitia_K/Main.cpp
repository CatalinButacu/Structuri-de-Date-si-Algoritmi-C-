#include <iostream>
#include <conio.h>
#include "pozitia_K.h"

using namespace std;

int main(void)
{
	Nod* cap;
	cap = 0;

	cout << "Introduceti elementele listei: ";
	cap = CreateList_Rec();

	PrintList(cap);

	int k;
	cout << endl << "k=";
	cin >> k;
	Nod *p, *q;
	int i;
	q = cap;
	p = cap;
	for (i = 1; i < k; ++i)
	{
		if (q->succ)
		{
			q = q->succ;
		}
		else
		{
			cout << endl << "Eroare! Lista este prea scurta pentru valoarea lui k.";
			exit(EXIT_FAILURE);
			_getch();
		}
	}
	while (q->succ)
	{
		p = p->succ;
		q = q->succ;
	}

	cout << "Elementul de pe pozitia " << k << " din coada este: " << p->data;

	_getch();

	return 0;
}