#pragma once

#define NMAX 20 //numarul maxim de noduri

using namespace std;

//structura arborelui optimal
struct OBST {
	char KEY;
	OBST *left, *right;
};

//functia pentru calculul matricelor
void Matrix(int nr_keys, int W[NMAX][NMAX], int C[NMAX][NMAX], int R[NMAX][NMAX], int p[], int q[]);
//functie de constructie a unui BST optimal
OBST* Build_OBST(int i, int j, char KEYS[], int R[NMAX][NMAX]);
//functie de afisare indentata a arborelui
void printIndent(OBST* r, int level);