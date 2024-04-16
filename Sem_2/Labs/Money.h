#include <iostream>
using namespace std;

class Money
{
	long rub;
	int kop;
public:
	Money() { rub = 0; kop = 0; };
	Money(long r, int k) {rub = r; kop = k;}
	Money(const Money& t) { rub = t.rub; kop = t.kop; }
	~Money() {};
	long get_rub() {return rub;}
	int get_kop() { return kop; }
	void set_rub(long r) {rub = r;}
	void set_kop(int k) { kop = k; }

	//перегруженные операции
	Money& operator=(const Money&);
	Money& operator++();
	Money operator++(int);//постфиксная операция
	Money operator+(const Money&);

	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};