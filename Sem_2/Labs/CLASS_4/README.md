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
# Контрольные вопросы
1. Для чего используется механизм наследования?
Наследование позволяет структурировать и повторно использовать код и ускорить процесс разработки. Оно позволяет выделить общее для нескольких классов поведение и вынести его в отдельную сущность - базовый класс.

2. Каким образом наследуются компоненты класса, описанные со спецификатором public?
public – член класса может использоваться любой функцией, которая является членом данного или производного класса, а также к public - членам возможен доступ извне через имя объекта.

3. Каким образом наследуются компоненты класса, описанные со спецификатором private?
private – член класса может использоваться только функциями – членами данного класса и функциями – “друзьями” своего класса. В производном классе он недоступен.

4. Каким образом наследуются компоненты класса, описанные со спецификатором protected?
protected – то же, что и private, но дополнительно член класса с данным атрибутом доступа может использоваться функциями-членами и функциями – “друзьями” классов, производных от данного.

5. Каким образом описывается производный класс?
Синтаксис определения производного класса:
class имя_класса : список_базовых_классов
{список_компонентов_класса};
class Base{ //базовый класс
	…
};
class Derive: Base { //производный класс
…
};

6. Наследуются ли конструкторы?
Конструкторы не наследуются, при создании производного класса
наследуемые им данные-члены должны инициализироваться конструктором базового класса. 

7. Наследуются ли деструкторы?
Деструкторы не наследуются. Однако они вызываются, когда объект производного класса выходит из области видимости.

8. В каком порядке конструируются объекты производных классов?
Объекты класса конструируются снизу вверх: сначала базовый, потом компоненты объекты (если они имеются), а потом сам производный класс. Таким образом, объект производного класса содержит в качестве подобъекта объект базового класса.

9. В каком порядке уничтожаются объекты производных классов?
Уничтожаются объекты в обратном порядке: сначала производный, потом его компоненты-объекты, а потом базовый объект.

10. Что представляют собой виртуальные функции и механизм позднего связывания?
К механизму виртуальных функций обращаются в тех случаях, когда в каждом производном классе требуется свой вариант некоторой компонентной функции. Интерпретация каждого вызова виртуальной функции через указатель на базовый класс зависит от значения этого указателя, т.е. от типа объекта, для которого выполняется вызов.
class Base {
public:
virtual void print(){cout<<”\nBase”;}
. . .
};
class Derive : public Base {
public:
void print(){cout<<”\n Derive”;}
};
int main() {
Base B,*bp;
Derive D,*dp;
bp=&B; //указатель базового класса ставится на объект
dp=&D; //производного класса
Base *p = &D;
bp –>print(); // вызывается метод для Base
dp –>print(); // вызывается метод для Derive
p –>print(); // вызывается метод для Derive
return 0;
}

11. Могут ли быть виртуальными конструкторы? Деструкторы?
Виртуальными могут быть только нестатические функции-члены, то есть конструкторы и деструкторы не могут быть виртуальными, так как они ненаследуемы.

12. Наследуется ли спецификатор virtual?
Виртуальность наследуется. После того как функция определена как виртуальная, ее повторное определение в производном классе (с тем же самым прототипом) создает в этом классе новую виртуальную функцию, причем спецификатор virtual может не использоваться.

13. Какое отношение устанавливает между классами открытое наследование?
Открытое наследование устанавливает между классами отношение «является»: класс-наследник является частью класса-родителя. Это означает, что везде, где может быть использован объект базового класса (при присваивании, при передаче параметров и возврате результата), вместо него разрешается использовать объект производного класса.Таким образом, порожденный класс представляет собой модификацию базового класса.
class A { protected: int i; };
class B: public A {...};// i остается protected членом B
class C: public B {public:void f();};
//поскольку i является protected для B, оно может наследоваться вC 
void C::f(){ i = 2;} //данная функция работает т.к. i доступна в C

14. Какое отношение устанавливает между классами закрытое наследование?
Закрытое наследование означает, что от базового класса необходимо взять какую-то функциональность, базовый класс и потомок не имеют какой-либо концептуальной связи .Закрытое наследование не носит характера отношения подтипов. Закрытое (также как и защищенное) наследование не создает иерархии типов.
class A { protected: int i; };
class B: private A {...};// i  преобразовано к private члену B
class C: public B {public:void f();};
//поскольку i является private для B, оно не может наследоваться вC (не создается иерархии объектов)
void C::f(){ i = 2;}//  данная функция не работает т.к. i не доступна

15. В чем заключается принцип подстановки?
Принцип подстановки: класс S может считаться подклассом T, если замена объектов T на объекты S не приведёт к изменению работы программы.

16. Имеется иерархия классов:
class Student {
int age;
public:
string name;
...
};
class Employee : public Student {
protected:
string post;
...
};
class Teacher : public Employee {
protected: int stage;
...
};
Teacher x;
Какие компонентные данные будет иметь объект х?

В классе Employee открыто наследуется public name (age не наследуется, поскольку поле private). В Teacher открыто наследуется public name, и открыто наследуется protected post. Таким образом, у класса Teacher доступны следующие поля: public name, protected post, protected stage.

17. Для классов Student, Employee и Teacher написать конструкторы без параметров.
Student::Student(){
	age = 0;
	name = “NULL”; }
Employee::Employee() {
	name = “NULL”;
	post = “NULL”; }
Teacher::Teacher(){
	name = “NULL”;
	post = “NULL”;
	stage = 0; }

18. Для классов Student, Employee и Teacher написать конструкторы с параметрами.
Student::Student(int age, string name){
	this->age = age;
	this->name = name; }
Employee::Employee(string name, string spost) {
	this->name = name;
	this->post = post; }
Teacher::Teacher(string name, string post, int stage){
	this->name = name;
	this->post = post;
	this->stage = stage; }

19. Для классов Student, Employee и Teacher написать конструкторы копирования.
Student::Student(const Student& s){
	age = s.age;
	name = s.name; }
Employee::Employee(const Employee& e) {
	name = e.name;
	post = e.post; }
Teacher::Teacher(const Teacher& t){
	name = t.name;
	post = t.post;
	stage = t.stage; }
20. Для классов Student, Employee и Teacher определить операцию присваивания.
Student& Student::operator = (const& Student s) {
if (&s==this) return*this; //проверка на самоприсваивание
name = s.name;
age = s.age;
return *this; }
Employee& Employee::operator = (const& Employee e) {
if (&e==this) return*this; //проверка на самоприсваивание
name = e.name;
age = e.age;
return *this; }
Teacher& Teacher::operator = (const& Teacher t) {
if (&t==this) return*this; //проверка на самоприсваивание
name = t.name;
age = t.age;
return *this; }
