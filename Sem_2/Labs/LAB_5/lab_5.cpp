#include <iostream>
#include <ctime>
using namespace std;
int** createArr(int height, int width) 
{
    int** seq = new int* [height];
    for (int l = 0; l < height; l++)
        seq[l] = new int[width];
    return seq;
}

int** fillArr(int** seq, int height, int width) 
{
    srand(time(NULL));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            seq[i][j] = rand() % 10;
    return seq;
}

void getWord(int** a, int height, int width) {
    cout << endl << "(";
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (a[i][j] == 0)
                cout << ", ";
            else
                cout << a[i][j];
    cout << ")" << endl;
}

void main() {
    setlocale(LC_ALL, "Russian");
    int i, j, l, height, width;
    cout << "Введите высоту массива: \n";
    cin >> height;
    cout << "Введите ширину массива: \n";
    cin >> width;
    width++;
    int** seq;
    seq = fillArr(createArr(height, width), height, width);
    getWord(seq, height, width);
    system("pause");
}
