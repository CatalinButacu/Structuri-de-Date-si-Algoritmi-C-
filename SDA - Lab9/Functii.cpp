#include <iostream>
#include "Tree.h"
#include "Functii.h"

// 1)

// a)
void Insert(Tree*& cap, int val) 
{
	if (cap == nullptr) 
	{
		cap = new Tree();
		cap->data = val;
		return;
	}
	if (val >= cap->data)
	{
		if (cap->dr == nullptr) 
		{
			cap->dr = new Tree();
			cap->dr->data = val;
			return;
		}
		Insert(cap->dr, val);
		return;
	}
	else
	{
		if (cap->st == nullptr)
		{
			cap->st = new Tree();
			cap->st->data = val;
			return;
		}
		Insert(cap->st, val);
		return;
	}
}

// b)
void Preordine(Tree* cap)
{
	if (cap != nullptr)
	{
		std::cout << cap->data << " ";

		if (cap->st != nullptr)
		{
			Preordine(cap->st);
		}

		if (cap->dr != nullptr)
		{
			Preordine(cap->dr);
		}
		return;
	}
	return;
}
void Postordine(Tree* cap) 
{
	if (cap != nullptr)
	{
		if (cap->st != nullptr)
		{
			Postordine(cap->st);
		}


		if (cap->dr != nullptr)
		{
			Postordine(cap->dr);
		}

		std::cout << cap->data << " ";
		return;
	}
	return;
}
void Inordine(Tree* cap) 
{
	if (cap != nullptr)
	{
		if (cap->st != nullptr)
		{
			Inordine(cap->st);
		}

		std::cout << cap->data << " ";

		if (cap->dr != nullptr)
		{
			Inordine(cap->dr);
		}
		return;
	}
	return;
}

// c)
bool Cauta(Tree* cap, int val)
{
	if (cap != nullptr)
	{
		if (cap->data == val)
			return true;

		if (val < cap->data)
		{
			if (cap->st != nullptr)
			{
				return Cauta(cap->st, val);
			}
		}else if (cap->dr != nullptr)
		{
				return Cauta(cap->dr, val);
		}
	}
	return false;
}

// d)
Tree* removeGreatest(Tree*& r)
{
	Tree* p;
	if (r->dr == nullptr) {
		p = r;
		r = r->st;
		return p;
	}
	else return removeGreatest(r->dr);
}
void deleteRoot(Tree*& rad)
{
	Tree* p = rad;
	if (rad->st == 0) 
		rad = rad->dr;
	else if (rad->dr == 0) 
		rad = rad->st;
	else {
		rad = removeGreatest(rad->st);
		rad->st = p->st;
		rad->dr = p->dr;
	}
	delete p;
}
void Delete(Tree*& rad, int a)
{
	if (rad == nullptr)
		printf("Eroare: Valoarea %d nu este in arbore!", a);
	else if (a < rad->data)
		Delete(rad->st, a);
	else if (a > rad->data)
		Delete(rad->dr, a);
	else 
		deleteRoot(rad);
}

// 2)
// a)
bool Cauta_nerec(Tree* cap, int val) 
{
	if (cap != nullptr)
	{
		if (cap->data == val)
			return true;

		Tree* p = cap;
		while (p!=nullptr)
		{
			if (val >= p->data)
			{
				p = p->dr;
				if (p == nullptr)
					return false;
			}
			if (val < p->data)
			{
				p = p->st;
				if (p == nullptr)
					return false;
			}
			if (p->data == val)
				return true;
		}
	}
	return false;
}
// b)
void Insert_nerec(Tree*& cap, int val) 
{
	if (cap == nullptr) 
	{
		cap = new Tree();
		cap->data = val;
		return;
	}
	Tree* p = cap;
	while (true) 
	{
		if (val >= p->data)
		{
			if (p->dr == nullptr) 
			{
				p->dr = new Tree();
				p->dr->data = val;
				return;
			}
			p = p->dr;
		}
		else if (val < p->data)
		{
			if (p->st == nullptr)
			{
				p->st = new Tree();
				p->st->data = val;
				return;
			}
			p = p->st;
		}
	}
}
// c)
void Delete_nerec(Tree*& cap, int val)
{
	if (cap == nullptr)
	{
		std::cout << "Arborele este gol" << std::endl;
		return;
	}
	Tree* p = cap,*q=p;
	if (p->data != val) 
	{
		if (val >= p->data)
		{
			p = p->dr;
			if (p == nullptr)
			{
				std::cout << "Valolarea nu exista" << std::endl;
				return;
			}
		}
		else if (val < p->data)
		{
			p = p->st;
			if (p == nullptr)
			{
				std::cout << "Valolarea nu exista" << std::endl;
				return;
			}
		}
		while (p->data != val)
		{
			if (val >= p->data)
			{
				q = p;
				p = p->dr;
				if (p == nullptr)
				{
					std::cout << "Valolarea nu exista" << std::endl;
					return;
				}
			}
			else if (val < p->data)
			{
				q = p;
				p = p->st;
				if (p == nullptr)
				{
					std::cout << "Valolarea nu exista" << std::endl;
					return;
				}
			}
		}
	}

	if (p->st == nullptr) 
	{
		q->dr = p->dr;
		delete p;
		return;
	}

	if (p->st->dr == nullptr) 
	{
		p->st->dr = p->dr;
		if(q->data < p->st->data)
		    q->dr = p->st;
		else
			q->st = p->st;
		delete p;
		return;
	}

	Tree* r=p->st,*t=nullptr;
	while (r->dr != nullptr)
	{
		t = r;
		r = r->dr;
	}
	t->dr = r->st;
	r->st = p->st;
	r->dr = p->dr;
	if (q == cap)
		cap = r;
	else
	{
		if (q->data < r->data)
			q->dr = r;
		else
			q->st = r;
	}
	delete p;
}
