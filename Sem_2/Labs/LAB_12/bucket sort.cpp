#include <iostream>
using namespace std;
const int quantity = 10;

int menu()
{
    cout << "1 - сортировка ведрами(карманами)"<<endl;
    cout << "2 - сортировка подсчетом"<<endl;
    cout << "3 - сортировка слиянием"<<endl;
    cout << "4 - быстрая сортировка"<<endl;
    cout<< "Введите нужную цифру: ";
    int kolvo;
    cin >> kolvo;
    return kolvo;
}

void show_array(int arr[])
{
    for (int i = 0; i < quantity; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bucketSort(int arr[])
{
    const int bucket_num = 10;
    const int bucket_size = 10;

    int buckets[bucket_num][bucket_size];

    int bucket_sizes[bucket_num] = { 0 };
    // раскидали по ведрам
    for (int i = 0; i < quantity; i++)
    {
        int bucket_index = arr[i] / bucket_num;
        buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
        bucket_sizes[bucket_index]++;
    }
    // сортируем каждое ведро
    for (int i = 0; i < bucket_num; i++)
    {
        // сортировка вставками или любая другая
        for (int j = 0; j < bucket_sizes[i]; j++)
        {
            int tmp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > tmp)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = tmp;
        }
    }
    // складываем все обратно
    int idx = 0;
    for (int i = 0; i < bucket_num; i++)
    {
        for (int j = 0; j < bucket_sizes[i]; j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }
}

void countSort(int arr[])
{
    int* output = new int[quantity];
    int* count;
    int max = arr[0];
    for (int i = 0; i < quantity; i++)
    {
        if (arr[i] > max) max = arr[i]; 
    }

    count = new int[max + 1];
    for (int i = 0; i <= max; ++i) count[i] = 0; 
    // выполняем подсчет
    for (int i = 0; i < quantity; i++) count[arr[i]]++;
    // делаем вычисление префиксных сумм
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    // заполняем массив выходной
    for (int i = quantity - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    // модифицируем исходный массив (опционально)
    for (int i = 0; i < quantity; i++) arr[i] = output[i];

    delete[] count;
}

void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
    delete[] left;
    delete[] right;
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int* array = new int [quantity];
    for (int i = 0; i < quantity; i++)
    {
        array[i] = rand() % 10; 
    }
    cout << "Исходный массив: ";
    show_array(array);
    switch (menu())
    {
    case 1:
        bucketSort(array);
        cout << "Отсортированный массив: ";
        show_array(array);
        break;
    case 2:
        countSort(array);
        cout << "Отсортированный массив: ";
        show_array(array);
        break;
    case 3:
        mergeSort(array, 0, quantity - 1);
        cout << "Отсортированный массив: ";
        show_array(array);
        break;
    case 4:
        quickSort(array, 0, quantity - 1);
        cout << "Отсортированный массив: ";
        show_array(array);
        break;
    default:
        cout << "Неподходящее значение ";
        break;
    }
    return 0;
}
