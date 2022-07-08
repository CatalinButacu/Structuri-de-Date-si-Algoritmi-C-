#include<iostream>
#include"Header.h"
int main()
{
	int n;
	std::cout << "Nr de val ale vectorului= ";
	std::cin >> n;
	int *a = citire(n);
	Element *cap = 0;
	for (int i=0;i < n;++i)
	{
		inserareFata(cap, a[i]);
	}

	afisare(cap);
	inserare(cap);
	afisare(cap);
	return 0;
}