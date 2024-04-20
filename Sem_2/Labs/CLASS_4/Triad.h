#include <string>
#include <iostream>
using namespace std;

class Triad//конструктор без параметров
{
public:
	Triad(void);
public:
	virtual ~Triad(void); //деструктор
	//констрктор с параметрами 
	Triad(int, int, int);
	// конструктор копирования
	Triad(const Triad&);
	//селекторы
	int Get_first() {return first;}
	int Get_second() {return second; }
	int Get_third() {return third;}
	//модификаторы
	void Set_first(int);
	void Set_second(int);
	void Set_third(int);
	//перегрузка операции присваивания
	Triad& operator=(const Triad&);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator»(istream& in, Triad&c);
	friend ostream& operator«(ostream& out, const Triad&c);
	//атрибуты
protected:
	int first;
	int second;
	int third;
};