#pragma once

typedef int Atom;

struct Nod {
	Atom data;
	Nod *stg, *drt;
};

Nod* makeNod(Atom k);
bool inserare(Nod*& r, Atom a);
bool stergere(Nod*& r, Atom a);
void deleteRoot(Nod*& r);
Nod* removeGreatest(Nod*& r);
Nod* cautare(Nod* r, Atom k);
void inordine(Nod* r);
void afisareIndentata(Nod* r, int nivel);
bool testBST(Nod* r);
Nod* minim(Nod* r);
Nod* maxim(Nod* r);
Nod* parent(Nod* r, Nod* p);
Nod* succesorInordine(Nod* r, Nod* p);
bool testAVL(Nod* r);
int adancime(Nod* r);