#include "Graf.h"

void citire_graf(int** a, int n, int m)
{
	int i, j, cost;
	for (int k = 0; k < m; k++)
	{
		std::cout << "i,j,cost=";
		std::cin >> i;
		std::cin >> j;
		std::cin >> cost;
		a[i-1][j-1] = cost;

	}
}

void afisare(int** a, int n)
{
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << a[i][j];
		}
		std::cout << std::endl;

	}
}
