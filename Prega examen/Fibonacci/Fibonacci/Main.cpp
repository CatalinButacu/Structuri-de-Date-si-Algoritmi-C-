#include <iostream>
#include <conio.h>
#include "Fibonacci.h"
using namespace std;
int main(void)
{
	int n, i;
	cout << "n=";
	cin >> n;

	cout << "Primii " << n << " termeni ai sirului lui Fibonacci sunt: ";
	for (i = 0; i < n; ++i)
	{
		cout << Fibonacci(i) << "; ";
	}
	_getch();
	return 0;
}