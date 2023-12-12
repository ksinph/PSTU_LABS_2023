#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float n, s, a;
	int i = 1;
	bool ch = false;

	cin >> n >> s;
	while (i<=n and !ch)
	{
		a = sin(n + i / n);
		a = round(a * 10) / 10;
		if (a == s)
		{
			ch = true;
		}
		else
		{
			i++;
		}
	}
if (ch)
{
	cout << "есть данное число";
}
else
{
	cout << "нет данного числа";
}
return 0;
}
