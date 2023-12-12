#include <iostream>
using namespace std;
int main()
{
	int a, b, c, x;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;
	cout << "x= ";
	cin >> x;
	cout << a * pow(x, 2) + b * x + c;
	return 0;
}
