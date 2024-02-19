#include <iostream>
#include <cstring>
using namespace std;
bool gets(string s)
{
    int len =s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    char s[255];
    cin >> s;
    if(gets(s))
    {
        cout << " является полиндромом";
    }
    else
    {
        cout << " не является полиндромом";
    }
}
