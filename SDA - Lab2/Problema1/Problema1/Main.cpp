#include<iostream>
#include"Header.h"
int main()
{
	int n,v[10];
	std::cout << "n= ";
	std::cin >> n;
	for (int i = 0;i < n;++i)
	{
		std::cout << "v[" << i << "]= ";
		std::cin >> v[i];
	}
	int smax = -100, x = 1, y = 1;
	for( int i=0;i<n;++i)
		for(int j=i;j<n;++j)
			if (smax < sum(v, i, j))
			{
				smax = sum(v, i, j);
				x = i;
				y = j;
			}

	std::cout << "suma maxima a vectorului este cuprinsa intre elementul " << x << " si elementul " << y<<std::endl;
	return 0;
}