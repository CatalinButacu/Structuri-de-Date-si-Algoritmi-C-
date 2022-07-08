#pragma once

struct Nod {
	int data;
	Nod* succ;
};

extern int x;

Nod* CreateList_Rec(int &nrElem);
void PrintList(Nod* cap);
bool palindrom(Nod* cap, int nrElem);
int parcurgeRecursiv(Nod* p);
void palindrom2(Nod *p, Nod *&q, int &ok);