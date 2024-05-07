﻿#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class List;//дружественный класс
public:
	Iterator() { elem = 0; }//конструктор без параметров🐱‍🚀🐱‍🚀🐱‍🚀
	Iterator(const Iterator& it) { elem = it.elem; } //конструктор копирования
	//перегруженные операции сравнения
	bool operator==(const Iterator& it) { return elem == it.elem; };
	bool operator!=(const Iterator& it) {return elem != it.elem;};
	//перегруженная операция инкремент
	void operator++(int) { ++elem; };
	//перегруженная операция декремент
	void operator--() { --elem; }
	//перегруженная операция разыменования
	int& operator *() const { return*elem; }
private:
	int* elem;//указатель на элемент типа int
};

class List 
{
public:
	//конструктор с параметрами: выделяет память под в элементов и заполняет их значением к
	List(int s, int k = 0);
	//конструктор с параметрами 
	List (const List&a);
	//деструктор 
	~List();
	//оператор присваивания 
	List&operator=(const List&a);
	//операция доступа по индексу 
	int&operator[] (int index); 
	//операция для добавление константы
	List operator+(const int k);
	//операция, возвращающая длину вектора 
	int operator()();
	//перегруженные операции ввода-вывода 
	friend ostream& operator<<(ostream& out, const List&a); 
	friend istream& operator>> (istream& in, List&a);
	Iterator first() { return beg; }//возвращает указатель на первый элемент 
	Iterator last() { return end; }//возвращает указатель на элемент следующий за последним
private:
	int size;//размер вектора
	int* data;//укзатель на динамический массив значений вектора
	Iterator beg;//указатель на первый элемент вектора
	Iterator end;//указатель на элемент следующий за последним
};