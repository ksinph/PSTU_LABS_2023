# Вариант задания
1. Создать динамический массив из записей (в соответствии с вариантом), содержащий не менее 100 элементов. Для заполнения элементов массива использовать ДСЧ.
2. Предусмотреть сохранение массива в файл и загрузку массива из файла.
3. Предусмотреть возможность добавления и удаления элементов из массива (файла).
4. Выполнить поиск элемента в массиве по ключу в соответствии с вариантом. Для поиска использовать хэш-таблицу.
5. Подсчитать количество коллизий при размере хэш-таблицы 40, 75 и 90 элементов.

Данные: ФИО, Дата рождения, номер паспорта.
Ключ (string): Дата рождения.
Хэш-функция: H(k)= [M (kAmod1)], 0<A<1, mod1 – получение дробной части, [] – получение целой части.
# Код программы
```cpp
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

const int HashTableSize = 10;
const double PiOverFour = M_PI_4;
int CollisionCount = 0;

struct Node
{
    string key = " ";
    string value = " ";
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct HashTable
{
    Node* buckets[HashTableSize];
    HashTable()
    {
        for (int i = 0; i < HashTableSize; ++i)
        {
            buckets[i] = nullptr;
        }
    }
};

double GetFractionalPart(double var)
{
    int intPart = static_cast<int>(var);
    return var - intPart;
}

int ComputeHash(double var)
{
    return static_cast<int>(HashTableSize * GetFractionalPart(var * PiOverFour));
}

int ComputeHash(string str)
{
    int hashValue = 0;
    for (int i = 0; i < str.size(); i++)
    {
        hashValue += static_cast<int>(pow(str[i], 2) * M_2_SQRTPI + abs(str[i]) * M_SQRT1_2);
    }
    return ComputeHash(abs(hashValue));
}

bool AddToHashTable(HashTable& table, string key, string value)
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    int hash = ComputeHash(key);
    if (table.buckets[hash] == nullptr)
    {
        table.buckets[hash] = newNode;
        return true;
    }
    else
    {
        Node* current = table.buckets[hash];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        CollisionCount++;
        return true;
    }
}

bool RemoveByHashKey(HashTable& table, string key)
{
    int hash = ComputeHash(key);
    Node* current = table.buckets[hash];
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            else
            {
                table.buckets[hash] = current->next;
            }
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool RemoveByHashValue(HashTable& table, string value)
{
    for (int i = 0; i < HashTableSize; i++)
    {
        Node* current = table.buckets[i];
        while (current != nullptr)
        {
            if (current->value == value)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    table.buckets[i] = current->next;
                }
                if (current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }
                delete current;
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

Node* GetNodeByHashKey(HashTable& table, string key)
{
    int hash = ComputeHash(key);
    Node* current = table.buckets[hash];
    while (current != nullptr)
    {
        if (current->key == key)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void PrintHashTable(const HashTable& table)
{
    for (int i = 0; i < HashTableSize; i++)
    {
        Node* current = table.buckets[i];
        while (current != nullptr)
        {
            cout << "[" << current->key << " : " << current->value << "]" << endl;
            current = current->next;
        }
    }
    cout << endl;
}

string Surnames[] = {
    "Washington", "Lincoln", "Roosevelt", "Kennedy", "Nixon",
    "Reagan", "Clinton", "Obama", "Biden", "Johnson",
    "Bush", "Truman", "Eisenhower", "Jefferson", "Adams",
    "Madison", "Monroe", "Jackson", "Harrison", "Tyler",
    "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan",
    "Grant", "Hayes", "Garfield", "Arthur", "Cleveland"
};

string FirstNames[] = {
    "George", "Abraham", "Theodore", "John", "Richard",
    "Ronald", "Bill", "Barack", "Joe", "Lyndon",
    "George", "Harry", "Dwight", "Thomas", "John",
    "James", "James", "Andrew", "William", "John",
    "James", "Zachary", "Millard", "Franklin", "James",
    "Ulysses", "Rutherford", "James", "Chester", "Grover"
};

string MiddleNames[] = {
    "Herbert", "Mason", "Delano", "Fitzgerald", "Milhous",
    "Wilson", "Jefferson", "Hussein", "Robinette", "Baines",
    "Walker", "S.", "David", "Woodrow", "Quincy",
    "Madison", "Monroe", "Jackson", "Henry", "Tyler",
    "Knox", "Taylor", "Fillmore", "Pierce", "Buchanan",
    "Grant", "Birchard", "Abram", "Alan", "Cleveland"
};

string GenerateFullName()
{
    string surname = Surnames[rand() % 30];
    string firstName = FirstNames[rand() % 30];
    string middleName;
    do
    {
        middleName = MiddleNames[rand() % 30];
    } while (firstName == middleName);
    return firstName + " " + middleName + " " + surname;
}

string FormatNumber(int n, int length)
{
    string tempString = to_string(n);
    while (tempString.size() < length)
    {
        tempString = '0' + tempString;
    }
    while (tempString.size() > length)
    {
        tempString.erase(0, 1);
    }
    return tempString;
}

string GenerateBirthDate()
{
    return FormatNumber(rand() % 28 + 1, 2) + "." + FormatNumber(rand() % 12 + 1, 2) + "." + to_string(rand() % 80 + 1930);
}

string GeneratePassportNumber()
{
    return FormatNumber(rand() % 10000, 4) + " " + FormatNumber(rand() % 1000000 * 100, 6);
}

int main()
{
    srand(time(NULL));
    HashTable table;
    for (int i = 0; i < HashTableSize; i++)
    {
        string birthDate = GenerateBirthDate();
        string person = GenerateFullName() + " | " + birthDate + " | " + GeneratePassportNumber();
        AddToHashTable(table, birthDate, person);
    }
    cout << "Hash-table creation successful: " << endl;
    PrintHashTable(table);

    int existingIndex = rand() % HashTableSize;
    while (table.buckets[existingIndex] == nullptr)
    {
        existingIndex = rand() % HashTableSize;
    }
    Node* randomPerson = table.buckets[existingIndex];
    string key = randomPerson->key;
    cout << "Removing by key '" << key << "': " << endl;
    if (RemoveByHashKey(table, key))
    {
        cout << "Element successfully removed." << endl;
    }
    else
    {
        cout << "Removing error. Element not found: " << endl;
    }
    PrintHashTable(table);

    existingIndex = rand() % HashTableSize;
    while (table.buckets[existingIndex] == nullptr)
    {
        existingIndex = rand() % HashTableSize;
    }
    randomPerson = table.buckets[existingIndex];
    string value = randomPerson->value;
    cout << "Removing by value '" << value << "': " << endl;
    if (RemoveByHashValue(table, value))
    {
        cout << "Element successfully removed." << endl;
    }
    else
    {
        cout << "Removing error. Element not found: " << endl;
    }
    PrintHashTable(table);

    existingIndex = rand() % HashTableSize;
    while (table.buckets[existingIndex] == nullptr)
    {
        existingIndex = rand() % HashTableSize;
    }
    randomPerson = table.buckets[existingIndex];
    string keyToGet = randomPerson->key;
    cout << "Getting element by key '" << keyToGet << "': " << endl;
    Node* node = GetNodeByHashKey(table, keyToGet);
    if (node != nullptr)
    {
        cout << "Got element " << node->value << endl;
    }
    else
    {
        cout << "Getting error. Element not found." << endl;
    }
    cout << "Number of collisions: " << CollisionCount << endl;
    return 0;
}
```
# Блок-схема программы
<image src="hash.drawio.png">
	
# Тесты
### Пример 1
Входные данные:
```
10
```
Выходные данные:
```
Hash-table creation successful:
[08.05.1952 : Lyndon Milhous Cleveland | 08.05.1952 | 9682 985600]
[15.11.1957 : Harry S. Biden | 15.11.1957 | 6044 579900]
[25.03.1963 : Abraham Knox Adams | 25.03.1963 | 1715 736900]
[07.06.2007 : Joe Milhous Jefferson | 07.06.2007 | 7591 963600]
[26.11.1995 : George Taylor Monroe | 26.11.1995 | 7647 610600]
[21.09.1986 : Zachary Walker Washington | 21.09.1986 | 9932 142800]
[22.03.1972 : Abraham Wilson Reagan | 22.03.1972 | 0357 402200]
[27.05.1943 : Thomas Tyler Hayes | 27.05.1943 | 1221 920000]
[09.04.1978 : William Cleveland Eisenhower | 09.04.1978 | 8173 466300]
[05.04.1999 : George Pierce Adams | 05.04.1999 | 1653 150600]

Removing by key '05.04.1999':
Element successfully removed.
[08.05.1952 : Lyndon Milhous Cleveland | 08.05.1952 | 9682 985600]
[15.11.1957 : Harry S. Biden | 15.11.1957 | 6044 579900]
[25.03.1963 : Abraham Knox Adams | 25.03.1963 | 1715 736900]
[07.06.2007 : Joe Milhous Jefferson | 07.06.2007 | 7591 963600]
[26.11.1995 : George Taylor Monroe | 26.11.1995 | 7647 610600]
[21.09.1986 : Zachary Walker Washington | 21.09.1986 | 9932 142800]
[22.03.1972 : Abraham Wilson Reagan | 22.03.1972 | 0357 402200]
[27.05.1943 : Thomas Tyler Hayes | 27.05.1943 | 1221 920000]
[09.04.1978 : William Cleveland Eisenhower | 09.04.1978 | 8173 466300]

Removing by value 'Abraham Knox Adams | 25.03.1963 | 1715 736900':
Element successfully removed.
[08.05.1952 : Lyndon Milhous Cleveland | 08.05.1952 | 9682 985600]
[15.11.1957 : Harry S. Biden | 15.11.1957 | 6044 579900]
[07.06.2007 : Joe Milhous Jefferson | 07.06.2007 | 7591 963600]
[26.11.1995 : George Taylor Monroe | 26.11.1995 | 7647 610600]
[21.09.1986 : Zachary Walker Washington | 21.09.1986 | 9932 142800]
[22.03.1972 : Abraham Wilson Reagan | 22.03.1972 | 0357 402200]
[27.05.1943 : Thomas Tyler Hayes | 27.05.1943 | 1221 920000]
[09.04.1978 : William Cleveland Eisenhower | 09.04.1978 | 8173 466300]

Getting element by key '27.05.1943':
Got element Thomas Tyler Hayes | 27.05.1943 | 1221 920000
Number of collisions: 3
```
### Пример 2
Входные данные:
```
5
```
Выходные данные:
```
Hash-table creation successful:
[09.01.1976 : James Henry Pierce | 09.01.1976 | 9488 824900]
[18.02.1940 : Ronald Quincy Truman | 18.02.1940 | 4509 933000]
[16.09.1999 : Joe David Bush | 16.09.1999 | 0576 989500]
[07.12.1991 : Millard Taylor Truman | 07.12.1991 | 6574 930000]
[04.03.1969 : Bill Jackson Lincoln | 04.03.1969 | 4287 153900]

Removing by key '16.09.1999':
Element successfully removed.
[09.01.1976 : James Henry Pierce | 09.01.1976 | 9488 824900]
[18.02.1940 : Ronald Quincy Truman | 18.02.1940 | 4509 933000]
[07.12.1991 : Millard Taylor Truman | 07.12.1991 | 6574 930000]
[04.03.1969 : Bill Jackson Lincoln | 04.03.1969 | 4287 153900]

Removing by value 'James Henry Pierce | 09.01.1976 | 9488 824900':
Element successfully removed.
[18.02.1940 : Ronald Quincy Truman | 18.02.1940 | 4509 933000]
[07.12.1991 : Millard Taylor Truman | 07.12.1991 | 6574 930000]
[04.03.1969 : Bill Jackson Lincoln | 04.03.1969 | 4287 153900]

Getting element by key '18.02.1940':
Got element Ronald Quincy Truman | 18.02.1940 | 4509 933000
Number of collisions: 2
```
### Пример 3
Входные данные:
```
100
```
Выходные данные:
```
Hash-table creation successful:
[26.10.1936 : Harry Wilson Taylor | 26.10.1936 | 1958 143300]
[05.02.1941 : John Quincy Harrison | 05.02.1941 | 7471 306400]
[04.09.1971 : Abraham Grant Arthur | 04.09.1971 | 3874 512800]
[06.07.1960 : James Robinette Washington | 06.07.1960 | 8069 240500]
[13.10.1936 : James Henry Bush | 13.10.1936 | 2504 067100]
[03.01.1973 : John Abram Harrison | 03.01.1973 | 9510 541100]
[11.05.1954 : Chester S. Eisenhower | 11.05.1954 | 2204 209200]
[18.09.1965 : John Fillmore Lincoln | 18.09.1965 | 7993 786400]
[08.01.2001 : Lyndon Fitzgerald Kennedy | 08.01.2001 | 8644 264000]
[19.06.1957 : Chester Woodrow Lincoln | 19.06.1957 | 3893 973100]
[10.07.1964 : Abraham Jackson Obama | 10.07.1964 | 0158 838900]
[22.06.1998 : James Quincy Biden | 22.06.1998 | 2501 573700]
[24.01.1952 : Zachary Milhous Madison | 24.01.1952 | 2489 902000]
[03.05.1969 : George Jackson Polk | 03.05.1969 | 7367 220900]
[25.03.1987 : Theodore Mason Hayes | 25.03.1987 | 5608 126400]
[13.02.1983 : Andrew Abram Adams | 13.02.1983 | 8165 661600]
[12.03.1938 : Lyndon Robinette Adams | 12.03.1938 | 1452 541600]
[15.10.1953 : Franklin Pierce Monroe | 15.10.1953 | 3983 212500]
[11.11.1959 : Bill Abram Pierce | 11.11.1959 | 0381 973900]
[12.12.1975 : Franklin Alan Pierce | 12.12.1975 | 7780 231600]
[27.08.1995 : Ronald Pierce Jackson | 27.08.1995 | 0628 138200]
[09.10.1985 : James Alan Tyler | 09.10.1985 | 8067 093000]
[25.06.1982 : James Walker Arthur | 25.06.1982 | 7272 253100]
[18.12.2000 : Ulysses Woodrow Johnson | 18.12.2000 | 0061 240600]
[19.09.1949 : Rutherford Baines Bush | 19.09.1949 | 5414 653700]
[15.04.1954 : John Robinette Lincoln | 15.04.1954 | 4997 103900]
[09.08.1961 : Millard Abram Clinton | 09.08.1961 | 7224 814700]
[18.02.1987 : John Jackson Kennedy | 18.02.1987 | 4834 301700]
[14.08.2000 : Andrew Grant Jefferson | 14.08.2000 | 2739 429000]
[24.10.1967 : Ronald Woodrow Washington | 24.10.1967 | 6887 275800]
[09.01.1967 : William Herbert Obama | 09.01.1967 | 2038 765300]
[02.05.1934 : Andrew Cleveland Bush | 02.05.1934 | 3776 052300]
[25.02.1991 : James Buchanan Garfield | 25.02.1991 | 8671 533200]
[09.10.1991 : Chester Woodrow Nixon | 09.10.1991 | 6298 269100]
[04.02.1959 : Abraham Hussein Jefferson | 04.02.1959 | 3586 940300]
[14.10.1973 : Joe Cleveland Hayes | 14.10.1973 | 2296 186900]
[27.03.1970 : Joe Walker Harrison | 27.03.1970 | 3104 599700]
[18.11.1973 : Richard Pierce Pierce | 18.11.1973 | 5434 072400]
[20.09.1987 : Zachary David Polk | 20.09.1987 | 4524 723400]
[22.11.1943 : Ronald Wilson Harrison | 22.11.1943 | 2703 797300]
[07.05.1994 : Joe Cleveland Nixon | 07.05.1994 | 6160 620200]
[04.07.1981 : James Tyler Arthur | 04.07.1981 | 1495 851100]
[24.02.1940 : Lyndon Herbert Fillmore | 24.02.1940 | 9918 875400]
[17.12.1934 : Ronald Madison Grant | 17.12.1934 | 4852 133800]
[12.03.2008 : George Walker Eisenhower | 12.03.2008 | 3569 909300]
[16.11.1939 : James Baines Madison | 16.11.1939 | 2385 465300]
[27.04.1935 : James Fillmore Roosevelt | 27.04.1935 | 7328 226700]
[13.02.1961 : Joe Herbert Truman | 13.02.1961 | 8598 979500]
[18.05.1957 : Andrew Baines Tyler | 18.05.1957 | 0942 350900]
[16.06.1972 : James Alan Obama | 16.06.1972 | 8919 067900]
[24.08.1969 : Abraham Pierce Kennedy | 24.08.1969 | 8536 047700]
[18.02.1948 : Chester Jefferson Fillmore | 18.02.1948 | 0379 389500]
[04.01.2004 : Chester Henry Adams | 04.01.2004 | 9146 024400]
[04.12.1978 : George Taylor Truman | 04.12.1978 | 1106 899300]
[25.09.1983 : Andrew Grant Garfield | 25.09.1983 | 2811 374000]
[27.02.1975 : James S. Monroe | 27.02.1975 | 0717 187400]
[26.02.1978 : Zachary Hussein Kennedy | 26.02.1978 | 3927 777900]
[11.10.1939 : James Alan Garfield | 11.10.1939 | 1121 207100]
[14.01.1934 : Dwight Cleveland Roosevelt | 14.01.1934 | 3051 260000]
[08.10.1985 : John Walker Washington | 08.10.1985 | 6153 036300]
[05.09.1931 : Zachary Taylor Fillmore | 05.09.1931 | 8337 986800]
[23.05.1962 : Grover Henry Madison | 23.05.1962 | 2829 266700]
[22.03.1956 : Dwight Pierce Garfield | 22.03.1956 | 2579 476100]
[04.06.1951 : James David Jefferson | 04.06.1951 | 6113 175100]
[19.05.1966 : Abraham Baines Grant | 19.05.1966 | 2315 089700]
[13.07.1982 : George S. Monroe | 13.07.1982 | 5024 969500]
[28.03.1971 : Dwight Jackson Garfield | 28.03.1971 | 1659 196200]
[11.06.2000 : Lyndon Fitzgerald Polk | 11.06.2000 | 8757 806100]
[07.03.1984 : Thomas Walker Bush | 07.03.1984 | 1166 000200]
[08.05.1956 : Millard David Jefferson | 08.05.1956 | 4819 582700]
[09.12.1964 : George Milhous Clinton | 09.12.1964 | 0465 627400]
[18.02.1952 : Theodore Jefferson Adams | 18.02.1952 | 8440 112200]
[15.03.1947 : James Milhous Adams | 15.03.1947 | 1686 375000]
[09.07.1990 : John Pierce Taylor | 09.07.1990 | 5313 130400]
[13.10.1961 : Barack Woodrow Eisenhower | 13.10.1961 | 5545 555900]
[05.06.1986 : Franklin Abram Bush | 05.06.1986 | 8663 335000]
[18.09.1988 : Chester Birchard Monroe | 18.09.1988 | 7803 716400]
[01.04.1984 : Franklin Fillmore Garfield | 01.04.1984 | 5759 149100]
[27.01.1941 : Dwight Cleveland Reagan | 27.01.1941 | 0296 890600]
[18.09.1964 : Rutherford Cleveland Reagan | 18.09.1964 | 4281 520600]
[15.02.1988 : William Abram Arthur | 15.02.1988 | 5321 804300]
[20.02.1999 : James Grant Hayes | 20.02.1999 | 7106 024700]
[21.08.1986 : Abraham Madison Pierce | 21.08.1986 | 6720 157400]
[28.12.1973 : George Buchanan Arthur | 28.12.1973 | 8174 155500]
[21.04.2003 : Barack Birchard Buchanan | 21.04.2003 | 0895 776400]
[09.07.2005 : John Fitzgerald Washington | 09.07.2005 | 1371 727800]
[04.12.2003 : James Henry Pierce | 04.12.2003 | 0640 616000]
[08.07.1972 : Thomas Tyler Monroe | 08.07.1972 | 4865 101300]
[17.11.1988 : James Delano Adams | 17.11.1988 | 5161 474000]
[27.03.1984 : Thomas Quincy Lincoln | 27.03.1984 | 0037 997600]
[20.09.1952 : James Mason Washington | 20.09.1952 | 6361 867800]
[24.09.1993 : George Birchard Taylor | 24.09.1993 | 4917 218600]
[12.11.1963 : Dwight Herbert Buchanan | 12.11.1963 | 3875 225900]
[04.02.2002 : George Fitzgerald Grant | 04.02.2002 | 6906 388500]
[08.05.1992 : John Monroe Adams | 08.05.1992 | 7247 310300]
[23.08.1938 : Grover Delano Kennedy | 23.08.1938 | 4342 406400]
[11.07.1938 : Millard Wilson Washington | 11.07.1938 | 2890 760500]
[10.06.1965 : Bill Fitzgerald Madison | 10.06.1965 | 3688 189400]
[15.08.1953 : John Delano Taylor | 15.08.1953 | 3377 741500]
[15.03.1958 : Abraham Robinette Buchanan | 15.03.1958 | 6452 353600]

Removing by key '18.02.1987':
Element successfully removed.
[26.10.1936 : Harry Wilson Taylor | 26.10.1936 | 1958 143300]
[05.02.1941 : John Quincy Harrison | 05.02.1941 | 7471 306400]
[04.09.1971 : Abraham Grant Arthur | 04.09.1971 | 3874 512800]
[06.07.1960 : James Robinette Washington | 06.07.1960 | 8069 240500]
[13.10.1936 : James Henry Bush | 13.10.1936 | 2504 067100]
[03.01.1973 : John Abram Harrison | 03.01.1973 | 9510 541100]
[11.05.1954 : Chester S. Eisenhower | 11.05.1954 | 2204 209200]
[18.09.1965 : John Fillmore Lincoln | 18.09.1965 | 7993 786400]
[08.01.2001 : Lyndon Fitzgerald Kennedy | 08.01.2001 | 8644 264000]
[19.06.1957 : Chester Woodrow Lincoln | 19.06.1957 | 3893 973100]
[10.07.1964 : Abraham Jackson Obama | 10.07.1964 | 0158 838900]
[22.06.1998 : James Quincy Biden | 22.06.1998 | 2501 573700]
[24.01.1952 : Zachary Milhous Madison | 24.01.1952 | 2489 902000]
[03.05.1969 : George Jackson Polk | 03.05.1969 | 7367 220900]
[25.03.1987 : Theodore Mason Hayes | 25.03.1987 | 5608 126400]
[13.02.1983 : Andrew Abram Adams | 13.02.1983 | 8165 661600]
[12.03.1938 : Lyndon Robinette Adams | 12.03.1938 | 1452 541600]
[15.10.1953 : Franklin Pierce Monroe | 15.10.1953 | 3983 212500]
[11.11.1959 : Bill Abram Pierce | 11.11.1959 | 0381 973900]
[12.12.1975 : Franklin Alan Pierce | 12.12.1975 | 7780 231600]
[27.08.1995 : Ronald Pierce Jackson | 27.08.1995 | 0628 138200]
[09.10.1985 : James Alan Tyler | 09.10.1985 | 8067 093000]
[25.06.1982 : James Walker Arthur | 25.06.1982 | 7272 253100]
[18.12.2000 : Ulysses Woodrow Johnson | 18.12.2000 | 0061 240600]
[19.09.1949 : Rutherford Baines Bush | 19.09.1949 | 5414 653700]
[15.04.1954 : John Robinette Lincoln | 15.04.1954 | 4997 103900]
[09.08.1961 : Millard Abram Clinton | 09.08.1961 | 7224 814700]
[14.08.2000 : Andrew Grant Jefferson | 14.08.2000 | 2739 429000]
[24.10.1967 : Ronald Woodrow Washington | 24.10.1967 | 6887 275800]
[09.01.1967 : William Herbert Obama | 09.01.1967 | 2038 765300]
[02.05.1934 : Andrew Cleveland Bush | 02.05.1934 | 3776 052300]
[25.02.1991 : James Buchanan Garfield | 25.02.1991 | 8671 533200]
[09.10.1991 : Chester Woodrow Nixon | 09.10.1991 | 6298 269100]
[04.02.1959 : Abraham Hussein Jefferson | 04.02.1959 | 3586 940300]
[14.10.1973 : Joe Cleveland Hayes | 14.10.1973 | 2296 186900]
[27.03.1970 : Joe Walker Harrison | 27.03.1970 | 3104 599700]
[18.11.1973 : Richard Pierce Pierce | 18.11.1973 | 5434 072400]
[20.09.1987 : Zachary David Polk | 20.09.1987 | 4524 723400]
[22.11.1943 : Ronald Wilson Harrison | 22.11.1943 | 2703 797300]
[07.05.1994 : Joe Cleveland Nixon | 07.05.1994 | 6160 620200]
[04.07.1981 : James Tyler Arthur | 04.07.1981 | 1495 851100]
[24.02.1940 : Lyndon Herbert Fillmore | 24.02.1940 | 9918 875400]
[17.12.1934 : Ronald Madison Grant | 17.12.1934 | 4852 133800]
[12.03.2008 : George Walker Eisenhower | 12.03.2008 | 3569 909300]
[16.11.1939 : James Baines Madison | 16.11.1939 | 2385 465300]
[27.04.1935 : James Fillmore Roosevelt | 27.04.1935 | 7328 226700]
[13.02.1961 : Joe Herbert Truman | 13.02.1961 | 8598 979500]
[18.05.1957 : Andrew Baines Tyler | 18.05.1957 | 0942 350900]
[16.06.1972 : James Alan Obama | 16.06.1972 | 8919 067900]
[24.08.1969 : Abraham Pierce Kennedy | 24.08.1969 | 8536 047700]
[18.02.1948 : Chester Jefferson Fillmore | 18.02.1948 | 0379 389500]
[04.01.2004 : Chester Henry Adams | 04.01.2004 | 9146 024400]
[04.12.1978 : George Taylor Truman | 04.12.1978 | 1106 899300]
[25.09.1983 : Andrew Grant Garfield | 25.09.1983 | 2811 374000]
[27.02.1975 : James S. Monroe | 27.02.1975 | 0717 187400]
[26.02.1978 : Zachary Hussein Kennedy | 26.02.1978 | 3927 777900]
[11.10.1939 : James Alan Garfield | 11.10.1939 | 1121 207100]
[14.01.1934 : Dwight Cleveland Roosevelt | 14.01.1934 | 3051 260000]
[08.10.1985 : John Walker Washington | 08.10.1985 | 6153 036300]
[05.09.1931 : Zachary Taylor Fillmore | 05.09.1931 | 8337 986800]
[23.05.1962 : Grover Henry Madison | 23.05.1962 | 2829 266700]
[22.03.1956 : Dwight Pierce Garfield | 22.03.1956 | 2579 476100]
[04.06.1951 : James David Jefferson | 04.06.1951 | 6113 175100]
[19.05.1966 : Abraham Baines Grant | 19.05.1966 | 2315 089700]
[13.07.1982 : George S. Monroe | 13.07.1982 | 5024 969500]
[28.03.1971 : Dwight Jackson Garfield | 28.03.1971 | 1659 196200]
[11.06.2000 : Lyndon Fitzgerald Polk | 11.06.2000 | 8757 806100]
[07.03.1984 : Thomas Walker Bush | 07.03.1984 | 1166 000200]
[08.05.1956 : Millard David Jefferson | 08.05.1956 | 4819 582700]
[09.12.1964 : George Milhous Clinton | 09.12.1964 | 0465 627400]
[18.02.1952 : Theodore Jefferson Adams | 18.02.1952 | 8440 112200]
[15.03.1947 : James Milhous Adams | 15.03.1947 | 1686 375000]
[09.07.1990 : John Pierce Taylor | 09.07.1990 | 5313 130400]
[13.10.1961 : Barack Woodrow Eisenhower | 13.10.1961 | 5545 555900]
[05.06.1986 : Franklin Abram Bush | 05.06.1986 | 8663 335000]
[18.09.1988 : Chester Birchard Monroe | 18.09.1988 | 7803 716400]
[01.04.1984 : Franklin Fillmore Garfield | 01.04.1984 | 5759 149100]
[27.01.1941 : Dwight Cleveland Reagan | 27.01.1941 | 0296 890600]
[18.09.1964 : Rutherford Cleveland Reagan | 18.09.1964 | 4281 520600]
[15.02.1988 : William Abram Arthur | 15.02.1988 | 5321 804300]
[20.02.1999 : James Grant Hayes | 20.02.1999 | 7106 024700]
[21.08.1986 : Abraham Madison Pierce | 21.08.1986 | 6720 157400]
[28.12.1973 : George Buchanan Arthur | 28.12.1973 | 8174 155500]
[21.04.2003 : Barack Birchard Buchanan | 21.04.2003 | 0895 776400]
[09.07.2005 : John Fitzgerald Washington | 09.07.2005 | 1371 727800]
[04.12.2003 : James Henry Pierce | 04.12.2003 | 0640 616000]
[08.07.1972 : Thomas Tyler Monroe | 08.07.1972 | 4865 101300]
[17.11.1988 : James Delano Adams | 17.11.1988 | 5161 474000]
[27.03.1984 : Thomas Quincy Lincoln | 27.03.1984 | 0037 997600]
[20.09.1952 : James Mason Washington | 20.09.1952 | 6361 867800]
[24.09.1993 : George Birchard Taylor | 24.09.1993 | 4917 218600]
[12.11.1963 : Dwight Herbert Buchanan | 12.11.1963 | 3875 225900]
[04.02.2002 : George Fitzgerald Grant | 04.02.2002 | 6906 388500]
[08.05.1992 : John Monroe Adams | 08.05.1992 | 7247 310300]
[23.08.1938 : Grover Delano Kennedy | 23.08.1938 | 4342 406400]
[11.07.1938 : Millard Wilson Washington | 11.07.1938 | 2890 760500]
[10.06.1965 : Bill Fitzgerald Madison | 10.06.1965 | 3688 189400]
[15.08.1953 : John Delano Taylor | 15.08.1953 | 3377 741500]
[15.03.1958 : Abraham Robinette Buchanan | 15.03.1958 | 6452 353600]

Removing by value 'James Quincy Biden | 22.06.1998 | 2501 573700':
Element successfully removed.
[26.10.1936 : Harry Wilson Taylor | 26.10.1936 | 1958 143300]
[05.02.1941 : John Quincy Harrison | 05.02.1941 | 7471 306400]
[04.09.1971 : Abraham Grant Arthur | 04.09.1971 | 3874 512800]
[06.07.1960 : James Robinette Washington | 06.07.1960 | 8069 240500]
[13.10.1936 : James Henry Bush | 13.10.1936 | 2504 067100]
[03.01.1973 : John Abram Harrison | 03.01.1973 | 9510 541100]
[11.05.1954 : Chester S. Eisenhower | 11.05.1954 | 2204 209200]
[18.09.1965 : John Fillmore Lincoln | 18.09.1965 | 7993 786400]
[08.01.2001 : Lyndon Fitzgerald Kennedy | 08.01.2001 | 8644 264000]
[19.06.1957 : Chester Woodrow Lincoln | 19.06.1957 | 3893 973100]
[10.07.1964 : Abraham Jackson Obama | 10.07.1964 | 0158 838900]
[24.01.1952 : Zachary Milhous Madison | 24.01.1952 | 2489 902000]
[03.05.1969 : George Jackson Polk | 03.05.1969 | 7367 220900]
[25.03.1987 : Theodore Mason Hayes | 25.03.1987 | 5608 126400]
[13.02.1983 : Andrew Abram Adams | 13.02.1983 | 8165 661600]
[12.03.1938 : Lyndon Robinette Adams | 12.03.1938 | 1452 541600]
[15.10.1953 : Franklin Pierce Monroe | 15.10.1953 | 3983 212500]
[11.11.1959 : Bill Abram Pierce | 11.11.1959 | 0381 973900]
[12.12.1975 : Franklin Alan Pierce | 12.12.1975 | 7780 231600]
[27.08.1995 : Ronald Pierce Jackson | 27.08.1995 | 0628 138200]
[09.10.1985 : James Alan Tyler | 09.10.1985 | 8067 093000]
[25.06.1982 : James Walker Arthur | 25.06.1982 | 7272 253100]
[18.12.2000 : Ulysses Woodrow Johnson | 18.12.2000 | 0061 240600]
[19.09.1949 : Rutherford Baines Bush | 19.09.1949 | 5414 653700]
[15.04.1954 : John Robinette Lincoln | 15.04.1954 | 4997 103900]
[09.08.1961 : Millard Abram Clinton | 09.08.1961 | 7224 814700]
[14.08.2000 : Andrew Grant Jefferson | 14.08.2000 | 2739 429000]
[24.10.1967 : Ronald Woodrow Washington | 24.10.1967 | 6887 275800]
[09.01.1967 : William Herbert Obama | 09.01.1967 | 2038 765300]
[02.05.1934 : Andrew Cleveland Bush | 02.05.1934 | 3776 052300]
[25.02.1991 : James Buchanan Garfield | 25.02.1991 | 8671 533200]
[09.10.1991 : Chester Woodrow Nixon | 09.10.1991 | 6298 269100]
[04.02.1959 : Abraham Hussein Jefferson | 04.02.1959 | 3586 940300]
[14.10.1973 : Joe Cleveland Hayes | 14.10.1973 | 2296 186900]
[27.03.1970 : Joe Walker Harrison | 27.03.1970 | 3104 599700]
[18.11.1973 : Richard Pierce Pierce | 18.11.1973 | 5434 072400]
[20.09.1987 : Zachary David Polk | 20.09.1987 | 4524 723400]
[22.11.1943 : Ronald Wilson Harrison | 22.11.1943 | 2703 797300]
[07.05.1994 : Joe Cleveland Nixon | 07.05.1994 | 6160 620200]
[04.07.1981 : James Tyler Arthur | 04.07.1981 | 1495 851100]
[24.02.1940 : Lyndon Herbert Fillmore | 24.02.1940 | 9918 875400]
[17.12.1934 : Ronald Madison Grant | 17.12.1934 | 4852 133800]
[12.03.2008 : George Walker Eisenhower | 12.03.2008 | 3569 909300]
[16.11.1939 : James Baines Madison | 16.11.1939 | 2385 465300]
[27.04.1935 : James Fillmore Roosevelt | 27.04.1935 | 7328 226700]
[13.02.1961 : Joe Herbert Truman | 13.02.1961 | 8598 979500]
[18.05.1957 : Andrew Baines Tyler | 18.05.1957 | 0942 350900]
[16.06.1972 : James Alan Obama | 16.06.1972 | 8919 067900]
[24.08.1969 : Abraham Pierce Kennedy | 24.08.1969 | 8536 047700]
[18.02.1948 : Chester Jefferson Fillmore | 18.02.1948 | 0379 389500]
[04.01.2004 : Chester Henry Adams | 04.01.2004 | 9146 024400]
[04.12.1978 : George Taylor Truman | 04.12.1978 | 1106 899300]
[25.09.1983 : Andrew Grant Garfield | 25.09.1983 | 2811 374000]
[27.02.1975 : James S. Monroe | 27.02.1975 | 0717 187400]
[26.02.1978 : Zachary Hussein Kennedy | 26.02.1978 | 3927 777900]
[11.10.1939 : James Alan Garfield | 11.10.1939 | 1121 207100]
[14.01.1934 : Dwight Cleveland Roosevelt | 14.01.1934 | 3051 260000]
[08.10.1985 : John Walker Washington | 08.10.1985 | 6153 036300]
[05.09.1931 : Zachary Taylor Fillmore | 05.09.1931 | 8337 986800]
[23.05.1962 : Grover Henry Madison | 23.05.1962 | 2829 266700]
[22.03.1956 : Dwight Pierce Garfield | 22.03.1956 | 2579 476100]
[04.06.1951 : James David Jefferson | 04.06.1951 | 6113 175100]
[19.05.1966 : Abraham Baines Grant | 19.05.1966 | 2315 089700]
[13.07.1982 : George S. Monroe | 13.07.1982 | 5024 969500]
[28.03.1971 : Dwight Jackson Garfield | 28.03.1971 | 1659 196200]
[11.06.2000 : Lyndon Fitzgerald Polk | 11.06.2000 | 8757 806100]
[07.03.1984 : Thomas Walker Bush | 07.03.1984 | 1166 000200]
[08.05.1956 : Millard David Jefferson | 08.05.1956 | 4819 582700]
[09.12.1964 : George Milhous Clinton | 09.12.1964 | 0465 627400]
[18.02.1952 : Theodore Jefferson Adams | 18.02.1952 | 8440 112200]
[15.03.1947 : James Milhous Adams | 15.03.1947 | 1686 375000]
[09.07.1990 : John Pierce Taylor | 09.07.1990 | 5313 130400]
[13.10.1961 : Barack Woodrow Eisenhower | 13.10.1961 | 5545 555900]
[05.06.1986 : Franklin Abram Bush | 05.06.1986 | 8663 335000]
[18.09.1988 : Chester Birchard Monroe | 18.09.1988 | 7803 716400]
[01.04.1984 : Franklin Fillmore Garfield | 01.04.1984 | 5759 149100]
[27.01.1941 : Dwight Cleveland Reagan | 27.01.1941 | 0296 890600]
[18.09.1964 : Rutherford Cleveland Reagan | 18.09.1964 | 4281 520600]
[15.02.1988 : William Abram Arthur | 15.02.1988 | 5321 804300]
[20.02.1999 : James Grant Hayes | 20.02.1999 | 7106 024700]
[21.08.1986 : Abraham Madison Pierce | 21.08.1986 | 6720 157400]
[28.12.1973 : George Buchanan Arthur | 28.12.1973 | 8174 155500]
[21.04.2003 : Barack Birchard Buchanan | 21.04.2003 | 0895 776400]
[09.07.2005 : John Fitzgerald Washington | 09.07.2005 | 1371 727800]
[04.12.2003 : James Henry Pierce | 04.12.2003 | 0640 616000]
[08.07.1972 : Thomas Tyler Monroe | 08.07.1972 | 4865 101300]
[17.11.1988 : James Delano Adams | 17.11.1988 | 5161 474000]
[27.03.1984 : Thomas Quincy Lincoln | 27.03.1984 | 0037 997600]
[20.09.1952 : James Mason Washington | 20.09.1952 | 6361 867800]
[24.09.1993 : George Birchard Taylor | 24.09.1993 | 4917 218600]
[12.11.1963 : Dwight Herbert Buchanan | 12.11.1963 | 3875 225900]
[04.02.2002 : George Fitzgerald Grant | 04.02.2002 | 6906 388500]
[08.05.1992 : John Monroe Adams | 08.05.1992 | 7247 310300]
[23.08.1938 : Grover Delano Kennedy | 23.08.1938 | 4342 406400]
[11.07.1938 : Millard Wilson Washington | 11.07.1938 | 2890 760500]
[10.06.1965 : Bill Fitzgerald Madison | 10.06.1965 | 3688 189400]
[15.08.1953 : John Delano Taylor | 15.08.1953 | 3377 741500]
[15.03.1958 : Abraham Robinette Buchanan | 15.03.1958 | 6452 353600]

Getting element by key '08.10.1985':
Got element John Walker Washington | 08.10.1985 | 6153 036300
Number of collisions: 36
```
