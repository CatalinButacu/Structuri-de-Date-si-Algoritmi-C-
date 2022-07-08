#pragma once

struct Nod {
	int data;
	Nod* succ;
};

void createCL(Nod *&cap);
void printCL(Nod *cap);
void permutari(Nod* cap);
bool ciclare(Nod* cap);
void inserare(Nod*& cap, int x);
bool stergere(Nod*& cap, int x);