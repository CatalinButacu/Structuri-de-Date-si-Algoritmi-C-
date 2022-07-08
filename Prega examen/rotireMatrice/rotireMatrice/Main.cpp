#include <iostream>
#include <conio.h>
using namespace std;
int main(void)
{
	int n;
	float** a = 0;
	float aux;
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

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			aux = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = aux;
		}
	}
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n - 2; ++j)
		{
			aux = a[i][j];
			a[i][j] = a[i][n - j - 1];
			a[i][n - j - 1] = aux;
		}
	}

	cout << "Matricea rotita:\n";
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

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