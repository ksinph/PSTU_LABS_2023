//вариант 24
//f(x)=e^x-e^-x-2=0
//[0;1]
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, b, c;
    float fA, fB, fC;
    a = 0;
    b = 1;
    double eps = 0.000001;
    const float e = 2.71828;
    while ((b - a) > eps)
    {
        c = (a + b) / 2;
        fA = pow(e, a) - pow(e, -a)-2;
        fB = pow(e, b) - pow(e, -b)-2;
        fC = pow(e, c) - pow(e, -c) - 2;
        if (fA*fC>0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
    }
    cout << "a= "<<a<<"; b= "<<b;
    return 0;
}