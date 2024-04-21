#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;


//вывод массива на экран
void showArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout « setw(4) « arr[i]; if ((i + 1) % 10 == 0)
		{
			cout « endl;
		}
	}
	cout « endl « endl;
}

//линейный поиск
int linSearch(int arr[], int requiredKey, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == requiredKey) return i;
	}
	return -1;
}

// функция с алгоритном двоичного поиска
int Search_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd(left + right) / 2;
		if (key < arr[midd])//если искомое меньше значения в ячейке
			right midd - 1;//смещаем правую границу поиска
		else if (key > arr[midd])//если искомое больше значения в ячейке
			left = midd + 1;//смещаем левую границу поиска
		else// иначе(значения равны)
			return midd;// функция возвращает индекс ячейки
		if (left > right)// если границы сомкнулись
			return -1;
	}
}

int interpolatingSearch(int a[], int arraySize, int keyOfSearch)
{
	//изначально устанавливаем нижний индекс на начало массива,
	//а верний на конец массива
	int low = 0;
	int high = arraySize - 1;
	int mid;

	while (a[low] < keyOfSearch && a[high] >= keyOfSearch) {
		//оценка новой области поиска
		//по расстоянию между ключом поиска и текущим значение элемента
		mid = low + ((keyOfSearch - a[low]) * (high - low)) / (a[high] - a[low]);

		//если значение в ячейке с индексом mid меньше, то смещаем нижнюю границу
		if (a[mid] < keyOfSearch) {
			low = mid + 1;
		}
		//в случае, если значение больше, то смещаем верхнюю границу
		else {
			if (a[mid] > keyOfSearch)
			{
				high = mid - 1;
			}
			else
			{
				return mid;
			}
		}
	}
	//если цикл while не вернул индекс искомого значения,
	//то проверяем не находится ли оно в ячейке массива с индексом low,
	//иначе возвращаем -1 (значение не найдено)
	if (a[low] == keyOfSearch)
		return low;
	return -1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[] = { 0, 101, 78, 12, 55, 92, 1, 2, 4, 12, 7, 16, 34, 5, 6, 4, 23, 60, 28, 52, 11, 3, 43, 6, 2 };
	int requiredKey = 0; // искомое значение (ключ)
	int nElement = 0; // исемер элемента массива
	srand(time(NULL));
	//запись случ. чисел в массив от 1 до 50 
	for (int i = 0; i < arrSize; i++)
	{ 
		arr[i] = 1 + rand() % 50;
	}
	showArr(arr, arrSize);
	cout « "Какое число необходимо искать?";
	cin » requiredKey; // ввод искомого числа

	//поиск искомого числа и запись номера элемента nElement linSearch(arr, requiredKey, arrSize);
	if (nElement != -1)
	{
		//если в массиве найдено искомое число выводим индекс элемента на экран
		cout « "Значение «< requiredKey «< находится в ячейке с индексом: «« nElement « endl;
	}
	else
	{
		//если в массиве не найдено искомое число
		cout « "В массиве нет такого значения «< endl;
	}
	return 0;
}


int main()
{
	setlocale(LC_ALL, "rus");
	const int SIZE = 12;
	int array[SIZE] = {};
	int key = 0;
	int index = 0; // индекс ячейки с искомым значением
	for (int i = 0; i < SIZE; i++) // заполняем и показываем массив
	{
		array[i] = i + 1;
		cout « array[i] « " ";
	}
	cout « "\n\nвведите любое число: ";
	cin » key;
	index = Search_Binary(array, 0, SIZE, key);
	if (index >= 0)
		cout « "указанное число находится в ячейке с индексом: " « index « < "\n\n";
	else
		cout « "в массиве нет такого числа!\n\n";
	return 0;
}