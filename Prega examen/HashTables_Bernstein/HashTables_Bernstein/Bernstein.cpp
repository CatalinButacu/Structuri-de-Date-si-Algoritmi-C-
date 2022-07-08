#include <iostream>
#include <string.h>
#include "Bernstein.h"

using namespace std;

ListaLiniara::ListaLiniara()
{
	cap = nullptr;
	lungime = 0;
}

ListaLiniara::~ListaLiniara()
{
	if (lungime)
	{
		Nod *p, *q;
		p = q = cap;
		while (q)
		{
			p = q;
			q = q->succ;
			if (p)
			{
				if (p->data)
				{
					delete[] p->data;
				}
				delete p;
			}
		}
	}
}

void ListaLiniara::inserareNod(Nod* nodNou)
{
	if (!cap) //daca nu am niciun element in lista, urmatorul va fi direct nodul nou pe care il pun
	{
		cap = nodNou;
		++lungime;
		return;
	}
	//altfel, cautam ultimul nod al listei si inseram la final
	Nod *p, *q;
	p = q = cap;
	while (q)
	{
		p = q;
		q = p->succ;
	}
	//am ajuns la sfarsitul listei si inseram
	p->succ = nodNou;
	nodNou->succ = nullptr;
	++lungime;
}

bool ListaLiniara::stergereNod(char* cheie)
{
	if (!cap) //daca lista nu are niciun element, inseamna ca nu exista niciun element care sa ii fie asociata cheia "cheie"
	{
		return false;
	}
	//altfel, cautam in lista pana gasim elementul cu cheia respectiva
	Nod *p = cap;
	Nod *q = cap;
	while (q)
	{
		if (strcmp(q->data, cheie) == 0)
		{
			p->succ = q->succ;
			delete[] q->data;
			delete q;
			--lungime;
			return true;
		}
		p = q;
		q = q->succ;
	}
	return false; //daca nu s-a gasit nimic
}

Nod* ListaLiniara::preiaNod(char* cheie)
{
	Nod *p = cap;
	while (p)
	{
		if (strcmp(p->data, cheie) == 0)
		{
			return p;
		}
		p = p->succ;
	}
	return nullptr; //daca nu se gaseste nimic
}

void ListaLiniara::afisareLista()
{
	if (lungime == 0)
	{
		cout << "{ }\n";
		return;
	}
	Nod *p = cap;
	cout << "{ ";
	while (p)
	{
		cout << p->data;
		if (p->succ)
		{
			cout << "; ";
		}
		else
		{
			cout << " ";
		}
		p = p->succ;
	}
	cout << "}\n";
}

int ListaLiniara::preiaLungime()
{
	return lungime;
}

HashTable::HashTable(int lungime)
{
	if (lungime <= 0)
	{
		this->lungime = 13;
	}
	vector = new ListaLiniara[lungime];
	this->lungime = lungime;
}

HashTable::~HashTable()
{
	delete[] vector;
}

/*
FUNCTIE HASH() BERNSTEIN
----------------------------------------------------------------------------------
*/
unsigned int HashTable::hash(char* cheie)
{
	unsigned int h, c;
	for (h = 5381; c = *cheie++; )
	{
		h += (h << 5) + c;
	}
	return h%lungime;
}
/*
----------------------------------------------------------------------------------
*/

void HashTable::inserareNod(Nod* nodNou)
{
	unsigned int index = hash(nodNou->data); //calculam un index pentru noul element de adugat folosind functia hash()
	vector[index].inserareNod(nodNou); //inseram nodul nou in lista liniara simplu inlantuita de pe pozitia index
}

bool HashTable::stergereNod(char* cheie)
{
	unsigned int index = hash(cheie); //aflam pozitia listei ce contine elementul cu cheia "cheie"
	return vector[index].stergereNod(cheie); //stergem nodul din lista respectiva, daca acesta exista
}

Nod* HashTable::preiaNodDupaCheie(char* cheie)
{
	unsigned int index = hash(cheie); //aflam pozitia listei ce contine elementul cu cheia "cheie"
	return vector[index].preiaNod(cheie); //preluam nodul din lista gasita, daca acesta exista
}

void HashTable::afisareHT()
{
	cout << "\n\nTabela Hash:\n";
	for (int i = 0; i < lungime; ++i)
	{
		if (vector[i].preiaLungime())
		{
			cout << "\nGaleata " << i + 1 << ":\n";
			vector[i].afisareLista();
		}
	}
}

void HashTable::afisareHistograma()
{
	cout << "\n\nHistograma Tabelei Hash:\n";
	cout << "Tabela Hash contine " << preiaNumarNoduri() << " elemente.\n";
	for (int i = 0; i < lungime; ++i)
	{
		cout << i + 1 << ":\t";
		for (int j = 0; j < vector[i].preiaLungime(); ++j)
		{
			cout << "X ";
		}
		cout << endl;
	}
}

int HashTable::preiaLungime()
{
	return lungime;
}

int HashTable::preiaNumarNoduri()
{
	int nrNoduri = 0;
	for (int i = 0; i < lungime; ++i)
	{
		nrNoduri += vector[i].preiaLungime();
	}
	return nrNoduri;
}