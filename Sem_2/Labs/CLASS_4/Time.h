#pragma once
#include "Triad.h"
class Time :
    public Triad
{
public:

    Time(void); //конструктор без параметров

public:
    ~Time(void); //деструктор
    Time(int, int, int, int, int, int); //конструктор с параметрами
    Time(const Time&);//конструктор копирования
    int Get_hour() (return hour;)//модификатор
    void Set_hour(int);//cелектор 
    int Get_minute() (return minute;)//модификатор
    void Set_minute(int);//cелектор 
    int Get_seconds() (return seconds;)//модификатор
    void Set_seconds(int);//cелектор 
    Time& operator=(const Time&);//oперация присваивания
    friend istream& operator»(istream & in, Time & l);//операция ввода
    friend ostream& operator«(ostream & out, const Time & l); //oneрация вывода
protected:
    int hour;//aтрибут часы
    int minute;//aтрибут минуты
    int seconds;//aтрибут секунды
};

