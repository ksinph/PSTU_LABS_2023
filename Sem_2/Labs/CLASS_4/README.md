# Вариант задания
Лабораторная работа по классам №4, вариант 11. 
Базовый класс:
ТРОЙКА ЧИСЕЛ (TRIAD)
Первое_число (first) - int
Второе_число (second) - int
Третье_число (third) - int
Определить методы изменения полей и увеличения полей на 1.
Создать производный класс ТІМЕ с полями часы, минуты и секунды. Переопределить
методы увеличения полей на 1 и определить методы увеличения на в секунд и минут.
# Код программы
```cpp
#include <iostream>
#include "Triad.h"
#include "Time.h"
using namespace std;

//Triad
//����������� ��� ����������
Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}

//���������� 
Triad::~Triad(void)
{
}

//����������� � ����������� 
Triad::Triad(int M, int C, int P)
{
	first = M;
	second = C;
	third = P;
}

//����������� �����������
Triad::Triad(const Triad& triad)
{
	first = triad.first;
	second = triad.second;
	third = triad.third;
}

//������������
void Triad::Set_first(int M)
{
	first = M;
}
void Triad::Set_second(int C)
{
	second = C;
}
void Triad::Set_third(int P)
{
	third = P;
}

//���������� �������� ������������ 
Triad& Triad::operator=(const Triad& c)
{
	if (&c == this) return *this;
	first = c.first;
	second = c.second;
	third = c.third;
	return *this;
}

//���������� ������� ��� ����� 
istream& operator >> (istream& in, Triad& c)
{
	cout << "\nFirst:";
	in >> c.first;
	cout << "\nSecond:";
	in >> c.second;
	cout << "\nThird:";
	in >> c.third;
	return in;
}

//���������� ������� ��� ������ 
ostream& operator << (ostream& out, const Triad& c)
{
	out << "\nFIRST: " << c.first;
	out << "\nSECOND: " << c.second;
	out << "\nTHIRD: " << c.third;
	out << "\n";
	return out;
}

//Time.h
//êîíñòðóêòîð áåç ïàðàìåòðîâ
Time::Time(void) : Triad()
{
	hour = 0;
	minute = 0;
	seconds = 0;
}

//äåñòðêòîð
Time::~Time(void)
{
}

//êîíñòðóêòîð ñ ïàðàìåòðàìè
Time::Time(int G, int H, int S) :Triad(M, C, P)
{
	hour = G;
	minute = H;
	seconds = S;
}

//êîíñòðóêòîð êîïèðîâàíèÿ
Time::Time(const Time& L)
{
	first = L.first;
	second = L.second;
	third = L.third;
	hour = L.hour;
	minute = L.minute;
	seconds = L.seconds;
}

//ìîäèôèêàòîð
void Time::Set_hour(int G)
{
	hour = G;
}
void Time::Set_minute(int H)
{
	minute = H;
}
void Time::Set_seconds(int S)
{
	seconds = S;
}

//îïåðöèÿ ïðèñâàèâàíèÿ
Time& Time::operator= (const Time& l)
{
	if (&l == this) return *this;
	first = l.first;
	second = l.second;
	third = l.third;
	hour = l.hour;
	minute = l.minute;
	seconds = l.seconds;
	return *this;
}

//îïåðàöèÿ ââîäà
istream& operator>>(istream& in, Time& l)
{
	cout << "\nFirst:";
	in >> l.first;
	cout << "\nSecond:";
	in >> l.second;
	cout << "\nThird:";
	in >> l.third;
	cout << "\nHour:";
	in >> l.hour;
	cout << "\nMinute:";
	in >> l.minute;
	cout << "\nSeconds:";
	in >> l.seconds;
	return in;
}

//îïåðàöèÿ âûâîäà
ostream& operator<<(ostream& out, const Time& l)
{
	out << "\nFIRST: " << l.first;
	out << "\nSECOND: " << l.second;
	out << "\nTHIRD: " << l.third;
	out << "\nHOUR: " << l.hour;
	out << "\nMINUTE: " << l.minute;
	out << "\nSECONDS: " << l.seconds;
	out << "\n";
	return out;
}

void f1(Triad& c)
{
	c.Set_first(11);
	cout << c;
	c.Set_second(22);
	cout << c;
	c.Set_third(33);
	cout << c;
}

Triad f2()
{
	Time l(00,00,00);
	return l;
}

void main()
{
	Triad a;
	cin >> a;
	cout << a;
	Time c;
	cin >> c;
	cout << c;
	f1(c);
	a = f2();
	cout << a;
}
```
# Блок-схема программы
<image src="class4.drawio.svg">
	
# Тесты
### Пример
Входные данные:
```
First:1
Second:2
Third:3

First:6
Second:5
Third:4

Hour:8
Minute:56
Seconds:34
```
Выходные данные:
```
FIRST: 1
SECOND: 2
THIRD: 3

Hour:00
Minute:00
Seconds:00

FIRST: 6
SECOND: 5
THIRD: 4
HOUR: 8
MINUTE: 56
SECONDS: 34

FIRST: 11
SECOND: 5
THIRD: 4

FIRST: 11
SECOND: 22
THIRD: 4

FIRST: 11
SECOND: 22
THIRD: 33

FIRST: 0
SECOND: 0
THIRD: 0
```
