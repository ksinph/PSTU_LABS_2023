﻿#include "Money.h"
#include <iostream>
using namespace std;

//перегрузка операции присваивания🐱‍👤🐱‍👤🐱‍👤
Money&Money::operator=(const Money&t)
{
	//проверка на самоприсваивание 
	if(&t==this) return *this; 
	rub=t.rub; 
	kop=t.kop; 
	return *this;
}
bool Money::operator<(const Money& t)
{
	if (rub < t.rub) return true;
	if (t.rub < rub) return false;
	return kop > t.kop;
}

bool Money::operator>(const Money& t)
{
	if (rub > t.rub) return true;
	if (t.rub > rub) return false;
	return kop < t.kop;
}

//перегрузка префиксной операции инкремент 
Money& Money:: operator++()
{
	int temp = rub * 100 + kop;
	temp++;
	rub = temp / 100;
	kop = temp % 100;
	return *this;
}
	
//перегрузка постфиксной операции инкремент 
Money Money:: operator ++ (int)
{
	int temp = rub * 100 + kop;
	temp++; 
	Money t(rub, kop);
	rub = temp / 100;
	kop = temp % 100;
	return t;
} 

//перегрузка глобальной функции-операции ввода 
istream&operator>>(istream&in, Money&t)
{
	cout<<"rub?"; in>>t.rub; 
	cout<<"kop?"; in>>t.kop; 
	return in;
}

//перегрузка глобальной функции-операции вывода
ostream&operator<<(ostream&out, const Money&t)
{
	return (out<<t.rub<<" , "<<t.kop);
}