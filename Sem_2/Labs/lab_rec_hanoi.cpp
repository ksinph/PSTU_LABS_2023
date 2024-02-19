#include <iostream>
using namespace std;

void hanoi(int n,int start, int buf,int end)
{
    if (n>0)
    {
        hanoi(n - 1, start, buf, end);
        cout << "from " << start << " to ---> " << end << endl;
        hanoi(n - 1, buf, end, start);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n,1,2,3);
    return 0;
}