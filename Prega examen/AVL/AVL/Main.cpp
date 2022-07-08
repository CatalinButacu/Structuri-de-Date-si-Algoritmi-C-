#include<iostream>
#include <conio.h>
#include "AVL.h"
using namespace std;

int main()
{
	AVL* arboreAVL = nullptr;
	int x;

	/*
	int v[] = { 20,9,26,5,7,17,23,30,11,22,28,33,27,29,32,37};
	for (int i = 0; i < sizeof(v) / sizeof(v[0]); i++)
		InsertAVL(arboreAVL, v[i]);
	*/
	
	int optiune;
	do {
		system("CLS");
		cout << "Arbore AVL\nAlegeti o optiune:\n1.INSERARE\n2.STERGERE\n3.AFISARE\n4.TEST AVL\n5.PARASIRE PROGRAM\n";
		cin >> optiune;

		switch (optiune)
		{
		case 1:
			cout << endl << "Introduceti nodul de inserat: ";
			cin >> x;
			InsertAVL(arboreAVL, x);
			cout << endl << "Nodul " << x << " a fost inserat cu succes.";
			break;
		case 2: 
			cout << endl << "Introduceti nodul de sters: ";
			cin >> x;
			RemoveNode(arboreAVL, x);
		case 3:
			cout << endl << "Arborele AVL afisat indentat:" << endl;
			AfisareIndentat(arboreAVL, 0);
			break;
		case 4:
			if (testAVL(arboreAVL))
			{
				cout << endl << "Arborele este AVL.";
			}
			else
			{
				cout << endl << "Arborele nu este AVL.";
			}
			break;
		case 5:
			exit(EXIT_SUCCESS);
			break;
		}
		cout << endl << endl << "Apasati o tasta...";
		_getch();
	} while (optiune >= 1 && optiune <= 4);

	return 0;
}