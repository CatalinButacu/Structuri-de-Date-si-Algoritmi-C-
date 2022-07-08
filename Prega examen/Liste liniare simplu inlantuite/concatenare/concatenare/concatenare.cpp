#include <iostream>
#include "concatenare.h"

using namespace std;

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