#include <iostream>
#include <conio.h>
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
	int k;
	for (k = 0; k <= n / 2 - 1; ++k)
	{
		for (i = k; i <= n-1-k; ++i)
		{
			cout << a[k][i]<<" ";
		}
		for (i = k + 1; i <= n - k - 1; ++i)
		{
			cout << a[i][n-k-1] << " ";
		}
		for (i = n - k - 2; i >= k; --i)
		{
			cout << a[n-k-1][i] << " ";
		}
		for (i = n - k - 2; i >= k + 1; --i)
		{
			cout << a[i][k] << " ";
		}
	}
	if (n % 2 != 0)
	{
		cout << a[n / 2][n / 2];
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