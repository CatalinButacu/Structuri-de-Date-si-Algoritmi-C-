#include <iostream>
#include "listeDI.h"

using namespace std;

void CreateDLL(Nod *&First, Nod *&Last)
{
	int n;
	cin >> n;
	while (n)
	{
		if (!First) //daca pun primul nod
		{
			Nod* p = new Nod;
			p->data = n;
			p->succ = nullptr;
			p->pred = nullptr;
			First = Last = p;
		}
		else
		{
			Nod* p = new Nod;
			p->data = n;
			p->succ = First;
			p->pred = nullptr;
			First->pred = p;
			First = p;
		}
		cin >> n;
	}
}
void PrintDLL(Nod *cap)
{
	while (cap)
	{
		cout << cap->data << " ";
		cap = cap->succ;
	}
	cout << endl;
}
void PrintDLL_Reverse(Nod *cap)
{
	while (cap)
	{
		cout << cap->data << " ";
		cap = cap->pred;
	}
	cout << endl;
}
void PrintDLL_Recursiv(Nod *cap)
{
	if (cap)
	{
		PrintDLL_Recursiv(cap->succ);
		cout << cap->data << " ";
	}
}
bool Insert(Nod*& First, Nod*& Last, int x, int y)
{
	if (Last->data == x) //daca inserez dupa ultimul nod
	{
		Nod* p = new Nod;
		p->data = y;
		p->succ = nullptr;
		p->pred = Last;
		Last->succ = p;
		Last = p;
		return true;
	}
	else //inserez dupa un alt nod din interior
	{
		Nod *p = First;
		bool gasit = false;

		while (p)
		{
			if (p->data == x)
			{
				gasit = true;
				break;
			}
			p = p->succ;
		}

		if (!gasit)
		{
			return false;
		}

		//trebuie inserat dupa nodul p

		Nod* q = new Nod;
		q->data = y;
		q->pred = p;
		q->succ = p->succ;
		p->succ->pred = q;
		p->succ = q;
		return true;
	}
}
bool Delete(Nod*& First, Nod*& Last, int x)
{
	if (First->data == x) //daca sterg primul nod
	{
		Nod* p = First->succ;
		p->pred = nullptr;
		delete First;
		First = p;
		return true;
	}
	else if (Last->data == x) //daca sterg ultimul nod
	{
		Nod* p = Last->pred;
		p->succ = nullptr;
		delete Last;
		Last = p;
		return true;
	}
	else //nodul de sters se afla in interior
	{
		Nod *p = First;
		Nod *q = First->succ;

		bool gasit = false;

		while (q)
		{
			if (q->data == x)
			{
				gasit = true;
				break;
			}
			p = q;
			q = q->succ;
		}

		if (!gasit)
		{
			return false;
		}

		//p=nodul dinaintea celui ce trebuie sters
		p->succ = q->succ;
		q->succ->pred = p;
		delete q;
		return true;
	}
}
bool palindrom(Nod* First, Nod* Last)
{
	while (First != Last && First->succ != Last)
	{
		if (First->data != Last->data)
		{
			return false;
		}
		First = First->succ;
		Last = Last->pred;
	}
	return true;
}