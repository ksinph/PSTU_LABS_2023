#pragma once
#include <iostream>

using namespace std;

template <class T>
class Plurality {
private:
    T size;
    T* array;

public:
    Plurality(T size);
    void show();
    ~Plurality();
    int& operator()();
    Plurality operator+(const Plurality& other);
    T& operator[](int index);
};
