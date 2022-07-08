#include <iostream>
#include"Element.h"
#include"Functii.h"

int main() 
{
#if 0
	Element queue;
	InitQueue(queue);

	int val=-1;
	while (val != 0) 
	{
		std::cout << "Choose an option : " << std::endl << "1 - write    2 - read    0 - do nothing";
		std::cin >> val;
		if (val == 1) 
		{
			std::cout << "val = ";
			std::cin >> val;
			Put(queue,val);
		}
		else if (val == 2) 
		{
			std::cout << "val = " << Get(queue) << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "Front value " << Front(queue) << std::endl;

	while (!isEmpty(queue)) //Afisare restul cozii
	{
		std::cout << Get(queue) << " ";
	}
	
#endif

#if 1
	Queue* queue;
	InitQueue(queue);

	int val = -1;
	while (val != 0)
	{
		std::cout << "Choose an option : " << std::endl << "1 - write    2 - get    0 - do nothing: ";
		std::cin >> val;
		if (val == 1)
		{
			std::cout << "val = ";
			std::cin >> val;
			Put(queue, val);
		}
		else if (val == 2)
		{
			std::cout << "val = " << Get(queue) << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "Front value " << Front(queue) << std::endl;

	while (!isEmpty(queue)) //Afisare restul cozii
	{
		std::cout << Get(queue) << " ";
	}

#endif
	return 0;
}