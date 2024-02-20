#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 4;
    bool flag = false;
    int arr[n] = { 41,41,43,44 };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3])
    {
        flag = true;
    }
    if (flag)
    {
        cout << "возрастает";
    }
    else
    {
        cout << "не возрастает";
    }
    return 0;
}
