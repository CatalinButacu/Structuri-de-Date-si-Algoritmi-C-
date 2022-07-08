#include <iostream>
#include "palindrom.h"

using namespace std;

Nod* CreateList_Rec(int &nrElem)
{
	Nod *p;
	int n;
	cin >> n;

	if (n)
	{
		++nrElem;
		p = new Nod;
		p->succ = CreateList_Rec(nrElem);
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

int parcurgeRecursiv(Nod* p)
{
	static Nod *q;
	static int data;
	if (p->succ)
	{
		q = p;
		parcurgeRecursiv(p->succ);
	}
	else
	{
		data = p->data;
		return data;
	}
}

bool palindrom(Nod* cap, int nrElem)
{
	Nod *p, *q, *r;
	r = 0;
	p = cap;
	q = p;
	while (q && q->succ)
	{
		r = p;
		p = p->succ;
		q = q->succ->succ;
	}

	if (nrElem % 2 == 0)
	{
		q = r->succ;
		r->succ = 0;
		//cap -> 0 ||| q -> 0
		r = cap;
		while (r->succ)
		{
			if (r->data != parcurgeRecursiv(q))
			{
				return false;
			}
			r = r->succ;
			q = q->succ;
		}
		return true;
	}
	else
	{
		q = p->succ;
		p->succ = 0;
		//cap -> 0 ||| q -> 0
		r = cap;
		while (r->succ)
		{
			if (r->data != parcurgeRecursiv(q))
			{
				return false;
			}
			r = r->succ;
			q = q->succ;
		}
		return true;
	}
}

void palindrom2(Nod *p, Nod *&q, int &ok)
{
	if (p)
	{
		palindrom2(p->succ, q, ok);
		if (p->data != q->data)
		{
			ok = 0;
		}
		q = q->succ;
	}
}