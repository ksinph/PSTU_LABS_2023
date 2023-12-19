#include <iostream>
using namespace std;
int main()
{
    int n, b, * ptr = &b, max, min;
    cin >> n;//длина последовательности
    cin >> *ptr;
    max = *ptr;
    min = *ptr;
    for (int i = 2; i <= n; i++)
    {
        cin >> *ptr;
        if (*ptr > max)
        {
            max = *ptr;
        }
        else if (*ptr < min)
        {
            min = *ptr;
        }
    }
    cout << "max="<<max <<", min="<< min;
    return 0;
}