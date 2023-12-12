#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int pr = 1;
	cin >> n;
	if (n <= 0)
	{
		cout << "Не является натуральным числом";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			pr *= i;
		}
	}
	cout << pr;
	return 0;
}
