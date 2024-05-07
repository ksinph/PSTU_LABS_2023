#include <iostream>
#include "Triad.h"
#include "Object.h"
#include "Time.h"
#include "Vector.h"
using namespace std;

int main()
{
	Triad a;
	cin >> a;
	cout << a<<endl;//вывод с помощью перегруженной операции
	Object* p = &a;
	p->Show();//вывод с помощью метода Show() и указателя

	Time b;
	cin >> b;
	cout << b << endl;//вывод с помощью перегруженной операции
	p = &b;
	p->Show();//вывод с помощью метода Show() и указателя
	
	Vector v(5);//вектор из 5 элементов
	Triad c;//объект класca Car
	cin>>c;
	Time d;// объект класса Lorry
	cin>>d;
	p = &c;
	/*Object* p = &c;//ставим указатель на объект класса Car */
	v.Add(p);//добавляем объект в вектор
	p = &d;//ставим указатель на объект класса Lorry 
	v.Add(p); //добавляем объект в вектор
	cout<<v;//вывод вектора*/
	return 0;
}