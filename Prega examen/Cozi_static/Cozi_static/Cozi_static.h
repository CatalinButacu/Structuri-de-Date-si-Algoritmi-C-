#pragma once
#define DIM 20

typedef int Atom;

struct Queue {
	int tail, head;
	Atom v[DIM];
};

void initQ(Queue &q);
bool isEmpty(Queue q);
int nextPos(int index);
void Put(Queue &q, Atom a);
Atom Get(Queue &q);