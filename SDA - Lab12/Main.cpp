#include"Graf.h"

int main()
{
	int n,m;
	std::cout << "Numar noduri= ";
	std::cin >> n;
	std::cout << "Numar muchii= ";
	std::cin >> m;
	int** a=nullptr;
	a = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	citire_graf(a, n, m);
	afisare(a, n);
	return 0;

}