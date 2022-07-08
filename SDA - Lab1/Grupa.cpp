#include "Grupa.h"

void InitGrupa(Grupa &g)
{
	std::cout << "Nr de studenti din grupa este: ";
	std::cin >> g.nr;
	std::cout << "ID-ul grupei este:";
	std::cin >> g.id;
	
	g.tab = new Student[g.nr];
	for (int i = 0;i < g.nr ;++i)
	{
		InitStudent(g.tab[i]);
	}
	
}

void AfisGrupa(Grupa g)
{
	std::cout << "Nr de studenti din grupa " <<g.id<<" este: " << g.nr;
	for (int i = 0;i < g.nr;++i)
	{
		AfisStudent(g.tab[i]);
	}
}

void StergeGrupa(Grupa &g)
{
	for (int i = 0;i < g.nr;++i)
	{
		StergeStudent(g.tab[i]);
	}
	delete[] g.tab;
}

void CautaStudent(Grupa g)
{
	int OK = 0;
	char* c;
	c = new char[10];
	std::cout<<std::endl;
	std::cout<<"Numele studentului cautat este ";
	std::cin >> c;
	for (int i = 0;i < g.nr;++i)
	{
		if (strcmp((g.tab[i]).nume, c) == 0)
		{
			OK = 1;
			std::cout << "Nota studentului " << c << " este ";
			std::cout << (g.tab[i]).nota<<std::endl;
		}
	}
	if (OK == 0)
	{
		std::cout << "Nu exista niciun student cu numele " << c << std::endl;
	}
	delete[] c;
}

void NotaMaxMin(Grupa g)
{
	int nMax = 0;
	int nMin = 10;
	for (int i = 0;i < g.nr;++i)
	{
		if ((g.tab[i]).nota > nMax)
		{
			nMax = (g.tab[i]).nota;
		}

		if ((g.tab[i]).nota < nMin)
		{
			nMin = (g.tab[i]).nota;
		}
	}
	std::cout << "Nota maxima este: " << nMax;
	std::cout << "Nota minima este: " << nMin;
}
