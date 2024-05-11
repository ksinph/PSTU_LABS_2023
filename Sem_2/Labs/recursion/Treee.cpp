#include <iostream>
#include <stdio.h>
#include "tree.h"

void AddToSubTree(Node*& node, Node* newnode)
{
	if (node == NULL)//���� ������ ���������, �� �������
	{
		node = newnode;
		return;
	}
	if (newnode->data == node->data)//���� ����� ����� ��������� � ������� 
	{
		node->counter += newnode->counter;//� ������� ����� ����������� ������� ������
		free(newnode);//����������� ������
		return;
	}

	if (newnode->data < node->data)//���� ������ �� �����, �� ���� � �����
	{
		AddToSubTree(node->left, newnode);//��������� � ����� ���������
	}
	else
	{
		AddToSubTree(node->right, newnode);//��������� � ������ ���������
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
	printf(" %i", node->data);//������ ����� ������
	if(node->counter>1)
	{
		printf("x%i", node->counter);
	}
	PrintNode(node->right);
}

void PrintTree(BinaryTree tree)
{
	PrintNode(tree.root);
}

void PrintSubTreeStructure(Node* node, int depth,bool isroot)
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
	PrintSubTreeStructure(tree.root, 0,true);
}

int SearchInSubTree(Node* node, int d)
{
	if (node == NULL) return 0;//��� ���������
	if (node->data == d)
	{
		return node->counter;
	}
	if(d<node->data)//���� � ����� ���������
	{
		SearchInSubTree (node->left,d);
	}
	else//������ ���������
	{
		SearchInSubTree (node->right, d);
	}
}

int SearchInTree(BinaryTree tree, int d)
{
	return SearchInSubTree(tree.root,d);
}