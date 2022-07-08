#include <iostream>
#include <fstream>
#include <conio.h>
#include "labirint.h"

using namespace std;

int main(void)
{
	ifstream f("labirint.txt");

	int m, n;
	char** L = nullptr;
	L = citeste_labirint(m, n, f);

	int x_i, x_f, y_i, y_f; //pozitiile initiala si finala

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (L[i][j] == 'I')
			{
				x_i = i;
				y_i = j;
			}
			if (L[i][j] == 'F')
			{
				x_f = i;
				y_f = j;
			}
			cout << L[i][j];
		}
		cout << endl;
	}

	cout << endl << x_i << " " << y_i << " " << x_f << " " << y_f << endl;

	if (!cautare(x_i, y_i, L, x_f, y_f, m, n))
	{
		cout << "Nu exista drum spre iesirea labirintului." << endl;
	}
	else
	{
		cout << "Exista drum spre iesirea labirintului." << endl;
	}

	f.close();

	_getch();
	return 0;
}