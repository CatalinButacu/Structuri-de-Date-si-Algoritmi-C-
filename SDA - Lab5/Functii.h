#pragma once
#include "Element.h"
#include "Circular.h"

//1)
void InserareFata(Element *& cap, int val);
void Afisare(Element* cap);
void AfisareD_I(Element*cap);
void InserarePos(Element *&cap, int pos, int val);
void StergePos(Element*& cap, int pos);

//2)
void Concat(Element *&cap,Element*x,Element*y);
void Inercal(Element*& cap, Element* x, Element* y);

//3)
void InserareFata(Circular *&cap,int val);
void Afisare(Circular *cap);
void InversareLeg(Circular *&cap);

//4)
void StergerePos_cuAfisare(Circular*& cap, int pos);
void StergerePos(Circular*& cap,int pos);
void AfisareExecutare(Circular* cap,int m);
void PozitiaSigura(Circular* cap, int m);

//5)
void Concat(Circular*& cap, Circular* x, Circular* y);
void Inercal(Circular*& cap, Circular* x, Circular* y);

//6)
void InserareFata_DubluCircular(Element *&cap,int val);
void StergerePrimElement_DubluCircular(Element*& cap);
void Golire_DubluCircular(Element*&cap);
void Afisare_DubluCircular(Element* cap);
bool Compar_DubluCircular(Element* x, Element* y);
void Adunare_DubluCircular(Element*& sum, Element* x, Element* y);