#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Tree.h"

using namespace std;

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
