#include <iostream>
#include <string.h>
using namespace std;

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
    int arr[] = { 1, 101, 78, 12, 55, 92, 0, 2, 4, 12, 7, 16, 34, 5, 6, 4, 23, 60, 28, 52, 11, 3, 43, 6, 2 };
    //эти вычисления нужны для подсеты длины изменяющегося массива
    int kolvo, bait;
    kolvo = sizeof(arr);
    bait = sizeof(int);
    quickSort(arr, 0, kolvo / bait);
    for (int i = 0; i <= kolvo / bait; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
