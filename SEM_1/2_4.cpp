#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
int n;
cin >> n;

if (n <= 3)
{
	cout << "Неподходящее число";
}
else
{
	int sp = n / 2;
	int stars = 1;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < sp; j++)
		{
			cout << " ";
		}
		sp--;
		for (int y = 0; y < stars; y++)
		{
			cout << "*";
		}
		stars += 2;
		cout <<endl;
	}
}
return 0;
}
