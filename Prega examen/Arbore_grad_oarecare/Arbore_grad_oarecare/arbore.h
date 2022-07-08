#pragma once

#define DIM_EXPR 100
#define GRMAX 20
#define Atom char

struct Nod
{
	Atom data;
	int grad;
	Nod* vDesc[GRMAX];
};

Nod* parse(char buffer[], int start, int end);
Nod* creareArbore();

int determinaGrad(Nod* r);
void afisareArbore(Nod* r);
void afisareOperanzi(Nod* r);
void afisareOperatori(Nod* r);
int evaluareExpresie(Nod* r);