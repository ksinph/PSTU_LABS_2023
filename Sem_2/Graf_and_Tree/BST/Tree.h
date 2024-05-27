#ifndef TREE_H
#define TREE_H

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

#endif
