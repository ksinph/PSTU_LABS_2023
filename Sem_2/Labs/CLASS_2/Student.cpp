#include "Student.h"
#include <iostream>
#include <string>
using namespace std;
setlocale(LC_ALL,"Russian");
//êîíñòðóêòîð áåç ïàðàìåòðîâ
Student::Student()
{
	naime = "";
	gruppa = "";
	grades = 0;
	cout<<"Constructor bez parametrov dlia objecta "<<this<<endl;
}

//êîíñòðóêòîð ñ ïàðàìåòðàìè
Student::Student(string N, string K, float S)
{
	naime = N;
	gruppa = K;
	grades = S;
	cout<<"Constructor s parametrami dlia objecta "<<this<<endl;
}

//êîíñòðóêòîð êîïèðîâàíèÿ
Student::Student(const Student& t)
{
	naime = t.naime;
	gruppa = t.gruppa;
	grades = t.grades;
	cout << "Constructor copirovania dlia objecta " << this << endl;
}

//äåñòðóêòîð
Student::~Student()
{
	cout << "Destructor dlia objecta " << this << endl;
}

//ñåëåêòîðû
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

//ìîäèôèêàòîðû
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

//ìåòîä äëÿ ïðîñìîòðà àòðèáóòîâ
void Student::show()
{
	cout << "naime: " << naime << endl;
	cout << "gruppa: " << gruppa << endl;
	cout << "grades:" << grades << endl;
}
