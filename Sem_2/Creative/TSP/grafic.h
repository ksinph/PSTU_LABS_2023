#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <sstream>

constexpr auto NODE_RADIUS = 20;
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 600;

using namespace std;
#define INF INT_MAX // ќпределение INF как максимального целого значени€

struct GraphNode {
    int x, y;
};

extern FT_Library ft;
extern FT_Face face;
extern vector<GraphNode> nodes;
extern vector<vector<int>> costMatrix;
extern vector<int> bestPath;
extern int minCost;

extern int selectedNode;
extern bool movingNode;
extern int currentX, currentY;

void display(GLFWwindow* window);
void reshape(GLFWwindow* window, int w, int h);
void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse(GLFWwindow* window, int button, int action, int mods);
void motion(GLFWwindow* window, double x, double y);
void drawNode(int x, int y, int id);
void drawEdge(int x1, int y1, int x2, int y2, int cost);
void drawText(FT_Face face, const char* text, float x, float y);