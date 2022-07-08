#pragma once

#define MAX 20
#define DIM 20

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

struct Queue {
	int tail, head;
	Atom vect[DIM];
};

void initQ(Queue &q);
bool isEmpty(Queue q);
void Put(Queue &q, Atom a);
Atom Get(Queue &q);
Atom Front(Queue q);
int nextPos(int index);