﻿#include <iostream>
using namespace std;
int main()
{
	float a, b, * ptr1, * ptr2, sum = 0;
	cin >> a >> b;
	ptr1 = &a;
	ptr2 = &b;
	sum = *ptr1 + *ptr2;
	cout << sum;
	return  0;
}
