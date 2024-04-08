#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

//����������� ��� ����������
Student::Student()
{
	naime = "";
	gruppa = "";
	grades = 0;
	cout<<"Constructor bez parametrov dlia objecta "<<this<<endl;
}

//����������� � �����������
Student::Student(string N, string K, float S)
{
	naime = N;
	gruppa = K;
	grades = S;
	cout<<"Constructor s parametrami dlia objecta "<<this<<endl;
}

//����������� �����������
Student::Student(const Student& t)
{
	naime = t.naime;
	gruppa = t.gruppa;
	grades = t.grades;
	cout << "Constructor copirovania dlia objecta " << this << endl;
}

//����������
Student::~Student()
{
	cout << "Destructor dlia objecta " << this << endl;
}

//���������
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

//������������
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

//����� ��� ��������� ���������
void Student::show()
{
	cout << "naime: " << naime << endl;
	cout << "gruppa: " << gruppa << endl;
	cout << "grades:" << grades << endl;
}