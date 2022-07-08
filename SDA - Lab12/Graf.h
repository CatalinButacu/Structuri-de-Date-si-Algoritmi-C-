#pragma once
#include <iostream>
#include <algorithm>
#include <list>

void DFS_iter(int** mat, int** M, int n, std::list<int>& L, int i = 0) {
	/*
	std::list<int>S;
	S.push_back(i);
	while (!S.empty()) {
		int j = S.pop_back();
		if (M[j] == 0) {
			L.insert(j);
			M[j] = 1;
			for (int k = 1; k < n, ++k)
				if (mat[j][k])
					S.push_back(k);
		}
	}*/
};

void DFS_rec() {};
void BFS_iter() {};
void BFS_rec() {};