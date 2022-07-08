#include <iostream>
#include "Functii.h"

//1)
void InserareFata(Element *& cap, int val)
{
	Element* p = new Element();
	if (cap == nullptr)
	{
		p->data = val;
		p->next = nullptr;
		p->prev = nullptr;
		cap = p;
	}
	else 
	{
		p->data = val;
		p->next = cap;
		p->prev = nullptr;
		cap->prev = p;
		cap = p;
	}

}

void Afisare(Element* cap) 
{
	if (cap == nullptr)
	{
		return;
	}
	Element* p = cap;
	while (p->next != nullptr)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << p->data << " ";
}

void AfisareD_I(Element* cap)
{
	if (cap == nullptr) 
	{
		return;
	}
	Element* p=cap;
	while (p->next != nullptr) 
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	while (p->prev != nullptr)
	{
		std::cout << p->data << " ";
		p = p->prev;
	}
	std::cout << p->data << " ";
}

void InserarePos(Element*& cap, int pos, int val)
{
	if (cap == nullptr) 
	{
		cap = new Element();
		cap->data = val;
	}
	else 
	{
		Element* p = cap;
		for (int i = 0; i < pos && p->next != nullptr; i++)
		{
			p = p->next;
		}
		Element* q = new Element();
		q->data = val;
		q->next = p->next;
		q->prev = p;
		if (p->next != nullptr)
			(p->next)->prev = q;
		p->next = q;
	}
}

void StergePos(Element*& cap, int pos)
{
	if (cap == nullptr)
	{
		return;
	}
	Element* p = cap;
	for (int i = 0; i < pos && p->next != nullptr; i++)
	{
		p = p->next;
	}

	if(p->next!=nullptr)
	{
		p = p->next;
		(p->next)->prev = p->prev;
		(p->prev)->next = p->next;
		delete p;
	}
}


//2)
void Concat(Element*& cap, Element* x, Element* y)
{
	Element* p = y;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	while (p->prev != nullptr)
	{
		InserareFata(cap, p->data);
		p=p->prev;
	}
	InserareFata(cap, p->data);

	p = x;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	while (p->prev != nullptr)
	{
		InserareFata(cap, p->data);
		p = p->prev;
	}
	InserareFata(cap, p->data);
}

void Inercal(Element*& cap, Element* x, Element* y)
{
	Element* p = y;
	int countp=0,countq=0, max;
	while (p->next != nullptr)
	{
		p = p->next;
		countp++;
	}
	countp++;
	Element* q = x;
	while (q->next != nullptr)
	{
		q = q->next;
		countq++;
	}
	countq++;

	max = (countp >= countq) ? countp : countq;

	for(int i=max;i>0;i--)
	{
		if (p->prev != nullptr && countp>=i)
		{
			InserareFata(cap, p->data);
			p = p->prev;
		}
		if (q->prev != nullptr && countq >= i)
		{
			InserareFata(cap, q->data);
			q = q->prev;
		}
	}
	InserareFata(cap, p->data);
	InserareFata(cap, q->data);
}


//3)
void InserareFata(Circular*& cap, int val)
{
	if (cap == nullptr) 
	{
		cap = new Circular();
		cap->data = val;
		cap->leg = cap;
		return;
	}

	Circular* p = new Circular();
	p->leg = cap->leg;
	cap->leg = p;
	p->data = cap->data;
	cap->data = val;
}

void Afisare(Circular* cap)
{
	if (cap == nullptr)
		return;
	if (cap->leg == cap) 
	{
		std::cout << cap->data << " ";
		return;
	}
	Circular* p=cap;
	std::cout << p->data << " ";
	p = p->leg;
	while (p->leg != cap) 
	{
		std::cout << p->data << " ";
		p = p->leg;
	}
	std::cout << p->data << " ";
}

void InversareLeg(Circular*& cap)
{
	if (cap == nullptr)
		return;
	if (cap->leg == cap)
		return;
	if (cap->leg->leg == cap)
		return;

	Circular* p=cap, * q=cap->leg, * r=cap->leg->leg;
	while (r->leg != cap)
	{
		q->leg = p;
		p = q;
		q = r;
		r = r->leg;
	}
	q->leg = p;
	r->leg = q;
	cap->leg = r;
}


//4)
void StergerePos_cuAfisare(Circular*& cap, int pos)
{
	if (cap == nullptr) 
	{
		return;
	}
	Circular* p=cap;
	for (int i = 1; i < pos-1; i++) 
	{
		p = p->leg;
	}
	Circular* q=p->leg;
	p->leg = q->leg;
	if (q == cap)
		cap = p->leg;
	std::cout << q->data << " ";
	delete q;
}

void StergerePos(Circular*& cap, int pos)
{
	if (cap == nullptr)
	{
		return;
	}
	Circular* p = cap;
	for (int i = 1; i < pos - 1; i++)
	{
		p = p->leg;
	}
	Circular* q = p->leg;
	p->leg = q->leg;
	if (q == cap)
		cap = p->leg;
	delete q;
}

void AfisareExecutare(Circular* cap,int m)
{
	Circular* p = cap;
	while (p != p->leg) 
	{
		StergerePos_cuAfisare(p, m);
	}
}

void PozitiaSigura(Circular* cap, int m) 
{
	Circular* p = cap;
	while (p != p->leg)
	{
		StergerePos(p, m);
	}
	Afisare(p);
}

