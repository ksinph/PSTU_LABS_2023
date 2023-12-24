#include <iostream>
#include <string>
#include <wctype.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int chC = 0, chV = 0;
    std::wstring st;
    std::wcin >> st;//введите строку
    
    const wchar_t* pt = st.c_str();
    for (int i = 0; i < st.length(); i++)
    {
       
        if (tolower(*pt) == 'a' || tolower(*pt) == 'e' || tolower(*pt) == 'y' || tolower(*pt) == 'u' || tolower(*pt) == 'i' || tolower(*pt) == 'o')
        {
            chV++;
        }
        else
        {
            chC++;
        }
        pt++;
    }
    std::wcout << "Колво гласных - " << chV << ", Колво согласных - " << chC;
    return 0;
}
