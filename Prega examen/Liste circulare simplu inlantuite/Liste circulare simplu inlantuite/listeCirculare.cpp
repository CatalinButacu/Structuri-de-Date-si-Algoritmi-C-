#include <iostream>
#include "listeCirculare.h"

using namespace std;

void createCL(Nod *&cap)
{
	Nod *p;
	int n;
	cin >> n;
	while (n)
	{
		p = new Nod;
		p->data = n;

		if (!cap) //daca pun primul nod in lista circulara
		{
			cap = p;
			p->succ = cap;
		}
		else
		{
			p->succ = cap->succ;
			cap->succ = p;
			cap = p;
		}
		cin >> n;
	}
	cap = cap->succ; //pentru ca citirea aduce "capul listei" la ultimul element citit
}
void printCL(Nod *cap)
{
	Nod *p = cap;
	while (p->succ != cap)
	{
		cout << p->data << " ";
		p = p->succ;
	}
	cout << p->data << endl; //pentru ultimul element
}
void permutari(Nod* cap)
{
	Nod *p = cap;
	while (p->succ != cap)
	{
		printCL(p);
		p = p->succ;
	}
	printCL(p);
}
bool ciclare(Nod* cap)
{
	Nod *p, *q;
	p = cap;
	q = cap->succ;
	while (q && q->succ && q != p)
	{
		p = p->succ;
		q = q->succ->succ; //q merge de 2 ori mai repede decat p
	}
	if (q == p) //daca q l-a ajuns pe p din urma
	{
		return true; //lista e circulara
	}
	else
	{
		return false;
	}
}
void inserare(Nod*& cap, int x)
{
	Nod *p = new Nod;
	p->data = x;
	p->succ = cap->succ;
	cap->succ = p;
}
bool stergere(Nod*& cap, int x)
{
	Nod *p = cap;
	Nod *q = p->succ;
	bool gasit = false;
	while (q->succ!=cap)
	{
		if (q->data == x)
		{
			gasit = true;
			break;
		}
		p = q;
		q = q->succ;
	}
	//daca trebuie sa stergem capul listei, q nu ajunge acolo
	if (q->succ->data==x)
	{
		gasit=true;
		//avansam spre capul listei, pentru a fi sters
		p = q;
		q = q->succ;
		cap = p;
	}
	if (!gasit)
	{
		return false;
	}
	//trebuie sters nodul de dupa p
	p->succ = q->succ;
	delete q;

	return true;
}