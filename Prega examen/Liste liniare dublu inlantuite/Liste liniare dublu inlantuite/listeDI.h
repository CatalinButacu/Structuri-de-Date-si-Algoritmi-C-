#pragma once

struct Nod {
	int data;
	Nod *succ, *pred;
};

void CreateDLL(Nod *&First, Nod *&Last);
void PrintDLL(Nod*);
void PrintDLL_Reverse(Nod*);
void PrintDLL_Recursiv(Nod*);
bool Insert(Nod*& First, Nod*& Last, int x, int y);
bool Delete(Nod*& First, Nod*& Last, int x);
bool palindrom(Nod*, Nod*);