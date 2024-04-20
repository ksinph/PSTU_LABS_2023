#include "Triad.h"

//конструктор без параметров
Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}

//деструктор 
Triad::Triad (void)
{
}

//конструктор с параметрами 
Triad::Triad(int M, int C, int P)
{
	first = M;
	second = C;
	third = P;
}

//конструктор копирования
Triad::Triad(const Triad& car)
{
	first = car.first;
	second = car.second;
	third = car.third;
}

//модификаторы
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

//перегрузка операции присваивания 
Triad& Triad::operator=(const Triad& c)
{
	if (&c == this) return *this;
	first = c.first;
	third = c.third;
	second = c.second;
	return *this;
}

//глобальная функция для ввода 
istream& operator» (istream&in,Triad&c)
{		
	cout<<"\nFirst:";
	in>>c.first;
	cout<<"\nSecond:"; 
	in >> c.second;
	cout<<"\nThird:"; 
	in >> c.third;
	return in;
}
	
//глобальная функция для вывода 
ostream& operator«(ostream& out, const Triad& c)
{
	out<<"\nFIRST: "<<c.first;
	out<<"\nSECOND: "<<c.second;
	out<<"\nTHIRD: "<<c.third;
	out<<"\n";
	return out;
}