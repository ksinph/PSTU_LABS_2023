#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int max= 0;
	double min =INFINITY;
	while (n > 0)
	{
		n--;
		int y;
		cin >> y;

		if (y > max)
		{
			max = y;
		}
		else if (y<min)
		{
			min = y;
		}
	}
	cout << max+min;
	return 0;
}
