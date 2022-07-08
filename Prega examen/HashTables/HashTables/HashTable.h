#pragma once

#define M 23
#define CMAX 80

struct Nod {
	char* cheie;
	Nod* succ;
};

int f_hash(char* key);
bool cautare(char* key, Nod* HT[]);
void inserare(Nod* HT[]);
void stergere(char* key, Nod* HT[]);
void afisare(Nod* HT[]);
void afisareHistograma(Nod* HT[]);
void eliberareMemorie(Nod* HT[]);

Nod* citireNod();