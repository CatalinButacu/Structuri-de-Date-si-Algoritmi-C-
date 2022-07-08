#include <iostream>
#include <conio.h>
#include "listeCirculare.h"

using namespace std;

int main(void)
{
	Nod* listaCirculara;
	listaCirculara = nullptr;
	int x;

	cout << "Introduceti elemente in lista circulara (0 incheie citirea): ";
	createCL(listaCirculara);

	cout << endl << "Lista circulara citita este:" << endl;
	printCL(listaCirculara);

	cout << endl << "Test lista circulara: ";
	if (ciclare(listaCirculara))
	{
		cout << "lista este circulara";
	}
	else
	{
		cout << "lista nu este circulara";
	}
	cout << endl;

	cout << endl << "Permutarile circulare sunt:" << endl;
	permutari(listaCirculara);

	cout << endl << "Introduceti elementul de inserat in lista circulara (dupa capul listei): ";
	cin >> x;
	inserare(listaCirculara, x);
	printCL(listaCirculara);

	cout << endl << "Introduceti elementul de sters din lista circulara: ";
	cin >> x;
	if (stergere(listaCirculara, x))
	{
		cout << "Elementul " << x << " a fost sters din lista." << endl;
		printCL(listaCirculara);
	}
	else
	{
		cout << "Elementul " << x << " nu a fost gasit in lista.";
	}

	_getch();
	return 0;
}