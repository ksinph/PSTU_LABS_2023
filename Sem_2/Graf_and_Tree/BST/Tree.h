#include <iostream>

struct Node
{
	int data;
	int counter;
	Node* left, * right;
	Node* parent = NULL;
};

struct BinaryTree
{
	Node* root = NULL;
};

void AddToSubTree(Node* parent, Node*& node, Node* newnode);//функция поддерева, предаем ссылку на указатель    

void AddToTree(BinaryTree& tree, int d);
void PrintNode(Node* node);
void PrintTree(BinaryTree tree);
void PrintSubTreeStructure(Node* node, int depth, bool isroot = false);
void PrintTreeStructure(BinaryTree tree);
void DeleteNode(BinaryTree tree, int d);
void Reorder(Node* node);
void InOrder(Node* node);
void PostOrder(Node* node);
void BalancedTree(Node* node, int d);
Node* SearchInSubTree(Node* node, int d);
Node* SearchInTree(BinaryTree  tree, int d);
Node* FindMin(Node* node);
Node* FindMax(Node* node);
Node* SearchNext(Node* node, int d);
Node* SearchPrev(BinaryTree tree, int d);

/*template <typename T>
class Tree
{
	static Tree<T>* BalancedTree(Node* node, int d);
};*/