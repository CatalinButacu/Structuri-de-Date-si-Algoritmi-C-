#include <iostream>
#include <conio.h>
#include "Hanoi.h"
int main(void)
{
	int n = 4;
	char ti = 'A', tm = 'B', tf = 'C';

	Hanoi(n, ti, tf, tm);

	_getch();

	return 0;
}