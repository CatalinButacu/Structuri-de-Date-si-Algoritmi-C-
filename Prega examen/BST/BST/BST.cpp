#include <iostream>
#include "BST.h"

using namespace std;

Nod* makeNod(Atom k)
{
	Nod* p = new Nod;
	p->data = k;
	p->stg = p->drt = nullptr; //nodul nou creat in BST va fi mereu frunza
	return p;
}
bool inserare(Nod*& r, Atom a)
{
	if (r == nullptr) //daca punem prima valoare sau am ajuns pe o frunza
	{
		r = makeNod(a); //cream nodul nou ca frunza
		return true;
	}
	else if (a < r->data)
	{
		return inserare(r->stg, a); //ma duc spre stanga cu inserarea
	}
	else if (a > r->data)
	{
		return inserare(r->drt, a); //ma duc spre dreapta cu inserarea
	}
	else
	{
		//nu se trateaza cazul de egalitate, in BST nu exista chei duble
		return false;
	}
}
bool stergere(Nod*& r, Atom a)
{
	if (!r) //s-a terminat arborele
	{
		return false; //nu avem ce sterge
	}
	else if (r->data == a) //am gasit ce avem de sters
	{
		deleteRoot(r);
		return true;
	}
	else if (a < r->data) //caut nodul de sters in subarborele stang
	{
		return stergere(r->stg, a);
	}
	else if (a > r->data) //caut nodul de sters in subarborele drept
	{
		return stergere(r->drt, a);
	}
	return false;
}
void deleteRoot(Nod*& r)
{
	if (!r->stg) //daca avem numai descendent drept
	{
		//"urcam" subarborele drept mai sus, inlocuind radacina curenta
		Nod* p = r;
		r = r->drt;
		delete p;
	}
	else if (!r->drt) //daca avem numai descendent stang
	{
		//"urcam" subarborele stang mai sus, inlocuind radacina curenta
		Nod* p = r;
		r = r->stg;
		delete p;
	}
	else //avem ambii descendenti
	{
		Nod* p = removeGreatest(r->stg); //cautam maximul din subarborele stang
		r->data = p->data; //il punem in locul radacinii curente
		delete p; //stergem maximul gasit anterior din memorie
	}
}
Nod* removeGreatest(Nod*& r)
{
	if (!r->drt) //daca nu mai avem descendent drept
	{
		Nod* p = r;
		r = r->stg; //detasam nodul curent din arbore, aducand descendentul stang in loc
		return p; //si il returnam spre prelucrare
	}
	else //continuam cautarea maximului spre dreapta
	{
		return removeGreatest(r->drt);
	}
}
Nod* cautare(Nod* r, Atom k)
{
	if (r == nullptr || r->data == k) //s-a terminat arborele sau am ajuns pe cheia cautata
	{
		return r;
	}
	else if (k < r->data)
	{
		return cautare(r->stg, k); //caut in subarborele stang
	}
	else
	{
		return cautare(r->drt, k); //caut in subarborele drept
	}
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
void afisareIndentata(Nod* r, int nivel)
{
	for (int i = 0; i < nivel; ++i)
	{
		cout << "\t";
	}
	if (!r)
	{
		cout << "-" << endl;
	}
	else
	{
		cout << r->data << endl;
		afisareIndentata(r->drt, nivel + 1);
		afisareIndentata(r->stg, nivel + 1);
	}
}
bool testBST(Nod* r)
{
	if (r)
	{
		if (r->stg && r->stg->data>r->data)
		{
			return false;
		}
		if (r->drt && r->drt->data < r->data)
		{
			return false;
		}
		testBST(r->stg);
		testBST(r->drt);
	}
	return true;
}
Nod* minim(Nod* r)
{
	if (!r->stg)
	{
		return r;
	}
	else
	{
		return minim(r->stg);
	}
}
Nod* maxim(Nod* r)
{
	if (!r->drt)
	{
		return r;
	}
	else
	{
		return maxim(r->drt);
	}
}
Nod* parent(Nod* r, Nod* p)
{
	if (!r || p == r) //sunt pe radacina sau arborele este vid
	{
		return nullptr; //nu exista parinte
	}
	else
	{
		if (p->data < r->data) //parintele se afla in subarborele stang
		{
			if (r->stg == p) //daca fiul stang este nodul cautat
			{
				return r; //inseamna ca acesta este parintele
			}
			return parent(r->stg, p); //daca nu, mai cautam in subarborele stang
		}
		else if (p->data > r->data) //parintele se afla in subarborele drept
		{
			if (r->drt == p) //daca fiul drept este cel cautat
			{
				return r; //inseamna ca acesta este parintele
			}
			return parent(r->drt, p); //daca nu, mai cautam in subarborele drept
		}
		return nullptr;
	}
}
Nod* succesorInordine(Nod* r, Nod* p)
{
	if (p->drt) //daca avem descendent drept
	{
		return minim(p->drt); //succesorul este minimul din subarborele drept
	}
	Nod* pp = parent(r, p); //aflam parintele
	while (pp && pp->drt == p) //urcam in arbore cat timp mai putem urca si exista fiu drept
	{
		p = pp;
		pp = parent(r, pp);
	}
	return pp; //succesorul este ultimul nod cu fiu drept
}
bool testAVL(Nod* r)
{
	if (r)
	{
		if (abs(adancime(r->stg) - adancime(r->drt)) > 1)
		{
			return false;
		}
		testAVL(r->stg);
		testAVL(r->drt);
	}
	return true;
}
int adancime(Nod* r)
{
	int a, b;
	a = b = 1;
	if (!r)
	{
		return 0;
	}
	else
	{
		a += adancime(r->stg);
		b += adancime(r->drt);
		return (a > b) ? a : b;
	}
}