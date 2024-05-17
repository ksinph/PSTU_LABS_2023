#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "kommivoyazher.h"
#include "grafic.h"
using namespace std;

vector<GraphNode> nodes;
vector<vector<int>> costMatrix;
vector<int> bestPath;
int minCost = INF;

int selectedNode = -1;
bool movingNode = false;
int currentX = 0, currentY = 0;

FT_Library ft;
FT_Face face;

int main() 
{
    setlocale(LC_ALL, "Russian");
    string filename;

    // ������������� GLFW
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "TSP Visualizer", nullptr, nullptr);
    if (!window) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    // ������������� FreeType
    if (FT_Init_FreeType(&ft)) {
        cerr << "Could not initialize FreeType Library" << endl;
        return -1;
    }

    if (FT_New_Face(ft, "Mncbi.ttf", 0, &face)) {
        cerr << "Failed to load font" << endl;
        return -1;
    }

    FT_Set_Pixel_Sizes(face, 0, 48);

    cout << "������� ��� ����� � �������� ������: ";
    cin >> filename;

    vector<vector<int>> costMatrix = readCostMatrix(filename);

    if (costMatrix.empty()) { // ���������, ��� ������� �� �����
        cerr << "������ ������ ������� ������" << endl;
        return 1;
    }

    cout << "�������� ������� ������:\n";
    for (const auto& row : costMatrix) {
        for (int cost : row) {
            cout << cost << " ";
        }
        cout << endl;
    }

    auto result = TSPBranchAndBound(costMatrix);
    int cost = result.first;
    vector<int> path = result.second;


    if (cost == INF) {
        cout << "�� ������� ����� �������." << endl;
    }
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

    // ������������� ����� � ��������� �������� (��� ������������)
    int numNodes = costMatrix.size();
    nodes.resize(numNodes);
    for (int i = 0; i < numNodes; ++i) {
        nodes[i] = { rand() % (WINDOW_WIDTH - 2 * NODE_RADIUS) + NODE_RADIUS,
                     rand() % (WINDOW_HEIGHT - 2 * NODE_RADIUS) + NODE_RADIUS };
    }

    glfwSetFramebufferSizeCallback(window, reshape);
    glfwSetKeyCallback(window, keyboard);
    glfwSetMouseButtonCallback(window, mouse);
    glfwSetCursorPosCallback(window, motion);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT, -1.0, 1.0);

    TSPBranchAndBound(costMatrix);

    while (!glfwWindowShouldClose(window)) {
        display(window);
        glfwPollEvents();
    }

    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}