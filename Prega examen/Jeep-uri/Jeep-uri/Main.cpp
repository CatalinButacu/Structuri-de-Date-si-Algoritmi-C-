#include <iostream>
#include <conio.h>
#include "Jeep-uri.h"
using namespace std;
int main(void)
{
	float r, c, dmax, dp;
	int n;
	cout << "Numarul de litri de benzina din Jeep / canistre: r=";
	cin >> r;
	cout << "Numarul de canistre: n=";
	cin >> n;
	cout << "Consumul Jeep-ului (l/100km): c=";
	cin >> c;
	dmax = r * 100 / c;
	dp = distanta(n, dmax);
	cout << "Jeep-ul poate parcurge max. " << dp << " km.";
	_getch();
	return 0;
}