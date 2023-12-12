#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cout << "*";
	}
	cout << endl;
	for (int y = 0; y < n-2; y++)
	{
		cout << "*";
		for (int d = 0; d < n - 2; d++)
		{
			cout << " ";
		}
		cout << "*";
		cout<<endl;
	}
	for (int h = 0; h < n; h++)
	{
		cout << "*";
	}
	return 0;v
}