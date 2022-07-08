#include <iostream>
#include <conio.h>
#include "mijloc.h"

using namespace std;

int main(void)
{
	Nod* cap;
	cap = 0;

	cout << "Introduceti valori nenule in lista liniara simplu inlantuita: ";
	cap = CreateList_Rec();

	PrintList(cap);

	Nod *p, *q;
	p = cap;
	q = cap;
	while (q && q->succ)
	{
	p = p->succ;
	q = q->succ->succ;
	}
	cout << endl << "Elementul din mijlocul listei este: " << p->data << endl;		

	_getch();

	return 0;
}