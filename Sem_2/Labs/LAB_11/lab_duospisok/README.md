# Вариант задания
Лабараторная работа №11, вариант 1.
1. Написать функцию для создания списка. Функция может
создавать пустой список, а затем добавлять в него
элементы.
2. Написать функцию для печати списка. Функция должна
предусматривать вывод сообщения, если список пустой.
3. Написать функции для удаления и добавления элементов
списка в соответствии со своим вариантом.
4. Выполнить изменения в списке и печать списка после
каждого изменения.
5. Написать функцию для записи списка в файл.
6. Написать функцию для уничтожения списка.
7. Записать список в файл, уничтожить его и выполнить
печать (при печати должно быть выдано сообщение "Список
пустой").
8. Написать функцию для восстановления списка из файла.
9. Восстановить список и распечатать его.
10. Уничтожить список.

1. Записи в линейном списке содержат ключевое поле типа
int. Сформировать двунаправленный список. Удалить из
него элемент с заданным номером, добавить элемент с
заданным номером.
# Код программы
```cpp
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
```
# Блок-схема программы
## Функция main
<image src="main.drawio.svg">

## Структура Element
<image src="element.drawio.svg">	

## Класс List
<image src="class.drawio.svg">	

## Конструктор List
<image src="struct.drawio.svg">	

## Функция Add
<image src="add.drawio.svg">	

## Функция Print
<image src="print.drawio.svg">	

## Функция DelElement
<image src="delelement.drawio.svg">	

## Функция Write
<image src="write.drawio.svg">	

## Функция Read
<image src="read.drawio.svg">	

## Функция DelSpisok
<image src="delspisok.drawio.svg">	
	
# Тесты
### Пример 1
Входные данные:
```
Введите количество элементов:
0
Заполненный список:
Список пустой
Введите позицию с которой добавлять:
0
Список пустой
Введите номер элемента для удаления:
0
```
Выходные данные:
```
Список пустой
```
### Пример 2
Входные данные:
```
Введите количество элементов:
5

Введите элемент:
1

Введите элемент:
2

Введите элемент:
3

Введите элемент:
4

Введите элемент:
5
Заполненный список:
1 2 3 4 5

Введите позицию с которой добавлять:
3

Введите элемент:
9
1 2 3 9 4 5

Введите номер элемента для удаления:
3
```
Выходные данные:
```
Список пустой
1 2 9 4 5
```
### Пример 3
Входные данные:
```
Введите количество элементов:
4

Введите элемент:
8

Введите элемент:
-3

Введите элемент:
5

Введите элемент:
1
Заполненный список:
8 -3 5 1

Введите позицию с которой добавлять:
1

Введите елемент:
9
8 9 -3 5 1

Введите номер элемента для удаления:
0
8 9 -3 5 1
```
Выходные данные:
```
Список пустой
8 9 -3 5 1
```
