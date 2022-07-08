#include <iostream>
#include <conio.h>

using namespace std;

void insertionSort(float *v, int n)
{
	float temp;
	int i;
	for (int k = 1; k < n; ++k)
	{
		temp = *(v + k);
		i = k - 1;
		while (i >= 0 && *(v + i)>temp)
		{
			*(v + i + 1) = *(v + i);
			--i;
		}
		*(v + i + 1) = temp;
	}
}

int main(void)
{
	float *v;
	int n;

	cout << "n=";
	cin >> n;

	v = new float[n];

	for (int i = 0; i < n; ++i)
	{
		cout << "v[" << i << "]=";
		cin >> *(v + i);
	}

	insertionSort(v, n);

	cout << endl << "Vectorul sortat crescator este:\n";
	for (int i = 0; i < n; ++i)
	{
		cout << *(v + i) << "; ";
	}

	delete[] v;
	v = 0;

	_getch();
	return 0;
}