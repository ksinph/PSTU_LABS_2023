#include<iostream>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, l, s, m;
	srand(time(NULL));
	cout << "Колво элементов массива = ";
	cin >> n;
	int* arr = new int[n];

	cout << "k: ";
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = k - 1; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	cout << "Введите номер, куда нужно вставить элемент: ";
	cin >> l;
	cout << "Введите значение элемента: ";
	cin >> s;
	n += 1;
	for (int i = n-1; i >l-1; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[l - 1] = s;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}
