#pragma once
#include<string>
#include<iostream>
struct Student {
	char* nume;
	int nota;
};
void InitStudent(Student &s);
void AfisStudent(Student);
void StergeStudent(Student&);