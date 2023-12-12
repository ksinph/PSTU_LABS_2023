#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float n, s, max;
	int i = 2;
	int  ch= 1;
	cin >> n;
	max = sin(n + 1 / n);
	while (i <= n)
	{
		s = sin(n + i / n);
		if (s > max)
		{
			max = s;
			ch =1;
		}
		else if (s == max)
		{
			ch++;
		}
		i++;
	}
	cout << "max=" << max << ",ch=" << ch;
	return 0;
}