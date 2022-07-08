#include <iostream>
#include <conio.h>
#include "permutari.h"
using namespace std;
int main(void)
{
	int n, i;
	int *v, *s;
	cout << "n=";
	cin >> n;

	v = new int[n+1];
	s = new int[n+1];

	cout << "Vectorul: ";
	for (i = 1; i <= n; ++i)
	{
		v[i] = i-1;
		cout << v[i] << "; ";
	}

	cout << endl << "Permutarile:\n";

	back(v, n, s);

	delete[] v;
	delete[] s;

	_getch();
	return 0;
}