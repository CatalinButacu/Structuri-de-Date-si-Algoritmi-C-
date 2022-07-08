#include <iostream>
#include "Header.h"

int main(){
	int v[10], x, i, n, poz;
	std::cout << "\nSe citesc valori in lista pana la intalnirea valorii \'0\'";
	std::cout << "x = ";
	std::cin >> x;
	i = 0;
	while (x != 0){
		v[i] = x;
		std::cout << "x = ";
		std::cin >> x;
		i++;
	}
	n = i;

	Element* cap = 0;
	for (i = 0; i < n; i++)
		InserareInceput(cap, v[i]);

	std::cout << "\nAfisare listei: ";
	Afisare(cap);

	std::cout << "\nIntroduceti o valoare care poate aparea in lista ";
	std::cin >> x;
	if (VerifAparitie(cap, x) == 1)
		std::cout << "\nElementul introdus apare in lista.";
	else
		std::cout << "\n Elementul nu apare in lista ";
	std::cout << std::endl;

	std::cout << "\n Introduceti o pozitie pe care sa fie inserat un nou element ";
	std::cin >> poz;
	std::cout << "\n Introduceti valoare care va fi inserata ";
	std::cin >> x;
	InserareInPozitie(cap, poz, x);
	Afisare(cap);

	std::cout << "\n Introduceti o pozitie de pe care sa fie sters un element ";
	std::cin >> poz;
	StergerePozitie(cap, poz);
	Afisare(cap);



	AfisareDus_Intors(cap);
	AfisareMijloc(cap);
	return 0;
}