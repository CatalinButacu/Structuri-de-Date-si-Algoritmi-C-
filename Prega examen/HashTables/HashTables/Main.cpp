#include <iostream>
#include "HashTable.h"

using namespace std;

int main(void)
{
	Nod* HT[M];

	for (int i = 0; i < M; ++i)
	{
		HT[i] = nullptr;
	}

	int optiune;

	do {
		cout << endl << "MENIU HASH TABLE\n1.INSERARE\n2.STERGERE\n3.CAUTARE\n4.AFISARE TABELA HASH\n5.AFISARE HISTOGRAMA\n6.PARASIRE PROGRAM\n";
		cin >> optiune;
		cin.get();

		switch (optiune)
		{
		case 1:
			cout << endl << "Introduceti cheia nodului de inserat in tabela: ";
			inserare(HT);
			break;
		case 2:
		{
			cout << endl << "Introduceti cheia nodului de sters din tabela: ";
			char cheie[CMAX];
			cin.get(cheie, CMAX - 1);
			cin.get();
			stergere(cheie, HT);
			break;
		}
		case 3:
			cout << endl << "Introduceti cheia nodului de cautat in tabela: ";
			char cheie[CMAX];
			cin.get(cheie, CMAX - 1);
			cin.get();
			if (cautare(cheie, HT))
			{
				cout << endl << "Nodul cu cheia \"" << cheie << "\" exista in tabela Hash." << endl;
			}
			else
			{
				cout << endl << "Nodul cu cheia \"" << cheie << "\" nu exista in tabela Hash!" << endl;
			}
			break;
		case 4:
			cout << endl << "Tabela Hash contine urmatoarele elemente:\n\n";
			afisare(HT);
			break;
		case 5:
			cout << endl << "Histograma tabelei Hash:\n\n";
			afisareHistograma(HT);
			break;
		}
	} while (optiune >= 1 && optiune <= 5);

	eliberareMemorie(HT);

	return 0;
}