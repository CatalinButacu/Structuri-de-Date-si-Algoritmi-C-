#include<iostream>
#include<chrono>
#include<algorithm>
#include<random>
int main()
{
	int N = 25000;
	int *vec = new int[N];
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10 * N);
	for (int i = 0; i < N; ++i)
	{
		vec[i] = dis(gen);
	}

	//sortare
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

		int i, j, m; 
		for (i = 0; i < N - 1; i++)
		{
			m = i; 
			for (j = i + 1; j < N; j++)
			{
				if (vec[j] < vec[m])
					m = j;
			}

			std::swap(vec[i],vec[m]);
	
		}	end = std::chrono::system_clock::now();	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end -
		start).count() << " ms" << std::endl;
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end -
		start).count() << " us" << std::endl;	return 0;}