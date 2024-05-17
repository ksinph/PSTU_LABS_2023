#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "kommivoyazher.h"
using namespace std;


int main() 
{
    setlocale(LC_ALL, "Russian");
    string filename;
    cout << "Введите имя файла с матрицей затрат: ";
    cin >> filename;

    vector<vector<int>> costMatrix = readCostMatrix(filename);

    ifstream file(filename);
    if (!file) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return 1;
    }

    cout << "Исходная матрица затрат:\n";
    for (const auto& row : costMatrix) {
        for (int cost : row) {
            cout << cost << " ";
        }
        cout << endl;
    }

    /*int minCost = TSPBranchAndBound(costMatrix);
    cout << "Минимальная стоимость обхода: " << minCost << endl;*/
    auto result = TSPBranchAndBound(costMatrix);
    int cost = result.first;
    vector<int> path = result.second;


    if (cost == INF) {
        cout << "Не удалось найти решение." << endl;
    }
    /*else {
        cout << "Минимальная стоимость: " << cost << endl;
        cout << "Путь: ";
        for (int city : path) {
            cout << city + 1 << "->";
        }
        cout << path[0] + 1 << endl;  // Заканчиваем в исходном городе
    }*/
    else {
        cout << "Минимальная стоимость: " << cost << endl;
        cout << "Путь: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] + 1;
            if (i < path.size() - 1) {
                cout << "->";
            }
        }
        cout << endl;  // Заканчиваем в исходном городе
    }
    return 0;
}