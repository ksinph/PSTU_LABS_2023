#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int  tmp = 0, max = 0;
    double min = INFINITY;
    const int n = 4;
    int arr[n] = { 5,2,1,4 };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if (max < arr[i])
        {
            max = arr[i];
        }

        else if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << "Максимальный элемент: " << max << endl << "минимальный элемент" << min;
    return 0;
}