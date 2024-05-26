# Вариант задания
Лабораторная работа по классам №5, вариант 11. 
Базовый класс:

ТРОЙКА ЧИСЕЛ (TRIAD)

Первое число (first) - int

Второе число (second) - int

Третье число (third) - int

Определить методы изменения полей и увеличения полей на 1.

Создать производный класс ТІМЕ с полями часы, минуты и секунды. Переопределить методы увеличения полей на 1 и определить методы увеличения на п секунд и минут.
# Код программы
## object.h
```cpp
#include <iostream>
using namespace std;

class Object
{
public:
	Object(void);
public:
	~Object(void);
	virtual void Show() = 0;//����� ����������� �������

};
```
## object.cpp
```cpp
#include <iostream>
#include "object.h"
using namespace std;

Object::Object() {}
Object::~Object() {}
```
## triad.h
```cpp
#include "object.h"
#include <iostream>

using namespace std;

class Triad :
	public Object {
public:
	Triad(void);
public:
	virtual ~Triad(void);
	void Show() {} //������� ��� ��������� ��������� ������ � ������� ��������� 
	Triad(int, int, int);
	Triad(const Triad&);

	int getFirst() { return first; }
	int getSecond() { return second; }
	int getThird() { return third; }

	void increaseFirst();
	void increaseSecond();
	void increaseThird();

	void setFirst(int);
	void setSecond(int);
	void setThird(int);

	Triad& operator =(const Triad&);

	friend istream& operator >>(istream& in, Triad& T);
	friend ostream& operator <<(ostream& out, const Triad& T);

protected:
	int first, second, third;
};
```
## triad.cpp
```cpp
#include "triad.h"
#include <iostream>

Triad::Triad(void) {
	first = 0;
	second = 0;
	third = 0;
	cout << "������ ����������� ��� ���������� ��� ������� " << this << endl;
}
Triad::~Triad(void) {
	cout << "������ ���������� ��� ������� " << this << endl;
}

Triad::Triad(int F, int S, int T) {
	first = F;
	second = S;
	third = T;
}

Triad::Triad(const Triad& triad) {
	first = triad.first;
	second = triad.second;
	third = triad.third;
}

/*
void Triad::Show() {
	cout << "first = " << first << " second = " << second << " third = " << third << endl;
}
*/
void Triad::increaseFirst() { first++; }
void Triad::increaseSecond() { second++; }
void Triad::increaseThird() { third++; }

void Triad::setFirst(int F) {
	first = F;
}
void Triad::setSecond(int S) {
	second = S;
}
void Triad::setThird(int T) {
	third = T;
}

Triad& Triad::operator =(const Triad& triad) {
	if (&triad == this) {
		return *this;
	}
	first = triad.first;
	second = triad.second;
	third = triad.third;
	return *this;
}

istream& operator >>(istream& in, Triad& T) {
	cout << "\nFirst: "; in >> T.first;
	cout << "\nSecond: "; in >> T.second;
	cout << "\nThird: "; in >> T.third;
	return in;
}

ostream& operator <<(ostream& out, const Triad& T) {
	out << "\nFIRST: " << T.first;
	out << "\nSECOND: " << T.second;
	out << "\nTHIRD: " << T.third;
	return out;

}
```
## vector.h
```cpp
#include <iostream>
#include "object.h"

using namespace std;

class Vector {
public:
	Vector(void);
	Vector(int);
public:
	~Vector(void);
	void Add(Object*); // ���������� �������� � ������
	friend ostream& operator <<(ostream& out, const Vector&);
private:
	Object** ptr; // ��������� �� ������ ������� �������
	int size, cur; //������, ������� �������
};
```
## vector.cpp
```cpp
#include <iostream>
#include "vector.h"

using namespace std;

Vector::Vector() {
	ptr = 0;
	size = 0;
	cur = 0;
}

Vector::~Vector() {
	if (ptr != 0) {
		delete[] ptr;
	}
	ptr = 0;
}

Vector::Vector(int n) {
	ptr = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Add(Object* p) {
	if (cur < size) {
		ptr[cur] = p;
		cur++;
	}
}
ostream& operator <<(ostream& out, const Vector& v) {
	if (v.size == 0) {
		out << "EMPTY" << endl;
	}
	Object** p = v.ptr; // ��������� �� ��������� ���� Object
	for (int i = 0; i < v.cur; i++) {
		(*p)->Show(); // ����� ������  Show() (������� �����������)
		p++; // ����������� ��������� �� ��������� ������
	}
	return out;
}
```
## time.h
```cpp
#include <iostream>
#include "triad.h"

using namespace std;

class Time :
	public Triad {
public:
	Time(void);
public:
	~Time(void);
	Time(int, int, int);
	Time(const Time&);
	void Show();

	int getHour() { return hour; }
	int getMin() { return min; }
	int getSec() { return sec; }

	void increaseHour();
	void increaseMin();
	void increaseSec();

	void increaseBySec(int n);
	void increaseByMin(int n);

	void setHour(int);
	void setMin(int);
	void setSec(int);

	Time& operator =(const Time&);

	friend istream& operator >>(istream& in, Time& time);
	friend ostream& operator <<(ostream& out, const Time& time);

protected:
	int hour, min, sec;
};
```
## time.cpp
```cpp
#include <iostream>
#include "time.h"

using namespace std;

Time::Time(void) :Triad() {
	hour = 0;
	min = 0;
	sec = 0;
}

Time::~Time(void) {}
Time::Time(int h, int m, int s) :Triad(first, second, third)
{
	hour = h;
	min = m;
	sec = s;
}

Time::Time(const Time& t)
{
	first = t.first;
	second = t.second;
	third = t.third;
	hour = t.hour;
	min = t.min;
	sec = t.sec;
}

void Time::increaseHour() {
	hour++;
	if (hour > 23) {
		hour = 0;
	}
}

void Time::increaseMin() {
	min++;
	if (min > 59) {
		min = 0;
		increaseHour();
	}
}

void Time::increaseSec() {
	sec++;
	if (sec > 59) {
		sec = 0;
		increaseMin();
	}
}

void Time::increaseBySec(int n) {
	sec += n;
	while (sec > 59) {
		sec -= 60;
		increaseMin();
	}
}

void Time::increaseByMin(int n) {
	min += n;
	while (min > 59) {
		min -= 60;
		increaseHour();
	}
}

// ������������
void Time::setHour(int F) {
	first = F;
}
void Time::setMin(int S) {
	second = S;
}
void Time::setSec(int T) {
	third = T;
}



// ���������� ��������� ������������
Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	Time::hour = t.hour;
	Time::min = t.min;
	Time::sec = t.sec;
	return *this;

}
istream& operator>>(istream& in, Time& t)
{

	cout << "����: "; in >> t.hour;
	cout << "������: "; in >> t.min;
	cout << "�������: "; in >> t.sec;
	cout << "\n\n";
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{

	out << "\n" << t.hour << " � " << t.min << " ��� " << t.sec << " ��� ";

	out << "\n";
	return out;
}

void Time::Show()
{
	cout << hour << " � " << min << " ��� " << sec << " ��� " << endl;
}
```
## main.cpp
```cpp
#include <iostream>
#include "time.h"
#include "object.h"
#include "triad.h"
#include "vector.h"
using namespace std;

int main()
{
	system("chcp 1251");

	Time time;
	cin >> time;
	cout << time << endl;
	int n;
	cout << "На сколько секунд увеличить ";
	cin >> n;
	time.increaseBySec(n);
	cout << "После увеличения на " << n << " секунд : ";
	cout << time << endl;

	cout << "На сколько минут увеличить ";
	cin >> n;
	time.increaseByMin(n);
	cout << "После увеличения на " << n << " минут : ";
	cout << time << endl;
	cout << endl;
	cout << "переопределение методов увеличения на 1" << endl;
	Triad f;
	cin >> f;
	f.increaseFirst();
	f.increaseSecond();
	f.increaseThird();
	cout << f << endl;

	Vector v(5);
	Object* p = &f;
	v.Add(p);
	p = &time;
	v.Add(p);
	cout << v;
	return 0;
}
```
# Блок-схема программы
<image src="class5.drawio.svg">
	
# Тесты
<image src="Screenshot_6.png">
