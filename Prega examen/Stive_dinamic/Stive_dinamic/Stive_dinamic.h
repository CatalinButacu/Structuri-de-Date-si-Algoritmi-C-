#pragma once

typedef int Atom;

struct Stack {
	Atom data;
	Stack *leg;
};

void initStack(Stack *&s);
void Push(Stack *&s, Atom a);
Atom Pop(Stack *&s);
Atom Top(Stack *s);
bool isEmpty(Stack *s);