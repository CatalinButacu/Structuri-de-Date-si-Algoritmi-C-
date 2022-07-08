#include "Header.h"
#include<iostream>
int main()
{
	int nrl, nrc;
	std::cout << "Nr linii matrice= ";
	std::cin >> nrl;
	std::cout << "Nr coloane matrice= ";
	std::cin >> nrc;
	int** a = new int* [nrl];
	for (int i = 0;i < nrl;i++)
	{
		a[i] = new int[nrc];
	}
	
	citireMat(a, nrl, nrc);
	afisareMat(a, nrl, nrc);
	cautareMatrice(a, nrl, nrc);
	delete[] a;
	return 0;
}
