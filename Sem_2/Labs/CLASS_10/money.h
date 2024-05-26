#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Money {
	int rub;
	long kop;
public:
	Money() { 
		this->rub = 0;
		this->kop = 0;
	}
	Money(int rub, long kop) { 
		this->rub = rub;
		this->kop = kop;
	}
	Money(const Money& other) { 
		this->rub = other.rub;
		this->kop = other.kop;
	}
	~Money() { } 
	Money operator/(const int& x) {
		return (Money(this->rub / x, this->kop));
	}

	Money& operator++() { 
		Money x(this->rub++, this->kop);
		return x;
	}
	Money operator ++(int) { 
		Money x(this->rub, this->kop++);
		return x;
	}
	bool operator<(const Money& para) { 
		if (this->rub < para.rub) return true;
		else if (this->rub == para.rub) {
			if (this->kop < para.kop) return true;
			else return false;
		}
		else return false;
	}
	bool operator>(const Money& para) { 
		if (this->rub < para.rub) return false;
		else if (this->rub == para.rub) {
			if (this->kop < para.kop) return false;
			else return true;
		}
		else return true;
	}
	void operator=(const Money& para) { 
		this->rub = para.rub;
		this->kop = para.kop;
	}
	friend ostream& operator <<(ostream& stream, const Money& p) {
		stream << p.rub << " , " << p.kop;
		return stream;
	}
	friend istream& operator >>(istream& stream, Money& p) {
		cout << "¬ведите число rub и kop через пробел: ";
		stream >> p.rub >> p.kop;
		return stream;
	}
	friend fstream& operator<<(fstream& stream, Money& para) {
		stream << para.rub << endl << para.kop << endl;
		return stream;
	}
	friend fstream& operator>>(fstream& stream, Money& para) {
		stream >> para.rub;
		stream >> para.kop;
		return stream;
	}
};