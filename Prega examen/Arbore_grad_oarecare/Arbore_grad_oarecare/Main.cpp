#include <iostream>
#include "arbore.h"

using namespace std;

int main(void)
{
	Nod* rad = nullptr;

	cout << "Introduceti expresia aritmetica pe baza careia va fi creat arborele: ";
	rad = creareArbore();

	int optiune;

	do {
		cout << endl << "ARBORE DE GRAD OARECARE\n1.AFISARE\n2.DETERMINARE GRAD\n3.AFISARE OPERANZI\n4.AFISARE OPERATORI\n5.EVALUARE EXPRESIE\n6.PARASIRE PROGRAM\n";
		cin >> optiune;

		switch (optiune)
		{
		case 1:
			cout << endl << "Arborele este:\n";
			afisareArbore(rad);
			cout << endl;
			break;
		case 2:
			cout << endl << "Gradul arborelui este: " << determinaGrad(rad) << "." << endl;
			break;
		case 3:
			cout << endl << "Operanzii arborelui sunt:\n";
			afisareOperanzi(rad);
			cout << endl;
			break;
		case 4:
			cout << endl << "Operatorii arborelui sunt:\n";
			afisareOperatori(rad);
			break;
		case 5:
			cout << endl << "Valoarea expresiei este: " << evaluareExpresie(rad) << "." << endl;
			break;
		}
	} while (optiune >= 1 && optiune <= 5);

	return 0;
}