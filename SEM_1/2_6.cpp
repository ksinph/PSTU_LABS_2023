#include <iostream>


using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "Неподходящее число";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int sp = 1; sp < i; sp++)
            {
                cout << " ";
            }
            for (int stars = 1; stars <= n - i + 1; stars++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}