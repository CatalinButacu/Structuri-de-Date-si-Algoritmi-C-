#pragma once

#define MAX 20
typedef int Atom;

struct stack {
	int sp;
	Atom v[MAX];
};

void initStack(stack &s);
void Push(stack &s, Atom a);
bool isEmpty(stack s);
Atom Pop(stack &s);
Atom Top(stack s);