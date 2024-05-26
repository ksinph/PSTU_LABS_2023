# Вариант задания
Лабораторная работа по классам №7, вариант 11. 
Класс- контейнер СПИСОК с ключевыми значениями типа int.

Реализовать операции:

[]- доступа по индексу;

int() - определение размера списка;

+ вектор сложение элементов списков а[i]+b[i];

Пользовательский класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой.
# Код программы
```cpp
#include <iostream>
#include "plurality.h"
#include "money.h"

using namespace std;

class Money
{
public:
	Money(void);
	Money(long, int);
	Money(const Money&);
	Money& operator=(const Money&);

	friend ostream& operator<<(ostream& out, const Money&);
	friend istream& operator>>(istream& in, Money&);
	virtual ~Money(void) { rubles = 0; kop = 0; };

	void operator!=(const Money& t);
private:
	long rubles;
	int kop;
};

Money::Money(void)
{
	rubles = 0;
	kop = 0;
}

Money::Money(long r, int k)
{
	rubles = r;
	kop = k;
}

Money::Money(const Money& t)
{
	rubles = t.rubles;
	kop = t.kop;
}

Money& Money::operator=(const Money& t)
{
	rubles = t.rubles;
	kop = t.kop;
	return *this;
}

ostream& operator<<(ostream& out, const Money& t)
{
	out << t.rubles << " , " << t.kop;
	return out;
}

istream& operator>>(istream& in, Money& t)
{
	cout << "Введите рубли: "; in >> t.rubles;
	cout << "Введите копейки: "; in >> t.kop;
	return in;
}

void Money::operator!=(const Money& t)
{
	if (rubles == t.rubles && kop == t.kop) cout << "Равны" << endl;
	else cout << "Не равны" << endl;
}

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

int main() {
	system("chcp 1251");
	int size;
	cout << "Введите размер списка: " << endl;
	cin >> size;
	Plurality<int> A(size);
	cout << "Список A: "; A.show();
	int k;
	cout << "Введите индекс: " << endl;
	cin >> k;
	cout << "A[k] элемент: " << A[k] << endl;
	cout << "Размер списка A: " << A() << endl;
	cout << endl;
	cout << "Введите размер списка: " << endl;
	cin >> size;
	Plurality<int> B(size);
	cout << "Список B: "; B.show();
	cout << "Размер списка B: " << B() << endl;
	cout << endl;

	Plurality<int> C(size);
	C = A + B;
	cout << "Список C = A + B: "; C.show();
	cout << "Размер списка C: " << C() << endl;
	cout << endl;

	cout << "Тестирование класса Money:" << endl;

	Money t1;
	cin >> t1;
	cout << "Первый экземпляр класса Money:" << endl;
	cout << t1; cout << endl;

	Money t2;
	cin >> t2;
	cout << "Второй экзепляр класса Money: " << endl;
	cout << t2; cout << endl;

	cout << "Проверка их на неравенство: " << endl;
	t1 != t2;

	return 0;
}
```
# Блок-схема программы
<image src="class7.png">
	
# Тесты
### Пример 1
Входные данные:
```
Введите размер списка:
0
Введите индекс:
1
```
Выходные данные:
```
Ошибка
```
### Пример 2
Входные данные:
```
Введите размер списка:
4
Введите индекс:
1
Введите рубли: 32
Введите копейки: 56
Введите рубли: 12
Введите копейки: 34
```
Выходные данные:
```
Список A: 42 68 35 1
A[k] элемент: 68
Размер списка A: 4

Введите размер списка:
4
Список B: 70 25 79 59
Размер списка B: 4

Список C = A + B: 112 93 114 60
Размер списка C: 4

Тестирование класса Money:

Первый экземпляр класса Money:
32 , 56

Второй экзепляр класса Money:
12 , 34
Проверка их на неравенство:
Не равны
```
### Пример 3
Входные данные:
```
Введите размер списка:
3
Введите индекс:
2
Введите рубли: 23
Введите копейки: 34
Введите рубли: 23
Введите копейки: 34
```
Выходные данные:
```
Список A: 42 68 35
A[k] элемент: 35
Размер списка A: 3
Список B: 1 70 25
Размер списка B: 3
Проверка их на неравенство:
Равны
```
