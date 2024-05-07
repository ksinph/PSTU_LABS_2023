#pragma once
#include <iostream>
#include "object.h"
using namespace std;

class Triad://����������� ��� ����������
	public Object
{
public:
	Triad(void);
public:
	virtual ~Triad(void); //����������
	void Show() {};//функция для просмотра атрибутов класса с помощью указателя**/
	//���������� � ����������� 
	Triad(int, int, int);
	// ����������� �����������
	Triad(const Triad&);
	//���������
	int Get_first() { return first; }
	int Get_second() { return second; }
	int Get_third() { return third; }
	//������������
	void Set_first(int);
	void Set_second(int);
	void Set_third(int);
	//���������� �������� ������������
	Triad& operator=(const Triad&);
	//���������� ���������-������� �����-������
	friend istream& operator>>(istream& in, Triad& c);
	friend ostream& operator<<(ostream& out, const Triad& c);
	//��������
protected:
	int first;
	int second;
	int third;
};
