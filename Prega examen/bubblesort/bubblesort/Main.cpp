#include <iostream>
using namespace std;
void bubblesort(float* v, int n)
{
	bool schimbat;
	int i, k = n;
	float aux;
	do {
		schimbat = 0;
		for (i = 0; i<k - 1; ++i)
		{
			if (*(v + i)>*(v + i + 1))
			{
				schimbat = 1;
				aux = *(v + i);
				*(v + i) = *(v + i + 1);
				*(v + i + 1) = aux;
			}
		}
		--k;
	} while (schimbat);
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
	int n;
	cout << "n=";
	cin >> n;
	float *v;
	v = citire(n);
	cout << endl << "Vectorul initial: ";
	afisare(v, n);
	bubblesort(v, n);
	cout << endl << "Vectorul sortat: ";
	afisare(v, n);
	delete[] v;
	v = 0;
	return 0;
}
