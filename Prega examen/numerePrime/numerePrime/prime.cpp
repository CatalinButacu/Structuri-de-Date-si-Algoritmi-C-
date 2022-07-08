#include "prime.h"

bool isPrim(int x, int i)
{
	if (i == x)
	{
		return 1;
	}
	if (x%i == 0)
	{
		return 0;
	}
	return isPrim(x, i + 1);
}