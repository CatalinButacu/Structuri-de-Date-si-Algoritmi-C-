#include "Student.h"

void InitStudent(Student & s)
{
	char aux[100];
	std::cout << "nume= ";;
	std::cin >> aux;
	s.nume = new char[strlen(aux) + 1];
	strcpy_s(s.nume, strlen(aux) + 1, aux);
	std::cout << "nota= ";
	std::cin >> s.nota;
}

void AfisStudent(Student s)
{
	std::cout << "Numele studentului este " << s.nume << std::endl;
	std::cout << "Nota studentului este " << s.nota << std::endl;
}

void StergeStudent(Student &s)
{
	if(s.nume)
	delete[] s.nume;
}
