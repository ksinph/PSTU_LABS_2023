#include <iostream>
#include <string>
using namespace std;

class Student
{
	//àòðèáóòû 
	string naime; 
	string gruppa; 
	float grades;
public:
	Student();//êîíñòðóêòîð áåç ïàðàìåòðîâ 
	Student (string, string, float);//êîíñòðóêòîð ñ ïàðàìåòðàìè 
	Student (const Student&);//êîíñòðóêòîð êîïèðîâàíèÿ 
	~Student();//äåñòðóêòîð

	string get_naime();//ñåëåêòîð

	void set_naime(string);//ìîäèôèêàòîð

	string get_gruppa();//ñåëåêòîð

	void set_gruppa(string); //ìîäèôèêàòîð

	float get_grades();//ñåëåêòîð 

	void set_grades (float); //ìîäèôèêàòîð

	void show();//ïðîñìîòð àòðèáóòîâ

};
