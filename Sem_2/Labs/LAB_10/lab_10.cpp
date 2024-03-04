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
	int* mass = new int[n - 1];
	for (int i = 0; i < k-1; i++)
	{
		mass[i] = arr[i];
	}
	for (int i = k-1; i < n -1; i++)
	{
		mass[i] = arr[i + 1];
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
	n += 1;
	int*  itog= new int[n];
	
	for (int i = 0; i < l - 1; i++)
	{
		itog[i] = mass[i];
	}
	for (int i = l - 1; i < n-1; i++)
	{
		itog[i+1] = mass[i];
		
		
	}
	itog[l - 1] = s;
	delete[] mass;
	for (int i = 0; i < n; i++)
	{
		cout << itog[i] << " ";
	}
	delete[] itog;
	return 0;
}
