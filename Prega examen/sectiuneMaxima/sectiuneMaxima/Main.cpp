#include <iostream>
#include <conio.h>
using namespace std;
int main(void)
{
	int n, i;
	float* A = 0;

	cout << "n=";
	cin >> n;

	A = new float[n];

	for (i = 0; i < n; ++i)
	{
		cout << "A[" << i << "]=";
		cin >> A[i];
	}

	cout << "\nTabloul citit este: \n";
	for (i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}

	for (i = n; i > 1; --i)
	{

	}

	delete[] A;
	A = 0;

	_getch();

	return 0;
}