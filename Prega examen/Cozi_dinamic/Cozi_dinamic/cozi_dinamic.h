#pragma once

typedef int Atom;

struct Nod {
	Atom data;
	Nod* succ;
};

struct Queue {
	Nod *head, *tail;
};

void initQ(Queue &q);
void Put(Queue &q, Atom a);
Atom Get(Queue &q);
Atom Front(Queue q);
bool isEmpty(Queue q);