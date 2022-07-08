#include <iostream>
using namespace std;
int factorial(int k)
{
	if (k == 0)
	{
		return 1;
	}
	else
	{
		return k*factorial(k - 1);
	}
}
int main()
{
	int n;
	cout << "n=";
	cin >> n;
	cout << n << "!=" << factorial(n);
	return 0;
}
