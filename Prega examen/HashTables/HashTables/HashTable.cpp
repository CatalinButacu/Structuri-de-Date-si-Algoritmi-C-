#include <iostream>
#include <string.h>
#include "HashTable.h"

using namespace std;

int f_hash(char* key)
{
	int i, suma;
	suma = 0;
	for (i = 0; i < (int)strlen(key); ++i)
	{
		suma += key[i];
	}
	return suma%M;
}
bool cautare(char* key, Nod* HT[])
{
	int h = f_hash(key);
	Nod *p;
	p = HT[h];
	while (p)
	{
		if (strcmp(p->cheie, key) == 0)
		{
			return true;
		}
		p = p->succ;
	}
	return false;
}
void inserare(Nod* HT[])
{
	Nod* p = citireNod();
	if (cautare(p->cheie, HT))
	{
		cerr << endl << "Nodul introdus exista deja in tabela Hash!" << endl;
		delete[] p->cheie;
		delete p;
	}
	else
	{
		int h = f_hash(p->cheie);
		if (!HT[h])
		{
			HT[h] = p;
		}
		else
		{
			p->succ = HT[h];
			HT[h] = p;
		}
	}
}
void stergere(char* key, Nod* HT[])
{
	if (!cautare(key, HT))
	{
		cerr << endl << "Nodul nu exista in tabela Hash!" << endl;
	}
	else
	{
		int h = f_hash(key);
		if (strcmp(HT[h]->cheie, key) == 0)
		{
			Nod* p = HT[h];
			HT[h] = HT[h]->succ;
			delete[] p->cheie;
			delete p;
		}
		else
		{
			Nod* p = HT[h], *q = nullptr;
			while (p->succ)
			{
				if (strcmp(key, p->succ->cheie) == 0)
				{
					q = p;
				}
				p = p->succ;
			}
			p = q->succ;
			q->succ = q->succ->succ;
			delete[] p->cheie;
			delete p;
		}
	}
}
void afisare(Nod* HT[])
{
	for (int i = 0; i < M; ++i)
	{
		if (HT[i])
		{
			cout << "Galeata " << i + 1 << ":\n";
			cout << "{ ";
			Nod *p;
			p = HT[i];
			while (p)
			{
				cout << p->cheie;
				p = p->succ;
				if (p)
				{
					cout << "; ";
				}
			}
			cout << " }\n\n";
		}
	}
}
void afisareHistograma(Nod* HT[])
{
	for (int i = 0; i < M; ++i)
	{
		cout << i + 1 << ":\t";
		Nod *p;
		p = HT[i];
		while (p)
		{
			cout << "X ";
			p = p->succ;
		}
		cout << "\n";
	}
}
void eliberareMemorie(Nod* HT[])
{
	for (int i = 0; i < M; ++i)
	{
		Nod *p, *q;
		p = HT[i];
		q = HT[i];
		while (q)
		{
			p = q;
			q = p->succ;
			if (p)
			{
				delete[] p->cheie;
				delete p;
			}
		}
		HT[i] = nullptr;
	}
}

Nod* citireNod()
{
	Nod *p = nullptr;
	char *sir = nullptr;
	char buffer[CMAX];
	cin.get(buffer, CMAX - 1);
	cin.get();
	p = new Nod;
	p->cheie = new char[strlen(buffer) + 1];
	strcpy_s(p->cheie, strlen(buffer) + 1, buffer);
	p->succ = nullptr;
	return p;
}