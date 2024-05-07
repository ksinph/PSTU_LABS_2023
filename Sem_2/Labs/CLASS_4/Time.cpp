#include "Time.h"

//êîíñòðóêòîð áåç ïàðàìåòðîâ
Time::Time(void) : Triad()
{
	hour = 0;
	minute = 0;
	seconds = 0;
}

//äåñòðêòîð
Time::~Time(void)
{
}

//êîíñòðóêòîð ñ ïàðàìåòðàìè
Time::Time(int G, int H, int S) :Triad(M, C, P)
{
	hour = G;
	minute = H;
	seconds = S;
}

//êîíñòðóêòîð êîïèðîâàíèÿ
Time::Time(const Time& L)
{
	first = L.first;
	second = L.second;
	third = L.third;
	hour = L.hour;
	minute = L.minute;
	seconds = L.seconds;
}

//ìîäèôèêàòîð
void Time::Set_hour(int G)
{
	hour = G;
}
void Time::Set_minute(int H)
{
	minute = H;
}
void Time::Set_seconds(int S)
{
	seconds = S;
}

//îïåðöèÿ ïðèñâàèâàíèÿ
Time& Time::operator= (const Time& l)
{
	if (&l == this) return *this;
	first = l.first;
	second = l.second;
	third = l.third;
	hour = l.hour;
	minute = l.minute;
	seconds = l.seconds;
	return *this;
}

//îïåðàöèÿ ââîäà
istream& operator>>(istream& in, Time& l)
{
	cout << "\nFirst:";
	in >> l.first;
	cout << "\nSecond:";
	in >> l.second;
	cout << "\nThird:";
	in >> l.third;
	cout << "\nHour:";
	in >> l.hour;
	cout << "\nMinute:";
	in >> l.minute;
	cout << "\nSeconds:";
	in >> l.seconds;
	return in;
}

//îïåðàöèÿ âûâîäà
ostream& operator<<(ostream& out, const Time& l)
{
	out << "\nFIRST: " << l.first;
	out << "\nSECOND: " << l.second;
	out << "\nTHIRD: " << l.third;
	out << "\nHOUR: " << l.hour;
	out << "\nMINUTE: " << l.minute;
	out << "\nSECONDS: " << l.seconds;
	out << "\n";
	return out;
}
