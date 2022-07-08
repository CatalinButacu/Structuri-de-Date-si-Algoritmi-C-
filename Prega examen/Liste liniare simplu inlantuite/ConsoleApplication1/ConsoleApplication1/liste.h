#pragma once

struct Nod {
	int data;
	Nod* succ;
};

Nod* createList(Nod* cap);
Nod* createRec();
void printList(Nod* cap);
void printRec(Nod* p);
Nod* concatenare(Nod* l1, Nod* l2);
Nod* interclasare(Nod* l1, Nod* l2);