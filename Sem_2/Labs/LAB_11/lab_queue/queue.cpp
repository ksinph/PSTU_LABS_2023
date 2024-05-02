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
};
// Очередь 
class List
{ // Адрес головного элемента списка 
public:
    Element* Tail;
    Element* Head;
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
    temp->Next = NULL;
    if (pos == 0 && Count==0)
    {
        /*temp->Next = Tail;*/
        Tail = temp;
        Head = temp;
    }
    else if (pos == Count) {
        temp->Next = NULL;
        Tail->Next = temp;
        Tail = temp;
        
    }
    else {
        int mas[50];
        for (int i = 0; i < pos; i++)
        {
            mas[i] = Head->data;
            temp = Head;
            Head = temp->Next;
            delete temp;
        }

        Element* temp = new Element;
        temp->data = data;
        temp->Next = Head;
        Head = temp;

        for (int i = pos-1; i >= 0; i--)
        {
            Element* temp = new Element;
            temp->data = mas[i];
            temp->Next = Head;
            Head = temp;
        }
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
        cout << " "<<temp->data ;
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
        Tail = NULL;
        Head = NULL;
        Count--;
        return;
    }
    if (position == 1) {
        Head = temp->Next;
        delete temp;
        Count--;
        return;
    }

    int mas[50];
    for (int i = 0; i < position -1; i++)
    {
        mas[i] = Head->data;
        temp = Head;
        Head = temp->Next;
        delete temp;
    }

    temp = Head;
    Head = temp->Next;
    delete temp;

    for (int i = position - 2; i >= 0; i--)
    {
        Element* temp = new Element;
        temp->data = mas[i];
        temp->Next = Head;
        Head = temp;
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
        DelElement(Count);
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
    cout << "\nВведите позицию с коротой добавлять:\n";
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
