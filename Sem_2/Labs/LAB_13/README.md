# Вариант задания
Реализовать сортировку Шелла.
# Код программы
```cpp
#include <iostream>
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
    srand(time(NULL));
    for (int i = 0; i < kolvo; i++) arr[i] = rand() % 100;
    element(arr);
    cout << endl;
    shellSort(arr, kolvo);
    element(arr);
    return 0;
}
```
# Функция main
<image src="main.drawio.svg">

# Функция element
<image src="element.drawio.svg">

# Функция shellSort
<image src="shellSort.drawio.png">
	
# Тесты
### Пример 1
Входные данные:
```
83 64 13 4 76 30 23 25 3 16 44 25 6 1 21 75 2 2 93 78 69 50 87 76 44
```
Выходные данные:
```
1 2 2 3 4 6 13 16 21 23 25 25 30 44 44 50 64 69 75 76 76 78 83 87 93
```
### Пример 2
Входные данные:
```
44 68 55 57 74 88 75 19 42 90 11 80 44 88 22 98 54 60 11 75 5 41 57 88 34
```
Выходные данные:
```
5 11 11 19 22 34 41 42 44 44 54 55 57 57 60 68 74 75 75 80 88 88 88 90 98
```
### Пример 3
Входные данные:
```
6 12 94 8 43 60 75 36 50 49 1 17 98 88 89 42 75 92 27 92 24 67 95 93 78
```
Выходные данные:
```
1 6 8 12 17 24 27 36 42 43 49 50 60 67 75 75 78 88 89 92 92 93 94 95 98
```
