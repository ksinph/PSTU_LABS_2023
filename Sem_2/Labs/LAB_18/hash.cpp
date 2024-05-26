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
