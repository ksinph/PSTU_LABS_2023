# Вариант задания
Посчитать факториал.
<image src="lab_sum_png.drawio.png">

# Код программы
```cpp
#include <iostream>
#include <math.h>
using namespace std;
int factorial(int n)
{
	if (n < 2) { return 1; }
	return n * factorial(n - 1);
}
int fib(int n,int x)
{
	return 1+(pow(log(3),n)/factorial(n))*pow(x,n);
}
int main()
{
	int n,x;
	cin >> n>>x;
	cout << fib(n,x) << " ";
	
	return 0;
}
```
# Блок-схема программы
<image src="lab_sum.drawio.png">
	
# Тесты
### Пример 1
Входные данные:
```
4
2
```
Выходные данные:
```
1
```
### Пример 2
Входные данные:
```
12
6
```
Выходные данные:
```
15
```
### Пример 3
Входные данные:
```
23
7
```
Выходные данные:
```
-2147483648
```
