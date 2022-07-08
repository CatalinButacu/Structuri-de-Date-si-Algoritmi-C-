#include <iostream>
#include <conio.h>
#include "prime.h"
using namespace std;
int main(void)
{
	int x;
	cout << "x=";
	cin >> x;
	if (isPrim(x, 2))
	{
		cout << "Numarul " << x << " este prim.";
	}
	else
	{
		cout << "Numarul " << x << " nu este prim.";
	}
	_getch();
	return 0;
}