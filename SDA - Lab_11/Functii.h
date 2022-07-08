#pragma once

// 1)
void Schimba(int& a, int& b);
void Insert(int A[], int n, int x);
int  Remove(int A[], int& n);
void Afisare(int A[], int N);
void Afisare_Inordine(int A[], int N, int nod = 0);

// 2)
void Retro(int A[], int N, int i);
void BuildHeap_v1(int A[], int N);
void BuildHeap_v2(int A[], int N);
void Heapsort(int A[], int N);