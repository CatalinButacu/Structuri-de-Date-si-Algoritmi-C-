#pragma once

struct Nod {
	char data;
	Nod* stg, *drt;
};

Nod* creareArbore();

void eroare();
char readchar();
char citesteNume();
Nod* citesteArbore();
Nod* creareArbore();

void inordine(Nod* r);
void preordine(Nod* r);
void postordine(Nod* r);
void parcurgereNivel(Nod* r);
int determinaAdancime(Nod* r);
char calcMax(char v1, char v2);
char maxim(Nod* r);
int nrNoduri(Nod* r);
int nrFrunze(Nod* r);
void radMMDesc(Nod* r);
void stMMdr(Nod* r);
void comuta(Nod* r);
void afisareArbore(Nod* r);