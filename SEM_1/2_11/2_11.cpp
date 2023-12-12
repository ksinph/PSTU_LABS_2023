#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, y;
	int ch = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> y;
		if (y != 0 and ch == 0)
		{
			
			if (y < 0)
			{
				ch = -1;
			}
			else
			{
				ch = 1;
			}
		}
		else
		{
			ch = 0;
		}
	}

	if (ch == -1)
	{
		cout << "число отрицательное";
	}
	else if(ch==1)
	{
		cout << "число положительное";
	}
	else
	{
		cout << "значение не имеет знака";
	}
	return 0;
}
