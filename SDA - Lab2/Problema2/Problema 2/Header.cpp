#include "Header.h"


void citireMat(int ** a, int nrl, int nrc)
{
	for(int i=0;i<nrl;i++)
		for (int j = 0;j < nrc;j++)
		{
			std::cout << "a[" << i << "][" << j << "]= ";
			std::cin >> a[i][j];
		}
}

void afisareMat(int ** a, int nrl, int nrc)
{
	std::cout << "a= " << std::endl;
	for (int i = 0;i < nrl;i++)
	{
		for (int j = 0;j < nrc;j++)
		{
			std::cout << a[i][j]<<' ';
		}
		std::cout << std::endl;
	}
}

void afisareCoord(int ** a, int nrl, int nrc)
{
	int x=0, y=0;
	bool ok = 1;
	while (ok)
	{
		std::cout << "Linia elementului dorit este ";
		std::cin >> x;
		ok = 0;
		if (x > nrl)
		{
			std::cout << "reintroduceti x" << std::endl;
			ok = 1;
		}
	}
	ok = 1;
	while(ok)
	{
	
		std::cout << "Coloana elementului dorit este ";
		std::cin >> y;
		ok = 0;
		if (y> nrc)
		{
			std::cout << "reintroduceti y" << std::endl;
			ok = 1;
		}
	}
	std::cout << "a[" << x << "][" << y << "]= "<<a[x][y]<<std::endl;
}

void valMax(int ** a, int nrl, int nrc)
{

}
