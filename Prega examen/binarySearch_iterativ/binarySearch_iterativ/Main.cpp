#include <iostream>
#include <conio.h>

using namespace std;

int binarySearch(float *v, int n, float b)
{
	int st, dr, mij;
	st = 0;
	dr = n-1;
	while (st <= dr)
	{
		mij = (st + dr) / 2;
		if (*(v + mij) == b)
		{
			return mij+1;
		}
		else
		{
			if (*(v + mij) > b)
			{
				dr = mij - 1;
			}
			else
			{
				st = mij + 1;
			}
		}
	}
	return 0;
}
int main(void)
{
	int n, poz;
	float *v, b;

	cout << "n=";
	cin >> n;

	v = new float[n];

	for (int i = 0; i < n; ++i)
	{
		cout << "v[" << i << "]=";
		cin >> *(v + i);
	}

	cout << endl << "Introduceti elementul cautat: ";
	cin >> b;

	if (poz=binarySearch(v, n, b))
	{
		cout << "Elementul " << b << " se regaseste pe pozitia " << poz << ".";
	}
	else
	{
		cout << "Elementul " << b << " nu se gaseste in vector.";
	}

	delete[] v;
	v = 0;

	_getch();
	return 0;
}