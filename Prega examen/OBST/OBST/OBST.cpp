#include <iostream>
#include "OBST.h"

using namespace std;

//functia pentru calculul matricelor
void Matrix(int nr_keys, int W[NMAX][NMAX], int C[NMAX][NMAX], int R[NMAX][NMAX], int p[], int q[])
{
	int x, min;
	int i, j, k, h, m;

	//construiesc matricea de ponderi W
	for (i=0; i<=nr_keys; ++i)
	{
		W[i][i]=q[i];
		for (j=i+1; j<=nr_keys; j++)
		{
			W[i][j]=W[i][j-1]+p[j]+q[j];
		}
	}

	//construiesc matricea de cost C si matricea R
	for (i=0; i<=nr_keys; ++i)
	{
		C[i][i]=W[i][i];
	}
	for (i=0; i<=nr_keys-1; ++i)
	{
		//relatia pentru a doua diagnala din C (deasupra celei cunoscute)
		j=i+1;
		C[i][j]=C[i][i]+C[j][j]+W[i][j];

		//relatia pentru diagonala matricei R
		R[i][j]=j;
	}

	//completez matricele C si R
	for (h=2; h<=nr_keys; ++h)
	{
		for (i=0; i<=nr_keys-h; ++i)
		{
			j=i+h;
			m=R[i][j-1];
			min=C[i][m-1]+C[m][j];
			for (k=m+1; k<=R[i+1][j]; ++k)
			{
				//caut minim si index pentru minim(m)
				x=C[i][k-1]+C[k][j];
				if (x<min)
				{
					m=k;
					min=x;
				}
			}
			C[i][j]=W[i][j]+min;
			R[i][j]=m; //indexul lui k pentru care s-a obtinut minimum se pune in R
		}
	}

	//afisez W
	cout<<"\nMatricea W:\n\n";
	for (i=0; i<=nr_keys; ++i)
	{
		for (j=0; j<=nr_keys; ++j)
		{
			if (i>j)
			{
				cout<<"    ";
			}
			else
			{
				printf("%3d ", W[i][j]);
			}
		}
		cout<<endl;
	}
	//afisez C
	cout<<"\nMatricea cost:\n\n";
	for (i=0; i<=nr_keys; ++i)
	{
		for (j=0; j<=nr_keys; ++j)
		{
			if (i>j)
			{
				cout<<"    ";
			}
			else
			{
				printf("%3d ", C[i][j]);
			}
		}
		cout<<endl;
	}
	//afisez R
	cout<<"\nMatricea R:\n\n";
	for (i=0; i<=nr_keys; ++i)
	{
		for (j=0; j<=nr_keys; ++j)
		{
			if (i>j)
			{
				cout<<"    ";
			}
			else
			{
				printf("%3d ", R[i][j]);
			}
		}
		cout<<endl;
	}
}

//functie de constructie a unui BST optimal
OBST* Build_OBST(int i, int j, char KEYS[], int R[NMAX][NMAX])
{
	OBST* p;
	if (i==j)
	{
		p=nullptr;
	}
	else
	{
		p=new OBST; //se aloca memorie
		p->KEY=KEYS[R[i][j]]; //pun valoarea cheii
		p->left=Build_OBST(i, R[i][j]-1, KEYS, R); //subarbore stang
		p->right=Build_OBST(R[i][j], j, KEYS, R); //subarbore drept
	}
	return p;
}

//functie de afisare indentata a arborelui
void printIndent(OBST* r, int level)
{
	int i;
	for (i=0; i<level; ++i)
	{
		cout<<"\t";
	}
	if (!r)
	{
		cout<<"-"<<endl;
	}
	else
	{
		cout<<r->KEY<<endl;
		printIndent(r->left, level+1);
		printIndent(r->right, level+1);
	}
}