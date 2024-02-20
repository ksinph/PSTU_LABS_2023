#include <iostream>
using namespace std;
int main()
{
    int  tmp = 0, max = 0;
    const int n = 4;
    int arr[n] = { 5,2,3,4 };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "Максимальный элемент: " << max << endl;
    return 0;
}
