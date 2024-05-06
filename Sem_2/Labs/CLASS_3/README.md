# Вариант задания
Лабораторная работа по классам №1, вариант 11. 
Использование перегруженных операций в классах.Создать класс Моnеу для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
операции сравнения (<, >).
добавление копеек (++) (постфиксная и префиксная формы)
# Код программы
```cpp
#include "Money.h"
#include <iostream>
using namespace std;

//перегрузка операции присваивания🐱‍👤🐱‍👤🐱‍👤
Money&Money::operator=(const Money&t)
{
	//проверка на самоприсваивание 
	if(&t==this) return *this; 
	rub=t.rub; 
	kop=t.kop; 
	return *this;
}
bool Money::operator<(const Money& t)
{
	if (rub < t.rub) return true;
	if (t.rub < rub) return false;
	return kop > t.kop;
}

bool Money::operator>(const Money& t)
{
	if (rub > t.rub) return true;
	if (t.rub > rub) return false;
	return kop < t.kop;
}

//перегрузка префиксной операции инкремент 
Money& Money:: operator++()
{
	int temp = rub * 100 + kop;
	temp++;
	rub = temp / 100;
	kop = temp % 100;
	return *this;
}
	
//перегрузка постфиксной операции инкремент 
Money Money:: operator ++ (int)
{
	int temp = rub * 100 + kop;
	temp++; 
	Money t(rub, kop);
	rub = temp / 100;
	kop = temp % 100;
	return t;
} 

//перегрузка глобальной функции-операции ввода 
istream&operator>>(istream&in, Money&t)
{
	cout<<"rub?"; in>>t.rub; 
	cout<<"kop?"; in>>t.kop; 
	return in;
}

//перегрузка глобальной функции-операции вывода
ostream&operator<<(ostream&out, const Money&t)
{
	return (out<<t.rub<<" , "<<t.kop);
}

int main()
{
	Money a;//конструктор без параметров
	Money b;//конструктор без параметров 
	
	cin>>a;//ввод переменной 
	cin>>b;//ввод переменной
	++a;//префиксная операция инкремент 
	cout<<a<<endl;//вывод переменной 
	a++;//сложение и постфиксная операция инкремент
	cout<<"a = "<<a<<endl;//вывод переменной
	cout<<"b = "<<b<<endl;//вывод переменной
	if (a > b) cout << "a > b";
	else if (a < b) cout << "a < b";
	
	return 0;
}
```
# Блок-схема программы
<image src="class3.drawio.svg">
	
# Тесты
### Пример 1
Входные данные:
```
rub?230
kop?45
rub?654
kop?6
```
Выходные данные:
```
230 , 46
a = 230 , 47
b = 654 , 6
a < b
```
### Пример 2
Входные данные:
```
rub?654
kop?6
rub?230
kop?45
```
Выходные данные:
```
654 , 7
a = 654 , 8
b = 230 , 45
a > b
```
### Пример 3
Входные данные:
```
rub?0
kop?0
rub?0
kop?0
```
Выходные данные:
```
0 , 1
a = 0 , 2
b = 0 , 0
a > b
```
