#include <iostream>
#include "Stive_static.h"

using namespace std;

void initStack(Stack &s)
{
	s.sp = -1;
}
void Push(Stack &s, Atom a)
{
	if (s.sp < DIM - 1)
	{
		s.v[++s.sp] = a;
	}
	else
	{
		cerr << endl << "Stiva este plina!" << endl;
		return;
	}
}
Atom Pop(Stack &s)
{
	Atom aux;
	if (isEmpty(s))
	{
		cerr << endl << "Stiva este goala!" << endl;
	}
	else
	{
		aux = s.v[s.sp--];
		return aux;
	}
}
Atom Top(Stack s)
{
	if (isEmpty(s))
	{
		cerr << endl << "Stiva este goala!" << endl;
	}
	else
	{
		return s.v[s.sp];
	}
}
bool isEmpty(Stack s)
{
	return s.sp == -1;
}