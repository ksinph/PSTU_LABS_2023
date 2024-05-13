#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
using namespace std;

void AddToSubTree(Node* parent, Node*& node, Node* newnode)
{
	
	if (node == NULL )//если пустое поддерево, то выходим
	{
		newnode->parent = parent; 
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
		AddToSubTree(node,node->left, newnode);//добавляем в левое поддерево
	}
	else
	{
		AddToSubTree(node,node->right, newnode);//добавляем в правое поддерево
	}
}

void AddToTree(BinaryTree& tree, int d)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = d;
	newnode->counter = 1;
	newnode->left = newnode->right = newnode->parent = NULL;
	AddToSubTree(NULL,tree.root, newnode);
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

Node* FindMin(Node* node)
{
	if (node->left == NULL) return node;
	return FindMin(node->left);
}

Node* FindMax(Node* node)
{
	if (node->right == NULL) return node;
	return FindMax(node->right);
}

Node* SearchNext(Node* node, int d)
{
	if (node->right != NULL)
		return FindMin(node->right);
	Node* prnt = node->parent;
	while ((prnt != NULL) && (node == prnt->right)) {
		node = prnt;
		prnt = prnt->parent;
	}
	return prnt;
}

Node* SearchPrev(BinaryTree tree, int d)
{
	Node* node = SearchInSubTree(tree.root, d);
	if (node->left != NULL)
		return FindMax(node->left);
	Node* prnt = node->parent;
	while ((prnt != NULL) && (node == prnt->left)) {
		node = prnt;
		prnt = prnt->parent;
	}
	return prnt;
}

void DeleteNode(BinaryTree tree, int d)
{
	Node* node = SearchInSubTree(tree.root, d);//поиск удаляемого элемента
	Node* parent = node->parent; //предок удаляемого элемента
	// Первый случай: удаляемый элемент не имеет потомков
	if ((node->left == NULL) && (node->right == NULL))
	{
		if (parent->left == node) parent->left = NULL;
		if (parent->right == node) parent->right = NULL;
	}

	// Второй случай: удаляемый элемент имеет одного потомка
	else if ((node->left == NULL) || (node->right == NULL))
	{
		if (node->left == NULL)//для правого потомка
		{
			if (parent->left == node) parent->left = node->right;
			else parent->right = node->right;
			node->right->parent = parent;
		}
		//для левого потомка
		else
		{
			if (parent->left == node) parent->left = node->left;
			else parent->right = node->left;
			node->left->parent = parent;
		}
	}

	// Третий случай: удаляемый элемент имеет двух потомков
	else
	{
		Node* next_node = SearchNext(node, d);
		// Следующий элемент за удаляемым
		node->data = next_node->data;
		if (next_node->parent->left == next_node)//удаляемый элемент находится слева
		{
			next_node->parent->left = next_node->right;
			if (next_node->right != NULL)
				next_node->right->parent = next_node->parent;
		}
		else//удаляемый элемент находится справа
		{
			next_node->parent->right = next_node->right;
			if (next_node->right != NULL)
				next_node->right->parent = next_node->parent;
		}
	}
}

// ПРЯМОЙ ОБХОД (СВЕРХУ ВНИЗ)
void Reorder(Node* node) 
{
	if (node != NULL) {
		cout<< node->data << " ";
		Reorder(node->left);
		Reorder(node->right);
	}
}

// СИММЕТРИЧНЫЙ ОБХОД (СЛЕВА НАПРАВО)
void InOrder(Node *node) 
{
	if (node != NULL) {
		InOrder(node->left);
		cout << node->data << " ";
		InOrder(node->right);
	}
}

// ОБРАТНЫЙ ОБХОД (СНИЗУ ВВЕРХ)👩🏻‍🎤👩🏻‍🎤👩🏻‍🎤
void PostOrder(Node* node) 
{
	if (node != NULL) {
		PostOrder(node->left);
		PostOrder(node->right);
		cout <<node->data << " ";
	}
}
/*
template <class T>
Node<T>* BalancedTree(BinaryTree& tree, int d)
{
	if (d == 0) return;	
	Node* node = SearchInSubTree(tree.root, d);
	Node* prnt = node->parent;
    AddToSubTree(NULL, node->left, BalancedTree( NULL,d / 2));
    AddToSubTree(NULL, node->right, BalancedTree( NULL,d - 1 - d / 2));

}*/

void BalancedTree(Node* node,int n)
{
	if (n == 0) return;
	Node* newnode = (Node*)malloc(sizeof(Node));
	/*newnode->left = newnode->right = NULL;
	Tree<T>* tree = new Tree<T>(dt);*/
	BalancedTree(newnode->left, n / 2);
	int d;
	cin >> d;
	
	newnode->data = d;
	
	BalancedTree(newnode->right, n - 1 - n / 2);
	cin >> d;
	newnode->data = d;
}
