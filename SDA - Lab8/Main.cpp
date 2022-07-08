#include <iostream>
#include "Element.h"
#include "Functii.h"

int main() 
{
// E1)
#if 0
	int val;
	Element* cap = nullptr; // pointer la primul element al unei liste

	std::cout << "val = ";
	std::cin >> val;
	while (val != -1)
	{
		InserareList(cap, val);
		std::cout << "val = ";
		std::cin >> val;
	}
	InOrder_rec(cap);
	ParcurgereList(cap);
	Afisare_rec(cap);
#endif

// E2)
#if 0
	int val1, val2;
	std::cout << "val1 = ";
	std::cin >> val1;
	std::cout << "val2 = ";
	std::cin >> val2;
	std::cout << cmmdc(val1, val2);
#endif

// E3)
#if 0
	int Sum = 1,n,x;
	std::cout << "n = ";
	std::cin >> n;
	std::cout << "x = ";
	std::cin >> x;
	std::cout << "Sum1 = " << S(x, n) << std::endl;
	for (int i = 1; i <= n; i++)
		Sum += putere(x, i) / fact(i);
	std::cout << "Sum2 = " << Sum;
	std::cout << "Sum3 = " << S_rec(x, n) << std::endl;
#endif

// E4)
#if 0
	#define dim 20
	int a[dim],n;
	for (int i = 0; i < dim; i++)
		a[i] = i;

	std::cout << "n = ";
	std::cin >> n;
	std::cout << binSearch(a,n,0,dim-1);
#endif

// E5)
#if 0
	int n,*a = nullptr;
	std::cout << "n = ";
	std::cin >> n;

	a = new int[n];
	a[0] = 1;
	a[1] = 1;

	std::cout << "Met 1: " << Fibonacci(n) << std::endl;
	Fib(n, a);
	afisare(a, n);

	std::cout << std::endl;

	int f, v1=1, v2=1;
	std::cout << v1 << " " << v2 << " ";
	for (int i = 0; i <= n-3; i++)
	{
		f = v1 + v2;
		v1 = v2;
		v2 = f;
		std::cout << f << " ";
	}
#endif

// E6)
#if 0
	int p;
	std::cout << "p = ";
	std::cin >> p;

	std::cout << "Is prime: " << isPrime(p)<< std::endl;
#endif

// E7)
#if 0
	int* a=nullptr,n;
	std::cout << "n = ";
	std::cin >> n;

	a = new int[n];
	for (int i = 1; i <= n; i++)
		a[i - 1] = i;
	afisare(a, n);

	Permutari(a,n,n);
#endif

// E8)
#if 0
	int n,ti,tm=0,tf=0;
	std::cout << "n = ";
	std::cin >> n;
	ti = n;
	std::cout << ti << tf << tm << std::endl;
	Hanoi(n,ti,tf,tm);
#endif

	return 0;
}