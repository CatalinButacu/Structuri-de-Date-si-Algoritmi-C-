#include <iostream>
#include <conio.h>
#include "palindrom.h"

using namespace std;

void initStack(stack &s)
{
	s.sp = -1;
}
void Push(stack &s, Atom a)
{
	if (s.sp < MAX - 1)
	{
		s.v[++s.sp] = a;
	}
	else
	{
		cerr << "Stiva este plina!" << endl;
	}
}
bool isEmpty(stack s)
{
	return s.sp == -1;
}
Atom Pop(stack &s)
{
	Atom aux;
	if (!isEmpty(s))
	{
		aux = s.v[s.sp--];
		return aux;
	}
	else
	{
		return 0;
	}
}
Atom Top(stack s)
{
	if (!isEmpty(s))
	{
		return s.v[s.sp];
	}
	else
	{
		return 0;
	}
}


void initQ(Queue &q)
{
	q.head = q.tail = 0;
}
bool isEmpty(Queue q)
{
	return q.head == q.tail;
}
void Put(Queue &q, Atom a)
{
	if (q.head != nextPos(q.tail))
	{
		q.vect[q.tail] = a;
		q.tail = nextPos(q.tail);
	}
	else
	{
		cerr << endl << "Coada este plina!" << endl;
		_getch();
		exit(EXIT_FAILURE);
	}
}
Atom Get(Queue &q)
{
	Atom aux;
	if (!isEmpty(q))
	{
		aux = q.vect[q.head];
		q.head = nextPos(q.head);
		return aux;
	}
}
Atom Front(Queue q)
{
	return q.vect[q.head];
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