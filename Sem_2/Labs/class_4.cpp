#include <iostream>
#include "Triad.h"
#include "Time.h"
using namespace std;

void f1(Triad& c)
{
	c.Set_first(9);
	cout << c;
	c.Set_second(89);
	cout << c;
	c.Set_third(23);
	cout << c;
}

Triad f2()
{
	Time l(2, 3, 7, 8, 45, 56);
	return l;
}

void main()
{
	Triad a;
	cin >> a;
	cout << a;
	Time c;
	cin >> c;
	cout << c;
	f1(c);
	a = f2();
	cout << a;
	
}