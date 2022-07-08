#include <iostream>
#include <conio.h>
#include "Bernstein.h"

using namespace std;

int main(void)
{
	int m = 29;

	HashTable tabel(m);

	Nod * A = new Nod{ "Apple", NULL };
	Nod * B = new Nod{ "Banana", NULL };
	Nod * C = new Nod{ "Caterpillar", NULL };
	Nod * D = new Nod{ "Dog", NULL };
	Nod * E = new Nod{ "Elephant", NULL };
	Nod * F = new Nod{ "Fedora", NULL };
	Nod * G = new Nod{ "Goosebumps", NULL };
	Nod * H = new Nod{ "House", NULL };
	Nod * I = new Nod{ "Insects", NULL };
	Nod * J = new Nod{ "Jam", NULL };
	Nod * K = new Nod{ "Kite", NULL };
	Nod * L = new Nod{ "Limestone", NULL };
	Nod * M = new Nod{ "Mountaineering", NULL };
	Nod * N = new Nod{ "Night", NULL };
	Nod * O = new Nod{ "Open Sesame", NULL };
	Nod * P = new Nod{ "Potatoes", NULL };
	Nod * Q = new Nod{ "Quantum Mechanics", NULL };
	Nod * R = new Nod{ "Rrrrrrrrrrawr", NULL };
	Nod * S = new Nod{ "Snakes", NULL };
	Nod * T = new Nod{ "Tizzy Tube", NULL };
	Nod * U = new Nod{ "Underworld", NULL };
	Nod * V = new Nod{ "Volcanic Ash", NULL };
	Nod * W = new Nod{ "Who When What Why", NULL };
	Nod * X = new Nod{ "XXX", NULL };
	Nod * Y = new Nod{ "Yellow", NULL };
	Nod * Z = new Nod{ "ZABG", NULL };

	//coliziuni
	Nod * C1 = new Nod{ "Caterpilarl", NULL };
	Nod * C2 = new Nod{ "Caetripllar", NULL };
	Nod * C3 = new Nod{ "Caterpilarl", NULL };
	Nod * C4 = new Nod{ "Atcerpillar", NULL };

	Nod * Z1 = new Nod{ "ZABG", NULL };
	Nod * Z2 = new Nod{ "ABGZ", NULL };
	Nod * Z3 = new Nod{ "BGZA", NULL };
	Nod * Z4 = new Nod{ "GZAB", NULL };
	Nod * Z5 = new Nod{ "GBAZ", NULL };

	tabel.inserareNod(A);
	tabel.inserareNod(B);
	tabel.inserareNod(C);
	tabel.inserareNod(D);
	tabel.inserareNod(E);
	tabel.inserareNod(F);
	tabel.inserareNod(G);
	tabel.inserareNod(H);
	tabel.inserareNod(I);
	tabel.inserareNod(J);
	tabel.inserareNod(K);
	tabel.inserareNod(L);
	tabel.inserareNod(M);
	tabel.inserareNod(N);
	tabel.inserareNod(O);
	tabel.inserareNod(P);
	tabel.inserareNod(Q);
	tabel.inserareNod(R);
	tabel.inserareNod(S);
	tabel.inserareNod(T);
	tabel.inserareNod(U);
	tabel.inserareNod(V);
	tabel.inserareNod(W);
	tabel.inserareNod(X);
	tabel.inserareNod(Y);
	tabel.inserareNod(Z);

	tabel.inserareNod(C1);
	tabel.inserareNod(C2);
	tabel.inserareNod(C3);
	tabel.inserareNod(C4);
	tabel.inserareNod(Z1);
	tabel.inserareNod(Z2);
	tabel.inserareNod(Z3);
	tabel.inserareNod(Z4);
	tabel.inserareNod(Z5);

	tabel.afisareHT();
	tabel.afisareHistograma();

	_getch();
	return 0;

}