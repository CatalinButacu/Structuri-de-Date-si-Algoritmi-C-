#include "Grafuri.h"

int main() {
	
	#if 0
		//ex-1
		int n, m;
		std::cout << "\nnoduri = "; std::cin >> n;
		std::cout << "\nmuchii = "; std::cin >> m;
		
		int const value = 0;
		int** mat = new int* [n];
		for (int i = 0; i < n; i++)
			mat[i] = new int[n];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				mat[i][j] = 0;

		int mcpy = m;
		while (mcpy--) {
			int i, j, cost;
			bool ok = 1;
			while (ok) {
				std::cout << "\ni = "; std::cin >> i;
				std::cout << "j = "; std::cin >> j;
				std::cout << "cost = "; std::cin >> cost;
				if (i >= n || i < 0 || j >= n || j < 0)
					ok = true, std::cout << "\nEroare! Muchia cuprinde noduri ce nu exista!";
				else
					ok = false;
			}
			mat[i][j] = cost;
		}
		std::cout << "\nMatricea de adiacenta este descrisa prin:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				std::cout << mat[i][j] << " ";
			std::cout << std::endl;
		}
	#endif // 0	
	#if 01
		//ex-2
		int n, m;
		std::cout << "\nnoduri = "; std::cin >> n;
		std::cout << "\nmuchii = "; std::cin >> m;
		
		int const value = 0;
		int** mat = new int* [n];
		for (int i = 0; i < n; i++)
			mat[i] = new int[n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				mat[i][j] = 0;

		int** viz = new int* [n];
		for (int i = 0; i < n; i++)
			viz[i] = new int[n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				viz[i][j] = 0;
		std::list <int>L;
		int mcpy = m;
		while (mcpy--) {
			int i, j, cost;
			bool ok = 1;
			while (ok) {
				std::cout << "\ni = "; std::cin >> i;
				std::cout << "j = "; std::cin >> j;
				std::cout << "cost = "; std::cin >> cost;
				if (i >= n || i < 0 || j >= n || j < 0)
					ok = true, std::cout << "\nEroare! Muchia cuprinde noduri ce nu exista!";
				else
					ok = false;
			}
			mat[i][j] = cost;
			viz[i][j] = 1;
			L.push_front(j);
			L.push_front(i);
		}
		std::cout << "\nMatricea de adiacenta este descrisa prin:\n";
		DFS_iter(mat, viz, n, L, 0);
	#endif // 0

	return 0;
}