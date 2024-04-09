#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::Init(double F, int S, int D)
{
    first = F;
    second = S;
    date = D;
}
void fraction::Read()
{
    cout << "first = ";
    cin >> first;
    cout << "second = ";
    cin >> second;
    cout << "date = ";
    cin >> date;
}

void fraction::Show()
{
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
    cout << "date = " << date << endl;
}

double fraction::Summa()
{
    return first / second * date;
}