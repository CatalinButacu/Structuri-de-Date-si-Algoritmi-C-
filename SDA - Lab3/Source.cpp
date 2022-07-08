#include "Header.h"

void InserareInceput(Element*& cap, Date val){
	Element* elem = new Element;
	elem->valoare = val;
	elem->urmator = cap;
	cap = elem;
}
void Afisare(Element* cap){
	while (cap != 0){
		std::cout << cap->valoare << std::endl;
		cap = cap->urmator;
	}
}
int VerifAparitie(Element* cap, int x){
	while (cap != 0){
		if (cap->valoare == x)
			return 1;
		cap = cap->urmator;
	}
	return 0;
}
void InserareInPozitie(Element* cap, int poz, int val){
	Element* q = 0;
	if (poz <= 0)
		std::cout << "\n Pozitie invalida - prea mica!";
	else {
		if (poz == 1) {
			std::cout << "\n Inserare in fata";
			InserareInceput(cap, val);
		}
		else {
			q = cap;

			int cnt = 1;
			while (q && cnt < poz - 1) {
				cnt++;
				q = q->urmator;
			}
			if (cnt == poz - 1) {
				Element* p;
				p = new Element;
				p->valoare = val;
				p->urmator = q->urmator;
				q->urmator = p;
			}
			else
				std::cout << "\n Poz inv. - prea mare!";

		}
	}
}
Element* CautarePozitie(Element* cap, int pozitie){
	int i = 0;
	while (cap != NULL && i < pozitie)	{
		cap = cap->urmator;
		i++;
	}
	if (i == pozitie)
		return cap;
	else
		return NULL;
}
void StergerePozitie(Element*& cap, int poz){
	if (cap != 0)
		if (poz == 0)		{
			Element* deSters = cap;
			cap = cap->urmator;
			delete deSters;
			return;
		}
	Element* predecesor = CautarePozitie(cap, poz - 1);
	Element* deSters = predecesor->urmator;
	predecesor->urmator = predecesor->urmator->urmator;
	delete deSters;
}
void AfisareDus_Intors(Element* cap){
	if (cap == 0)	{
		std::cout << "Nu exista lista!" << std::endl;
		AfisareDus_Intors(cap->urmator);
		std::cout << cap->valoare << " " << std::endl;
	}
}
void AfisareMijloc(Element* cap){
	Element* f = cap;
	Element* s = cap;
	if (cap){
		while (f != 0 && f->urmator != 0){
			f = f->urmator->urmator;
			s = s->urmator;
		}
		std::cout << "\n Mijlocul sirului este: " << s->valoare << "\n";
	}
}