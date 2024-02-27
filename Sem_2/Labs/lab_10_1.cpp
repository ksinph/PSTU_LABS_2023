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
	int* mass = new int[n - k];
	for (int i = 0; i < k; i++)
	{
		mass[i] = arr[i];
	}
	for (int i = k-1; i < n ; i++)
	{
		mass[i] = arr[i + k-1];
	}
	n--;
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << ' ';
	}
	delete[] arr;
	cout << endl;
	cout << "Введите номер, куда нужно вставить элемент: ";
	cin >> l;
	cout << "Введите значение элемента: ";
	cin >> s;
	int*  itog= new int[n - k + 1];
	for (int i = 0; i < l; i++)
	{
		itog[i] = mass[i];
	}
	itog[l] = s;
	for (int i = l + 1; i < n - k + 1; i++)
	{
		itog[i+1] = mass[i];
	}
	delete[] mass;
	for (int i = 0; i < n - k + 1; i++)
	{
		cout << itog[i] << " ";
	}
	delete[] itog;
	return 0;
}