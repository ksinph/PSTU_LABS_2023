//f(x)=e^x-e^-x-2=0
//f'(x)=e^x+e^-x=0
//f''(x)=e^x-e^-x=0
//[0;1]
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, xn_1;
    //f(b)*f''(b)>0
    //(e^1-^e-1-2)*(e^1-e^-1)>0 => x0=b
    x = 1;
    xn_1 = 0;
    const float e = 2.72;
    const double eps = 0.000001;
    while (abs(x-xn_1)>eps)
    {
        xn_1 = x;
        x = xn_1 - (pow(e, xn_1) - pow(e, -xn_1) - 2) / (pow(e, xn_1) + pow(e, -xn_1));
    }
    cout << "x= " << x;
    return 0;
}
