#include <iostream>
#include <conio.h>
#include "listeDI.h"

using namespace std;

int main(void)
{
	Nod *First, *Last;
	First = Last = nullptr;

	int x, y;

	cout << "Introduceti elemente in lista liniara dublu inlantuita (0 incheie citirea): ";
	CreateDLL(First, Last);

	cout << endl << "Afisarea listei de la cap la coada: ";
	PrintDLL(First);

	cout << endl << "Afisarea listei de la coada la cap: ";
	PrintDLL_Reverse(Last);

	cout << endl << "Afisarea listei recursiv: ";
	PrintDLL_Recursiv(First);
	cout << endl;

	if (palindrom(First, Last))
	{
		cout << endl << "Sirul de numere introdus este palindrom.";
	}
	else
	{
		cout << endl << "Sirul de numere introdus nu este palindrom.";
	}

	cout << endl << endl << "Introduceti numarul de sters din lista: ";
	cin >> x;

	if (Delete(First, Last, x))
	{
		cout << "Nodul " << x << " a fost sters din lista." << endl;
	}
	else
	{
		cout << "Nodul " << x << " nu a putut fi gasit in lista." << endl;
	}
	PrintDLL(First);

	cout << endl << "Introduceti elementul dupa care va fi inserat un nou element in lista: ";
	cin >> x;

	cout << "Introduceti elementul de inserat in lista: ";
	cin >> y;

	if (Insert(First, Last, x, y))
	{
		cout << "Nodul " << y << " a fost inserat in lista dupa elementul " << x << "." << endl;
	}
	else
	{
		cout << "Nodul " << x << " nu a putut fi gasit in lista. Inserarea nu poate fi facuta." << endl;
	}
	PrintDLL(First);

	_getch();
	return 0;
}