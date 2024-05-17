#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Node //—труктура дл€ узла дерева ветвей и границ
{
    vector<vector<int>> reducedMatrix;
    vector<int> path;
    int cost;
    int vertex;
    int level;

    Node(const vector<vector<int>>& costMatrix, const vector<int>& p, int c, int v, int l)
        : path(p), cost(c), reducedMatrix(costMatrix), vertex(v), level(l) {}

    bool operator<(const Node& other) const {
        return cost > other.cost;  // Changed to > to make set a min-heap
    }
};

vector<vector<int>> readCostMatrix(const string& filename);
int reduceMatrix(vector<vector<int>>& matrix);
pair<int, vector<int>> TSPBranchAndBound(const vector<vector<int>>& costMatrix);