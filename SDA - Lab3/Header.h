#pragma once
#include <iostream>
typedef int Date;
struct Element{
	Date valoare;
	Element* urmator;
};
void InserareInceput(Element*& cap, Date val);
void Afisare(Element* cap);
int VerifAparitie(Element* cap, int x);
void InserareInPozitie(Element* cap, int poz, int val);
Element* CautarePozitie(Element* cap, int pozitie);
void StergerePozitie(Element*& cap, int pozitie);
void AfisareDus_Intors(Element* cap);
void AfisareMijloc(Element* cap);