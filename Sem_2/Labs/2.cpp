﻿#include <iostream>
using namespace std;
int main()
{
	const int m = 100;
	int numbers, n;
	int a[m][m] = { 0 };
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		numbers = 1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (j <= i)
			{
				a[i][j] = numbers;
				numbers++;
				if (numbers == 10) numbers = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}