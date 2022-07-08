#include <iostream>
#include "queue.h"

using namespace std;

void initQ(Queue *&q)
{
	q->head = q->tail = nullptr;
}
void Put(Queue *&q, Atom a)
{
	Nodq *p;
	p = new Nodq;
	p->data = a;
	p->succ = nullptr;

	if (isEmpty(q))
	{
		q->head = q->tail = p;
	}
	else
	{
		q->tail->succ = p;
		q->tail = p;
	}
}
Atom Get(Queue *&q)
{
	if (!isEmpty(q))
	{
		Atom aux;
		Nodq *p;
		aux = q->head->data;
		p = q->head;
		q->head = q->head->succ;
		if (q->head==nullptr)
		{
			q->tail = nullptr;
		}
		delete p;
		return aux;
	}
	return NULL;
}
Atom Front(Queue *q)
{
	if (!isEmpty(q))
	{
		return q->head->data;
	}
	return NULL;
}
bool isEmpty(Queue *q)
{
	return q->head == nullptr;
}