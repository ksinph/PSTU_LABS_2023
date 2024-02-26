# Вариант задания
Лабораторная работа №6, вариант 1.
 В двумерном массиве записаны слова, представляющие
собой последовательность цифр, завершающихся 0.
Необходимо распечатать слова через запятую, заключив
печатную строку в скобки. Длина печатной строки 60
символов. Извлечение слова оформить в виде функции.
 Например:
 исходные данные - 123023402303450
 234450234567010
234455677670450
31
 результат - (123,234,23,345)(23445,234567,1)
(23445567767,45)

# Код программы
```cpp
#include <iostream>
#include <ctime>
using namespace std;
int** createArr(int height, int width) 
{
    int** seq = new int* [height];
    for (int l = 0; l < height; l++)
        seq[l] = new int[width];
    return seq;
}

int** fillArr(int** seq, int height, int width) 
{
    srand(time(NULL));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            seq[i][j] = rand() % 10;
    return seq;
}

void getWord(int** a, int height, int width) {
    cout << endl << "(";
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (a[i][j] == 0)
                cout << ", ";
            else
                cout << a[i][j];
    cout << ")" << endl;
}

void main() {
    setlocale(LC_ALL, "Russian");
    int i, j, l, height, width;
    cout << "Введите высоту массива: \n";
    cin >> height;
    cout << "Введите ширину массива: \n";
    cin >> width;
    width++;
    int** seq;
    seq = fillArr(createArr(height, width), height, width);
    getWord(seq, height, width);
}
```
# Блок-схема программы
## Функция main
<image src="lab_5.drawio.png">

 ## Функция createArr
 <image src="lab_5_createArr.drawio.png">
	 
 ## Функция fillArr
 <image src="lab_5_fillArr.drawio.png">

  ## Функция getWord
 <image src="lab_5_getWord.drawio.png">
	 
# Тесты
### Пример 1
Входные данные:
```
Введите высоту массива:
3
Введите ширину массива:
15
```
Выходные данные:
```
 (694858427721, 8641, 9, 466, 7673287, 7569, 82163461653)
```
### Пример 2
Входные данные:
```
Введите высоту массива:
3
Введите ширину массива:
15
```
Выходные данные:
```
(33947172981985525818681574, 424, 312138737, , 555256)
```
### Пример 3
Входные данные:
```
Введите высоту массива:
3
Введите ширину массива:
15
```
Выходные данные:
```
(975, 99434, 7225495, , 47367, 315829632, 41, 2384447777)
```
