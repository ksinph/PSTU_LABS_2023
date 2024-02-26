# Вариант задания
Лабораторная работа №6, вариант 1.
Проверить является ли строка палиндромом. (Палиндром -
это выражение, которое читается одинаково слева направо
и справа налево).
# Код программы
```cpp
#include <iostream>
#include <cstring>
using namespace std;
bool gets(string s)
{
    int len =s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    char s[255];
    cin >> s;
    if(gets(s))
    {
        cout << " является палиндромом";
    }
    else
    {
        cout << " не является палиндромом";
    }
}
```
# Блок-схема программы
## Функция main
<image src="LAB_6.drawio.png">
## Функция gets
<image src="lab_6_func.drawio.png">	
# Тесты
### Пример 1
Входные данные:
```
polop
```
Выходные данные:
```
 является полиндромом
```
### Пример 2
Входные данные:
```
polindrom
```
Выходные данные:
```
 не является полиндромом
```
### Пример 3
Входные данные:
```
11111
```
Выходные данные:
```
 является полиндромом
```
