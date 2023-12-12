#include <iostream>
using namespace std;
int main()
{
	int x, n;
	float sum = 1;
	cin >> x >> n;
	int fac = 1;
	
	for (int i = 1; i <= n; i++)
	{
		fac *= i;
		sum += (pow(x, i) / fac);
	}
	
	cout << sum;
	return 0;
}