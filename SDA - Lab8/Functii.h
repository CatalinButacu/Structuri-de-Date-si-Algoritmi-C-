#pragma once

// E1)
void InserareList(Element *&cap, int val);
void ParcurgereList(Element* cap);
Element* Rev_leg_rec(Element* p, Element* q);
void InOrder_rec(Element*& cap);
void Afisare_rec(Element* cap);

// E2)
int cmmdc(int m, int n);

// E3)
int fact(int n);
float putere(float x, int n);
float S(float x, int n);
float S_rec(float x, int n);

// E4)
int binSearch(int a[], int b, int st, int dr);

// E5)
int Fibonacci(int n);
int Fib(int n,int *a);

// E6)
bool isPrime(int p, int i = 2);

// E7)
void swamp(int& a, int& b);
void afisare(int* a, int n);
void Permutari(int* a,int n,int length);

// E8)
void Hanoi(int n, int& ti, int& tf, int& tm);