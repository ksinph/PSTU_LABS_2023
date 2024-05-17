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
    cout << "������� ��� ����� � �������� ������: ";
    cin >> filename;

    vector<vector<int>> costMatrix = readCostMatrix(filename);

    ifstream file(filename);
    if (!file) {
        cerr << "�� ������� ������� ����: " << filename << endl;
        return 1;
    }

    cout << "�������� ������� ������:\n";
    for (const auto& row : costMatrix) {
        for (int cost : row) {
            cout << cost << " ";
        }
        cout << endl;
    }

    /*int minCost = TSPBranchAndBound(costMatrix);
    cout << "����������� ��������� ������: " << minCost << endl;*/
    auto result = TSPBranchAndBound(costMatrix);
    int cost = result.first;
    vector<int> path = result.second;


    if (cost == INF) {
        cout << "�� ������� ����� �������." << endl;
    }
    /*else {
        cout << "����������� ���������: " << cost << endl;
        cout << "����: ";
        for (int city : path) {
            cout << city + 1 << "->";
        }
        cout << path[0] + 1 << endl;  // ����������� � �������� ������
    }*/
    else {
        cout << "����������� ���������: " << cost << endl;
        cout << "����: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] + 1;
            if (i < path.size() - 1) {
                cout << "->";
            }
        }
        cout << endl;  // ����������� � �������� ������
    }
    return 0;
}