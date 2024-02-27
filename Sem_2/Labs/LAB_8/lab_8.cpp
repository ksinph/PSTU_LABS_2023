#include <iostream>
#include <string>
#include <stdio.h>
#include < cstdio >
using namespace std;
FILE* F;
struct abt 
{
    char name[100];
    int year;
    float exams;
    float certificate;
};

abt input_abt() 
{
    string name;
    abt obj;
    getline(cin, name);
    for (int i = 0; i < name.length(); i++)
        {
            obj.name[i] = name[i];
        }
    cin >> obj.year;
    cin >> obj.exams;
    cin >> obj.certificate;
    return obj;
}

void write(abt user) 
{
    fwrite(&user, sizeof(abt), 1, F);
}

void read(abt user) 
{
    fread(&user, sizeof(abt), 1, F);
    printf("%s %d %f %f", user.name, user.year, user.exams, user.certificate);
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* F;
    abt user;
    int f;
    f = fopen_s(&F,"file.bin", "wb, ccs=UNICODE");
    if (f != NULL) 
    {
        cout << "Файл открыт" << endl;
        cout << "Введите ФИО,  год рождения, оценки за экзамены, средний балл за аттестат: " << endl;
        abt user = input_abt();
        write(user);
        cout << "Вы ввели: " << endl;
        read(user);
        
    }
    else
    {
        cout << "Не удалось открыть файл" << endl;
    }
    fclose(F);
    return 0;
}
