#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	n = sqrt(n);
	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n; y++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}
