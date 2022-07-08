#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "queue.h"
#include "arbore.h"

using namespace std;

char car;
void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	_getch();
	exit(1);
}
char readchar()
{
	char c;
	do c = getchar(); while (c == ' ');
	return c;
}
char citesteNume()
{
	char c;
	if (!isalpha(car)) eroare();
	c = car;
	car = readchar();
	return c;
}
Nod* citesteArbore()
{
	Nod* rad;
	if (car == '-') {
		rad = 0;
		car = readchar();
	}
	else {
		rad = (Nod*)malloc(sizeof(Nod));
		rad->data = citesteNume();
		if (car != '(') {
			rad->stg = 0;
			rad->drt = 0;
		}
		else {
			car = readchar();
			rad->stg = citesteArbore();
			if (car != ',') rad->drt = 0;
			else {
				car = readchar();
				rad->drt = citesteArbore();
			}
			if (car != ')') eroare();
			car = readchar();
		}
	}
	return rad;
}
Nod* creareArbore()
{
	printf("\nIntroduceti arborele:");
	car = readchar();
	return citesteArbore();
}

void inordine(Nod* r)
{
	if (r)
	{
		inordine(r->stg);
		cout << r->data << " ";
		inordine(r->drt);
	}
}
void preordine(Nod* r)
{
	if (r)
	{
		cout << r->data << " ";
		preordine(r->stg);
		preordine(r->drt);
	}
}
void postordine(Nod* r)
{
	if (r)
	{
		postordine(r->stg);
		postordine(r->drt);
		cout << r->data << " ";
	}
}
void parcurgereNivel(Nod* r)
{
	Nod *p;
	if (r)
	{
		Queue *q;
		q = new Queue;
		initQ(q);
		Put(q, r);

		while (!isEmpty(q))
		{
			p = Get(q);
			cout << p->data << " ";
			if (p->stg)
			{
				Put(q, p->stg);
			}
			if (p->drt)
			{
				Put(q, p->drt);
			}
		}

		delete q;
	}
}
int determinaAdancime(Nod* r)
{
	int a, b;
	a = b = 1;

	if (r)
	{
		a += determinaAdancime(r->stg);
		b += determinaAdancime(r->drt);
	}
	else
	{
		return 0;
	}

	return (a > b) ? a : b;
}
char calcMax(char v1, char v2)
{
	return (v1 > v2) ? v1 : v2;
}
char maxim(Nod* r)
{
	if (r)
	{
		char vmax;
		vmax = r->data;

		if (r->stg)
		{
			vmax = calcMax(vmax, maxim(r->stg));
		}
		if (r->drt)
		{
			vmax = calcMax(vmax, maxim(r->drt));
		}
		return vmax;
	}
	return 0;
}
int nrFrunze(Nod* r)
{
	if (!r)
	{
		return 0;
	}
	if (!r->stg && !r->drt)
	{
		return 1;
	}
	return nrFrunze(r->stg) + nrFrunze(r->drt);
}
int nrNoduri(Nod* r)
{
	if (!r || !r->stg&&!r->drt)
	{
		return 0;
	}
	return 1 + nrNoduri(r->stg) + nrNoduri(r->drt);
}
void radMMDesc(Nod* r)
{
	if (r)
	{
		if (r->drt && r->stg)
		{
			if (r->data > maxim(r->drt) && r->data > maxim(r->stg))
			{
				cout << r->data << " ";
			}
		}
		else if (r->drt)
		{
			if (r->data > maxim(r->drt))
			{
				cout << r->data << " ";
			}
		}
		else if (r->stg)
		{
			if (r->data > maxim(r->stg))
			{
				cout << r->data << " ";
			}
		}
		radMMDesc(r->stg);
		radMMDesc(r->drt);
	}
}
void stMMdr(Nod* r)
{
	if (r)
	{
		if (r->stg && r->drt)
		{
			if (maxim(r->stg) < maxim(r->drt))
			{
				cout << r->data << " ";
			}
		}
		else if (r->drt)
		{
			cout << r->data << " ";
		}
		stMMdr(r->stg);
		stMMdr(r->drt);
	}
}
void comuta(Nod* r)
{
	if (r)
	{
		Nod* aux;
		aux = r->stg;
		r->stg = r->drt;
		r->drt = aux;
		comuta(r->stg);
		comuta(r->drt);
	}
}
void afisareArbore(Nod* r)
{
	if (r)
	{
		cout << r->data;
		if (r->stg || r->drt)
		{
			cout << "(";
			if (!r->stg)
			{
				cout << "-";
			}
			afisareArbore(r->stg);
			cout << ",";
			if (!r->drt)
			{
				cout << "-";
			}
			afisareArbore(r->drt);
			cout << ")";
		}
	}
}