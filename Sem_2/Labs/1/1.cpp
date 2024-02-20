#include <iostream>
using namespace std;
int main()
{
    int m, s = 1;
    const int n = 100;
    int a[n][n];
    cin >> m;
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 == 1)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = s;
                s++;
                if (s == 10)
                {
                    s = 1;
                }
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
