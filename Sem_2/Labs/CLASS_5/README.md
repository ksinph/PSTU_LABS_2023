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
# Контрольные вопросы
1. Какой метод называется чисто виртуальным? Чем он отличается от виртуального метода?
Чисто виртуальный метод - виртуальная функция, не имеющая определения в базовом классе. Для страховки от неправильного вызова ее часто объявляют равной нулю: virtual <тип> <имя функции> (<список параметров>) = 0; Чисто виртуальный метод должен переопределяться в производном классе (возможно, опять как чисто виртуальный). Переопределение происходит с помощью спецификатора override (он не обязателен).

2. Какой класс называется абстрактным?
Абстрактный класс - класс, содержащий хотя бы один чисто виртуальный метод.

3. Для чего предназначены абстрактные классы?
Используется как обобщенная концепция, которая используется для создания конкретных производных классов. Создание объектов абстрактного класса невозможно, однако можно использовать указатели и типы на типы абстрактных классов. Абстрактные классы нельзя использовать для приведения типов, но допускается объявление ссылок и указателей, если абстрактный класс имеет наследников. Если производный класс не определяет все чисто виртуальные функции, он также является абстрактным
Пример: 
Нужно сделать для класса TextFile базовый класс File, от которого будет унаследован еще один класс RTFFile. Однако, в такой ситуации неизвестно как реализовать метод read() класса File, т.к. класс File не реализует поведение какого-то конкретного типа файлов, а представляет интерфейс для работы с различными файлами. Для этого используется чисто виртуальная функция.
class File {
        virtual string read(int count) = 0;
};
Метод read(...) должен быть определен в классах наследниках. Теперь класс File стал абстрактным, и его экземпляры невозможно создать. Но можно работать через указатель на абстрактный класс с объектами производных классов.
File *f = new TextFile("text.txt");
//различные действия с файлом text.txt
delete f;
f = new RTFFile("rich_text.rtf");
//различные действия с файлом rich_text.rtf
delete f;

4. Что такое полиморфные функции?
При работе с абстрактными классами можно создать функцию, параметром которой будет являться указатель на абстрактный класс. Туда может передаваться указатель на объект любого производного класса, что позволяет создать полиморфные функции, то есть функции, работающие с объектом любого типа в пределах одной иерархии.
class Base {
        virtual void work() = 0;
};
class Derived : Base {...};

void print(Base*a){ cout << “Hello!”}

//в основной функции
Derived *t = new Derived;
print(t); //хотя в функцию передается базовый файл в качестве аргумента.

5. Чем полиморфизм отличается от принципа подстановки?
Полиморфизм - это возможность классов иметь разную реализацию одного и того же функционала в основном с помощью наследования. Это механизм работы языка программирования.
Принцип подстановки является “правилом хорошего кода". В хорошем коде все методы класса-потомка должны быть применимы к объекту класса родителя.

6. Привести примеры иерархий с использованием абстрактных классов.
class Shape {
public:
    virtual double getSquare() const = 0;     // площадь фигуры
    virtual double getPerimeter() const = 0;  // периметр фигуры
};
class Rectangle : public Shape { // класс прямоугольника
public:
    Rectangle(double w, double h) : width(w), height(h) { }
    double getSquare() const override {
        return width * height;
    }
    double getPerimeter() const override {
        return width * 2 + height * 2;
    }
private:
    double width;   // ширина
    double height;  // высота
};
class Circle : public Shape {    // круг
public:
    Circle(double r) : radius(r) { }
    double getSquare() const override {
        return radius * radius * 3.14;
    }
    double getPerimeter() const override {
        return 2 * 3.14 * radius;
    }
private:
    double radius;  // радиус круга
};

# Блок-схема программы
<image src="class5.drawio.svg">
	
# Тесты
<image src="5.png">
