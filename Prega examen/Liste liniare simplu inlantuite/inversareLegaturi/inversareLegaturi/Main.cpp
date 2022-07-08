#include <iostream>
#include <conio.h>
#include "inversare.h"

using namespace std;

int main(void)
{
	Nod* cap;
	cap = 0;

	cout << "Introduceti valori nenule in lista liniara simplu inlantuita: ";
	cap = CreateList_Rec();

	PrintList(cap);
	
	if (!cap)
	{
		cout << endl << "Lista este vida!" << endl;
	}
	else if (!cap->succ)
	{
		cout << endl << "Lista contine un singur element. Nu exista elemente de inversat." << endl;
	}
	else if (!cap->succ->succ)
	{
		Nod *q = cap->succ;
		cap->succ = 0;
		q->succ = cap;
		cap = q;
	}
	else
	{
		Nod *p, *q, *r;
		p = cap;
		q = p->succ;
		r = q->succ;
		p->succ = 0;
		q->succ = p;
		while (r->succ)
		{
			p = q;
			q = r;
			r = r->succ;
			q->succ = p;
		}
		q->succ = p;
		r->succ = q;
		cap = r;
	}

	cout << endl << "Lista cu legaturile inversate:\n";
	PrintList(cap);
			 
	_getch();

	return 0;
}