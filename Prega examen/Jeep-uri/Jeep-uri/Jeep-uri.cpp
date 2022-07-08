#include "Jeep-uri.h"

float distanta(int n, float dmax)
{
	if (n == 1)
	{
		return dmax;
	}
	else
	{
		return dmax/(2*n-3) + distanta(n - 1, dmax);
	}
}