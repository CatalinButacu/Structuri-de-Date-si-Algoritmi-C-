#include <iostream>
#include <conio.h>
using namespace std;
int nrOperatii_i, nrOperatii_r;
int binarySearch(float *v, int n, int b)
{
	int st, dr, mij;
	st = 0;
	dr = n - 1;
	while (st <= dr)
	{
		mij = (int)floor((st + dr) / 2);
		if (v[mij] == b)
		{
			++nrOperatii_i;
			return mij;
		}
		else
		{
			if (v[mij] > b)
			{
				++nrOperatii_i;
				dr = mij - 1;
			}
			else
			{
				++nrOperatii_i;
				st = mij + 1;
			}
		}
	}
	return -1;
}
int binarySearchRecursiv(float *v, int st, int dr, int b)
{
	if (st == dr)
	{
		++nrOperatii_r;
		if (*(v + dr) == b)
		{
			return dr;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		int mij = (st + dr) / 2;
		if (*(v + mij) >= b)
		{
			++nrOperatii_r;
			return binarySearchRecursiv(v, st, mij, b);
		}
		else
		{
			++nrOperatii_r;
			return binarySearchRecursiv(v, mij+1, dr, b);
		}
	}
}
void afisare(float* v, int n)
{
	for (int i = 0; i<n; ++i)
	{
		cout << *(v + i) << "; ";
	}
}
float* citire(int n)
{
	float* v;
	v = new float[n];
	for (int i = 0; i<n; ++i)
	{
		cout << "v[" << i << "]=";
		cin >> *(v + i);
	}
	return v;
}
int main()
{
	int n, b, gasit_r, gasit_i;
	cout << "b=";
	cin >> b;
	cout << "n=";
	cin >> n;
	float *v;
	v = citire(n);
	cout << endl << "Vectorul citit: ";
	afisare(v, n);
	gasit_r=binarySearchRecursiv(v, 0, n-1, b);
	gasit_i=binarySearch(v, n, b);
	cout << endl << "Elementul " << b << " se gaseste pe pozitia " << gasit_r + 1 << "." << endl << endl;
	cout << "Numarul de autoapeluri efectuate recursiv: " << nrOperatii_r << endl;
	cout << "Numarul de operatii efectuate iterativ: " << nrOperatii_i << endl;
	delete[] v;
	v = 0;
	_getch();
	return 0;
}