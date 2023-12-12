#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n,y;
	bool ch = true;
	cin >> n;
	while (n != 0)
	{
		cin >> y;
		if (y != 0 and n > y)
		{
			
			ch = false;
		}
		n = y;
	}
if (ch)
{
	cout << "возрастает";
}
else
{
	cout << "не возрастает";
}
return 0;
}
