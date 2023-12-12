#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n,s;
	int ch = 0;
	cin >> n>>s;
	if (n > 0 and s > 0)
	{
		while (n >= 1)
		{
			if (s == n % 10)
			{
				ch = 1;
			}
			n /= 10;
		}
	}
	else
	{
		cout << "неподходящие значения";
	}
if (ch == 1)
{
	cout << "есть данное число";
}
else
{
	cout << "нет данного числа";
}
return 0;
}