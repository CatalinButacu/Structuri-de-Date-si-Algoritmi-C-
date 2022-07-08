#include <iostream>
#include "cozi_dinamic.h"

using namespace std;

void initQ(Queue &q)
{
	q.head = q.tail = nullptr;
}
void Put(Queue &q, Atom a)
{
	Nod *p;
	p = new Nod;
	p->data = a;
	p->succ = nullptr;

	if (q.tail==nullptr)
	{
		q.head = q.tail = p;
	}
	else
	{
		q.tail->succ = p;
		q.tail = p;
	}
}
Atom Get(Queue &q)
{
	if (!isEmpty(q))
	{
		Atom aux;
		Nod *p;
		aux = q.head->data;
		p = q.head;
		q.head = q.head->succ;
		if (q.head == nullptr)
		{
			q.tail = nullptr;
		}
		delete p;
		return aux;
	}
	else
	{
		cerr << endl << "Coada este goala!" << endl;
		return NULL;
	}
}
Atom Front(Queue q)
{
	if (!isEmpty(q))
	{
		return q.head->data;
	}
	else
	{
		cerr << endl << "Coada este goala!" << endl;
		return NULL;
	}
}
bool isEmpty(Queue q)
{
	return q.head == nullptr;
}