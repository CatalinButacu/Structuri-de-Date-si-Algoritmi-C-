#pragma once

#define NMAX 100

void afisare(int H[], int n);
void inordine(int H[], int n, int poz);
bool inserare(int H[], int& n, int x);
int stergere(int H[], int& n);

void heapify1(int H[], int n);
void heapify2(int H[], int n);
void retrogradare(int H[], int n, int poz);
void HeapSort(int H[], int n);