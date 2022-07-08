#include "Header.h"

void citireMat(int** a, int nrl, int nrc)
{
	for (int i = 0;i < nrl;i++)
		for (int j = 0;j < nrc;j++)
		{
			std::cout << "a[" << i << "][" << j << "]= ";
			std::cin >> a[i][j];
		}
}

void afisareMat(int** a, int nrl, int nrc)
{
	std::cout << "a= " << std::endl;
	for (int i = 0;i < nrl;i++)
	{
		for (int j = 0;j < nrc;j++)
		{
			std::cout << a[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
void cautareMatrice(int** a, int nrl, int nrc)
{
	int x;
	std::cout << "Ce element cautam? ";
	std::cin >> x;
	int i = 0;
	int j = nrc-1;
	while (j >=0  && i < nrl)
	{
		if (a[i][j] == x)
		{
			std::cout << "Elementul se afla pe linia " << i << " si pe coloana " << j << std::endl;
			exit(-1);
		}
		else if (a[i][j] < x)
		{
			i++;
		}
		else if(a[i][j]>x)
		{
			j--;
		}
	}

	std::cout << "Nu exista elementul!" << std::endl;
}