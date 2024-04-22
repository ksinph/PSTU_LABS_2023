#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int menu()
{
	cout << "1 - линейный поиск" << endl;
	cout << "2 - бинарный поиск" << endl;
	cout << "3 - интерполяионный поиск" << endl;
	cout << "Введите нужную цифру: ";
	int kolvo;
	cin >> kolvo;
	return kolvo;
}

//вывод массива на экран
void showArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void linSearch(int arr[], int arrSize, int key)
{
	int* tmp = new int[0];
	int tmp_size = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == key)
		{
			tmp[tmp_size++] = i;
		}
	}
	if (tmp_size != 0)
	{
		for (int j = 0; j < tmp_size; j++)
		{
			cout << "Ключ найден на позиции: " << tmp[j] + 1 << endl;
		}
	}
	else 
	{ 
		cout << "Ключ не найден\n"; 
	}
}

void binarySearch(int arr[], int arraySize, int key) {
	int low = 0;
	int high = arraySize - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
		{
			cout << "Ключ найден на позиции: " << mid + 1 << endl;
			break;
		}
		else if (arr[mid] < key) low = mid + 1;
		else high = mid - 1;
	}
}

void interpolatingSearch(int a[], int arraySize, int key)
{
	if (a[0] == key) { cout << "Ключ найден на позиции: 1" << endl; return; }
	//изначально устанавливаем нижний индекс на начало массива,
	//а верний на конец массива
	int low = 0;
	int high = arraySize - 1;
	int mid;
	int keyPlace = -1;
	while (a[low] < key && a[high] >= key) {
		//оценка новой области поиска
		//по расстоянию между ключом поиска и текущим значение элемента
		mid = low + ((key - a[low]) * (high - low)) / (a[high] - a[low]);

		//если значение в ячейке с индексом mid меньше, то смещаем нижнюю границу
		if (a[mid] == key) 
		{ 
			keyPlace = mid + 1; 
			break;
		}
		//в случае, если значение больше, то смещаем верхнюю границу
		else 
		{
			if (a[mid] > key) high = mid - 1;
			else low=mid+1;
		}
	}
	if (keyPlace != -1)
	{
		cout << "Ключ найден на позиции: " << keyPlace << endl;
	}
	else
	{
		cout << "Ключ не найден" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size, key,tmp=0;
	cout << "Введите длинну массива: ";
	cin >> size;
	int* array = new int[size];
	switch (menu())
	{
	case 1:
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 21;
		}
		cout << "Исходный массив: ";
		showArr(array, size);
		cout << "Введите значение которое надо искать: ";
		cin >> key;
		linSearch(array, size, key);
		break;
	case 2:
		for (int i = 0; i < size; i++)
		{
			tmp += rand() % 3 + 1;
			array[i] = tmp;
		}
		cout << "Исходный массив: ";
		showArr(array, size);
		cout << "Введите значение которое надо искать: ";
		cin >> key;
		binarySearch(array, size, key);
		break;
	case 3:
		for (int i = 0; i < size; i++)
		{
			tmp += rand() % 3 + 1;
			array[i] = tmp;
		}
		cout << "Исходный массив: ";
		showArr(array, size);
		cout << "Введите значение которое надо искать: ";
		cin >> key;
		interpolatingSearch(array, size, key);
		break;
	default:
		cout << "Неподходящее значение ";
		break;
	}
	return 0;
}