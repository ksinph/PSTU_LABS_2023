#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float n, s, max;
	int i = 2;
	int num = 1;
	cin >> n;
	max = sin(n + i / n);
	while (i <= n)
	{
		s = sin(n + i / n);
		if (s > max)
		{
			max = s;
			num = i;
		}
		i++;
	}
	cout << "max="<<max<<",num=" << num;
	return 0;
}