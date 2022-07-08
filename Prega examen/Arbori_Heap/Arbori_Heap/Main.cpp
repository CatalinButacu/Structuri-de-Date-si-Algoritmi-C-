#include <iostream>
#include <conio.h>
#include "Heap.h"

using namespace std;

int main(void)
{
	int H[NMAX], n = 0;
	int optiune, x;

	do {
		system("CLS");
		cout << "ARBORE HEAP\nAlegeti o optiune:\n1.INSERARE\n2.STERGERE\n3.AFISARE\n4.AFISARE IN INORDINE\n5.INSERARE VECTOR OARECARE + HEAPIFY + HEAPSORT\n6.PARASIRE PROGRAM\n";
		cin >> optiune;
		cin.get();

		switch (optiune)
		{
		case 1:
			cout << endl << "Introduceti elementul de inserat: ";
			cin >> x;
			if (inserare(H, n, x))
			{
				cout << endl << "Nodul " << x << " a fost inserat cu succes.";
			}
			else
			{
				cout << endl << "Arborele Heap este plin!";
			}
			break;
		case 2:
			if (n)
			{
				x = stergere(H, n);
				cout << endl << "Nodul " << x << " a fost sters cu succes.";
			}
			else
			{
				cout << endl << "Arborele Heap este gol!";
			}
			break;
		case 3:
			if (n)
			{
				cout << endl << "Arborele Heap este:" << endl;
				afisare(H, n);
			}
			else
			{
				cout << endl << "Arborele Heap este gol.";
			}
			break;
		case 4:
			if (n)
			{
				cout << endl << "Arborele Heap afisat in inordine este:" << endl;
				inordine(H, n, 1);
			}
			else
			{
				cout << endl << "Arborele Heap este gol.";
			}
			break;
		case 5:
		{
			int v[NMAX], nv;
			cout << endl << "Introduceti numarul de elemente: ";
			cin >> nv;
			cout << endl << "Introduceti elementele vectorului de sortat: " << endl;
			for (int i = 1; i <= nv; ++i)
			{
				cout << "v[" << i << "]=";
				cin >> v[i];
			}

			//heapify1(v, nv);
			heapify2(v, nv);
			cout << endl << endl << "Vectorul dupa Heapify:" << endl;
			afisare(v, nv);

			HeapSort(v, nv);
			cout << endl << endl << "Vectorul dupa HeapSort:" << endl;
			afisare(v, nv);
			break;
		}
		case 6:
			exit(EXIT_SUCCESS);
			break;
		}
		cout << endl << endl << "Apasati o tasta.";
		_getch();
	} while (optiune >= 1 && optiune <= 5);
	return 0;
}