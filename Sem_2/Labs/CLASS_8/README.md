# Вариант задания
Лабораторная работа по классам №8, вариант 11. 
Базовый класс:

ЧЕЛОВЕК (Person)

Имя - string

Возраст - int

Производный класс

СТУДЕНТ (Student)

Рейтинг float

Группа - Дерево (Тгее).

Команды:

Создать группу (формат команды: т количество элементов группы).

Добавить элемент в группу (формат команды: +)

Удалить элемент из группы (формат команды -)

Вывести информацию об элементах группы (формат команды: s)

Вывести информацию об элементе группы (формат команды:? номер объекта в группе)

Конец работы (формат команды: q)

# Код программы
```cpp
#include <iostream>
#include "dialog.h"
#include "vector.h"
#include "student.h"
using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmFind = 7;
const int cmQuit = 101;

struct TEvent {
    int what;
    union {
        int command;
        struct {
            int message;
            int a;
        };
    };
};

class Object
{
public:
	Object(void) {};
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object(void) {};
	virtual void HandleEvent(const TEvent& e) = 0;
};

class Person : public Object {
protected:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);
	Person(const Person& p);
	virtual ~Person();
	string get_name();
	int get_age();
	void set_name(string name);
	void set_age(int age);
	Person& operator =(const Person& p);
	void Show();
	void Input();
	void HandleEvent(const TEvent& r);
};

Person::Person() {
	name = " ";
	age = 0;
}

Person::Person(string N, int A) {
	name = N;
	age = A;
}

Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}

Person::~Person() {}

string Person::get_name() { return name; }

int Person::get_age() { return age; }

void Person::set_name(string N) { name = N; }

void Person::set_age(int A) { age = A; }

Person& Person::operator=(const Person& person) {
	if (&person == this) { return *this; }
	name = person.name;
	age = person.age;
	return *this;
}

void Person::Show() {
	cout << "\nPerson name: " << name << endl;
	cout << "\nPerson age: " << age << endl;
}

void Person::Input() {
	cout << "\nEnter name: "; cin >> name;
	cout << "\nEnter age: "; cin >> age;
}

void Person::HandleEvent(const TEvent& r) {
	if (r.what == evMessage) {
		switch (r.command) {
		case cmGet:cout << "Автор = " << this->get_age() << endl;
			cout << "Имя = " << this->get_name() << endl;
			break;
		}
	}
}

class Student : public Person {
protected:
	float rating;
public:
	Student();
	Student(string name, int age, float rating);
	Student(const Student& s);
	~Student();
	float get_rating() { return rating; }
	void set_rating(float rating);
	void Show();
	void Input();
	Student& operator=(const Student&);
};

Student::Student() { rating = 0; }
Student::~Student() {}
void Student::Show() {
	cout << "\nStudent name: " << name << "\n";
	cout << "\nStudent age: " << age << "\n";
	cout << "\nStudent rating: " << rating << "\n";
}

void Student::Input() {
	cout << "\nEnter student name: "; cin >> name;
	cout << "\nEnter student age: "; cin >> age;
	cout << "\nEnter student rating: "; cin >> rating;
}

Student::Student(string N, int A, float R) {
	name = N;
	age = A;
	rating = R;
}

Student::Student(const Student& student) {
	name = student.name;
	age = student.age;
	rating = student.rating;
}
Student& Student::operator=(const Student& student) {
	if (&student == this) { return *this; }
	name = student.name;
	age = student.age;
	rating = student.rating;
	return *this;
}
void Student::set_rating(float R) {
	rating = R;
}

class Dialog :
	public Vector {
protected:
	int EndState;
public:
	Dialog();
	virtual ~Dialog();
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
};

Dialog::Dialog(void) : Vector() {
	EndState = 0;
}

Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event) {
	string OpInt = "+-s?qm";
	string s;
	string param;

	char code;
	cout << '>';
	cin >> s;
	code = s[0];
	if (OpInt.find(code) >= 0) {
		event.what = evMessage;
		switch (code) {
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'q': event.command = cmQuit; break;
		case '?': event.command = cmFind; break;
		}
		if (s.length() > 1) {
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else { event.what = evNothing; }
}
int Dialog::Execute() {
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}
int Dialog::Valid() {
	if (EndState == 0) { return 0; }
	else { return 1; }
}
void Dialog::ClearEvent(TEvent& event) { event.what = evNothing; }
void Dialog::EndExec() { EndState = 1; }
void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake:
			cout << "Enter size: ";
			cin >> size;
			beg = new Object * [size];
			cur = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del();
			ClearEvent(event);
			break;
		case cmShow:
			Show();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		case cmFind:
			int tmp = event.a;
			Find(tmp);
			ClearEvent(event);
			break;
			//default:Vector::HandleEvent(event);
		}
	}
}

class Vector
{
public:
	Vector(int);//конструктор с параметрами
public:
	~Vector(void);//деструктор
	Vector();
	void Add();//добавление элемента в вектор 👨🏻‍💻👨🏻‍💻👨🏻‍💻
	void Del();
	void Show();
	void Find(int);
	int operator()();//размер вектора
	void HandleEvent(const TEvent& y) {
		if (y.what == evMessage) {
			Object** p = this->beg;
			for (int i = 0; i < this->cur; i++) {
				(*p)->HandleEvent(y);
				p++;
			}
		}
	};
protected:
	Object** beg;//указатель на первый элемент вектора 
	int size;//размер
	int cur;//текущая позиция
};

Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

Vector::Vector() {
	beg = nullptr;
	cur = 0;
	size = 0;
}

//конструктор с параметрами 
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор 	
void Vector::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов 
	cout << "\n1.Person\n2.Student\nnВведите номер выбранного варианта >> ";
	int y;
	cin >> y; cout << "\n";
	if (y == 1)//добавление объекта класса 
	{
		Person* a = new Person();
		a->Input();//ввод значений атрибутов
		p = a;

		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор cur++;
			cur++;
		}
	}
	else if (y == 2) //добавление объекта класса
	{
		Student* b = new Student();
		b->Input();
		p = b;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}

//просмотр вектора
void Vector::Show()
{
	if (cur == 0) cout << "Пустой" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание) 
		p++;//передвигаем указатель на следующий объект
	}

}
void Vector::Find(int tmp) {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		if (i == tmp - 1) { (*p)->Show(); }
		p++;
	}
}

//операция, которая возвращает размер вектора 
int Vector::operator ()()
{
	return cur;
}
//удаление элемента из вектора, память не освобождается! 
void Vector::Del()
{
	if (cur == 0)return;//пустой
	cur--;
}

int main()
{
    system("chcp 1251");
    cout << "m: создать группу" << endl;
    cout << "+: добавить элемент в группу" << endl;
    cout << "-: удалить элемент из группы" << endl;
    cout << "s: вывести информацию об элементах группы" << endl;
    cout << "?: вывести информацию об элементе группы" << endl;
    cout << "q: конец работы" << endl;
    Dialog D;
    D.Execute();
    return 0;
}
```
# Блок-схема программы
<image src="class8.png">
	
# Тесты
### Пример 1
<image src="Screenshot_1.png">
	
# Контрольные вопросы
1.	Что такое класс-группа? Привести примеры таких классов. 
Группа  это объект, в который включены другие объекты. Объекты, входящие в группу, называются элементами группы. Элементы группы, в свою очередь, могут быть группой.
В отличие от контейнера мы понимаем группу как класс, который не только хранит объекты других классов, но и обладает собственными свойствами, не вытекающими из свойств его элементов.
Группа дает второй вид иерархии - иерархию объектов (иерархию типа целое/часть), построенную на основе агрегации, первый вид  иерархия классов, построенная на основе наследования.
Пример:
Класс-группа Vector. Группа содержит указатель на динамический массив указателей типа Object (Object **beg), количество элементов, под которые выделена память (int size), номер последнего элемента, добавленного в группу (int cur).
class Vector {	
public:
    Vector(int);//конструктор с параметрами
public: 
    ~Vector(void);//деструктор
    void Add();//добавление элемента в вектор 
    void Del();
    void Show();
    int operator()();//размер вектора
protected:
    Object**beg;//указатель на первый элемент вектора 
    int size;//размер
    int cur;//текущая позиция };

2.	Привести пример описания класса-группы Список (List).
struct Node {
	Node* prev = nullptr, * next = nullptr;
	Object* data;
};

class List {
public:
	List();
	List(int);
	List(List&);
	~List(void);
	void puchback();
	void popback();
	void Show();
protected:
	Node* head = nullptr, * tail = nullptr;
	int size;
};

3.	Привести пример конструктора (с параметром, без параметров, копирования) для класса-группы Список.
Без параметров:
List::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}
С параметрами:
List::List(int s) {
	for (int i = 0; i < size ; i++) 
		pushback();
}
Копирования:
List::List(const List& a) {
	Node* nodeA = a.head;
	List newList(a.size);
	Node* newNode = newList.head;
	while (nodeA != nullptr) {
		newNode->data = nodeA->data;
		nodeA = nodeA->next;
		newNode = newNode->next;
	}
}

4.	Привести пример деструктора для класса-группы Список.
List::~List() {
	Node* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr->data;
		delete curr;
		curr = head;
	}
}

5.	Привести пример метода для просмотра элементов для класса-группы Список.
void List::Show() {
	if (size == 0) cout << "Empty" << endl;
	Node* p = head;
	for (int i = 0;i < size;i++) {
		p->data->Show();   //вызов метода Show() (позднее связывание) 
		p = p->next;  //передвигаем указатель на следующий объект
	}
}

6.	Какой вид иерархии дает группа?
Группа дает второй вид иерархии - иерархию объектов(иерархию типа целое/часть), построенную на основе агрегации, первый вид  иерархия классов, построенная на основе наследования.

7.	Почему во главе иерархии классов, содержащихся в группе объектов должен находиться абстрактный класс?
Абстрактные классы предназначены для представления общих понятий, которые предполагается конкретизировать в производных классах.
Таким образом, можно создать функцию, параметром которой является указатель на абстрактный класс. На место этого параметра при выполнении программы может передаваться указатель на объект любого производного класса. Это позволяет создавать полиморфные функции, работающие с объектом любого типа в пределах одной иерархии.
Именно поэтому во главе иерархии классов должен находится абстрактный класс.

8.	Что такое событие? Для чего используются события?
События лучше всего представить себе как пакеты информации, которыми обмениваются объекты и которые создаются объектно-ориентированной средой в ответ на те или иные действия пользователя. Нажатие на клавишу или манипуляция мышью порождают событие, которое передается по цепочке объектов, пока не найдется объект, знающий, как обрабатывать это событие. События сами по себе не производят никаких действий в программе, но в ответ на событие могут создаваться новые объекты, модифицироваться или уничтожаться существующие, что и приводит к изменению состояния программы. Иными словами все действия по обработке данных реализуются объектами, а события лишь управляют их работой.
События предназначены для того, чтобы иметь возможность предусмотреть реакцию программы на то или иное действие.

9.	Какие характеристики должно иметь событие-сообщение? 
Сообщение передаваемое от одних объектов другим имеет, как правило, следующие характеристики:
-	код класса сообщения, отличающий сообщения объектов одного класса от объектов другого класса;
-	адрес объекта, которому предназначено сообщение (м.б. не задан, тогда сообщение могут прочитать все объекты);
-	информационное поле.

10.	 Привести пример структуры, описывающей событие.
const int evNothing = 0;      //пустое событие 
const int evMessage = 100; //непустое событие 
const int cmAdd = 1;      // добавить элемент в группу
const int cmDel = 2;       // удалить элемент из группы
const int cmShow = 3;    // вывести информацию об элементах группы
const int cmMake = 4;    // создать группу
const int cmQuit = 101;  // выйти из программы
struct TEvent {
	int what;          //наличие события 
	int command;  //тип команды
};

11.	 Задана структура события 
struct TEvent
{
int what; 
union
{
MouseEventType mouse; 
KeyDownEvent keyDown; 
MessageEvent message;
} };
Какие значения, и в каких случаях присваиваются полю what? 
Поле what задает тип события, определяющий источник данного события. Оно может принимать следующие значения:
-	evNothing - это пустое событие, которое означает, что ничего делать не надо. Полю what присваивается значение evNothing, когда событие обработано каким-либо объектом.
-	evMessage - событие-сообщение от объекта (непустое событие).

12.	Задана структура события
struct TEvent {
int what;//тип события 
union
{
int command;//код команды 
struct//параметры команды {
int message; 
int a; }; }; };
Какие значения, и в каких случаях присваиваются полю command?
Полю command присваиваются коды различных определённых команд. При получении того или иного сообщения, поле command принимает одно из кодов команд (см. пример из вопроса 10).
 
13.	 Задана структура события
struct TEvent {
int what;//тип события 
union {
int command;//код команды 
struct { //параметры команды 
int message; 
int a;  }; };};
Для чего используются поля a и message?
Поля a и message необходимы в случае, если программа получает сообщение с параметром. Тогда поле message будет отвечать за то, какая команда поступила, а поле a будет являться параметром команды.
Пример:
Пользователь вводит следующее сообщение:
+10
В этом случае, программа сначала посмотрит, какую команду мы получили (+ - добавить в группу) и на основе этого запишет в поле message заданную команду, а затем посмотрит, есть ли после символа + целочисленное значение. Далее, программа запишет введенное значение в поле a, и после этого обработчик события будет знать, что необходимо добавить 5 элементов в группу.

14.	 Какие методы необходимы для организации обработки сообщений?
Следующие методы необходимы для организации обработки событий (названия произвольны).
●	GetEvent – формирование события;
●	Execute реализует главный цикл обработки событий. Он постоянно получает событие путем вызова GetEvent и обрабатывает их с помощью HandleEvent. Этот цикл завершается, когда поступит событие «конец».
●	HandleEvent – обработчик событий. Обрабатывает каждое событие нужным для него образом. Если объект должен обрабатывать определенное событие (сообщение), то его метод HandleEvent должен распознавать это событие и реагировать на него должным образом. Событие может распознаваться, например, по коду команды (поле command).
●	ClearEvent очищает событие, когда оно обработано, чтобы оно не обрабатывалось далее.
●	Valid - проверяет, завершена ли работа.
●	EndExec - завершение обработки событий (после вызова этого метода цикл обработки событий заканчивается).

15.	 Какой вид имеет главный цикл обработки событий-сообщений?
Главный цикл обработки событий реализуется в методе Execute главной группы-объекта “прикладная программа” по следующей схеме:
int TMyApp::Execute() {
do {
endState=0;
GetEvent(event); //получить событие 
HandleEvent(event); //обработать событие
//событие осталось не обработано 
if(event.what!=evNothing)
EventError(event); 
} while(!Valid()); 
return endState;
}

16.	 Какую функцию выполняет метод ClearEvent()? Каким образом? 
ClearEvent очищает событие, присваивая полю event.what значение evNothing.

17.	 Какую функцию выполняет метод HandleEvent()? Каким образом?
Получив событие (структуру типа TEvent), обработчик событий для класса TDerivedClass обрабатывает его по следующей схеме:
void TDerivedClass::HandleEvent(TEvent& event) { 
//Вызов обработчика событий базового класса
TBaseClass::HandleEvent( event );
if (event.what == evCommand) { // Если обработчик базового
// событие не обработал
switch( event.message.command ) {
case cmCommand1: 
// Обработка команды cmCommand1;
СlearEvent( event ); 
break;
case cmCommand2: 
// Обработка команды cmCommand2; 
СlearEvent( event );
break; …
case cmCommandN:
// Обработка команды cmCommandN 
СlearEvent( event );
break;
default: // событие не обработано 
break;
} }; 
}

18.	 Какую функцию выполняет метод GetEvent()?
Метод GetEvent() выполняет функцию формирования события на основе полученного сообщения.

19.	 Для чего используется поле EndState? Какой класс (объект) содержит это поле?
Поле EndState используется в классе Dialog и отвечает за состояние работы диалога (идёт/завершён).
class Dialog : 
	public Vector 
{
public:
	Dialog(void);
	~Dialog(void);//деструктор
	void GetEvent(TEvent& event);//получить событие 
	void Execute();//главный цикл обработки событий 
	void HandleEvent (TEvent& event); //обработчик 
	void ClearEvent (TEvent & event);//очистить событие 
	bool Valid();//проверка атрибута EndState
	void EndExec();//обработка события «конец работы» 
protected:
	int EndState;
};
 
20.	 Для чего используется функция Valid()?
Функция Valid проверяет состояние поля EndState. Она возвращает значение True, если программа не завершена, False - если завершена. Используется в главном обработчике событий Execute.
bool Dialog::Valid() {
	return EndState == 0;
}
void Dialog::Execute() {
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event); //получить событие 
		HandleEvent(event); //обработать событие
	} while (Valid()); 
}
