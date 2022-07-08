#include <iostream>
#include "Functii.h"
#include "Tree.h"

int main()
{
	// 1)
#if 0
	Tree* cap = nullptr;
	int val;
	std::cout << "val de inserat = ";
	std::cin >> val;
	while (val != 0)
	{
		Insert(cap, val);
		std::cout << "val de inserat = ";
		std::cin >> val;
	}

	Preordine(cap);
	std::cout << std::endl;
	Postordine(cap);
	std::cout << std::endl;
	Inordine(cap);
	std::cout << std::endl;

	std::cout << "val de cautat = ";
	std::cin >> val;
	if (Cauta(cap, val))
		std::cout << "Valoarea este continuta" << std::endl;
	else
		std::cout << "Valoarea nu este continuta" << std::endl;

	std::cout << "val de sters = ";
	std::cin >> val;
	Delete(cap, val);
	Inordine(cap);

#endif
	// 2)
#if 1
	Tree* cap = nullptr;
	int val;
	std::cout << "val de inserat = ";
	std::cin >> val;
	while (val != 0)
	{
		Insert_nerec(cap, val);
		std::cout << "val de inserat = ";
		std::cin >> val;
	}

	Inordine(cap);
	std::cout << std::endl;

	std::cout << "val de cautat = ";
	std::cin >> val;
	if (Cauta_nerec(cap, val))
		std::cout << "Valoarea este continuta" << std::endl;
	else
		std::cout << "Valoarea nu este continuta" << std::endl;

	std::cout << "val de sters = ";
	std::cin >> val;
	Delete_nerec(cap, val);
	Inordine(cap);

#endif
	return 0;
}