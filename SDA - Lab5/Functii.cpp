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
	if (p != nullptr)
	{
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
	p = x;
	if (p != nullptr)
	{
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
}

void Inercal(Element*& cap, Element* x, Element* y)
{
	Element* p = y;
	Element* q = x;
	if (p==nullptr && q==nullptr)
	{
		return;
	}
	if (p == nullptr) 
	{
		Afisare(q);
		return;
	}
	if (q == nullptr)
	{
		Afisare(p);
		return;
	}
	int countp=0,countq=0, max;
	while (p->next != nullptr)
	{
		p = p->next;
		countp++;
	}
	countp++;
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


//5)
void Concat(Circular*& cap, Circular* x, Circular* y)
{
	Circular* p = y;
	if (p != nullptr)
	{
		InversareLeg(p);
		p=p->leg;
		while (p != y)
		{
			InserareFata(cap, p->data);
			p = p->leg;
		}
		InserareFata(cap, p->data);
		InversareLeg(p); //Revin la lista initiala
	}
	p = x;
	if (p != nullptr)
	{
		InversareLeg(p);
		p = p->leg;
		while (p != x)
		{
			InserareFata(cap, p->data);
			p = p->leg;
		}
		InserareFata(cap, p->data);
		InversareLeg(p); //Revin la lista initiala
	}
}

void Inercal(Circular*& cap, Circular* x, Circular* y)
{
	Circular* p = y;
	Circular* q = x;
	if (p == nullptr && q == nullptr)
	{
		return;
	}
	if (p == nullptr)
	{
		Afisare(q);
		return;
	}
	if (q == nullptr)
	{
		Afisare(p);
		return;
	}
	int countp = 1, countq = 1, max;

	InversareLeg(p);
	p=p->leg;
	while (p != y)
	{
		p = p->leg;
		countp++;
	}
	p = p->leg;

	InversareLeg(q);
	q = q->leg;
	while (q != x)
	{
		q = q->leg;
		countq++;
	}
	q = q->leg;

	max = (countp >= countq) ? countp : countq;

	for (int i = max; i > 0; i--)
	{
		if (p != y && countp >= i)
		{
			InserareFata(cap, p->data);
			p = p->leg;
		}
		if (q != x && countq >= i)
		{
			InserareFata(cap, q->data);
			q = q->leg;
		}
	}
	InserareFata(cap, p->data);
	InserareFata(cap, q->data);
}


//6)
void InserareFata_DubluCircular(Element*& cap, int val)
{
	if (cap == nullptr) 
	{
		cap = new Element();
		cap->data = val;
		cap->next = cap;
		cap->prev = cap;
		return;
	}
	if (cap->next == cap) 
	{
		Element* p = new Element();
		p->data = cap->data;
		cap->data = val;
		cap->next = p;
		cap->prev = p;
		p->prev = cap;
		p->next = cap;
		return;
	}
	Element* p=new Element();
	p->next = cap->next;
	p->prev = cap;
	(cap->next)->prev = p;
	cap->next = p;
	p->data = cap->data;
	cap->data = val;
}

void StergerePrimElement_DubluCircular(Element*& cap) 
{
	if (cap == nullptr) 
	{
		return;
	}
	if (cap->next == cap) 
	{
		delete cap;
	}
	Element* p = cap->next, * q=cap->prev;
	p->prev = q;
	q->next = p;
	delete cap;
	cap = p;
}

void Golire_DubluCircular(Element*& cap)
{
	while (cap != nullptr)
		StergerePrimElement_DubluCircular(cap);
}

void Afisare_DubluCircular(Element* cap)
{
	if (cap == nullptr)
		return;
	if (cap->next == cap)
	{
		std::cout << cap->data << " ";
		return;
	}
	Element* p = cap;
	std::cout << p->data << " ";
	p = p->next;
	while (p->next != cap)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << p->data << " ";
}

bool Compar_DubluCircular(Element* x, Element* y) 
{
	if (x == nullptr) 
	{
		return false;
	}
	if (y == nullptr)
	{
		return true;
	}
	Element* p=x, * q=y;
	int countp=1, countq=1;

	p = p->next;
	while (p != x)
	{
		p = p->next;
		countp++;
	}

	q = q->next;
	while (q != y)
	{
		q = q->next;
		countq++;
	}

	if (countp > countq)
		return true;
	else if (countp < countq)
		return false;

	if (p->data > q->data)
		return true;
	else if (p->data < q->data)
		return false;

	p = p->next;
	q = q->next;

	while (p != x && q != y)
	{
		if (p->data>q->data) 
			return true;
		else if (p->data < q->data)
			return false;
		p = p->next;
		q = q->next;
	}
	return true; //Daca sunt egale
}

void Adunare_DubluCircular(Element *&sum,Element* x, Element* y)
{
	if (x == nullptr) 
	{
		Element* p = y;
		p=p->prev;
		while (p != y) 
		{
			InserareFata_DubluCircular(sum, p->data);
			p = p->prev;
		}
		InserareFata_DubluCircular(sum, p->data);
	}
	if (y == nullptr)
	{
		Element* p = x;
		p = p->prev;
		while (p != x)
		{
			InserareFata_DubluCircular(sum, p->data);
			p = p->prev;
		}
		InserareFata_DubluCircular(sum, p->data);
	}
	Element* p=x, * q=y;
	int carry=0,s=0, qdata, pdata;

	p = p->prev;
	q = q->prev;
	pdata = p->data;
	qdata = q->data;

	while (p != x || q != y) 
	{
		s = pdata + qdata + carry;
		carry = 0;
		if (s >= 1000)
		{
			s = s - 1000;
			carry = 1;
		}
		InserareFata_DubluCircular(sum, s);
		if (p != x) {
			p = p->prev;
			pdata = p->data;
		}
		else
			pdata = 0;
		if (q != y) {
			q = q->prev;
			qdata = q->data;
		}
		else
			qdata = 0;
	}
	s = pdata + qdata + carry;
	carry = 0;
	if (s >= 1000)
	{
		s = s - 1000;
		carry = 1;
	}
	InserareFata_DubluCircular(sum, s);
	if(carry)
		InserareFata_DubluCircular(sum, carry);
}