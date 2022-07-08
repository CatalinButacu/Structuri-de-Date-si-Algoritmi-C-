#pragma once
#include "arbore.h"

typedef Nod* Atom;

struct Nodq {
	Atom data;
	Nodq* succ;
};

struct Queue {
	Nodq *head, *tail;
};

void initQ(Queue *&q);
void Put(Queue *&q, Atom a);
Atom Get(Queue *&q);
Atom Front(Queue *q);
bool isEmpty(Queue *q);