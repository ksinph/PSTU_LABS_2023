#include <iostream>
#include <string.h>
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


int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int num = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot) { num++; }
    }

    int pos = low + num;

    swap(arr[pos], arr[low]);

    int i = low, j = high;
    while (i < pos && j > pos)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pos && j > pos)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pos;
}
void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;

    int pI = partition(arr, low, high);

    // сортируем часть элементов до pivot
    quickSort(arr, low, pI - 1);

    // сортируем часть элементов после pivot
    quickSort(arr, pI + 1, high);
}
int main()
{
    int arr[kolvo];
    for (int i = 0; i < kolvo; i++) arr[i] = rand() % 10;
    element(arr);
    cout << endl;
    quickSort(arr, 0, kolvo);
    element(arr);
    return 0;
}
