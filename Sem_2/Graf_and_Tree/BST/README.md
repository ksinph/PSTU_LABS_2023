# Вариант задания
Тип информационного поля int. Найти среднее арифметическое элементов дерева.

Самостоятельно придумать вид Дерева и реализовать алгоритмы для этого собственного варианта бинарного дерева поиска, имеющего не менее трёх уровней .

Алгоритмы:

2.1. Необходимо реализовать функции для редактирования дерева:

Вставка узла.
Удаление узла.
Поиск элемента по ключу. 2.2 Реализовать алгоритмы обхода дерева: 2.3 Прямой 2.4 Симметричный 2.5 Обратный 2.6 Выполнить задание своего варианта из методички: Laby_Chast_3.docx
Реализовать алгоритм балансировки дерева.

Реализовать вертикальную и горизонтальную печать.

Визуализацию дерева выполнить с использованием любой доступной графической библиотеки – SFML, SDL, OpenGL…

Пользовательский интерфейс – на усмотрение разработчика - с условием кроссплатформенности (например, Windows Forms; также поощряется использование Qt или иных фреймворков).
# Код программы
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Tree.h"

using namespace std;

struct Node {
    int data;
    int counter;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) : data(value), counter(1), left(NULL), right(NULL), parent(NULL) {}
};

struct BinaryTree {
    Node* root;

    BinaryTree() : root(NULL) {}
};

void AddToSubTree(Node* parent, Node*& node, Node* newnode);
void AddToTree(BinaryTree& tree, int d);
void PrintNode(Node* node);
void PrintTree(BinaryTree tree);
void PrintSubTreeStructure(Node* node, int depth, bool isroot = false);
void PrintTreeStructure(BinaryTree tree);
void DeleteNode(BinaryTree& tree, int d);
void Reorder(Node* node);
void InOrder(Node* node);
void PostOrder(Node* node);
Node* SearchInSubTree(Node* node, int d);
Node* SearchInTree(BinaryTree tree, int d);
Node* FindMin(Node* node);
Node* FindMax(Node* node);
Node* SearchNext(Node* node);
Node* SearchPrev(Node* node);

BinaryTree BalancedTree(int* sorted_elements, int start, int end);

void AddToSubTree(Node* parent, Node*& node, Node* newnode) {
    if (node == NULL) {
        newnode->parent = parent;
        node = newnode;
        return;
    }
    if (newnode->data == node->data) {
        node->counter += newnode->counter;
        delete newnode;
        return;
    }

    if (newnode->data < node->data) {
        AddToSubTree(node, node->left, newnode);
    }
    else {
        AddToSubTree(node, node->right, newnode);
    }
}

void AddToTree(BinaryTree& tree, int d) {
    Node* newnode = new Node(d);
    AddToSubTree(NULL, tree.root, newnode);
}

void PrintNode(Node* node) {
    if (node == NULL) return;
    PrintNode(node->left);
    printf(" %i", node->data);
    if (node->counter > 1) {
        printf("x%i", node->counter);
    }
    PrintNode(node->right);
}

void PrintTree(BinaryTree tree) {
    PrintNode(tree.root);
}

void PrintSubTreeStructure(Node* node, int depth, bool isroot) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) {
        printf("| ");
    }
    printf("b\b\--%2d\n", node->data);

    PrintSubTreeStructure(node->left, depth + 1);
    PrintSubTreeStructure(node->right, depth + 1);
}

void PrintTreeStructure(BinaryTree tree) {
    if (tree.root != NULL) {
        printf("%2d\n", tree.root->data);
    }
    PrintSubTreeStructure(tree.root, 1);
}

Node* SearchInSubTree(Node* node, int d) {
    if (node == NULL) return NULL;
    if (node->data == d) return node;
    if (d < node->data) {
        return SearchInSubTree(node->left, d);
    }
    else {
        return SearchInSubTree(node->right, d);
    }
}

Node* SearchInTree(BinaryTree tree, int d) {
    return SearchInSubTree(tree.root, d);
}

Node* FindMin(Node* node) {
    if (node->left == NULL) return node;
    return FindMin(node->left);
}

Node* FindMax(Node* node) {
    if (node->right == NULL) return node;
    return FindMax(node->right);
}

Node* SearchNext(Node* node) {
    if (node->right != NULL) return FindMin(node->right);
    Node* parent = node->parent;
    while (parent != NULL && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node* SearchPrev(Node* node) {
    if (node->left != NULL) return FindMax(node->left);
    Node* parent = node->parent;
    while (parent != NULL && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void DeleteNode(BinaryTree& tree, int d) {
    Node* node = SearchInTree(tree, d);
    if (node == NULL) return;

    if (node->left == NULL && node->right == NULL) {
        if (node->parent != NULL) {
            if (node->parent->left == node) node->parent->left = NULL;
            else node->parent->right = NULL;
        }
        else {
            tree.root = NULL;
        }
        delete node;
        return;
    }

    if (node->left == NULL || node->right == NULL) {
        Node* child = (node->left != NULL) ? node->left : node->right;
        if (node->parent != NULL) {
            if (node->parent->left == node) node->parent->left = child;
            else node->parent->right = child;
        }
        else {
            tree.root = child;
        }
        child->parent = node->parent;
        delete node;
        return;
    }

    Node* successor = SearchNext(node);
    node->data = successor->data;
    node->counter = successor->counter;
    if (successor->parent->left == successor) successor->parent->left = successor->right;
    else successor->parent->right = successor->right;
    if (successor->right != NULL) successor->right->parent = successor->parent;
    delete successor;
}

void Reorder(Node* node) {
    if (node != NULL) {
        cout << node->data << " ";
        Reorder(node->left);
        Reorder(node->right);
    }
}

void InOrder(Node* node) {
    if (node != NULL) {
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }
}

void PostOrder(Node* node) {
    if (node != NULL) {
        PostOrder(node->left);
        PostOrder(node->right);
        cout << node->data << " ";
    }
}

BinaryTree BalancedTree(int* sorted_elements, int start, int end) {
    BinaryTree tree;
    if (start > end) return tree;

    int mid = (start + end) / 2;
    AddToTree(tree, sorted_elements[mid]);
    BinaryTree leftSubTree = BalancedTree(sorted_elements, start, mid - 1);
    BinaryTree rightSubTree = BalancedTree(sorted_elements, mid + 1, end);

    if (leftSubTree.root != NULL) AddToSubTree(tree.root, tree.root->left, leftSubTree.root);
    if (rightSubTree.root != NULL) AddToSubTree(tree.root, tree.root->right, rightSubTree.root);

    return tree;
}

void sortArray(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    BinaryTree tree;
    int n;
    scanf("%i", &n);

    int* elements = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%i", &elements[i]);
    }

    sortArray(elements, n);

    tree = BalancedTree(elements, 0, n - 1);
    PrintTree(tree);
    printf("\n");

    printf("Enter new number: ");
    int d;
    scanf("%i", &d);
    AddToTree(tree, d);
    PrintTree(tree);
    printf("\n");

    printf("Enter number to search: ");
    scanf("%i", &d);
    Node* res = SearchInTree(tree, d);
    if (res) {
        printf("This tree has number %i in quantity %i\n", d, res->counter);
    }
    else {
        printf("Number %i not found in the tree.\n", d);
    }
    printf("\n");

    PrintTreeStructure(tree);

    printf("Enter number to delete: ");
    scanf("%i", &d);
    DeleteNode(tree, d);
    printf("\n");
    PrintTreeStructure(tree);

    printf("Pre-order traversal:\n");
    Reorder(tree.root);
    printf("\n");

    printf("In-order traversal:\n");
    InOrder(tree.root);
    printf("\n");

    printf("Post-order traversal:\n");
    PostOrder(tree.root);
    printf("\n");

    Node* maxres = FindMax(tree.root);
    if (maxres) {
        printf("Maximum number: %i\n", maxres->data);
    }
    else {
        printf("Tree is empty.\n");
    }

    delete[] elements;
    return 0;
}
```
# Блок-схема программы
<image src="class2.drawio.svg">
	
# Тесты
<image src="tree.png">
