#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
int a;
int per, sum = 0;

cin >> a;
if (a <= 0)
{
	cout << "Не является натуральным числом";
}
else
{
    for (int i = 1; i <= a; i++)
    {
        per = 1;
        for (int j = i; j <= 2 * i; j++)
        {
            per *= j;
        }
        sum += per;
    }

}
cout << sum;
return 0;
}
