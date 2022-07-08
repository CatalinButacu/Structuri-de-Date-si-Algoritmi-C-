#include <iostream>
#include "Functii.h"

int main() 
{
	int A[100],B[100],C[100], na,n, x;
	std::cout << "n = ";
	std::cin >> n;
	na = n;
	for(int i=0;i<n;i++)
	{
		std::cout << "nr de inserat = ";
		std::cin >> x;
		B[i] = x;
		C[i] = x;
		Insert(A,i,x);
	}
	Afisare_Inordine(A, na);
	std::cout << std::endl;
	std::cout << "Elementul sters este = " << Remove(A, na) << std::endl;
	Afisare_Inordine(A, na);
	std::cout << std::endl;
	std::cout << "Sortat: ";
	int i = na;
	while(i>0) 
	{
		std::cout << Remove(A, i) << " ";
	}

	std::cout << std::endl << std::endl << "BuildHeap_v1 && Heapsort:" <<std::endl;
	Afisare(B, n);
	BuildHeap_v1(B, n);
	Afisare_Inordine(B, n);
	std::cout << std::endl;
	Heapsort(B, n);
	Afisare(B, n);

	std::cout << std::endl << "BuildHeap_v2 && Heapsort:" << std::endl;
	Afisare(C, n);
	BuildHeap_v2(C, n);
	Afisare_Inordine(C, n);
	std::cout << std::endl;
	Heapsort(C, n);
	Afisare(C, n);

	return 0;
}