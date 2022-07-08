#include <iostream>
#include <conio.h>
using namespace std;
int main(void)
{
	int n, i, j;
	long long int s;
	cout << "n=";
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		if (i == 1 || i==2)
		{
			cout << 1 << "; ";
		}
		else
		{
			s = 0;
			long long int f1 = 1, f2 = 1;
			for (j = 1; j <= i-2; ++j)
			{
				s = f1+f2;
				f1 = f2;
				f2 = s;
			}
			cout << s << "; ";
		}
	}
	_getch();
	return 0;
}