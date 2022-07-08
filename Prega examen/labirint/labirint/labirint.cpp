#include <iostream>
#include <fstream>
#include "labirint.h"

using namespace std;

char** citeste_labirint(int &m, int &n, ifstream &fisier)
{
	char** L = nullptr;

	fisier >> m; //numar de linii
	fisier.get();
	L = new char*[m];

	fisier >> n; //numar de coloane
	fisier.get();
	for (int i = 0; i < m; ++i)
	{
		L[i] = new char[n];
	}

	for (int i = 0; i < m; ++i) //citire matrice de caractere
	{
		for (int j = 0; j < n; ++j)
		{
			fisier >> L[i][j];
		}
	}

	return L;
}

bool cautare(int x, int y, char** L, int x_f, int y_f, int m, int n)
{
	L[x][y] = '2'; //facem mutarea pe noua casuta din labirint

	if (x == x_f && y == y_f) //daca am ajuns la iesire
	{
		return true;
	}

	//cautam pe pozitiile invecinate celei curente, atat timp cat nu am dat de zid
	if (y < n && L[x][y + 1] != '1' && cautare(x, y + 1, L, x_f, y_f, m, n)) //la dreapta
	{
		return true;
	}
	if (x < m && L[x + 1][y] != '1' && cautare(x + 1, y, L, x_f, y_f, m, n)) //in sus
	{
		return true;
	}
	if (y > 0 && L[x][y - 1] != '1' && cautare(x, y - 1, L, x_f, y_f, m, n)) //la stanga
	{
		return true;
	}
	if (x > 0 && L[x - 1][y] != '1' && cautare(x - 1, y, L, x_f, y_f, m, n)) //in jos
	{
		return true;
	}

	L[x][y] = '0'; //am dat de o fundatura, mergem inapoi recursiv corectand pasii gresiti

	return false; //daca nu exista solutie
}