#pragma once

struct Nod {
	int data;
	Nod* succ;
};

Nod* CreateList_Rec();
void PrintList(Nod* cap);