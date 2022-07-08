#include <iostream>
#include <conio.h>
#include "interclasare.h"

using namespace std;

int main(void)
{
	Nod* cap;
	cap = 0;

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

	cout << endl << "Listele interclasate: ";

	Nod* l_inter;
	l_inter = 0;

	l_inter = interclasareListe(cap1, cap2);
	PrintList(l_inter);

	_getch();

	return 0;
}