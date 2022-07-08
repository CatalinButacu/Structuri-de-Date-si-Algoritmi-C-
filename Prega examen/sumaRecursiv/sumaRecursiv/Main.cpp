#include <iostream>
using namespace std;
int factorial(int k)
{
	if (k)
	{
		return k*factorial(k - 1);
	}
	else
	{
		return 1;
	}
}
float putere(float x, int n)
{
	if (n)
	{
		return x*putere(x, n - 1);
	}
	else
	{
		return 1;
	}
}
float suma(float x, int i)
{
	if (i >= 0)
	{
		return putere(x, i) / factorial(i) + suma(x, i - 1);
	}
	else
	{
		return 0;
	}
}
int main()
{
	float x;
	int n;
	cout << "x=";
	cin >> x;
	cout << "n=";
	cin >> n;
	cout << "Suma este: " << suma(x, n);
	return 0;
}
