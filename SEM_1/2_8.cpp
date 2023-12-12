#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	if (n <= 2)
	{
		cout << "неподходящее число";
	}
	else
	{
		for (int i = n; i >=1; i--)
		{
			
			for (int stars = 1; stars <= n-i+1; stars++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	return 0;
}