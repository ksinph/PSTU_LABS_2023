#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* F1;
    FILE* F2;
    char str[255];
    int fil;
    fil=fopen_s(&F1,"f1.txt","w");
    int filesize1 = 0,filesize2=0;
    for (int i = 0; i < 10; i++)
    {
        fflush(F1);
        cout<<"введите строку : ";
        cin >> i;
        gets_s(str);
        fputs(str, F1);
        fputs("\n", F1);
        filesize1++;
    }
    fclose(F1);
    fclose(F1);
    fil = fopen_s(&F1, "f1.txt", "r");
    fil = fopen_s(&F2, "f2.txt", "w");

    for (int i = 0; i < 10 && fgets(str, 255, F1) != NULL; i++)
    {
        if (i % 2 != 0)
        fputs(str, F2);
        filesize2++;
    }
    cout << filesize1<<" "<<filesize2;
    fclose(F1);
    fclose(F2);
}
