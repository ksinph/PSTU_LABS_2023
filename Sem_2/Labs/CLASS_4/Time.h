#include "Triad.h"

class Time :
    public Triad
{
public:

    Time(void); //êîíñòðóêòîð áåç ïàðàìåòðîâ
public:
    ~Time(void); //äåñòðóêòîð
    Time(int, int, int, int, int, int); //êîíñòðóêòîð ñ ïàðàìåòðàìè
    Time(const Time&);//êîíñòðóêòîð êîïèðîâàíèÿ
    int Get_hour() { return hour; }//ìîäèôèêàòîð
    void Set_hour(int);//cåëåêòîð 
    int Get_minute() { return minute; }//ìîäèôèêàòîð
    void Set_minute(int);//cåëåêòîð 
    int Get_seconds() { return seconds; }//ìîäèôèêàòîð
    void Set_seconds(int);//cåëåêòîð 
    Time& operator=(const Time&);//oïåðàöèÿ ïðèñâàèâàíèÿ
    friend istream& operator>>(istream& in, Time& l);//îïåðàöèÿ ââîäà
    friend ostream& operator<<(ostream& out, const Time& l); //oneðàöèÿ âûâîäà
protected:
    int hour;//aòðèáóò ÷àñû
    int minute;//aòðèáóò ìèíóòû
    int seconds;//aòðèáóò ñåêóíäû
};
