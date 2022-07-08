#include <iostream>
#include <conio.h>
#include "ordonare.h"

using namespace std;

int main(void)
{
	stack s;
	Atom v[MAX];
	int n;

	initStack(s);

	cout << "Numarul de elemente din vector: ";
	cin >> n;
	cout << "Introduceti elementele vectorului (ordonate crescator): ";
	for (int i = 0; i < n; ++i)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
		Push(s, v[i]);
	}

	cout << "Vectorul ordonat crescator: ";
	for (int i = 0; i < n; ++i)
	{
		cout << v[i] << " ";
	}

	cout << endl << "Vectorul ordonat descrescator: ";
	for (int i = 0; i < n; ++i)
	{
		v[i] = Pop(s);
		cout << v[i] << " ";
	}

	_getch();
	return 0;
}