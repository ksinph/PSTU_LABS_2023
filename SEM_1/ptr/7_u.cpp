#include <iostream>
using namespace std;
int main()
{
	int x;
	int* ptr = &x;
	cin >> *ptr;
	cout << x;
}
