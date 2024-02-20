#include <iostream>
using namespace std;
int main()
{
    int  ch = 0, max = 0;
    const int n = 4;
    int arr[n] = { 5,2,5,5 };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (max == arr[i])
        {
            ch += 1;
        }
    }
    cout << "Максимальный элемент: " << max << endl << ch;
    return 0;
}