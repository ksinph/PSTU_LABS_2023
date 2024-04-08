#include <iostream>
#include <string>
using namespace std;

class Student
{
	//атрибуты 
	string naime; 
	string gruppa; 
	float grades;
public:
	Student();//конструктор без параметров 
	Student (string, string, float);//конструктор с параметрами 
	Student (const Student&);//конструктор копирования 
	~Student();//деструктор

	string get_naime();//селектор

	void set_naime(string);//модификатор

	string get_gruppa();//селектор🐱‍👓🐱‍👓🐱‍👓

	void set_gruppa(string); //модификатор

	float get_grades();//селектор 

	void set_grades (float); //модификатор

	void show();//просмотр атрибутов

};