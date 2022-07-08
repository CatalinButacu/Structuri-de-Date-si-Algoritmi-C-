#include <iostream>
#include <conio.h>
#include "stergere.h"

using namespace std;

int main(void)
{
	Nod* cap;
	cap = 0;

	cout << "Introduceti valori nenule in lista liniara simplu inlantuita: ";
	cap = CreateList_Rec();

	PrintList(cap);

	//STERGEREA PRIMULUI ELEMENT
	cout << endl << "Primul element sters:\n";
	Nod* p;
	p = cap;
	cap = p->succ;
	delete p;

	PrintList(cap);

	//STERGEREA ELEMENTULUI DE PE POZITIA 3
			 
	cout << endl << "Elementul de pe pozitia 3 sters:\n";
	p = cap->succ;
	Nod *q;
	q = p->succ;
	p->succ = q->succ;
	delete q;

	PrintList(cap);

	//STERGEREA ULTIMULUI ELEMENT
	cout << endl << "Ultimul element sters:\n";

	Nod* penultim;
	penultim = cap;
	while (penultim->succ->succ)
	{
		penultim = penultim->succ;
	}

	p = penultim->succ;
	penultim->succ = 0;
	delete p;
	p = 0;

	PrintList(cap);

	_getch();

	return 0;
}