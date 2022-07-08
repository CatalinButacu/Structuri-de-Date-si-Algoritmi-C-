#pragma once

#include <iostream>
#include <fstream>

using namespace std;

char** citeste_labirint(int &m, int &n, ifstream &fisier);
bool cautare(int x, int y, char** L, int x_f, int y_f, int m, int n);