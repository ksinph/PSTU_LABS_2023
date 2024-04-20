#pragma once
#include "Triad.h"
class Time :
    public Triad
{
public:

    Time(void); //����������� ��� ����������

public:
    ~Time(void); //����������
    Time(int, int, int, int, int, int); //����������� � �����������
    Time(const Time&);//����������� �����������
    int Get_hour() (return hour;)//�����������
    void Set_hour(int);//c������� 
    int Get_minute() (return minute;)//�����������
    void Set_minute(int);//c������� 
    int Get_seconds() (return seconds;)//�����������
    void Set_seconds(int);//c������� 
    Time& operator=(const Time&);//o������� ������������
    friend istream& operator�(istream & in, Time & l);//�������� �����
    friend ostream& operator�(ostream & out, const Time & l); //one����� ������
protected:
    int hour;//a������ ����
    int minute;//a������ ������
    int seconds;//a������ �������
};

