# Вариант задания
Реализовать быструю сортировку по Хоару.
# Код программы
```cpp
#include <iostream>
#include <string.h>
#include <ctime>
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
     srand(time(NULL));
    for (int i = 0; i < kolvo; i++) arr[i] = rand() % 100;
    element(arr);
    cout << endl;
    quickSort(arr, 0, kolvo);
    element(arr);
    return 0;
}
```
# Функция main
<image src="main.drawio.svg">

# Функция element
<image src="element.drawio.svg">

# Функция partition
<image src="partition.drawio.svg">

# Функция quickSort
<image src="quickSort.drawio.svg">
	
# Тесты
### Пример 1
Входные данные:
```
78 21 0 85 23 21 0 86 65 15 46 78 38 77 88 24 88 26 9 23 40 9 89 14 80
```
Выходные данные:
```
 0 0 9 9 14 15 21 21 23 23 24 26 38 40 46 65 77 78 78 80 85 86 88 88 89
```
### Пример 2
Входные данные:
```
41 91 46 5 97 15 35 73 82 41 89 19 14 45 81 80 52 95 97 71 27 12 75 86 64
```
Выходные данные:
```
5 12 14 15 19 27 35 41 41 45 46 52 64 71 73 75 80 81 82 86 89 91 95 97 97
```
### Пример 3
Входные данные:
```
11 99 85 26 95 20 53 69 49 34 30 74 96 95 6 29 39 59 55 31 59 28 22 21 68
```
Выходные данные:
```
6 11 20 21 22 26 28 29 30 31 34 39 49 53 55 59 59 68 69 74 85 95 95 96 99
```
