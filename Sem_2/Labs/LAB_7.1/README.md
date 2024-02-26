# Вариант задания
Лабараторная работа №7.1, вариант 1.
Написать перегруженные функции и основную программу,
которая их вызывает.
а) для сложения целых чисел;
б) для сложения комплексных чисел.
# Код программы
```cpp
#include <iostream>
#include<complex>
using namespace std;
complex<double> sum(complex<double> a, complex<double> b) { return a + b; }
int sum(int c, int w) { return c + w; }
int main()
{
    int c, w;
    double a1, a2;
    cin >> c;
    cin >> w;
    cin >> a1;
    cin >> a2;
    complex<double> a(a1, a2);
    complex<double> b(a2, a1);
    cout << sum(c, w);
    cout << sum(a, b);
    return 0;
}
```
# Блок-схема программы
## Функция main
<image src="lab_7.1.drawio.png">
## Функция complex sum
<image src="lab_7.1_func.drawio.png">
## Функция int sum
<image src="lab_7.1_int.drawio.png">	
# Тесты
### Пример 1
Входные данные:
```
3
5
10.20
10.23
```
Выходные данные:
```
8(20.43,20.43)
```
### Пример 2
Входные данные:
```
9
14
2.65
8
```
Выходные данные:
```
23(10.65,10.65)
```
### Пример 3
Входные данные:
```
-5
8
25.7
87.3
```
Выходные данные:
```
3(113,113)
```
