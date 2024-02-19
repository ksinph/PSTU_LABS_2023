#include <iostream>
#include<complex>
using namespace std;
complex<double> sum(complex<double> a, complex<double> b) { return a + b; }
int sum(int c, int w) { return c + w; }
int main()
{
    int c, w;
    double a1, a2;
    cin >> c;
    cin >> w;
    cin >> a1;
    cin >> a2;
    complex<double> a(a1, a2);
    complex<double> b(a2, a1);
    cout << sum(c, w);
    cout << sum(a, b);
}
