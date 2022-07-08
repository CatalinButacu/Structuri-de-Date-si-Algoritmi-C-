#pragma once
struct Pozitie {
	int x, y;
};

typedef Pozitie Atom;       // elementele cozii sint de tip Pozitie

struct Queue
{
	Pozitie data;
	Queue* leg, * tail;
};