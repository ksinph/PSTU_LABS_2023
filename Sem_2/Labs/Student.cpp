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