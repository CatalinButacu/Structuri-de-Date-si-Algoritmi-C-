#include <iostream>
#include "Element.h"
#include "Functii.h"

// E1)
void InserareList(Element *&cap, int val)
{
	if (cap == nullptr)
	{
		cap = new Element;
		cap->data = val;
		cap->leg = 0;
	}
	else
	{
		Element*p = new Element;
		p->data = val;
		p->leg = cap;
		cap = p;
	}
}
void ParcurgereList(Element* cap)
{
	while (cap != nullptr)
	{
		std::cout << cap->data << " ";
		cap = cap->leg;
	}
	std::cout << std::endl;
}
Element* Rev_leg_rec(Element* p, Element* q)
{
	if (p->leg == nullptr) 
	{
		p->leg = q;
		return p;
	}
	Element* last = Rev_leg_rec(p->leg, p);
	p->leg = q;
	return last;
}
void InOrder_rec(Element*& cap)
{
	Element* aux = cap;
	cap = Rev_leg_rec(cap->leg, cap);
	aux->leg = nullptr;
}
void Afisare_rec(Element* cap)
{
	if (cap->leg == nullptr) 
	{
		std::cout << cap->data << " ";
		return;
	}
	Afisare_rec(cap->leg);
	std::cout << cap->data << " ";
}

// E2)
int cmmdc(int m, int n)
{
	if (!n) return m;
	return cmmdc(n, m % n);
}

// E3)
int fact(int n)
{
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}
float putere(float x, int n)
{
	if (n == 0)
		return 1;
	return x * putere(x, n - 1);
}
float S(float x, int n)
{
	if (n == 0)
		return 1;
	return S(x, n - 1) + putere(x, n) / fact(n);
}
float S_rec(float x, int n)
{
	static float T = 1;
	if (n == 0)
	{
		T = 1;
		return 1;
	}
	return S(x, n - 1) + (T *= x / n);
}

// E4)
int binSearch(int a[], int b, int st, int dr)
{
	int m;
	if (st > dr)
		return -1;
	if (st == dr)
		return (b == a[dr]) ? dr : -1;
	else {
		m = (st + dr) / 2;
		if (b <= a[m])
			return binSearch(a, b, st, m);
		else
			return binSearch(a, b, m + 1, dr);
	}
}

// E5)
int Fibonacci(int n)
{
	if (n < 2)
		return n;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int Fib(int n,int *a)
{
	int sum = 0;
	static int count = 2;
	static int val1 = 1;
	static int val2 = 1;
	
	sum = val1 + val2;
	val1 = val2;
	val2 = sum;

	a[count] = sum;

	if (count == n - 1)
	{
		a[n - 2] = val1;
		a[n - 1] = val2;
		count = 1;
		val1 = 1;
		val2 = 1;
		return sum;
	}
	count++;
	sum = Fib(n,a);
	return sum;
}

// E6)
bool isPrime(int p, int i)
{
	if (i == p) return 1;
	if (p% i == 0) return 0;
	return isPrime(p, i + 1);
}

// E7)
void swamp(int& a, int& b) 
{
	int aux = a;
	a = b;
	b = aux;
}
void afisare(int* a,int n) 
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
void copy(int* b,int* a,int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
bool equal(int* b, int* a, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
void Permutari(int* a,int n,int length) 
{
	if (n == 1)
	{
		return;
	}
	int* b = new int[length];
	copy(b, a,length);

	for (int i = length - n; i < length; i++)
	{
		swamp(a[length - n], a[i]);
		if(!equal(a,b,length))
			afisare(a, length);
		Permutari(a, n - 1, length);
		copy(a, b, length);
	}
	
	delete[] b;
}

// E8)
void Hanoi(int n,int& ti,int& tf,int& tm)
{
	if (n == 1)
	{
		ti--;
		tf++;
		std::cout << ti << tf << tm << std::endl;
	}
	else
	{
		Hanoi(n - 1, ti, tm, tf);
		ti--;
		tf++;
		std::cout << ti << tf << tm << std::endl;
		Hanoi(n - 1, tm, tf, ti);
	}
}
