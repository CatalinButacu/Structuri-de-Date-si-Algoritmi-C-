#pragma once
#include "student.h"
struct Grupa {
	Student* tab;
	int nr;
	int id; 
};
void InitGrupa(Grupa&);
void AfisGrupa(Grupa);
void StergeGrupa(Grupa&);
void CautaStudent(Grupa g);
void NotaMaxMin(Grupa g);