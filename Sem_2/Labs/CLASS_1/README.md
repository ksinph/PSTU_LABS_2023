# Вариант задания
Лабораторная работа по классам №1, вариант 11. 
Поле first дробное положительное число, оклад, поле second - целое положительное число, количество отработанных дней. Реализовать метод summa() - вычисление начисленной суммы за данное количество дней по формуле: оклад/количество_дней_месяца* количество_отработанных_дней.
# Код программы
```cpp
﻿#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, int S, int D)
{
    fraction t;
    t.Init(F, S, D);
    return t;
}
void fraction::Init(double F, int S, int D)
{
    first = F;
    second = S;
    date = D;
}
void fraction::Read()
{
    cout << "first = ";
    cin >> first;
    cout << "second = ";
    cin >> second;
    cout << "date = ";
    cin >> date;
}

void fraction::Show()
{
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
    cout << "date = " << date << endl;
}

double fraction::Summa()
{
    return first / second * date;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    fraction A;
    A.Read();
    A.Show();

    if (A.date > 31 || A.date <= 0 || A.second > 31 || A.second <= 0)
    {
        cout << "Неподходящее значение";
    }
    else
    {
        cout << "A.Summa = " << A.Summa() << endl;
    }
    return 0;

```
# Блок-схема программы
<image src="class1.png">
	
# Тесты
### Пример 1
Входные данные:
```
first = 35000.0
second = 20
date = 30
```
Выходные данные:
```
first = 35000
second = 20
date = 30
A.Summa = 52500
```
### Пример 2
Входные данные:
```
first = 45000.500
second = 25
date = 31
```
Выходные данные:
```
first = 45000.5
second = 25
date = 31
A.Summa = 55800.6
```
### Пример 3
Входные данные:
```
first = 40000
second = 30
date = 32
```
Выходные данные:
```
first = 40000
second = 30
date = 32
Неподходящее значение
```
