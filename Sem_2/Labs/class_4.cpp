#include <iostream>
#include "Triad.h"
using namespace std;
int main ()
{
	Triad a;
	cin >> a;
	cout << a;
	Triad b(4, 5, 6 );
	cout << b;
	a = b;
	cout << a;
	Time c;
	cin >> c;
	cout << c;

	return 0;
}