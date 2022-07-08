#pragma once
#define CMAX 80

struct Nod { //structura listei liniare simplu inlantuite
	char* data;
	Nod *succ;
};

class ListaLiniara {
private:
	Nod *cap;
	int lungime;

public:
	ListaLiniara(); //constructorul de initializare (pune capul pe nullptr si lungimea pe 0)
	~ListaLiniara(); //destructorul ce dealoca memoria ocupata de lista

	void inserareNod(Nod* nodNou); //insereaza un nod in lista
	bool stergereNod(char* cheie); //sterge un element din lista pe baza cheii
	Nod* preiaNod(char* cheie); //preia un nod din lista pe baza cheii sale
	void afisareLista(); //afiseaza lista liniara
	int preiaLungime(); //preia lungimea listei
};

class HashTable {
private:
	ListaLiniara *vector; //vector de liste inlantuite
	int lungime; //lungimea vectorului Hash Table (de preferat numar prim)
	unsigned int hash(char* cheie); //functia hash() ce returneaza o locatie in vector in functie de cheia parametru

public:
	HashTable(int lungime = 13); //constructorul cu parametru implicit, lungime 13
	~HashTable(); //destructorul ce dealoca memoria ocupata de HashTable

	void inserareNod(Nod* nodNou); //insereaza un obiect nou in HashTable
	bool stergereNod(char* cheie); //sterge un obiect din HashTable pe baza cheii lui
	Nod* preiaNodDupaCheie(char* cheie); //preia un obiect din HashTable pe baza cheii lui
	void afisareHT(); //afiseaza intreg HashTable-ul pe ecran
	void afisareHistograma(); //afiseaza histograma ce arata distributia nodurilor in HashTable
	int preiaLungime(); //returneaza numarul de locatii distribuite din HashTable
	int preiaNumarNoduri(); //returneaza numarul de noduri existente in HashTable
};
