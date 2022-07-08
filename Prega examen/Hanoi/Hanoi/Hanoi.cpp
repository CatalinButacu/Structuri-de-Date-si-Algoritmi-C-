#pragma once
#include <iostream>
#include "Hanoi.h"

int i = 1;

void Hanoi(int n, char ti, char tf, char tm)
{
	if (n == 1)
	{
		std::cout << i<<") "<< ti << " >> " << tf<<"\n";
		++i;
	}
	else
	{
		Hanoi(n - 1, ti, tm, tf);
		std::cout << i << ") " << ti << " >> " << tf << "\n";
		++i;
		Hanoi(n - 1, tm, tf, ti);
	}
}