﻿#include <iostream>
using namespace std;
int main()
{
float a;
cin >> a;
if (a < 5)
{
	cout << a * 3;
}
else if (5 <= a and a<=7)
{
	cout << a / 10;
}
else
{
	cout << a + 3;
}
return 0;
}
