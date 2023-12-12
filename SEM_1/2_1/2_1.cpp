#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
int n;
int sum = 0;
cin >> n;
if (n <= 0)
{
	cout << "Не является натуральным числом";
}
else
{
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
}
cout << sum;
return 0;
}
