﻿#include <iostream>
using namespace std;
int main()
{
    const int n = 5;
    int k = 3, tmp;
    int arr[n] = { 41,42,66,77,45 };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        tmp = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = tmp;

        for (int t = 0; t < n; t++)
        {
            cout << arr[t] << " ";
        }
        cout << endl;
    }
    return 0;
}