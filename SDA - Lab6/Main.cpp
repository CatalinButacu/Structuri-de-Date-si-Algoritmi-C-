#include <iostream>
#include "Stack_Functions.h"
#include "Stack.h"
#include "Element.h"

// Fiecare problema trebuie sa aibe separat 1 la fiecare if

int main() 
{
// 1)
#if 0
	Stack s;
	initStack(s);

	int val;
	std::cout << "valoare de inserat = ";
	std::cin >> val;
	while (val != 0) 
	{
		Push(s,val);
		std::cout << "valoare de inserat = ";
		std::cin >> val;
	}

	std::cout << "Stiva este goala " << IsEmpty(s) << std::endl;
	std::cout << "Stiva este plina " << IsFull(s) << std::endl;

	//Afisare
	while (!IsEmpty(s))
	{
		std::cout << Pop(s) << " ";
	}
#endif

// 2)
#if 0
	Element* s = nullptr;
	initStack(s);

	char val;
	std::cout << "valoare de inserat = ";
	std::cin >> val;

	while (val != '0')
	{
		Push(s, val);
		std::cout << "valoare de inserat = ";
		std::cin >> val;
	}

	std::cout << "Stiva este goala " << IsEmpty(s) << std::endl;

	//Afisare
	while (!IsEmpty(s))
	{
		std::cout << Pop(s) << " ";
	}
#endif

// 3)
#if 0
	Element* s=nullptr;
	initStack(s);

	char v[30];
	std::cout << "Forma postfixata: ";
	std::cin >> v;
	std::cout << "Rezultatul este:" << calcul_postfixata(s,v);
#endif

// 4)
#if 0
	Element* s=nullptr;
	char rez[30], v[30];
	std::cout << "Forma infixata = ";
	std::cin >> v;
	transform_postfixata(rez, v);
	std::cout << "Forma postfixata = " << rez << std::endl;
	std::cout << "Rez calculului = " << calcul_postfixata(s,rez);
#endif
	
	return 0;
}