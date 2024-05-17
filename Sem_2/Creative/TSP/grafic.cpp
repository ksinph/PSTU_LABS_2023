#include "grafic.h"

void display(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < costMatrix.size(); ++i) {
        for (int j = 0; j < costMatrix.size(); ++j) {
            if (i != j && costMatrix[i][j] != INF) {
                drawEdge(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y, costMatrix[i][j]);
            }
        }
    }

    for (int i = 0; i < nodes.size(); ++i) {
        drawNode(nodes[i].x, nodes[i].y, i);
    }

    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < bestPath.size() - 1; ++i) {
        drawEdge(nodes[bestPath[i]].x, nodes[bestPath[i]].y,
            nodes[bestPath[i + 1]].x, nodes[bestPath[i + 1]].y, 0);
    }

    glfwSwapBuffers(window);
}

void reshape(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
}

void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void mouse(GLFWwindow* window, int button, int action, int mods) {
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        for (int i = 0; i < nodes.size(); ++i) {
            int dx = nodes[i].x - x;
            int dy = nodes[i].y - (WINDOW_HEIGHT - y);
            if (dx * dx + dy * dy <= NODE_RADIUS * NODE_RADIUS) {
                selectedNode = i;
                movingNode = true;
                currentX = x;
                currentY = WINDOW_HEIGHT - y;
                break;
            }
        }
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        movingNode = false;
        selectedNode = -1;
    }
}

void motion(GLFWwindow* window, double x, double y) {
    if (movingNode && selectedNode != -1) {
        nodes[selectedNode].x = x;
        nodes[selectedNode].y = WINDOW_HEIGHT - y;
        glfwPostEmptyEvent();
    }
}

void drawNode(int x, int y, int id) {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(x + cos(degInRad) * NODE_RADIUS, y + sin(degInRad) * NODE_RADIUS);
    }
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    drawText(face, to_string(id).c_str(), x - 5, y - 5);
}

void drawEdge(int x1, int y1, int x2, int y2, int cost) {
    // –исуем линию между узлами
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    // Ќаходим середину линии дл€ размещени€ текста
    float midX = static_cast<float>(x1 + x2) / 2.0f;
    float midY = static_cast<float>(y1 + y2) / 2.0f;

    // –исуем текст с стоимостью ребра посередине между узлами
    drawText(face, to_string(cost).c_str(), midX, midY);
}


void drawText(FT_Face face, const char* text, float x, float y) {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);

    for (const char* p = text; *p; p++) {
        if (FT_Load_Char(face, *p, FT_LOAD_RENDER)) {
            continue;
        }

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );

        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(x, y);
        glTexCoord2f(1, 0); glVertex2f(x + face->glyph->bitmap.width, y);
        glTexCoord2f(1, 1); glVertex2f(x + face->glyph->bitmap.width, y - face->glyph->bitmap.rows);
        glTexCoord2f(0, 1); glVertex2f(x, y - face->glyph->bitmap.rows);
        glEnd();

        x += (face->glyph->advance.x >> 6);
    }
}
