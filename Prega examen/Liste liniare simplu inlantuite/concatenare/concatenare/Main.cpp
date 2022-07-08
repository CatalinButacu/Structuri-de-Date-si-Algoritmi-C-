#include <iostream>
#include <conio.h>
#include "concatenare.h"

using namespace std;

int main(void)
{			
	Nod *cap1, *cap2;
	cap1 = cap2 = 0;

	cout << "Introduceti elementele primei liste: ";
	cap1 = CreateList_Rec();

	cout << "Introduceti elementele celei de-a doua liste: ";
	cap2 = CreateList_Rec();

	cout << "Prima lista: ";
	PrintList(cap1);

	cout << endl << "A doua lista: ";
	PrintList(cap2);

	cout << endl << "Listele concatenate: ";
	Nod *p;
	p = cap1;
	while (p->succ)
	{
	p = p->succ;
	}
	p->succ = cap2;

	PrintList(cap1);

	_getch();

	return 0;
}