#include <iostream>
using namespace std;

void shellSort(int arr[], int size)
{
    for (int h = size / 2; h > 0; h /= 2)
    {
        for (int i = h; i < size; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            /* альтернативно
            for (j = i; j >= h; j -= h)
            {
                if (tmp < arr[j - h])
                {
                    arr[j] = arr[j - h];
                }
                else break;
            } */
            arr[j] = tmp;
        }
    }
}
int main()
{
    int arr[] = { 0, 101, 78, 12, 55, 92, 1, 2, 4, 12, 7, 16, 34, 5, 6, 4, 23, 60, 28, 52, 11, 3, 43, 6, 2 };
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    shellSort(arr, (sizeof(arr) / sizeof(int)));
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
