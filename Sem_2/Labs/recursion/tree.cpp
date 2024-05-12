#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

void AddToSubTree(Node*& node, Node* newnode)
{
	/*node = tree; */
	if (node == NULL)//если пустое поддерево, то выходим
	{
		/*newnode.root = node; */
		node = newnode;
		return;
	}
	if (newnode->data == node->data)//если новое число совпадает с текущим 
	{
		node->counter += newnode->counter;//с помощью этого уменьшается глубина дерева
		free(newnode);//освобождаем память
		return;
	}

	if (newnode->data < node->data)//если данные не равны, то идем к детям
	{
		AddToSubTree(node->left, newnode);//добавляем в левое поддерево
	}
	else
	{
		AddToSubTree(node->right, newnode);//добавляем в правое поддерево
	}
}

void AddToTree(BinaryTree& tree, int d)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = d;
	node->counter = 1;
	node->left = node->right = NULL;
	AddToSubTree(tree.root, node);
}

void PrintNode(Node* node)
{
	if (node == NULL) return;
	PrintNode(node->left);
	printf(" %i", node->data);//вывели левый корень
	if (node->counter > 1)
	{
		printf("x%i", node->counter);//elementx2
	}
	PrintNode(node->right);
}

void PrintTree(BinaryTree tree)
{
	PrintNode(tree.root);
}

void PrintSubTreeStructure(Node* node, int depth, bool isroot)
{
	if (node == NULL) return;
	if (isroot)
	{
		printf("%2d\n", node->data);
	}
	else {
		for (int i = 0; i < depth; i++)
		{
			printf("| ");
		}
		printf("b\b\--%2d\n", node->data);
	}
	PrintSubTreeStructure(node->left, depth + 1);
	PrintSubTreeStructure(node->right, depth + 1);
}

void PrintTreeStructure(BinaryTree tree)
{
	PrintSubTreeStructure(tree.root, 0, true);
}

Node* SearchInSubTree(Node* node, int d)
{
	if (node == NULL) return 0;//нет элементов
	if (node->data == d)
	{
		return node;
	}
	if (d < node->data)//ищем в левом поддереве
	{
		SearchInSubTree(node->left, d);
	}
	else//правое поддерево
	{
		SearchInSubTree(node->right, d);
	}
}

Node* SearchInTree(BinaryTree tree, int d)
{
	return SearchInSubTree(tree.root, d);
}
/*
Node* SearchNext(BinaryTree tree, int d)
{
	Node* node=SearchInSubTree(tree.root, d);
	if (node->right != NULL)
		return node->right->findMin();
	Node* parent = node->root;
	while ((parent != NULL) && (node == parent->right)) {
		node = parent;
		parent = parent->root;
	}
	return parent;
}*/
/*
SearchTree<S>* SearchTree<S>::prev() {
	SearchTree* tree = this;
	if (tree->left != NULL)
		return tree->left->findMax();
	SearchTree<S>* t = tree->parent;
	while ((t != NULL) && (tree == t->left)) {
		tree = t;
		t = t->parent;
	}
	return t;
}*/