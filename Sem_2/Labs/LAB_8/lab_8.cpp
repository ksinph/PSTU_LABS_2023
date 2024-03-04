#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>

using namespace std;
FILE* F;
struct abt
{
    char name[100];
    int year;
    int exams;
    float certificate;
};

abt input_abt()
{
    string name;
    abt obj;
    getline(cin, name);
    cin>>obj.name;
    cin >> obj.year;
    cin >> obj.exams;
    cin >> obj.certificate;
    return obj;
}

void write(abt user)
{
    fwrite(&user, sizeof(abt), 1, F);
    scanf("%s", &user.name);
    scanf("%d", &user.year);
    scanf("%d", &user.exams);
    scanf("%f", &user.certificate);
}

void read(abt user)
{
    fread(&user, sizeof(abt), 1, F);
    printf("%s", user.name);
    printf("%d", user.year);
    printf("%d", user.exams);
    printf("%f", user.certificate);
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    abt user;
    int n;
    cin >> n;
    if ((F = fopen("file.dat", "wb")) != NULL)
    {
        cout << "Файл открыт" << endl;
        while (n > 0) {
            cout << "Введите ФИО,  год рождения, оценки за экзамены, средний балл за аттестат: " << endl;
            abt user = input_abt();
            write(user);
            cout << "Вы ввели: " << endl;
            read(user);
            n--;
        }
    }
    else
    {
        cout << "Не удалось открыть файл" << endl;
    }
    fclose(F);
    return 0;
}
