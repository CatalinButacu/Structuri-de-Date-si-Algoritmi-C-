#include <iostream>
#include "lista.h"
#include "interclasare.h"

Nod* interclasareListe(Nod* l1, Nod* l2)
{
	Nod* lf;
	lf = 0;

	Nod *p1, *p2;
	p1 = l1;
	p2 = l2;

	while (p1 && p2) //cat timp nu se termina vreo lista
	{
		Nod *p, *q;
		p = new Nod;
		p->data = p1->data;
		p->succ = lf;
		lf = p;

		q = new Nod;
		q->data = p2->data;
		q->succ = lf;
		lf = q;

		p1 = p1->succ;
		p2 = p2->succ;
	}

	if (p1) //daca s-a terminat a doua lista
	{
		while (p1)
		{
			Nod* r;
			r = new Nod;
			r->data = p1->data;
			r->succ = lf;
			lf = r;

			p1 = p1->succ;
		}
	}
	else //daca s-a terminat prima lista
	{
		while (p2)
		{
			Nod* r;
			r = new Nod;
			r->data = p2->data;
			r->succ = lf;
			lf = r;

			p2 = p2->succ;
		}
	}

	Nod *p, *q, *r;
	p = lf;
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
	lf = r;

	return lf;
}