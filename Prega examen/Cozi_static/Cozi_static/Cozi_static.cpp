#include <iostream>
#include "Cozi_static.h"

using namespace std;

void initQ(Queue &q)
{
	q.tail = q.head = 0;
}
bool isEmpty(Queue q)
{
	return q.head == q.tail;
}
int nextPos(int index)
{
	if (index < DIM - 1)
	{
		return index + 1;
	}
	else
	{
		return 0;
	}
}
void Put(Queue &q, Atom a)
{
	if (q.head != nextPos(q.tail))
	{
		q.v[q.tail] = a;
		q.tail = nextPos(q.tail);
	}
	else
	{
		cerr << endl << "Coada este plina!" << endl;
		return;
	}
}
Atom Get(Queue &q)
{
	if (!isEmpty(q))
	{
		Atom aux;
		aux = q.v[q.head];
		q.head = nextPos(q.head);
		return aux;
	}
}