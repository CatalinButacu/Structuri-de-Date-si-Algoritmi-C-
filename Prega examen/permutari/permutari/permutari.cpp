#include <iostream>
#include "permutari.h"

void initializare(int k, int *s)
{
	s[k] = -1;
}
bool exista(int k, int *s, int n)
{
	return s[k] < n-1;
}
bool valid(int k, int *s, int n)
{
	int i;
	for (i = 1; i < k; ++i)
	{
		if (s[i] == s[k])
		{
			return false;
		}
	}
	return true;
}
bool solutie(int k, int n)
{
	return k == n;
}
void afisare(int k, int *s)
{
	int i;
	for (i = 1; i <= k; ++i)
	{
		std::cout << s[i] << " ";
	}
	std::cout << std::endl;
}
void back(int *v, int n, int *s)
{
	int k;
	k = 1;
	initializare(k, s);
	while (k > 0)
	{
		if (exista(k, s, n))
		{
			s[k] = s[k] + 1;
			if (valid(k, s, n))
			{
				if (solutie(k, n))
				{
					afisare(k, s);
				}
				else
				{
					++k;
					initializare(k, s);
				}
			}
		}
		else
		{
			--k;
		}
	}
}