#include"Header.h"

int* citire(int n)
{
	
	int *a = 0;
	a = new int[n];
	for (int i = 0;i < n;++i)
	{
		std::cout << "a[" << i << "]= ";
		std::cin >> a[i];
	}
	return a;
}

void inserareFata(Element *&cap, int val)
{
	if (cap == NULL)
	{
		cap = new Element;
		cap->data = val;
		cap->leg = 0;
	}
	else
	{
		Element* p = new Element;
		p->data = val;
		p->leg = cap;
		cap = p;
	}	
}
void inserare(Element*& cap)
{
	
	int x;
	int val;
	std::cout << "Numarul dorit pt a fi inserat:";
	std::cin >>val;
	std::cout << "Pozitia pe care amdori sa fie inserat elementul este:";
	std::cin >> x;

	if (cap == NULL)
	{
		cap = new Element;
		cap->data = val;
		cap->leg = 0;
	}
	else
	{
		Element* q=nullptr;
		Element* p = new Element;
		for (int i = 0;i < x;++i)
		{
		}
		
	}
	
}
void afisare(Element* cap)
{
	for (Element* t = cap;t != 0;t = t->leg)
	{
		std::cout << t->data << ' ';
	}
	std::cout << std::endl;
}
