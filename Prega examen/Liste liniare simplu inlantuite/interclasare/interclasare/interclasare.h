#pragma once

struct Nod { //structura listei liniare simplu inlantuite
	int data;
	Nod* succ;
};

Nod* CreateList_Rec();
void PrintList(Nod* cap);
Nod* interclasareListe(Nod* l1, Nod* l2);