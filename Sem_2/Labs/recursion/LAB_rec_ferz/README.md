# Вариант задания
Расставить на стандартной 64-клеточной шахматной доске 8 ферзей так, чтобы ни один из них не находился под боем другого.
# Код программы
```cpp
#include <iostream>
using namespace std;
int board[8][8];
const int queen = -1;
void resetboard();
void showboard();
bool checkqueen(int i);
bool deletequeen(int i,int j);
void setqueen(int i, int j);

void resetboard()
{
    for (int i = 0;i<8;i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }
}
void showboard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] = queen) { cout << "[Q] "; }
            else { cout << "[ ] "; }
        }
        cout << endl;
    }
}
void setqueen(int i,int j)
{
    int d;
    for (int x = 0;x<8;++x)
    {
        board[x][j]++;//указываем на клетку по вертикали атакует
        board[i][x]++;//по горизонтали
        d = j - i + x;//вычисляем 1 диагональ
        if (d >= 0 && d < 8) { board[x][d]++; }
        d = j + i - x;//вычисляем 2 диагональ
        if (d >= 0 && d < 8) { board[x][d]++; }
    }
    board[i][j] = queen;
}
void deletequeen(int i, int j)
{
    int d;
    for (int x = 0; x < 8; ++x)
    {
        board[x][j]--;//указываем на клетку по вертикали атакует
        board[i][x]--;//по горизонтали
        d = j - i + x;//вычисляем 1 диагональ
        if (d >= 0 && d < 8) { board[x][d]--; }
        d = j + i - x;//вычисляем 2 диагональ
        if (d >= 0 && d < 8) { board[x][d]--; }
    }
    board[i][j] = 0;
}
//на вход достаточно подать номер строки
bool checkqueen(int i)
{
    bool result = false;
    for (int j = 0; j < 8; ++j)//сначала проверяем что ферзь никого не бьет поэтому ++джи
    {
        if (board[i][j] == 0)
        {
            setqueen(i, j);//пробуем поставить ферзя и разметить клетки под боем
            if (i == 7) {
                result = true;
            }
            else if (!(result = checkqueen(i + 1)))
            {
                deletequeen(i, j);
            }

        }
        if (result) { break; }
    }
    return result;
}
int main()
{
    //запилить случайную позицию кто хочет 
    //или ввод пользователем конкретной клетки
    resetboard();
    checkqueen(0);
    showboard();
    return 0;
}
```
# Блок-схема программы
<image src="lab_ferz.drawio.png">
	
# Тесты
### Пример 1
Входные данные:
```
a
s
d
f
g
h
j
k
l
z
```
Выходные данные:
```
s
f
h
k
z
```
