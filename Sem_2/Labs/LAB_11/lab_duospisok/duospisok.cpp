#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <fstream>
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
using namespace std;
// Элемент данных 
struct Element
{
    // Данные 
    int data;
    // Адрес следующего элемента списка 
    Element* Next;
    Element* Back;
};
// Двунаправленный список 
class List
{ // Адрес головного элемента списка 
public:
    Element* Head;
    Element* Tail;
    // Количество элементов списка 
    int Count;
public:
    // Конструктор 
    List();
    // Добавление элемента в список 
    void Add(int pos, int data);
    void DelElement(int position);
    // Распечатка содержимого списка 
    void Print();
    void Write();
    void Read();
    void DelSpisok();
};
List::List()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
void List::Add(int pos, int data) {
    // создание нового элемента 
    Element* temp = new Element;
    temp->data = data;
    if (pos == 0) {
        temp->Next = Head;
        temp->Back = NULL;
        Head = temp;
        if (Count == 0) Tail = temp;
    }
    else if(pos==Count)
    {
        temp->Next = NULL;
        temp->Back = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    
    else if(pos<=Count/2){
        Element* prev = Head;
        Element* current = Head->Next;
        int cnt = 1;

        while (cnt != pos) {
            prev = current;
            current = current->Next;
            cnt++;
        }
        prev->Next = temp;
        temp->Next = current;
        temp->Back = prev;
        current->Back = temp;
    }
    else
    {
        Element* prev = Tail;
        Element* current = Tail->Back;
        int cnt = Count-1;

        while (cnt != pos) {
            prev = current;
            current = current->Back;
            cnt--;
        }
        prev->Back = temp;
        temp->Next = prev;
        temp->Back = current;
        current->Next = temp;
    }
    Count++;
}
void List::Print()
{
    if (Count == 0) {
        cout << "Список пустой";
        return;
    }
    // запоминаем адрес головного элемента 
    Element* temp = Head;
    // Пока еще есть элементы 
    while (temp != 0)
    {
        // Выводим данные 
        cout << temp->data << " ";
        // Переходим на следующий элемент 
        temp = temp->Next;
    }
    cout << endl;
}

void List::DelElement(int position)
{
    if (Count < position || Count == 0 || position <= 0) return;
    Element* temp = Head;
    if (Count == 1)
    {
        delete temp;
        Head = NULL;
        Tail = NULL;
        Count--;
        return;
    }
    if (position == 1) {
        Head = temp->Next;
        Head->Back = NULL;
        delete temp;
        Count--;
        return;
    }
    if (position == Count) {
        Element* temp = Tail;
        Tail = temp->Back;
        Tail->Next = NULL;
        delete temp;
        Count--;
        return;
    }

    if (position <= Count / 2)
    {
        int ind = 0;
        position -= 2;
        while (ind != position)
        {
            temp = temp->Next;
            ind++;
        }
        //элемент лефт удаляемый
        Element* left = temp->Next;
        Element* right = left->Next;

        temp->Next = right;
        right->Back = temp;
        delete left;
    }
    else
    {
        Element* temp = Tail;
        int ind = Count;
        position += 1;
        while (ind != position)
        {
            temp = temp->Back;
            ind--;
        }
        //элемент right удаляемый
        Element* right = temp->Back;
        Element* left = right->Back;

        temp->Back = left;
        left->Next = temp;
        delete right;
    }
    Count--;
}

void List::Write()
{
    FILE* F;
    if ((F = fopen("file.bin", "wb")) == NULL) exit(5);
    fwrite(&Count, sizeof(int), 1, F);
    Element* temp = Head;
    for (int i = 0; i < Count; i++)
    {
        int data = temp->data;
        fwrite(&data, sizeof(Element), 1, F);
        temp = temp->Next;
    }
    fclose(F);
}

void List::Read()
{
    FILE* F;
    int data;
    int lng = 0;
    if ((F = fopen("file.bin", "rb")) == NULL) exit(6);
    fread(&lng, sizeof(int), 1, F);
    for (int i = 0; i < lng; i++)
    {

        fread(&data, sizeof(Element), 1, F);
        Add(i, data);
    }
    fclose(F);
}

void List::DelSpisok()
{
    while (Count != 0)
    {
        DelElement(1);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int k, n, x, y, q;
    // Создаем объект класса List 
    List lst;
    cout << "\nВведите количество элементов:\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nВведите элемент:\n";
        cin >> k;
        lst.Add(i, k);
    }
    cout << "Заполненный список:" << endl;
    lst.Print();
    cout << "\nВведите позицию с которой добавлять:\n";
    cin >> y;
    if (y > 0)
    {
        cout << "\nВведите елемент:\n";
        cin >> x;
        lst.Add(y, x);
    }
    lst.Print();
    cout << "\nВведите номер элемента для удаления:\n";
    cin >> q;
    lst.DelElement(q);
    lst.Print();
    lst.Write();
    lst.DelSpisok();
    cout << endl;
    lst.Print();
    lst.Read();
    cout << endl;
    lst.Print();
    lst.DelSpisok();
    return 0;
}
