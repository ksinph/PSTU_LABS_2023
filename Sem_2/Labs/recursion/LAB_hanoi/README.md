# Вариант задания
Реализовать Ханойскую башню
# Код программы
```cpp
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
```
# Блок-схема программы
## Функция main
<image src="lab_hanoi.drawio.png">

## Функция hanoi
<image src="lab_hanoi_void.drawio.png">
	
# Тесты
### Пример 1
Входные данные:

```
3
```

Выходные данные:
```
from 1 to ---> 3
from 1 to ---> 3
from 2 to ---> 1
from 1 to ---> 3
from 2 to ---> 1
from 2 to ---> 1
from 3 to ---> 2
```

### Пример 2
Входные данные:
```
5
```
Выходные данные:
```
from 1 to ---> 3
from 1 to ---> 3
from 2 to ---> 1
from 1 to ---> 3
from 2 to ---> 1
from 2 to ---> 1
from 3 to ---> 2
from 1 to ---> 3
from 2 to ---> 1
from 2 to ---> 1
from 3 to ---> 2
from 2 to ---> 1
from 3 to ---> 2
from 3 to ---> 2
from 1 to ---> 3
from 1 to ---> 3
from 2 to ---> 1
from 2 to ---> 1
from 3 to ---> 2
from 2 to ---> 1
from 3 to ---> 2
from 3 to ---> 2
from 1 to ---> 3
from 2 to ---> 1
from 3 to ---> 2
from 3 to ---> 2
from 1 to ---> 3
from 3 to ---> 2
from 1 to ---> 3
from 1 to ---> 3
from 2 to ---> 1
```
### Пример 3
Входные данные:
```
2
```
Выходные данные:
```
from 1 to ---> 3
from 1 to ---> 3
from 2 to ---> 1
```
