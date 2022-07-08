#include <iostream>
#include "lista.h"
#include "citire_afisare.h"

using namespace std;

Nod* CreateList(Nod* cap)
{
	Nod *p;
	int n;
	cout << "Introduceti valori nenule in lista liniara simplu inlantuita: ";
	cin >> n;

	while (n)
	{
		p = new Nod;
		p->data = n;
		p->succ = cap;
		cap = p;
		cin >> n;
	}
	return cap;
}


Nod* CreateList_Rec()
{
	Nod *p;
	int n;
	cin >> n;

	if (n)
	{
		p = new Nod;
		p->succ = CreateList_Rec();
		p->data = n;
		return p;
	}
	return 0;
}

void PrintList(Nod* cap)
{
	Nod *p;
	p = cap;
	while (p)
	{
		cout << p->data << " ";
		p = p->succ;
	}
}

void PrintList_Rec(Nod* p)
{
	if (p)
	{
		PrintList_Rec(p->succ);
		cout << p->data << " ";
	}
}