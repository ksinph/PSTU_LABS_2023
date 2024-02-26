#include <iostream>
using namespace std;
/*
        В двумерном массиве записаны слова, представляющие собой последовательность цифр, завершающихся 0.
        Необходимо распечатать слова через запятую, заключив печатную строку в скобки.
        Длина печатной строки 60 символов.Извлечение слова оформить в виде функции.
*/
void getWord(int height, int width,int* seq[]) {
   
    cout << endl << "(";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (seq[i][j] == 0)
            {
                cout << ",";
            }
            else
            {
                cout << seq[i][j];
            }
        }
    }
    cout << ")" << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    const int height = 3;
    const int width=4;
    
    int seq[height][width] = {{1230,2340,230,3450}, {234450,2345670,10}, {234455677670,450}};
    getWord(height, width, seq[]);
    return 0;
}
