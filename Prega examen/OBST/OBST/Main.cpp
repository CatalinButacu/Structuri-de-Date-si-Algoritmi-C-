#include <iostream>
#include <conio.h>
#include "OBST.h"

using namespace std;

int C[NMAX][NMAX]; //matrice cost
int W[NMAX][NMAX]; //matrice ponderi
int R[NMAX][NMAX]; //radacinile subarborilor optimali. Va contine indecsii cheilor din vectorul KEYS, corespunzator radacinilor arborilor

int q[NMAX]; //frecventa de cautare intre chei = esec in ceea ce priveste cautarea
int p[NMAX]; //frecventa de cautare a cheilor

int nr_keys; //numarul de noduri (chei)
char KEYS[NMAX]; //vectorul de chei

int main(void)
{
	do {
		cout<<"Numarul de chei: ";
		cin>>nr_keys;
		cin.get();
		if (nr_keys>NMAX)
		{
			cout<<"\n";
		}
	} while (nr_keys>NMAX);

	cout<<"\nVectorul de chei:\n";
	for (int i=1; i<=nr_keys; ++i)
	{
		cout<<"KEYS["<<i<<"]=";
		cin>>KEYS[i];
		cin.get();
	}

	cout<<"\nVectorul de frecvente:\n";
	for (int i=1; i<=nr_keys; ++i)
	{
		cout<<"p["<<i<<"]=";
		cin>>p[i];
		cin.get();
	}

	cout<<"\nVectorul de frecvente de cautare intre chei: \n";
	for (int i=0; i<=nr_keys; ++i)
	{
		cout<<"q["<<i<<"]=";
		cin>>q[i];
		cin.get();
	}

	Matrix(nr_keys, W, C, R, p, q);

	cout<<"\nDrumul mediu este: "<<(float)C[0][nr_keys]/W[0][nr_keys]<<".\n\n";

	OBST* arboreOBST=Build_OBST(0, nr_keys, KEYS, R);

	cout<<endl<<endl<<"Arborele OBST este:"<<endl;
	printIndent(arboreOBST, 0);

	_getch();
	return 0;
}