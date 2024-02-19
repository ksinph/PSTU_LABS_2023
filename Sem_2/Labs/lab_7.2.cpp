#include <iostream>
using namespace std;
int func(int k, ...) {
    int s = 0;
    int* p = &k;
 
    for (; k >=1; k--) {
        s += *(++++p);
       
    }
    return s;
}

int main()
{
    cout<<func(3, 1, 7, 9)<<endl;
    cout<<func(7, 1, 3, 4, 1, 7, 8, 8)<<endl;
    cout<<func(11, 1, 0, 2, 3, 4, 5, 6, 7, 8, 1, 0)<<endl;
    return 0;
}