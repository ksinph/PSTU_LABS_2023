#include "Money.h"
#include <iostream>
using namespace std;

//ïåðåãðóçêà îïåðàöèè ïðèñâàèâàíèÿ 
Money&Money::operator=(const Money&t)
{
	//ïðîâåðêà íà ñàìîïðèñâàèâàíèå 
	if(&t==this) return *this; 
	rub=t.rub; 
	kop=t.kop; 
	return *this;
}

//ïåðåãðóçêà ïðåôèêñíîé îïåðàöèè èíêðåìåíò 
Money& Money:: operator++()
{
	int temp = rub * 100 + kop;
	temp++;
	rub = temp / 100;
	kop = temp % 100;
	return *this;
}
	
//ïåðåãðóçêà ïîñòôèêñíîé îïåðàöèè èíêðåìåíò 
Money Money:: operator ++ (int)
{
	int temp = rub * 100 + kop;
	temp++; 
	Money t(rub, kop);
	rub = temp / 100;
	kop = temp % 100;
	return t;
} 

//ïåðåãðóçêà áèíàðíîé îïåðàöèè ñëîæåíèÿ
Money Money::operator+(const Money&t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 + temp2) / 100;
	p.kop = (temp1 + temp2) % 100;
	return p;
}

//ïåðåãðóçêà ãëîáàëüíîé ôóíêöèè-îïåðàöèè ââîäà 
istream&operator>>(istream&in, Money&t)
{
	cout<<"rub?"; in>>t.rub; 
	cout<<"kop?"; in>>t.kop; 
	return in;
}

//ïåðåãðóçêà ãëîáàëüíîé ôóíêöèè-îïåðàöèè âûâîäà
ostream&operator<<(ostream&out, const Money&t)
{
	return (out<<t.rub<<" , "<<t.kop);
}
