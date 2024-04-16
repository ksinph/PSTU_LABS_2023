#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int* calcprefixFunc(string pat, int size)
{
    int* lps = new int[size]; //longest prefix suffix
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < size)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len;
            len++;
            i++;
        }
        else {
            if (len != 0) len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(string str, string pat)
{
    int str_size = str.size();
    int pat_size = pat.size();

    int* lps = calcprefixFunc(pat, pat_size);

    int str_idx = 0;
    int pat_idx = 0;

    while ((str_size - str_idx) >= (pat_size - pat_idx))
    {
        if (pat[pat_idx] == str[str_idx])
        {
            pat_idx++;
            str_idx++;
        }
        if (pat_idx == pat_size)
        {
            cout << "Паттерн найден на позиции " << str_idx-pat_idx+1 << endl;
            cout << endl;
            pat_idx = lps[pat_idx - 1];
        }
        else if (str_idx < str_size && pat[pat_idx] != str[str_idx])
        {
            if (pat_idx != 0) pat_idx = lps[pat_idx - 1];
            else str_idx++;
        }
    }
}

const int CHAR_NUM = 256;
void calccharTable(string str, int size, int charTable[CHAR_NUM])//вычисление таблицы символов
{
    for (int i = 0; i < CHAR_NUM; i++)
    {
        charTable[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        charTable[(int)str[i]] = i; //принудительно делаем строку инт
    }
}

void BMSearch(string str, string pat)
{
    int str_size = str.size();
    int pat_size = pat.size();
    //таблица сдвигов
    int shift_table[CHAR_NUM];
    calccharTable(str, pat_size, shift_table);

    int shift = 0;

    while (shift <= (str_size - pat_size))
    {
        //суффиксный поиск
        int j = pat_size - 1;
        while (j >= 0 && pat[j] == str[shift + j]) { j--; }

        if (j < 0)
        {
            cout << "Паттен найден на позиции " << shift+1 << endl;

            if (shift + pat_size < str_size) //если паттерн встречается больше одного раза
            {
                shift += pat_size - shift_table[(int)str[shift + pat_size]]; //если есть плохой символ сразу за паттерном, то оно сдвинется
            }
            else shift++;
        }
        else
        {
            shift += max(1, j - shift_table[(int)str[shift + j]]); //если паттрен не нашли, то смотрим что больше и сдвигаем
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    /*string str = "abcabceabcabcd";
    string substr = "abcd";
string str = "abbdkaabcd";
string substr = "aabc";
*/
    string str, substr;
    cout << "Введите строку в которой будет происхожить поиск\n";
    cin >> str;
    cout << "Введти паттерн который будет искаться\n";
    cin >> substr;
    cout << "1 - бойра мура\n2 - КМП\nВведите цифру которая бдует соответствовать поиску которых нужно применить: ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        BMSearch(str, substr);
        break;
    case 2:
        KMPSearch(str,substr);
        break;
    default:
        cout << "Неправильный выбор";
    }
    return 0;
}