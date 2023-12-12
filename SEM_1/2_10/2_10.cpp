#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int max = 0;
	while (n > 0)
	{
		n--;
		int y;
		cin >> y;
		if (y >max)
		{
			max = y;
		}
	}
	cout << max;
	return 0;
}
