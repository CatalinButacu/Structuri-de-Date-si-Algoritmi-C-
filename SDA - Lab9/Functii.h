#pragma once
#include "Tree.h"

// 1)
// a)
void Insert(Tree*& cap, int val);

// b)
void Preordine(Tree* cap);
void Postordine(Tree* cap);
void Inordine(Tree* cap);

// c)
bool Cauta(Tree* cap,int val);

// d)
Tree* removeGreatest(Tree*& r);
void deleteRoot(Tree*& rad);
void Delete(Tree*& rad, int a);

// 2)
// a)
bool Cauta_nerec(Tree* cap, int val);
// b)
void Insert_nerec(Tree*& cap, int val);
// c)
void Delete_nerec(Tree*& cap, int val);