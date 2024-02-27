# Вариант задания
Посчитать числа Фибоначчи.
# Код программы
```cpp
#include <iostream>
using namespace std;
int fib(int n)
{
	if (n<=1)
	{
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<=n;i++)
	{
		cout << fib(i)<<" ";
	}
	return 0;
}
```
# Блок-схема программы
## Функция main
<image src="lab_rec_main.drawio.png">

## Функия fib
<image src="lab_fib_fib.drawio.png">
		
# Тесты
### Пример 1
Входные данные:
```
6
```
Выходные данные:
```
0 1 1 2 3 5 8
```
### Пример 2
Входные данные:
```
4
```
Выходные данные:
```
0 1 1 2 3
```
### Пример 3
Входные данные:
```
9
```
Выходные данные:
```
0 1 1 2 3 5 8 13 21 34
```
