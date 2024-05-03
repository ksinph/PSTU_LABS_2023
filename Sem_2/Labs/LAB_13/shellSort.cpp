#include <iostream>
using namespace std;
const int kolvo = 25;

void element(int arr[])
{
    for (int i = 0; i < kolvo; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

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
    int arr[kolvo];
    for (int i = 0; i < kolvo; i++) arr[i] = rand() % 10;
    element(arr);
    cout << endl;
    shellSort(arr, kolvo);
    element(arr);
    return 0;
}
