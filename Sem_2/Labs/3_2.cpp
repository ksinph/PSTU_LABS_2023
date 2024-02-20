#include <iostream>
using namespace std;
int main()
{
    int n, p, q, tmp;
    n = 11;
    p = 2;
    q = 6;

    int arr[11] = { 41,42,66,77,44,23,45,90,12,34,67 };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    while (p < q)
    {
        tmp = arr[p];
        arr[p] = arr[q];
        arr[q] = tmp;
        p++;
        q--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}