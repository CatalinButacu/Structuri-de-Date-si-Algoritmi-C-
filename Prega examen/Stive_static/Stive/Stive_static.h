#pragma once
#define DIM 10

typedef int Atom;

struct Stack {
	int sp;
	Atom v[DIM];
};

void initStack(Stack &s);
void Push(Stack &s, Atom a);
Atom Pop(Stack &s);
Atom Top(Stack s);
bool isEmpty(Stack s);