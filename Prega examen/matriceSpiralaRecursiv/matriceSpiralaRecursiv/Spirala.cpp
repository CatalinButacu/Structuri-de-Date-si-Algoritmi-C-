#include <iostream>
#include "Spirala.h"
using namespace std;

void afisareSpirala(float** a, int n, int k)
{
	if (k == n / 2)
	{
		cout << a[n / 2][n / 2];
	}
	else
	{
		int i;
		for (i = k; i <= n - 1 - k; ++i)
		{
			cout << a[k][i] << " ";
		}
		for (i = k + 1; i <= n - k - 1; ++i)
		{
			cout << a[i][n - k - 1] << " ";
		}
		for (i = n - k - 2; i >= k; --i)
		{
			cout << a[n - k - 1][i] << " ";
		}
		for (i = n - k - 2; i >= k + 1; --i)
		{
			cout << a[i][k] << " ";
		}
		afisareSpirala(a, n, k + 1);
	}
}