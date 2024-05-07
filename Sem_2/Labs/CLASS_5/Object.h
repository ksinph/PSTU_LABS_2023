#pragma once
#include <iostream>
using namespace std;

class Object
{
public:
	Object(void) {};
public:
	~Object(void) {};
	virtual void Show() = 0;//чисто виртуальная функция
};