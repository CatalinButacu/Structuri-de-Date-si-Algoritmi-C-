#include<iostream>
#include<cmath>
#include "AVL.h"

using namespace std;

int Eq_Required;
int countOp = 0;

void RSD(AVL*& a)
{
	AVL *b = a->stg;
	a->stg = b->drt;
	b->drt = a;
	if (b->bf == 1)
	{
		a->bf = 0;
		b->bf = 0;
	}
	else  //La stergere este posibil ca b->bf=0 cand h(T1)=h(T2)=h(T3) initial, iar dupa stergere h(T1)=h(T2)>h(T3)
		//In acest caz, arborele nu mai necesita echilibrare
	{
		a->bf = 1;
		b->bf = -1;
		Eq_Required = 0;
	}
	a = b;
}
void RSS(AVL*& a)
{
	AVL *b = a->drt;
	a->drt = b->stg;
	b->stg = a;
	if (b->bf == -1)
	{
		a->bf = 0;
		b->bf = 0;
	}
	else //La stergere este posibil ca b->bf=0 cand h(T1)=h(T2)=h(T3) initial, iar dupa stergere h(T1)<h(T2)=h(T3)
		 //In acest caz, arborele nu mai necesita echilibrare
	{
		a->bf = -1;
		b->bf = 1;
		Eq_Required = 0;
	}
	a = b;
}
void RDD(AVL*& a)
{
	AVL *b, *c;
	b = a->stg; c = b->drt;
	//se actualizeaza bf pentru starea finala
	switch (c->bf)
	{
	case 0:
		//c->bf este 0 la stergere cand h(T1)=h(T2s)=h(T2d)<h(T3) initial, iar dupa stergere (T1)=h(T2s)=h(T2d)=h(T3)
		a->bf = b->bf = 0; 
		break;
	case -1:
		//h(t2s)<h(t2d), initial, inainte de refacerea legaturilor
		a->bf = 0; //// deoarece h(T3)=h(t2d)
		b->bf = 1; // deorace h(T1)> h(t2s)
		break;
	case 1:
		//h(t2s)>h(t2d), initial, inainte de refacerea legaturilor
		a->bf = -1; // deoarece h(t2d)< h(T3)
		b->bf = 0; // // deoarece h(T1)=h(t2s)
	}
	a->stg = c->drt;
	b->drt = c->stg;
	c->bf = 0;
	c->drt = a; c->stg = b;
	a = c;
}
void RDS(AVL*& a)
{
	AVL *b, *c;
	b = a->drt; c = b->stg;
	//se actualizeaza bf pentru starea finala
	switch (c->bf)
	{
	case 0:
		//c->bf este 0 la stergere cand h(T1)>h(T2s)=h(T2d)=h(T3), iar dupa stergere (T1)=h(T2s)=h(T2d)=h(T3)
		a->bf = b->bf = 0;
		break;
	case -1:
		//h(t2s)<h(t2d), initial, inainte de refacerea legaturilor
		b->bf = 0; //// deoarece h(T3)=h(t2d)
		a->bf = 1; // deorace h(T1)> h(t2s)
		break;
	case 1:
		//h(t2s)>h(t2d), initial, inainte de refacerea legaturilor
		b->bf = -1; // deoarece h(t2d)< h(T3)
		a->bf = 0; // // deoarece h(T1)=h(t2s)
	}
	a->drt = c->stg;
	b->stg = c->drt;
	c->bf = 0;
	c->stg = a; c->drt = b;
	a = c;
}
void InsertAVL(AVL*& a, Atom x)
{
	if (a == 0) //arbore vid, pun radacina
	{
		a = new AVL;
		a->data = x; a->stg = a->drt = 0; a->bf = 0;
		Eq_Required = 1;
	}
	else
	{
		if (x < a->data)
		{ //inserez in stânga ca la BST
			countOp++; //asta pentru numararea operatiilor
			InsertAVL(a->stg, x);
			if (Eq_Required)
				switch (a->bf)
				{//Nodul critic are bf!=0
				case 1: // adincimea pe subarb stang e mai mare
					Eq_Required = 0;
					//aleg tipul de rota?ie
					(x < a->stg->data) ? RSD(a) : RDD(a);
					break;
				case 0: //nu exista dezechilibru
					a->bf = 1; //dar se produce acum
					break;
				case -1: //adincimea pe subarb stang e mai mica
					a->bf = 0; // inserarea produce echilibru
					Eq_Required = 0;
				}
		}
		else
			if (x > a->data)
			{//TO DO FOR STUDENTS
			 //inserez in subarborele drept
				countOp++; //asta pentru numararea operatiilor
				InsertAVL(a->drt, x);
				if (Eq_Required)
					switch (a->bf)
					{//Nodul critic are bf!=0
					case -1: // adincimea pe subarb drept e mai mare
						Eq_Required = 0;
						//aleg tipul de rota?ie
						(x > a->drt->data) ? RSS(a) : RDS(a);
						break;
					case 0: //nu exista dezechilibru
						a->bf = -1; //dar se produce acum
						break;
					case 1: //adincimea pe subarb drept e mai mica
						a->bf = 0; // inserarea produce echilibru
						Eq_Required = 0;
					}
			}
			else Eq_Required = 0;
	}
}
void AfisareIndentat(AVL* A, int level)
{
	if (A)
	{	
		AfisareIndentat(A->stg, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << '\t';
		}
		cout << A->data << '(' << A->bf << ')' << endl;
		AfisareIndentat(A->drt, level + 1);
	}
	else
	{ 
		for (int i = 0; i < level; i++)
		{
			cout << '\t';
		}
		cout << "-\n";
	}
}
void RemoveNode(AVL*& r, Atom a) //Folosim stergerea Hibbard de la BST
{
	if (r)
	{
		if (r->data == a)
		{
			RemoveRoot(r);
		}
		else if (r->data < a)
		{
			RemoveNode(r->drt, a);
			UpdateAfterDeletingRight(r); //Actualizam bf pentru nodurile de deasupra nodului sters
		}
		else if (r->data > a)
		{
			RemoveNode(r->stg, a);
			UpdateAfterDeletingLeft(r);
		}
	}
}
void RemoveRoot(AVL*& r)
{
	AVL* p;
	if (r->stg == 0)
	{
		p = r;
		Eq_Required = 1;
		r = r->drt;
	}
	else if (r->drt == 0)
	{
		p = r;
		r = r->stg;
		Eq_Required = 1;
	}
	else
	{
		p = Greatest(r->stg);
		r->data = p->data;
		UpdateAfterDeletingLeft(r);
	}
	delete p;
}
AVL* Greatest(AVL*& r)
{
	AVL* p;
	if (r->drt == 0)
	{
		p = r;
		r = r->stg;
		Eq_Required = 1;	
	}
	else
	{
		p = Greatest(r->drt);
		UpdateAfterDeletingRight(r);
	}
	return p;
}
void UpdateAfterDeletingLeft(AVL*& a)
{
	if (Eq_Required)
	{
		switch (a->bf)
		{//Nodul critic are bf=0 sau -1 cand a->drt->bf=0
		case 0: Eq_Required = 0;//Se produce un dezechilibru la nivelul nodului a, dar inaltimea subarborelui care il are ca radacina pe a
			a->bf = -1; //ramane aceeasi
			break;
		case 1: a->bf = 0;//Initial, h(Ts)>h(Td). Dupa stergerea unui nod de pe subarborele stang, inaltimea sa scade => h(Ts)=h(Td)
			break;// Deci inaltimea subarborului cu radacina a scade => afecteaza nodul de pe nivelul de mai sus 
		case -1: //Rotatii
			 (a->drt->bf <= 0)? RSS(a) : RDS(a);//Inaltimea intregului subarbore poate sa scada sau sa ramana aceeasi daca a este nod critic
			 break;
		}
	}
}
void UpdateAfterDeletingRight(AVL*& a)
{
	if (Eq_Required)
	{
		switch (a->bf)
		{//Nodul critic are bf=0 sau 1 cand a->stg->bf=0
		case 0: Eq_Required = 0;//Se produce un dezechilibru la nivelul nodului a, dar inaltimea subarborelui care il are ca radacina pe a
			a->bf = 1;//ramane aceeasi
			break;
		case 1: //Rotatii
			(a->stg->bf >= 0)? RSD(a) : RDD(a); //Inaltimea intregului subarbore poate sa scada sau sa ramana aceeasi daca a este nod critic
			break;
		case -1: a->bf = 0;//Initial, h(Ts)<h(Td). Dupa stergerea unui nod de pe subarborele drept, inaltimea sa scade => h(Ts)=h(Td)
			break;// Deci inaltimea subarborului cu radacina a scade => afecteaza nodul de pe nivelul de mai sus 
		}
	}
}
int adancime(AVL* r)
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
bool testAVL(AVL* r)
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