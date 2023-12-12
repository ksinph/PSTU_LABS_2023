#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int pr = 0;
	while(n>0)
	{
		pr = pr * 10 + n % 10;
		n /= 10;
	}
	cout << pr;
	return 0;
}