# Вариант задания
Лабораторная работа по классам №8, вариант 11. 
Базовый класс:

ЧЕЛОВЕК (Person)

Имя - string

Возраст - int

Производный класс

СТУДЕНТ (Student)

Рейтинг float

Группа - Дерево (Тгее).

Команды:

Создать группу (формат команды: т количество элементов группы).

Добавить элемент в группу (формат команды: +)

Удалить элемент из группы (формат команды -)

Вывести информацию об элементах группы (формат команды: s)

Вывести информацию об элементе группы (формат команды:? номер объекта в группе)

Конец работы (формат команды: q)

# Код программы
```cpp
#include <iostream>
#include "dialog.h"
#include "vector.h"
#include "student.h"
using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmFind = 7;
const int cmQuit = 101;

struct TEvent {
    int what;
    union {
        int command;
        struct {
            int message;
            int a;
        };
    };
};

class Object
{
public:
	Object(void) {};
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object(void) {};
	virtual void HandleEvent(const TEvent& e) = 0;
};

class Person : public Object {
protected:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);
	Person(const Person& p);
	virtual ~Person();
	string get_name();
	int get_age();
	void set_name(string name);
	void set_age(int age);
	Person& operator =(const Person& p);
	void Show();
	void Input();
	void HandleEvent(const TEvent& r);
};

Person::Person() {
	name = " ";
	age = 0;
}

Person::Person(string N, int A) {
	name = N;
	age = A;
}

Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}

Person::~Person() {}

string Person::get_name() { return name; }

int Person::get_age() { return age; }

void Person::set_name(string N) { name = N; }

void Person::set_age(int A) { age = A; }

Person& Person::operator=(const Person& person) {
	if (&person == this) { return *this; }
	name = person.name;
	age = person.age;
	return *this;
}

void Person::Show() {
	cout << "\nPerson name: " << name << endl;
	cout << "\nPerson age: " << age << endl;
}

void Person::Input() {
	cout << "\nEnter name: "; cin >> name;
	cout << "\nEnter age: "; cin >> age;
}

void Person::HandleEvent(const TEvent& r) {
	if (r.what == evMessage) {
		switch (r.command) {
		case cmGet:cout << "Автор = " << this->get_age() << endl;
			cout << "Имя = " << this->get_name() << endl;
			break;
		}
	}
}

class Student : public Person {
protected:
	float rating;
public:
	Student();
	Student(string name, int age, float rating);
	Student(const Student& s);
	~Student();
	float get_rating() { return rating; }
	void set_rating(float rating);
	void Show();
	void Input();
	Student& operator=(const Student&);
};

Student::Student() { rating = 0; }
Student::~Student() {}
void Student::Show() {
	cout << "\nStudent name: " << name << "\n";
	cout << "\nStudent age: " << age << "\n";
	cout << "\nStudent rating: " << rating << "\n";
}

void Student::Input() {
	cout << "\nEnter student name: "; cin >> name;
	cout << "\nEnter student age: "; cin >> age;
	cout << "\nEnter student rating: "; cin >> rating;
}

Student::Student(string N, int A, float R) {
	name = N;
	age = A;
	rating = R;
}

Student::Student(const Student& student) {
	name = student.name;
	age = student.age;
	rating = student.rating;
}
Student& Student::operator=(const Student& student) {
	if (&student == this) { return *this; }
	name = student.name;
	age = student.age;
	rating = student.rating;
	return *this;
}
void Student::set_rating(float R) {
	rating = R;
}

class Dialog :
	public Vector {
protected:
	int EndState;
public:
	Dialog();
	virtual ~Dialog();
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
};

Dialog::Dialog(void) : Vector() {
	EndState = 0;
}

Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event) {
	string OpInt = "+-s?qm";
	string s;
	string param;

	char code;
	cout << '>';
	cin >> s;
	code = s[0];
	if (OpInt.find(code) >= 0) {
		event.what = evMessage;
		switch (code) {
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'q': event.command = cmQuit; break;
		case '?': event.command = cmFind; break;
		}
		if (s.length() > 1) {
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else { event.what = evNothing; }
}
int Dialog::Execute() {
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}
int Dialog::Valid() {
	if (EndState == 0) { return 0; }
	else { return 1; }
}
void Dialog::ClearEvent(TEvent& event) { event.what = evNothing; }
void Dialog::EndExec() { EndState = 1; }
void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake:
			cout << "Enter size: ";
			cin >> size;
			beg = new Object * [size];
			cur = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del();
			ClearEvent(event);
			break;
		case cmShow:
			Show();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		case cmFind:
			int tmp = event.a;
			Find(tmp);
			ClearEvent(event);
			break;
			//default:Vector::HandleEvent(event);
		}
	}
}

class Vector
{
public:
	Vector(int);//конструктор с параметрами
public:
	~Vector(void);//деструктор
	Vector();
	void Add();//добавление элемента в вектор 👨🏻‍💻👨🏻‍💻👨🏻‍💻
	void Del();
	void Show();
	void Find(int);
	int operator()();//размер вектора
	void HandleEvent(const TEvent& y) {
		if (y.what == evMessage) {
			Object** p = this->beg;
			for (int i = 0; i < this->cur; i++) {
				(*p)->HandleEvent(y);
				p++;
			}
		}
	};
protected:
	Object** beg;//указатель на первый элемент вектора 
	int size;//размер
	int cur;//текущая позиция
};

Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

Vector::Vector() {
	beg = nullptr;
	cur = 0;
	size = 0;
}

//конструктор с параметрами 
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор 	
void Vector::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов 
	cout << "\n1.Person\n2.Student\nnВведите номер выбранного варианта >> ";
	int y;
	cin >> y; cout << "\n";
	if (y == 1)//добавление объекта класса 
	{
		Person* a = new Person();
		a->Input();//ввод значений атрибутов
		p = a;

		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор cur++;
			cur++;
		}
	}
	else if (y == 2) //добавление объекта класса
	{
		Student* b = new Student();
		b->Input();
		p = b;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}

//просмотр вектора
void Vector::Show()
{
	if (cur == 0) cout << "Пустой" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание) 
		p++;//передвигаем указатель на следующий объект
	}

}
void Vector::Find(int tmp) {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		if (i == tmp - 1) { (*p)->Show(); }
		p++;
	}
}

//операция, которая возвращает размер вектора 
int Vector::operator ()()
{
	return cur;
}
//удаление элемента из вектора, память не освобождается! 
void Vector::Del()
{
	if (cur == 0)return;//пустой
	cur--;
}

int main()
{
    system("chcp 1251");
    cout << "m: создать группу" << endl;
    cout << "+: добавить элемент в группу" << endl;
    cout << "-: удалить элемент из группы" << endl;
    cout << "s: вывести информацию об элементах группы" << endl;
    cout << "?: вывести информацию об элементе группы" << endl;
    cout << "q: конец работы" << endl;
    Dialog D;
    D.Execute();
    return 0;
}
```
# Блок-схема программы
<image src="class8.png">
	
# Тесты
### Пример 1
<image src="Screenshot_1.png">
