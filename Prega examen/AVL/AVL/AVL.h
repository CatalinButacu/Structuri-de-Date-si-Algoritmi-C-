#pragma once

typedef int Atom;

struct AVL
{
	Atom data;
	int bf;
	AVL *stg, *drt;
};

void RSD(AVL*& a);
void RSS(AVL*& a);
void RDD(AVL*& a);
void RDS(AVL*& a);
void InsertAVL(AVL*& a, Atom x);
void AfisareIndentat(AVL* A, int level);
void RemoveNode(AVL*& r, Atom a);
void RemoveRoot(AVL*& r);
AVL* Greatest(AVL*& r);
void RSDDelete(AVL*& a);
void RSSDelete(AVL*& a);
void UpdateAfterDeletingRight(AVL*& a);
void UpdateAfterDeletingLeft(AVL*& a);
int adancime(AVL* r);
bool testAVL(AVL* r);