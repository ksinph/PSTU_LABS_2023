#include <iostream>
#include<complex>
using namespace std;
complex<double> sum(complex<double> a, complex<double> b) { return a + b; }
int sum(int c, int w) { return c + w; }
int main()
{
    int c, w;
    cin >> c;
    cin >> w;
    double a1 = 10.20; double a2 = 10.23;
    complex<double> a(a1, a2);
    complex<double> b(a2, a1);
    cout << sum(c, w);
    cout << sum(a, b);
}
