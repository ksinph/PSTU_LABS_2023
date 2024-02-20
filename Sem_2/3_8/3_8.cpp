#include <iostream>
using namespace std;
int main()
{
    int n, tmp;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            for (int j = n + 1; j > 0; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i] = -1;
            i++;
            n++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
