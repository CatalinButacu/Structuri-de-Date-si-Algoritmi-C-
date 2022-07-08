#pragma once
#define infinit 1000000
#define maxi 9
void citire_graf(int** a, int n, int m);
void afisare_graf(int** a, int n);
void dijkstra(int** a, int n, int dist[], int previous[], int sursa);