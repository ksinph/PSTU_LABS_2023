#include "error.h"
#include <string>
#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

struct Node
{
    Node* next = nullptr;
    Node* prev = nullptr;
    int Data;
};


template<typename t>
class list
{
public:

    list() : elements(nullptr), num_elements(0) {}

    list(const list& other) : elements(new t[other.num_elements]), num_elements(other.num_elements)
    {
        for (int i = 0; i < num_elements; i++)
            elements[i] = other.elements[i];
    }

    list& operator=(const list& other)
    {
        if (this != &other)
        {
            delete[] elements;

            elements = new t[other.num_elements];
            num_elements = other.num_elements;

            for (int i = 0; i < num_elements; i++)
                elements[i] = other.elements[i];
        }

        return *this;
    }

    ~list() { delete[] elements; }

    t& operator[](int index)
    {
        if (index >= num_elements) throw IndexOutOfRangeError();
        if (index < 0) throw NegativeIndexError();
        return elements[index];
    }

    list& operator--()
    {
        num_elements--;
        return *this;
    }

    friend istream& operator>>(istream& in, list& list)
    {
        int num_elements;
        in >> num_elements;
        if (num_elements > MAX_SIZE) throw OverflowError();
        if (num_elements == 0) throw EmptyColletionError();

        list.elements = new t[num_elements];
        list.num_elements = num_elements;

        for (int i = 0; i < num_elements; i++)
            in >> list.elements[i];

        return in;
    }

    friend ostream& operator<<(ostream& out, const list& list)
    {
        for (int i = 0; i < list.num_elements; i++)
            out << list.elements[i] << " ";

        return out;
    }

    list<t> operator+(const list<t>& other) {
        list<t> res;
        res.num_elements = num_elements + other.num_elements;
        res.elements = new t[res.num_elements];
        for (int i = 0; i < num_elements; i++) {
            res.elements[i] = elements[i];
        }
        for (int i = 0; i < other.num_elements; i++) {
            res.elements[i + num_elements] = other.elements[i];
        }
        return res;
    }
private:
    t* elements;
    int num_elements;
};