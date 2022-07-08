#include <iostream>
#include <limits>
#include "functii.h"

using namespace std;

int main()
{
	int n; int m;
	cout << "numarul de noduri" << endl;
	cin >> n;
	cout << "numar muchii" << endl;
	cin >> m;
	int** a;
	a = new int* [n];

	for (int i = 0; i < n; i++)
	{


		a[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;

		}

	}
	cout << "graful=" << endl;
	citire_graf(a, n, m);
	afisare_graf(a, n);

	int previous[maxi];
	for (int i = 0; i < maxi; i++)
	{
		previous[i] = -1;
	}
	 unsigned int uimax = std::numeric_limits<unsigned  int>::max();
	
	int dist[maxi];
	for (int i = 0; i < maxi; i++)
	{
		dist[i] = uimax;
	}
	dijkstra(a, n, dist, previous,1);

	return 0;
}