#include <iostream>
using namespace std;
int main()
{
	int n;
	int sum = 0;
	cin >> n;
	while (n > 0)
	{
		if (n % 2 != 0)
		{
			sum -=n;
		}
		else
		{
			sum += n;
		}
		n--;
	}
	cout << sum;
	return 0;
}
