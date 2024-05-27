#include <iostream>
#include <stdio.h>
#include "Tree.h"

using namespace std;

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
