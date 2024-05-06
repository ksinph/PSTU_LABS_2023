# Вариант задания
Лабораторная работа по классам №1, вариант 1. 
Создание оъектов с помощью конструкторов. Пользовательский класс студент. ФИО - string, группа - string, средний балл - float.
# Код программы
```cpp
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

//конструктор без параметров
Student::Student()
{
	naime = "";
	gruppa = "";
	grades = 0;
	cout<<"Constructor bez parametrov dlia objecta "<<this<<endl;
}
//конструктор с параметрами
Student::Student(string N, string K, float S)
{
	naime = N;
	gruppa = K;
	grades = S;
	cout<<"Constructor s parametrami dlia objecta "<<this<<endl;
}

//конструктор копирования
Student::Student(const Student& t)
{
	naime = t.naime;
	gruppa = t.gruppa;
	grades = t.grades;
	cout << "Constructor copirovania dlia objecta " << this << endl;
}

//деструктор
Student::~Student()
{
	cout << "Destructor dlia objecta " << this << endl;
}

//селекторы
string Student::get_naime()
{
	return naime;
}
string Student::get_gruppa()
{
	return gruppa;
}
float Student::get_grades()
{
	return grades;
}

//модификаторы
void Student::set_naime(string N)
{
	naime = N;
}
void Student::set_gruppa(string K)
{
	gruppa= K;
}
void Student::set_grades(float S)
{
	grades = S;
}

//метод для просмотра атрибутов
void Student::show()
{
	cout << "naime: " << naime << endl;
	cout << "gruppa: " << gruppa << endl;
	cout << "grades:" << grades << endl;
}
//функция для возврата объекта как результата 
Student make_student ()
{
	string s;
	string i;
	float d;
	cout<<"Vvedite naime: ";
	getline(cin,s);
	cout<<"Vvedite gruppu: ";
	cin>>i;
	cout<<"Vvedite grades: ";
	cin>>d;
	Student t(s, i, d);
	return t;
}

//функция для передачи объекта как параметра
void print_student(Student t)
{
	t.show();
}

void main()
{
	//конструктор без параметров
	Student t1; 
	t1.show();
	//коструктор с параметрами 
	Student t2 ("Ivanov Ivan Ivanovich", "RIS - 23 - 1b", 4.0);
	t2.show();
	//конструктор копирования 
	Student t3=t2;
	t3.set_naime("Katerinova Katya Katerinovna");
	t3.set_gruppa("EE - 20 - 1c");
	t3.set_grades(5.0);
	//конструктор копирования 
	print_student(t3);
	//конструктор копирования 
	t1=make_student(); 
	t1.show();
}
```
# Блок-схема программы
<image src="class2.png">
	
# Тесты
### Пример 1
Выходные данные:
```
naime: Ivanov Ivan Ivanovich
gruppa: RIS - 23 - 1b
grades:4
```
### Пример 2
Выходные данные:
```
naime: Katerinova Katya Katerinovna
gruppa: EE - 20 - 1c
grades:5
```
### Пример 3
Входные данные:
```
Vvedite naime: Egorov Egor Egorovich
Vvedite gruppu: IVT-23-2b
Vvedite grades: 4.5
```
Выходные данные:
```
naime: Egorov Egor Egorovich
gruppa: IVT-23-2b
grades:4.5
```
