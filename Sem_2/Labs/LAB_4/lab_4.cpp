#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	int k, n;
	int arr[100] = {};
	srand(time(NULL));
	cout << "n ";
	cin >> n;
	cout << " k ";
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
		cout << arr[i] << " ";
		
	}
	cout << endl;

	for (int j = k - 1; j < n - 1; j++)
	{
		arr[j] = arr[j+1];
	}
	n--;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = n-1; i >0; i--)
	{
		if (i % 2 != 0) {
			for (int j = n-1; j > i; j--)
			{
				arr[j+1] = arr[j];
			}
			arr[i+1] = 0;
			i--;
			n++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}