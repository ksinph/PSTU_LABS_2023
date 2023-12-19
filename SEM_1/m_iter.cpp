//f(x)=e^x-e^-x-2=0
//f'(x)=e^x+e^-x=0
//f''(x)=e^x-e^-x=0
//[0;1]
//fi(x)=x+lyam(e^x+e^-x-2)
//-1/r < λ < 0, если f'(x) > 0
// 0 < λ < 1/r, если f'(x) < 0
// r = max(|f'(a)|, |f'(b)|)
// r = max(|e^0+e^0|,|e^1+e^-1|) = max(2, 3,08616) = 3,08616
// f'(x) > 0 => -1/r < λ < 0
// берем любое удобное число в диапазоне
// λ = -1/20 = -0.05
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, xn_1,lyam=-0.05;
    const float e = 2.71828;
    double eps = 0.000001;
    x = 1;
    xn_1 = 0;
    while (abs(x - xn_1) > eps)
    {
        xn_1 = x;
        x = lyam*(pow(e, xn_1) - pow(e, -xn_1)-2) +xn_1;
    }
    cout << "x = "<<x;
    return 0;
}