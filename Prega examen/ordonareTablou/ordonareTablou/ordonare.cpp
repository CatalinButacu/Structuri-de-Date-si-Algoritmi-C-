#include <iostream>
#include "ordonare.h"

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