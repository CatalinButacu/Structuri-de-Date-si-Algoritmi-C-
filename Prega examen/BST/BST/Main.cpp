#include <iostream>
#include <conio.h>
#include "BST.h"

using namespace std;

int main(void)
{
	Nod* BST = nullptr;
	int optiune;
	Atom x;

	do {
		system("CLS");
		cout << "Arbore BST\nAlegeti o optiune:\n1.INSERARE\n2.STERGERE\n3.CAUTARE\n4.AFISARE IN INORDINE\n5.AFISARE INDENTATA\n6.TEST BST\n7.CALCUL MINIM\n8.CALCUL MAXIM\n9.TEST AVL\n10.PARASIRE PROGRAM\n";
		cin >> optiune;
		cin.get();

		switch (optiune)
		{
		case 1:
			cout << endl << "Introduceti cheia nodului de inserat: ";
			cin >> x;
			cin.get();
			if (inserare(BST, x))
			{
				cout << endl << "Nodul a fost inserat cu succes.";
			}
			else
			{
				cout << endl << "Cheie duplicata!";
			}
			break;
		case 2:
			cout << endl << "Introduceti cheia nodului de sters: ";
			cin >> x;
			cin.get();
			if (stergere(BST, x))
			{
				cout << endl << "Nodul a fost sters cu succes.";
			}
			else
			{
				cout << endl << "Nodul nu a fost gasit in BST!";
			}
			break;
		case 3:
		{
			cout << endl << "Introduceti cheia nodului de cautat: ";
			cin >> x;
			cin.get();
			Nod* p = cautare(BST, x);
			if (p)
			{
				cout << endl << "Nodul " << p->data << " a fost gasit in BST.";
			}
			else
			{
				cout << endl << "Nodul " << x << " nu exista in BST!";
			}
			break;
		}
		case 4:
			cout << endl << "Arborele afisat in inordine (ordine crescatoare) este: " << endl;
			inordine(BST);
			break;
		case 5:
			cout << endl << "Arborele afisat indentat este: " << endl;
			afisareIndentata(BST, 0);
			break;
		case 6:
			if (testBST(BST))
			{
				cout << endl << "Arborele este BST.";
			}
			else
			{
				cout << endl << "Arborele nu este BST.";
			}
			break;
		case 7:
			cout << endl << "Valoarea minima din BST este " << minim(BST)->data << ".";
			break;
		case 8:
			cout << endl << "Valoarea maxima din BST este " << maxim(BST)->data << ".";
			break;
		case 9:
			if (testAVL(BST))
			{
				cout << endl << "Arborele este AVL.";
			}
			else
			{
				cout << endl << "Arborele nu este AVL.";
			}
			break;
		case 10:
			exit(EXIT_SUCCESS);
			break;
		}
		cout << endl << endl << "Apasati o tasta...";
		_getch();
	} while (optiune >= 1 && optiune <= 8);

	return 0;
}