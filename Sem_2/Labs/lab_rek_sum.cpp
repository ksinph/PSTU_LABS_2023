#include <iostream>
#include <math.h>
using namespace std;
int factorial(int n)
{
	if (n < 2) { return 1; }
	return n * factorial(n - 1);
}
int fib(int n,int x)
{
	return 1+(pow(log(3),n)/factorial(n))*pow(x,n);
}
int main()
{
	int n,x;
	cin >> n>>x;
	cout << fib(n,x) << " ";
	
	return 0;
}