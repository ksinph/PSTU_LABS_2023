#include <iostream>
#include "Triad.h"
using namespace std;

//����������� ��� ����������
Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}

//���������� 🐱‍🏍🐱‍🏍🐱‍🏍
Triad::~Triad(void)
{
}

//����������� � ����������� 
Triad::Triad(int M, int C, int P)
{
	first = M;
	second = C;
	third = P;
}

//����������� �����������
Triad::Triad(const Triad& triad)
{
	first = triad.first;
	second = triad.second;
	third = triad.third;
}

//������������
void Triad::Set_first(int M)
{
	first = M;
}
void Triad::Set_second(int C)
{
	second = C;
}
void Triad::Set_third(int P)
{
	third = P;
}

//���������� �������� ������������ 
Triad& Triad::operator=(const Triad& c)
{
	if (&c == this) return *this;
	first = c.first;
	second = c.second;
	third = c.third;
	return *this;
}

//���������� ������� ��� ����� 
istream& operator >> (istream& in, Triad& c)
{
	cout << "\nFirst:";
	in >> c.first;
	cout << "\nSecond:";
	in >> c.second;
	cout << "\nThird:";
	in >> c.third;
	return in;
}

//���������� ������� ��� ������ 
ostream& operator << (ostream& out, const Triad& c)
{
	out << "\nFIRST: " << c.first;
	out << "\nSECOND: " << c.second;
	out << "\nTHIRD: " << c.third;
	out << "\n";
	return out;
}

/*void Triad::Show()
{
	cout << "\nFIRST: " << first;
	cout << "\nSECOND: " <<second;
	cout << "\nTHIRD: " << third;
	cout << "\n";
}*/