#include <iostream>
#include "lista.h"
#include "citire_afisare_simpla.h"

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