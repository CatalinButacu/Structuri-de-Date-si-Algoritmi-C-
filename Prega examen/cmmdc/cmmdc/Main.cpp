#include <iostream>
#include <conio.h>
using namespace std;
int cmmdc(int x, int y)
{
	if (y)
	{
		return cmmdc(y, x%y);
	}
	else
	{
		return x;
	}
}
int main()
{
	int x, y, c;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	if (x>y)
	{
		c = cmmdc(x, y);
	}
	else
	{
		c = cmmdc(y, x);
	}
	cout << "cmmdc(" << x << ", " << y << ")=" << c << endl;
	_getch();
	return 0;
}
