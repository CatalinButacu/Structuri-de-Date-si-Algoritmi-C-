#pragma once
#include "Nod.h"

// 1)
#define M 87 // N=87 => alfa = 1

int f(std::string key, int m);
void Inserare(Nod* Hash[], std::string cheie, int m);
bool Corect(Nod* Hash[], std::string cheie);
void Afisare(Nod* Hash[]);
void Stergere(Nod* Hash[], std::string cheie);

// 2)
#define N 87

#define M1 50
#define M2 100
#define M3 200

#define A 0.618034

int f2(std::string key, int m);
int f3(std::string key, int m);

void Inserare2(Nod* Hash[], std::string cheie, int m);
void Inserare3(Nod* Hash[], std::string cheie, int m);

int Numarare(Nod* Hash[], int pos);
double Clusterizare(Nod* Hash[], int m);

// 3)
void Inserare(Nod2* Hash[], char cheie, int m);
void Afisare(Nod2* Hash[], int m);

 // 4)
void Inserare(Nod3* Hash[], std::string cheie, int m);
void Afisare(Nod3* Hash[], int m);