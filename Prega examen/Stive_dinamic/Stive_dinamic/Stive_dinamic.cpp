#include <iostream>
#include "Stive_dinamic.h"

using namespace std;

void initStack(Stack *&s)
{
	s = nullptr;
}
void Push(Stack *&s, Atom a)
{
	Stack *p;
	p = new Stack;
	p->data = a;
	p->leg = s;
	s = p;
}
Atom Pop(Stack *&s)
{
	if (!isEmpty(s))
	{
		Atom aux;
		Stack *p;
		p = s;
		aux = s->data;
		s = s->leg;
		delete p;
		return aux;
	}
	else
	{
		cerr << endl << "Stiva este goala!" << endl;
	}
}
Atom Top(Stack *s)
{
	if (!isEmpty(s))
	{
		return s->data;
	}
	else
	{
		cerr << endl << "Stiva este goala!" << endl;
	}
}
bool isEmpty(Stack *s)
{
	return s == 0;
}