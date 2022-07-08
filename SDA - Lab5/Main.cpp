#include <iostream>
#include "Functii.h"
#include "Element.h"
#include "Circular.h"

//Pentru fiecare problema trebuie ca if-urile de sa fie 1 separat pentru fiecare

int main() 
{
//1)
#if 0
	int val,pos;
	Element* cap = nullptr;
	std::cout << "nr de inserat = ";
	std::cin >> val;

	while (val != -1)
	{
		InserareFata(cap, val);
		std::cout << "nr de inserat = ";
		std::cin >> val;
	}

	AfisareD_I(cap);

	std::cout << std::endl;
	std::cout << "nr de inserat2 = ";
	std::cin >> val;

	std::cout << std::endl;
	std::cout << "pos de inserat = ";
	std::cin >> pos;

	InserarePos(cap,pos,val); //Lista porneste de la index-ul 0
	Afisare(cap);

	std::cout << std::endl;
	std::cout << "pos de sters = ";
	std::cin >> pos;

	StergePos(cap, pos); //Lista porneste de la index-ul 0
	Afisare(cap);
#endif

//2)
#if 0

	Element* cap1=nullptr, *cap2=nullptr, *cap=nullptr, *list=nullptr;
	int val;
	std::cout << "Cap 1:" << std::endl;
	std::cout << "Nr de inserat = ";
	std::cin >> val;

	while (val != -1)
	{
		InserareFata(cap1, val);
		std::cout << "nr de inserat = ";
		std::cin >> val;
	}

	std::cout << "Cap 2:" << std::endl;
	std::cout << "Nr de inserat = ";
	std::cin >> val;

	while (val != -1)
	{
		InserareFata(cap2, val);
		std::cout << "nr de inserat = ";
		std::cin >> val;
	}

	std::cout << "Lista 1:" << std::endl;
	Afisare(cap1);
	std::cout << std::endl;
	std::cout << "Lista 2:" << std::endl;
	Afisare(cap2);
	std::cout << std::endl;
	
	std::cout << "Concatenare:" << std::endl;
	Concat(cap, cap1, cap2);
	Afisare(cap);
	std::cout << std::endl;

	std::cout << "Intercalare:" << std::endl;
	Inercal(list,cap1,cap2);
	Afisare(list);
#endif

//3)
#if 0

	Circular* cap=nullptr;
	int val;
	std::cout << "Nr de inserat = ";
	std::cin >> val;

	while (val != -1)
	{
		InserareFata(cap, val);
		std::cout << "nr de inserat = ";
		std::cin >> val;
	}
	std::cout << "Lista:" << std::endl;
	Afisare(cap);
	std::cout << std::endl;

	std::cout << "Lista cu legaturi inversate:" << std::endl;
	InversareLeg(cap);
	Afisare(cap);

#endif

//4)
#if 0
	Circular* cap1 = nullptr,*cap2=nullptr;
	int n,m,pos;

	std::cout << "Problema a)" << std::endl;
	std::cout << "Numarul de persoane = ";
	std::cin >> n;

	for (int i = 1; i <= n; i++) 
	{
		InserareFata(cap1,i);
	}
	std::cout << "Persoane: "<<std::endl;
	Afisare(cap1);
	std::cout << std::endl;

	std::cout << "Numarul de executare = ";
	std::cin >> m;
	std::cout << "Oamenii executati: " << std::endl;
	AfisareExecutare(cap1, m);
	
	std::cout << std::endl;
	std::cout << "Problema b)" << std::endl;

	std::cout << "Numarul de persoane = ";
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		InserareFata(cap2, i);
	}

	std::cout << "Persoane: " << std::endl;
	Afisare(cap2);
	std::cout << std::endl;

	std::cout << "Numarul de executare = ";
	std::cin >> m;
	std::cout << std::endl;
	std::cout << "Pozitia sigura: " << std::endl;
	PozitiaSigura(cap2, m);

#endif

//5)
#if 0
	Circular* cap1 = nullptr, * cap2 = nullptr, * cap = nullptr, * list = nullptr;
	int val;
	std::cout << "Cap 1:" << std::endl;
	std::cout << "Nr de inserat = ";
	std::cin >> val;

	while (val != -1)
	{
		InserareFata(cap1, val);
		std::cout << "nr de inserat = ";
		std::cin >> val;
	}

	std::cout << "Cap 2:" << std::endl;
	std::cout << "Nr de inserat = ";
	std::cin >> val;

	while (val != -1)
	{
		InserareFata(cap2, val);
		std::cout << "nr de inserat = ";
		std::cin >> val;
	}

	std::cout << "Lista 1:" << std::endl;
	Afisare(cap1);
	std::cout << std::endl;
	std::cout << "Lista 2:" << std::endl;
	Afisare(cap2);
	std::cout << std::endl;

	std::cout << "Concatenare:" << std::endl;
	Concat(cap, cap1, cap2);
	Afisare(cap);
	std::cout << std::endl;

	std::cout << "Intercalare:" << std::endl;
	Inercal(list, cap1, cap2);
	Afisare(list);
#endif

//6)
#if 1
	Element* cap1 = nullptr, * cap2 = nullptr, * sum = nullptr;
	int val,aux;

	std::cout << "Numar de inserat 1 = ";
	std::cin >> val;

	while (val != 0) 
	{
		aux = val % 1000;
		val = (val - aux) / 1000;
		InserareFata_DubluCircular(cap1, aux);
	}
	std::cout << "Primul numar:" << std::endl;
	Afisare_DubluCircular(cap1);
	std::cout << std::endl;

	std::cout << "Numar de inserat 2 = ";
	std::cin >> val;

	while (val != 0)
	{
		aux = val % 1000;
		val = (val - aux) / 1000;
		InserareFata_DubluCircular(cap2, aux);
	}
	std::cout << "Al doilea numar:" << std::endl;
	Afisare_DubluCircular(cap2);
	std::cout << std::endl;

	bool comp = Compar_DubluCircular(cap1,cap2);
	if (comp == true)
		std::cout << "Numarul 1 este mai mare sau egal cu numarul 2" << std::endl;
	else
		std::cout << "Numarul 2 este mai mare decat numarul 1" << std::endl;

	Adunare_DubluCircular(sum, cap1, cap2);
	std::cout << "Suma este:" << std::endl;
	Afisare_DubluCircular(sum);

#endif
	return 0;
}