#include <iostream>
#include "functii.h"
using namespace std;
void citire_graf(int** a, int n, int m)
{
	int i, j;
	int cost;
	for (int k = 0; k < m; k++)
	{
		cout << "i" << " " << "j" << " " << "cost";
		cin >> i >> j >> cost;
		a[i - 1][j - 1] = cost;
	}

}

void afisare_graf(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}

}

void dijkstra(int** a, int n, int dist[], int previous[],int sursa)
{

	int cost[maxi][maxi];
	int vizitat[maxi];
	int count;
	int minidist;
	int next;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				cost[i][j] = infinit;
			}
			else
			{
				cost[i][j] = a[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		dist[i] = cost[sursa][i];
		previous[i] = sursa;
		vizitat[i] = 0;
	}

	dist[sursa] = 0;
	vizitat[sursa] = 1;
	count = 1;

	while (count < n - 1)
	{
		minidist = infinit;
	
		for (int i = 0; i < n; i++)
		{
			if (dist[i] < minidist && !vizitat[i])
			{	minidist = dist[i];
				next = i;
			}
		

			for (int j = 0; j < n; j++)
			{
				if (!vizitat[j])
				{
					if (minidist + cost[next][j] < dist[j])
					{
					dist[j] = minidist + cost[next][j];
					previous[j] = next;
					}

				}
			}
		}

		count++;

	}
	int j;
	for (int i = 0; i < n; i++)
	{
		if (i != sursa)
		{
			cout << sursa << "->" << i << "drum " << dist[i] << endl;
			//cout << "distanta nodului" << i <<" " <<dist[i] << endl;
			//cout << "drumul " << i;
			
			//j = i;
			
			/*do {

				j = previous[j];
				cout << "<-" << j;
			} while (j != sursa);*/
		}
	}
}
