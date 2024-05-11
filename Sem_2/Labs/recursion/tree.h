#include <iostream>

struct Node
{
	int data;
	int counter;
	Node* left, * right;
};

struct BinaryTree
{
	Node* root=NULL;
};

void AddToSubTree(Node*& node, Node* newnode);//функция поддерева, предаем ссылку на указатель    

void AddToTree(BinaryTree& tree, int d);
void PrintNode(Node* node);
void PrintTree(BinaryTree tree);
void PrintSubTreeStructure(Node* node,int depth,bool isroot=false);
void PrintTreeStructure(BinaryTree tree);
int SearchInSubTree(Node* node , int d);
int SearchInTree(BinaryTree  tree, int d); 