#include <iostream>
#include <conio.h>
#include "lista.h"
#include "citire_afisare.h"
#include "interclasare.h"

using namespace std;

int main(void)
{
	Nod* cap; //crearea capului listei
	cap = 0; //initializarea listei

	//CITIRE+AFISARE SIMPLA
	/*
	cap = CreateList(cap);

	PrintList(cap);
	*/

	//CITIRE SIMPLA + AFISARE INVERSA
	/*
	cap = CreateList(cap);

	PrintList_Rec(cap);
	*/

	//CITIRE RECURSIVA + AFISARE SIMPLA
	/*
	cout << "Introduceti valori nenule in lista liniara simplu inlantuita: ";
	cap = CreateList_Rec();

	PrintList(cap);
	*/

	//STERGEREA PRIMULUI ELEMENT
	/*
	cout << endl << "Primul element sters:\n";
	Nod* p;
	p = cap;
	cap = p->succ;
	delete p;

	PrintList(cap);
	*/
	

	//STERGEREA ELEMENTULUI DE PE POZITIA 3
	/*
	cout << endl << "Elementul de pe pozitia 3 sters:\n";
	Nod *p;
	p = cap->succ;
	Nod *q;
	q = p->succ;
	p->succ = q->succ;
	delete q;

	PrintList(cap);
	*/
	
	//STERGEREA ULTIMULUI ELEMENT
	/*
	cout << endl << "Ultimul element sters:\n";

	Nod* penultim;
	penultim = cap;
	while (penultim->succ->succ)
	{
		penultim = penultim->succ;
	}

	Nod* p;
	p = penultim->succ;
	penultim->succ = 0;
	delete p;
	p = 0;

	PrintList(cap);
	*/

	//GASIREA ELEMENTULUI DIN MIJLOC
	/*
	Nod *p, *q;
	p = cap;
	q = p->succ;
	while (q && q->succ)
	{
		p = p->succ;
		q = q->succ->succ;
	}
	cout << endl << "Elementul din mijlocul listei este: " << p->data << endl;
	*/

	//INVERSAREA LEGATURILOR LISTEI
	/*
	Nod *p, *q, *r;
	p = cap;
	q = p->succ;
	r = q->succ;
	p->succ = 0;
	q->succ = p;
	while (r->succ)
	{
		p = q;
		q = r;
		r = r->succ;
		q->succ = p;
	}
	q->succ = p;
	r->succ = q;
	cap = r;

	cout << endl << "Lista cu legaturile inversate:\n";
	PrintList(cap);
	*/

	//AFISAREA ELEMENTULUI DE PE POZITIA K DIN COADA
	/*
	int k;
	cout << endl << "k=";
	cin >> k;
	Nod *p, *q;
	int i;
	q = cap;
	p = cap;
	for ( i = 1; i < k; ++i)
	{
		if (q->succ)
		{
			q = q->succ;
		}
		else
		{
			cout << endl << "Eroare! Lista este prea scurta pentru valoarea lui k.";
			exit(EXIT_FAILURE);
			_getch();
		}
	}
	while (q->succ)
	{
		p = p->succ;
		q = q->succ;
	}

	cout << endl << "Elementul de pe pozitia " << k << " din coada este: " << (k==i)?p->data:p->succ->data;
	*/

	//CONCATENAREA A 2 LISTE
	/*
	Nod *cap1, *cap2;
	cap1 = cap2 = 0;

	cout << "Introduceti elementele primei liste: ";
	cap1 = CreateList_Rec();

	cout << "Introduceti elementele celei de-a doua liste: ";
	cap2 = CreateList_Rec();

	cout << "Prima lista: ";
	PrintList(cap1);
	
	cout << endl << "A doua lista: ";
	PrintList(cap2);

	cout << endl << "Listele concatenate: ";
	Nod *p;
	p = cap1;
	while (p->succ)
	{
		p = p->succ;
	}
	p->succ = cap2;

	PrintList(cap1);
	*/

	//INTERCLASAREA A 2 LISTE
	Nod *cap1, *cap2;
	cap1 = cap2 = 0;

	cout << "Introduceti elementele primei liste: ";
	cap1 = CreateList_Rec();

	cout << "Introduceti elementele celei de-a doua liste: ";
	cap2 = CreateList_Rec();

	cout << "Prima lista: ";
	PrintList(cap1);

	cout << endl << "A doua lista: ";
	PrintList(cap2);

	cout << endl << "Listele interclasate: ";

	Nod* l_inter;
	l_inter = 0;

	l_inter = interclasareListe(cap1, cap2);
	PrintList(l_inter);

	_getch();

	return 0;
}