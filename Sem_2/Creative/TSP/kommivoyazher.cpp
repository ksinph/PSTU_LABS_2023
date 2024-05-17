#include <set>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <iostream>
#include "kommivoyazher.h"
using namespace std;

// Функция для считывания матрицы затрат из файла
vector<vector<int>> readCostMatrix(const string& filename) {
    ifstream file(filename);
    vector<vector<int>> costMatrix;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> row;
        string cost;
        while (ss >> cost) {
            if (cost == "INF") {
                row.push_back(INF);
            }
            else {
                row.push_back(stoi(cost));
            }
        }
        costMatrix.push_back(row);
    }
    file.close();
    return costMatrix;
}

// Функция для нахождения минимума в строке, исключая конкретный элемент
int rowMin(const vector<vector<int>>& matrix, int row, int excludeCol) {
    int min = INF;
    for (int j = 0; j < matrix.size(); j++) {
        if (j != excludeCol && matrix[row][j] < min) {
            min = matrix[row][j];
        }
    }
    return min;
}

// Функция для нахождения минимума в столбце, исключая конкретный элемент
int colMin(const vector<vector<int>>& matrix, int col, int excludeRow) {
    int min = INF;
    for (int i = 0; i < matrix.size(); i++) {
        if (i != excludeRow && matrix[i][col] < min) {
            min = matrix[i][col];
        }
    }
    return min;
}

// Функция для редукции матрицы и нахождения стоимости редукции
int reduceMatrix(vector<vector<int>>& matrix) {
    int reductionCost = 0;

    // Row reduction
    for (int i = 0; i < matrix.size(); ++i) {
        int rowReduction = INF;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] < rowReduction) {
                rowReduction = matrix[i][j];
            }
        }
        if (rowReduction != INF && rowReduction != 0) {
            reductionCost += rowReduction;
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] != INF) {
                    matrix[i][j] -= rowReduction;
                }
            }
        }
    }

    // Column reduction
    for (int j = 0; j < matrix.size(); ++j) {
        int colReduction = INF;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][j] < colReduction) {
                colReduction = matrix[i][j];
            }
        }
        if (colReduction != INF && colReduction != 0) {
            reductionCost += colReduction;
            for (int i = 0; i < matrix.size(); ++i) {
                if (matrix[i][j] != INF) {
                    matrix[i][j] -= colReduction;
                }
            }
        }
    }

    return reductionCost;
}

pair<int, vector<int>> TSPBranchAndBound(const vector<vector<int>>& costMatrix) {
    auto compare = [](const Node& a, const Node& b) {
        return a.cost < b.cost;
        };
    set<Node, decltype(compare)> pq(compare);

    vector<int> initialPath = { 0 };
    Node root(costMatrix, initialPath, 0, 0, 0);

    root.cost = reduceMatrix(root.reducedMatrix);
    pq.insert(root);

    while (!pq.empty()) {
        Node current = *pq.begin();
        pq.erase(pq.begin());

        if (current.level == costMatrix.size() - 1) {
            current.path.push_back(0);
            return { current.cost, current.path };
        }

        for (int i = 0; i < costMatrix.size(); i++) {
            if (find(current.path.begin(), current.path.end(), i) == current.path.end()) {
                Node child = current;
                child.path.push_back(i);
                child.level = current.level + 1;
                child.vertex = i;
                if (i < current.reducedMatrix.size())
                {
                    child.cost += current.reducedMatrix[current.vertex][i];
                    child.reducedMatrix = current.reducedMatrix;

                    for (int j = 0; j < costMatrix.size(); j++) {
                        child.reducedMatrix[current.vertex][j] = INF;
                        child.reducedMatrix[j][i] = INF;
                    }
                    child.reducedMatrix[i][0] = INF;

                    child.cost += reduceMatrix(child.reducedMatrix);
                    pq.insert(child);
                }
            }
        }
    }

    return { INF, {} };
}