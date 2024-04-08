#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

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
