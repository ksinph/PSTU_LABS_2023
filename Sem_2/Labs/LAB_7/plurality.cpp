#include "plurality.h"

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
Plurality<T>::~Plurality() {
    delete[] array;
}

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
    return tmp;
}

template<class T>
T& Plurality<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        return array[index];
    }
    else {
        cout << "Îøèáêà" << endl;
    }
}
