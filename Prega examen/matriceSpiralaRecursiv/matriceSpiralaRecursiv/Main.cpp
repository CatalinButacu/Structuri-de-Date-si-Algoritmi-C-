#include <iostream>
#include <conio.h>
#include "Spirala.h"
using namespace std;
int main(void)
{
	int n;
	float** a = 0;
	int i, j;
	cout << "n=";
	cin >> n;

	a = new float*[n];

	for (i = 0; i < n; ++i)
	{
		a[i] = new float[n];
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	}

	cout << "Matricea initiala:\n";

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Matricea parcursa in spirala:\n";
	afisareSpirala(a, n, 0);

	for (int i = 0; i < n; ++i)
	{
		delete[] a[i];
		a[i] = 0;
	}

	delete[] a;
	a = 0;

	_getch();

	return 0;
}