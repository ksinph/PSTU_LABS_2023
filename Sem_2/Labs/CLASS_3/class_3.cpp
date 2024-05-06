#include "Money.h"
#include <iostream>
using namespace std;

int main()
{
	Money a;//конструктор без параметров
	Money b;//конструктор без параметров 
	
	cin>>a;//ввод переменной 
	cin>>b;//ввод переменной
	++a;//префиксная операция инкремент 
	cout<<a<<endl;//вывод переменной 
	a++;//сложение и постфиксная операция инкремент
	cout<<"a = "<<a<<endl;//вывод переменной
	cout<<"b = "<<b<<endl;//вывод переменной
	if (a > b) cout << "a > b";
	else if (a < b) cout << "a < b";
	
	return 0;
}