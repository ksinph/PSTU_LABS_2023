#include <iostream>
#pragma once

using namespace std;

template <class T>
class Plurality {
private:
	T size;
	T* array;
public:
	Plurality(T size);
	virtual void show();
	~Plurality();
	int& operator ()();
	Plurality operator +(const Plurality& other);
	T& operator [](int index);
};

template<class T>
Plurality<T>::Plurality(T size) {
	this->size = size;
	array = new T[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100 + 1;
	}
}
template<class T>
void Plurality<T>::show() {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class T>
Plurality<T>::~Plurality() {}

template<class T>
int& Plurality<T>::operator()() {
	return size;
}

template<class T>
Plurality<T> Plurality<T>::operator+(const Plurality& other) {
	Plurality<T> tmp(size);
	for (int i = 0; i < size; i++) {
		tmp[i] = array[i] + other.array[i];
	}
	delete[]array;
	return tmp;
}

template<class T>
T& Plurality<T>::operator [](int index) {
	if (index >= 0 && index < size) {
		return array[index];
	}
	else {
		cout << "Ошибка" << endl;
	}
}
