#include <iostream>
#include <conio.h>
using namespace std;
long int nrOperatii;
void selectionSort(float* v, int n)
{
	int i, j, m;
	float aux;
	for (i = 0; i < n - 1; ++i)
	{
		m = i;
		for (j = i + 1; j < n; ++j)
		{
			if (*(v + j) < *(v + i))
			{
				m = j;
				++nrOperatii;
			}
		}
		aux = *(v + i);
		*(v + i) = *(v + m);
		*(v + m) = aux;
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
		//cout << "v[" << i << "]=";
		//cin >> *(v + i);
		*(v + i) = n - i;
	}
	return v;
}
int main()
{
	int n;
	//cout << "n=";
	//cin >> n;
	n = 21;
	float *v;
	v = citire(n);
	//cout << endl << "Vectorul initial: ";
	//afisare(v, n);
	selectionSort(v, n);
	//cout << endl << "Vectorul sortat: ";
	afisare(v, n);
	cout << endl << "Numarul de operatii efectuate: " << nrOperatii << endl;

	delete[] v;
	v = 0;

	_getch();
	return 0;
}
