#pragma once
#include <string>

struct Nod
{
	std::string cheie = "";
	struct Nod* urm = nullptr;
};
struct Nod2
{
	int nr = 0;
	char cheie = ' ';
	struct Nod2* urm = nullptr;
};
struct Nod3
{
	int nr = 1;
	std::string cheie = "";
	struct Nod3* urm = nullptr;
};