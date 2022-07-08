#include <iostream>
#include "liste.h"

using namespace std;

Nod* createList(Nod* cap)
{
	Nod* p;
	int n;
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

Nod* createRec()
{
	Nod *p;
	int n;
	cin >> n;
	if (n)
	{
		p = new Nod;
		p->succ = createRec();
		p->data = n;
		return p;
	}
	return 0;
}

void printList(Nod* cap)
{
	Nod *p;
	p = cap;
	while (p)
	{
		cout << p->data << " ";
		p = p->succ;
	}
}

void printRec(Nod* p)
{
	if (p)
	{
		printRec(p->succ);
		cout << p->data << " ";
	}
}

Nod* concatenare(Nod* l1, Nod* l2)
{
	Nod *p;
	p = l1;
	while (p->succ)
	{
		p = p->succ;
	}
	p->succ = l2;
	return l1;
}

Nod* interclasare(Nod* l1, Nod* l2)
{
	Nod *p, *q;
	Nod *rez, *r;
	rez = 0;
	p = l1;
	q = l2;

	while (p && q)
	{
		r = new Nod;
		r->data = p->data;
		r->succ = rez;
		rez = r;

		r = new Nod;
		r->data = q->data;
		r->succ = rez;
		rez = r;

		p = p->succ;
		q = q->succ;
	}

	if (q)
	{
		while (q)
		{
			r = new Nod;
			r->data = q->data;
			r->succ = rez;
			rez = r;
			q = q->succ;
		}
	}
	else
	{
		while (p)
		{
			r = new Nod;
			r->data = p->data;
			r->succ = rez;
			rez = r;
			p = p->succ;
		}
	}

	p = rez;
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
	r->succ = q;
	rez = r;

	return rez;
}