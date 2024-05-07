#include <iostream>
#include "Triad.h"
#include "Time.h"
using namespace std;

void f1(Triad& c)
{
	c.Set_first(11);
	cout << c;
	c.Set_second(22);
	cout << c;
	c.Set_third(33);
	cout << c;
}

Triad f2()
{
	Time l(00,00,00);
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
