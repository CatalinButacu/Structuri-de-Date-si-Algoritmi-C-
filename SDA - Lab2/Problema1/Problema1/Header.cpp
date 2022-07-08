#include "Header.h"

int sum(int v[], int i, int j)
{
	int s = 0;
	for (int k = i;k <= j;++k)
		s += v[k];

	return s;
}
