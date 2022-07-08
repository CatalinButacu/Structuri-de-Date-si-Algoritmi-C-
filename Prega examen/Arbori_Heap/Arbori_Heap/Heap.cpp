#include <iostream>
#include <math.h>
#include "Heap.h"

using namespace std;

void afisare(int H[], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		cout << H[i] << " ";
	}
}
void inordine(int H[], int n, int poz)
{
	if (poz <= n)
	{
		inordine(H, n, 2 * poz); //subarbore stang
		cout << H[poz] << " "; //afisam nodul curent
		inordine(H, n, 2 * poz + 1); //subarbore drept
	}
}
bool inserare(int H[], int& n, int x)
{
	if (n == NMAX - 1) //arbore plin
	{
		return false;
	}
	H[++n] = x; //pun elementul nou la coada
	int parinte = (int)floor(n / 2); //parintele initial (index)
	int fiu = n; //fiul initial (index)
	while (parinte >= 1)
	{
		if (H[fiu] > H[parinte]) //facem schimb de noduri daca nu este indeplinita inca conditia de MaxHeap
		{
			int aux = H[fiu];
			H[fiu] = H[parinte];
			H[parinte] = aux;
		}
		else //nu mai sunt necesare schimbari, iesim din while
		{
			parinte = 0;
		}
		fiu = parinte; //avansam inspre radacina
		parinte = (int)floor(fiu / 2);
	}
	return true;
}
int stergere(int H[], int& n)
{
	if (n)
	{
		int elem_sters = H[1];
		H[1] = H[n--]; //stergem primul element si il aducem pe ultimul pe pozitia 1
		int parinte = 1; //pozitia initiala a elementului ce trebuie mutat
		int fiu = 2; //fiul stang initial
		while (fiu <= n)
		{
			if (H[fiu] < H[fiu + 1]) //alegem fiul mai mare
			{
				++fiu;
			}
			//fiu = fiul nodului poz cu care facem interschimbarea, daca este necesar
			if (H[parinte] < H[fiu])
			{
				int aux = H[parinte];
				H[parinte] = H[fiu];
				H[fiu] = aux;

				parinte = fiu; //avansam spre frunze
				fiu = 2 * parinte;
			}
			else //nu mai sunt necesare schimbari, iesim din while
			{
				fiu = n + 1;
			}
		}
		return elem_sters;
	}
	else //nu exista elemente de sters
	{
		return NULL;
	}
}

void heapify1(int H[], int n)
{
	//consideram ca inseram elementul de pe pozitia i in Heap-ul H[1]->H[i-1]
	for (int i = 2; i <= n; ++i)
	{
		int k = i - 1; //in Heap-ul de dimensiune i-1
		inserare(H, k, H[i]); //inseram elementul curent
	}
}

void heapify2(int H[], int n)
{
	//consideram ca elementele de la i+1 la n formeaza baza unui Heap
	for (int i = (int)floor(n / 2); i >= 1; --i)
	{
		retrogradare(H, n, i);
	}
}
void retrogradare(int H[], int n, int poz)
{
	int parinte = poz; //pozitia initiala a elementului ce trebuie mutat
	int fiu = 2 * poz; //fiul stang initial
	while (fiu <= n)
	{
		if (H[fiu] < H[fiu + 1]) //alegem fiul mai mare
		{
			++fiu;
		}
		//fiu = fiul nodului poz cu care facem interschimbarea, daca este necesar
		if (H[parinte] < H[fiu])
		{
			int aux = H[parinte];
			H[parinte] = H[fiu];
			H[fiu] = aux;

			parinte = fiu; //avansam spre frunze
			fiu = 2 * parinte;
		}
		else //nu mai sunt necesare schimbari, iesim din while
		{
			fiu = n + 1;
		}
	}
}
void HeapSort(int H[], int n)
{
	while (n >= 1)
	{
		int aux = stergere(H, n);
		H[n + 1] = aux;
	}
}