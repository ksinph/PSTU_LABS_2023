#include <iostream>
#include <string>
using namespace std;

class Student
{
	//�������� 
	string naime; 
	string gruppa; 
	float grades;
public:
	Student();//����������� ��� ���������� 
	Student (string, string, float);//����������� � ����������� 
	Student (const Student&);//����������� ����������� 
	~Student();//����������

	string get_naime();//��������

	void set_naime(string);//�����������

	string get_gruppa();//��������

	void set_gruppa(string); //�����������

	float get_grades();//�������� 

	void set_grades (float); //�����������

	void show();//�������� ���������

};