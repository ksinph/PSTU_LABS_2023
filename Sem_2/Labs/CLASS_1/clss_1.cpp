#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, int S, int D)
{
    fraction t;
    t.Init(F, S, D);
    return t;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    fraction A;
    A.Read();
    A.Show();

    if (A.date > 31 || A.date <= 0 || A.second > 31 || A.second <= 0)
    {
        cout << "Неподходящее значение";
    }
    else
    {
        cout << "A.Summa = " << A.Summa() << endl;
    }
    return 0;
}