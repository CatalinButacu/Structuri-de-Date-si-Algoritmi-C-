#pragma once
#include<iostream>
struct Element
{
	int data;
	Element * leg;
};
int * citire(int n);
void inserareFata(Element *&cap, int val);
void inserare(Element*& cap);
void afisare(Element *cap);
