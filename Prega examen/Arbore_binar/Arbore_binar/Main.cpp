#include <iostream>
#include "arbore.h"

using namespace std;

int main(void)
{
	Nod* arb = nullptr;

	arb = creareArbore();

	int optiune;

	do {
		cout << endl << "1.AFISARE IN INORDINE\n2.AFISARE IN PREORDINE\n3.AFISARE IN POSTORDINE\n4.PARCURGERE PE NIVEL\n5.DETERMINA ADANCIME\n6.CALCULEAZA VALOAREA MAXIMA DIN ARBORE\n7.AFISARE NUMAR DE NODURI INTERNE\n8.AFISARE NUMAR DE FRUNZE\n9.RAD>DESC\n10.SUBARB_ST<SUBARB_DR\n11.COMUTARE SUBARBORI\n12.PARASIRE PROGRAM\n";
		cin >> optiune;
		cin.get();

		switch (optiune)
		{
		case 1:
			cout << endl << "Arborele afisat in inordine este:\n";
			inordine(arb);
			cout << endl;
			break;
		case 2:
			cout << endl << "Arborele afisat in preordine este:\n";
			preordine(arb);
			cout << endl;
			break;
		case 3:
			cout << endl << "Arborele afisat in postordine este:\n";
			postordine(arb);
			cout << endl;
			break;
		case 4:
			cout << endl << "Arborele parcurs pe nivel este:\n";
			parcurgereNivel(arb);
			cout << endl;
			break;
		case 5:
			cout << endl << "Adancimea arborelui este " << determinaAdancime(arb) << "." << endl;
			break;
		case 6:
			cout << endl << "Valoarea maxima din arbore este " << maxim(arb) << "." << endl;
			break;
		case 7:
			cout << endl << "Numarul de noduri interne este " << nrNoduri(arb)-1 << "." << endl;
			break;
		case 8:
			cout << endl << "Numarul de frunze este " << nrFrunze(arb) << "." << endl;
			break;
		case 9:
			cout << endl << "Nodurile care au valoarea radacinii mai mare decat toate valorile din subarborii descendenti sunt: ";
			radMMDesc(arb);
			cout << endl;
			break;
		case 10:
			cout << endl << "Nodurile pentru care toate valorile din subarborele stang sunt mai mici decat toate valorile din subarborele drept sunt: ";
			stMMdr(arb);
			cout << endl;
			break;
		case 11:
			cout << endl << "Arborele comutat este: " << endl;
			comuta(arb);
			afisareArbore(arb);
			cout << endl;
			break;
		}
	} while (optiune >= 1 && optiune <= 11);

	return 0;
}