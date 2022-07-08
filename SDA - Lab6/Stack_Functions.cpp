#include <iostream>
#include "Stack_Functions.h"


// 1)
void initStack(Stack& S)
{
	S.sp = -1;
}

void Push(Stack& S, int a)
{
	if (!IsFull(S))
	{
		S.sp++;
		S.vect[S.sp] = a;
	}
}

int Pop(Stack& S)
{
	if (!IsEmpty(S)) 
	{
		S.sp--;
		return S.vect[S.sp + 1];
	}
	return 0;
}

int Top(Stack S)
{
	if (!IsEmpty(S))
	{
		return S.vect[S.sp];
	}
	return 0;
}

bool IsEmpty(Stack S)
{
	if (S.sp == -1)
		return true;
	return false;
}

bool IsFull(Stack S)
{
	if (S.sp == dim - 1)
		return true;
	return false;
}


//2)
void initStack(Element* cap)
{
	cap = nullptr;
}

void Push(Element*& cap, char val)
{
	if (IsEmpty(cap))
	{
		cap = new Element();
		cap->data = val;
		return;
	}
	Element* p = new Element();
	p->data = val;
	p->leg = cap;
	cap = p;
}

char Pop(Element*& cap)
{
	if (IsEmpty(cap)) 
		return '\0';

	Element* p = cap;
	char val = cap->data;
	cap = cap->leg;
	delete p;
	return val;
}

char Top(Element* cap)
{
	if (IsEmpty(cap))
		return '\0';
	return cap->data;
}

bool IsEmpty(Element* cap)
{
	return cap==nullptr;
}


// 3)
bool IsOperator(char v) 
{
	return v == '+' || v == '-' || v == '*' || v == '/';
}

int calcul_postfixata(Element*& s, char v[])
{
	int i = 0,rez=0;
	while (v[i]!='\0')
	{
		if (v[i] >= 48 && v[i] <= 57) //Din tabelul ASCII
			Push(s, v[i]);
		else if (IsOperator(v[i]))
		{
			int t1, t2;
			t1 = Pop(s) - 48;
			t2 = Pop(s) - 48;
			if (v[i] == '+')
				rez = t2 + t1;
			else if (v[i] == '-')
				rez = t2 - t1;
			else if (v[i] == '*')
				rez = t2 * t1;
			else if (v[i] == '/')
				rez = t2 / t1;

			Push(s,rez+48);
		}
		else
		{
			std::cout << "Forma incorecta" << std::endl;
			return 0;
		}
		i++;
	}

	return rez;
}

// 4)
bool IsNumber(char v) 
{
	return v >= 48 && v <= 57;
}

bool BigeerPriority(char a,char b) 
{
	if (a == '\0')
		return false;
	if (a == '+') 
	{
		if (b == '\0')
			return true;
		return false;
	}
	if (a == '-')
	{
		if (b == '/')
			return false;
		if (b == '*')
			return false;
		return true;
	}
	if (a == '*') 
	{
		if (b == '/')
			return false;
		return true;
	}
	if (a == '/')
		return true;
	return false;
}

void transform_postfixata(char rez[], char v[]) 
{
	int i = 0,j = 0;
	Element* operatori=nullptr;

	while (v[i] != '\0') 
	{
		if (IsNumber(v[i]))
		{
			rez[j] = v[i];
			j++;
		}
		else if (IsOperator(v[i]) || v[i]=='(')
		{
			if (IsOperator(v[i]) && BigeerPriority(Top(operatori), v[i]))
			{
				rez[j] = Pop(operatori);
				j++;
				Push(operatori, v[i]);
			}else if(IsOperator(v[i]))
				Push(operatori, v[i]);
			if (v[i] == '(') 
			{
				i++;
				int k = 0;
				char r[30],aux[30];
				while (v[i+1] != ')')
				{
					r[k] = v[i];
					k++;
					i++;
					if (v[i] == '\0') 
					{
						std::cout << "Forma prost scrisa";
						return;
					}
						
				}
				r[k] = v[i];
				r[k + 1] = '\0';
				transform_postfixata(aux, r);
				k = 0;
				while (aux[k] != '\0') 
				{
					rez[j] = aux[k];
					j++;
					k++;
				}
				i++;
			}
			
		}
		i++;
	}
	while (!IsEmpty(operatori))
	{
		rez[j] = Pop(operatori);
		j++;
	}
	rez[j] = '\0';
}





