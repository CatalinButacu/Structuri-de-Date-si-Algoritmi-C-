//#include<iostream>
//#include<chrono>
//#include<random>
//int main()
//{
//	int N = 25000;
//	int *vec = new int[N];
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<> dis(1, 10 * N);
//	for (int i = 0; i < N; ++i)
//	{
//		vec[i] = dis(gen);
//	}
//
//	//sortare
//	std::chrono::time_point<std::chrono::system_clock> start, end;
//	start = std::chrono::system_clock::now();
//	bool swapped = 1;
//	int j = 0;
//	while (swapped)
//	{
//		int tmp = 0;
//		swapped = 0;
//		j = j + 1;
//			for(int i = 1;i< N - j ;++i)
//				if (vec[i] > vec[i + 1])
//				{
//					tmp = vec[i];
//					vec[i] = vec[i + 1];
//					vec[i + 1] = tmp;
//					swapped = 1;
//				}
//	}//	end = std::chrono::system_clock::now();////	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end -
//		start).count() << " ms" << std::endl;
//	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end -
//		start).count() << " us" << std::endl;////	return 0;//}