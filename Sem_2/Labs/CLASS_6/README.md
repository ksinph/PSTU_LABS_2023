# Вариант задания
Лабораторная работа по классам №6, вариант 11. 
Класс- контейнер СПИСОК с ключевыми значениями типа int.
Реализовать операции:
[] доступа по индексу;
int() - определение размера списка;
вектор сложение элементов списков а[i]+b[i];
п - переход влево к элементу с номером п (с помощью класса-итератора).
# Код программы
```cpp
#include <iostream>
#include "List.h"
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

#include <iostream>
#include "List.h"
using namespace std;

List::List(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++) 
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}

//конструктор копирования
List::List(const List& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}

//деструктор
List::~List()
{
	delete[] data;
	data = 0;
}

//операция присваивания 
List&List::operator=(const List&a)
{
	if (this == &a) return *this;
	size = a.size; 
	if (data != 0) delete[] data;
	data = new int[size]; 
	for (int i = 0; i < size; i++) 
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
	return *this;
}

//операция доступа по индексу 
int&List::operator [] (int index)
{
	if (index < size) return data[index];
	else
	{
		cout << "\nError! Index>size";
		return data[0];
	}
}

//операция для сложения  
List List::operator+(const int k)//+k
{
	List temp(size);
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] + k;
	return temp;
}

//операция для получения длины вектора 
int List::operator () ()
{
	return size;
}

//операции для ввода-выода
ostream& operator<<(ostream& out, const List& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, List& a)
{
	for (int i = 0; i < a.size; ++i)
		in>>a.data[i];
	return in;
}

int main()
{
	List a(5);//создали вектор из 5 элементов, заполненный нулями
	cout<<a<<"\n"; //вывели значения элементов вектора 
	cin>>a;//ввели с клавиатуры значения элементов вектора
	cout<<a<<"\n"; //вывели значения элементов вектора
	a[2]=100;//используя операцию [] присвоили новое значение элементу
	cout<<a<<"\n"; //вывели значения элементов вектора 
	List b(10); //создали вектор ь из 10 элементов, заполненный нулями 
	cout<<b<<"\n"; //вывели значения элементов вектора
	b = a;//присвоили вектору в значения вектора а
	cout << b << "\n"; //вывели значения элементов вектора
	List c(10); //создали вектор с из 10 элементов, заполненный нулями 
	c=b+100;//Увеличили значения вектора в на 100 и присвоили вектору с 
	cout<<c<<"\n"; //вывели значения элементов вектора с 
	cout<<"\nthe length of a = "<<a()<<endl; //вывели длину вектора а

	//разыменовываем значение, которое возвращает a.first() и выводим его 
	cout<<*(a.first())<<endl;
	// переменную типа Iterator устанавливаем на первый элемент вектора а с помощью метода first
	Iterator i=a.first();
	//оперция инкремент
	i++;
	//разыменовываеи итератор и выводи его значение 
	cout<<*i<<endl;
	//выводим значения элеменов вектора с помощью итератора 
	for(i=a.first();i!=a.last();i++) cout<<*i<<endl;
	return 0;
}
```
# Блок-схема программы
<image src="class6.drawio.svg">
	
# Тесты
### Пример
Входные данные:
```
Vvedite znachenia:
1
2
3
4
5
```
Выходные данные:
```
0 0 0 0 0
Spisok 1: 1 2 3 4 5
Znachenia elementov: 1 2 100 4 5
Spisok 2: 0 0 0 0 0 0 0 0 0 0
Znachenia elementov: 1 2 100 4 5
Znachenia elementov posle summ: 101 102 200 104 105

the length of a = 5
Razymenovanie zyachenia a: 1
Iterator: 2
Znachenia elementov: 1
Znachenia elementov: 2
Znachenia elementov: 100
Znachenia elementov: 4
Znachenia elementov: 5
```
