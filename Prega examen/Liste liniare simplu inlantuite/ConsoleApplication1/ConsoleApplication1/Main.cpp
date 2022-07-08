#include <iostream>
#include <conio.h>
#include "liste.h"

using namespace std;

int main()
{
	Nod* lista;
	lista = 0;
	cout << "Introduceti elemente in lista (0 termina citirea): ";
	lista = createList(lista);

	Nod *p, *q, *r;
	p = lista;
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
	r->succ = q;
	lista = r;

	cout << endl << "Lista este: ";
	printList(lista);

	Nod *s, *t;
	s = lista;
	t = s->succ;

	while (t != s && t && t->succ)
	{
		s = s->succ;
		t = t->succ->succ;
	}

	if (t == s)
	{
		cout << endl << "Lista circulara.";
	}
	else
	{
		cout << endl << "Lista necirculara.";
	}
	cout << endl;

	int x;
	cout << endl << endl << "Inserare in fata: ";
	cin >> x;

	p = new Nod;
	p->data = x;
	p->succ = lista;
	lista = p;

	printList(lista);

	cout << endl << endl << "Inserare dupa mijloc: ";
	cin >> x;

	q = lista;
	r = q;

	while (r->succ && r->succ->succ)
	{
		q = q->succ;
		r = r->succ->succ;
	}

	cout << "Mijloc: " << q->data << endl;
	r = q->succ;
	p = new Nod;
	p->data = x;
	q->succ = p;
	p->succ = r;

	printList(lista);

	cout << endl << endl << "Inserare la sfarsitul listei: ";
	cin >> x;

	q = lista;
	while (q->succ)
	{
		q = q->succ;
	}
	p = new Nod;
	p->data = x;
	q->succ = p;
	p->succ = 0;

	printList(lista);

	cout << endl << endl << "Stergerea primului element: ";
	p = lista;
	lista = lista->succ;
	delete p;

	printList(lista);

	cout << endl << endl << "Stergerea elementului din mijloc: " << endl;
	p = lista;
	q = p;
	while (q->succ && q->succ->succ)
	{
		r = p;
		p = p->succ;
		q = q->succ->succ;
	}
	cout << "Mijloc: " << p->data << endl;
	q = p;
	r->succ = p->succ;
	delete p;

	printList(lista);

	cout << endl << endl << "Stergerea ultimului element: " << endl;
	p = lista;
	while (p->succ->succ)
	{
		p = p->succ;
	}
	q = p->succ;
	p->succ = 0;
	delete q;

	printList(lista);

	cout << endl << endl << "Stergerea elementului de pe pozitia k din coada: k=";
	int k;
	cin >> k;

	p = lista;
	q = lista;
	while (k)
	{
		q = q->succ;
		--k;
	}
	while (q->succ)
	{
		p = p->succ;
		q = q->succ;
	}
	q = p->succ;
	p->succ = q->succ;
	delete q;

	printList(lista);

	Nod* lista2;
	lista2 = 0;
	cout << endl << endl << "Introduceti elementele celei de a doua liste: ";
	lista2 = createRec();

	cout << endl << "Prima lista este: ";
	printList(lista);

	cout << endl << "Lista a doua este: ";
	printList(lista2);

	Nod* lista3;
	lista3 = 0;
	lista3 = concatenare(lista, lista2);

	cout << endl << endl << "Listele concatenate: ";
	printList(lista3);

	cout << endl << endl << "Introduceti elementele celei de a treia liste: ";
	lista2 = createRec();

	cout << endl<<"Prima lista este: ";
	printList(lista);

	cout << endl << "Lista a doua este: ";
	printList(lista2);

	lista3 = interclasare(lista, lista2);

	cout << endl << endl << "Listele interclasate: ";
	printList(lista3);

	_getch();
	return 0;
}