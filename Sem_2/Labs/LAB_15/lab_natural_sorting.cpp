#include <iostream>
using namespace std;
const int cnt = 25;

void element(int arr[])
{
    for (int i = 0; i < cnt; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void TrueMerge(int* arr, int right, int left)
{
    int PackOne = 1;
    int PackTwo = 1;
    int index = 0;
    bool NeedOneMore = false;
    while (arr[index] <= arr[index + 1] && index < right - 1) // Вычисление размера первой серии
    {
        PackOne++;
        index++;
    }
    if (arr[index] > arr[index + 1] && index < right - 1) // Вычисление размера второй серии
    {
        index++;
        NeedOneMore = true;
        while (arr[index] <= arr[index + 1] && index < right - 1)
        {
            PackTwo++;
            index++;
        }
    }
    int number = index + 1; // Number = индекс первого числа последовательности, не входящего в серию
    int* farr = new int[PackOne]; // farr и sarr - серии. Далее они инициализируются
    int* sarr = new int[PackTwo];
    for (index = 0; index < PackOne; index++)
    {
        farr[index] = arr[index];
    }
    int tempindex = 0;
    if (NeedOneMore)
    {
        for (index = PackOne; index < PackOne + PackTwo; index++)
        {
            sarr[tempindex] = arr[index];
            tempindex++;
        }
    }
    cout << endl;
    cout << "1: ";
    for (int i = 0; i < PackOne; i++)
    {
        cout << farr[i] << " ";
    }
    cout << endl << endl;
    cout << "2: ";
    for (int i = 0; i < PackTwo; i++)
    {
        cout << sarr[i] << " ";
    }
    cout << endl << endl;
    int j = 0;
    int l = 0;
    if (NeedOneMore)
    {
        for (index = 0; index < number; index++)
        {
            if ((farr[l] < sarr[j] || j >= PackTwo) && l < PackOne)
            {
                arr[index] = farr[l];
                l++;
            }
            else
                if ((farr[l] > sarr[j] || l >= PackOne) && j < PackTwo)
                {
                    arr[index] = sarr[j];
                    j++;
                }
                else
                    if (farr[l] == sarr[j] && j < PackTwo && l < PackOne)
                    {
                        arr[index] = farr[l];
                        arr[index + 1] = sarr[j];
                        l++;
                        j++;
                        index++;
                    }
        }
    }
}

void multiPhaseSort(int arr[])
{
    bool swapped = true;
    int gap = cnt;
    while (gap > 1 || swapped)
    {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;
        for (int i = 0; i < cnt - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void Sort(int* arr, int right, int left)
{
    if (left < right)
    {
        TrueMerge(arr, right, left);
        Sort(arr, right, left + 1);
    }
}

void PhaseSort(int* arr, int right, int left)
{
    if (left < right)
    {
        multiPhaseSort(arr);
        PhaseSort(arr, right, left + 1);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[cnt];
    for (int i = 0; i < cnt; i++) arr[i] = rand() % 10;
    element(arr);
    cout << endl;
    cout << "1 - естественная сортировка \n2 - многофазная сортировка \nВведите цифру которая бдует соответствовать сортировке которую нужно применить: ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        Sort(arr, cnt, 0);
        break;
    case 2:
        PhaseSort(arr, cnt, 0);
        break;
    default:
        cout << "Неправильный выбор";
    }
    cout << endl;
    element(arr);
    return 0;
}
