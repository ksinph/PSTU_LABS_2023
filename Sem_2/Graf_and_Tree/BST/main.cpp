#include <iostream>
#include <stdio.h>
#include "Tree.h"
using namespace std;

int main()
{
	BinaryTree tree;
	int n;
	scanf_s("%i", &n);/*
	int d;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%i", &d);
		AddToTree(tree, d);
	}
	PrintTree(tree);
	printf("\n");
	printf("Vvedite novoe chislo ");
	scanf_s("%i", &d);
	AddToTree(tree, d);
	PrintTree(tree);
	printf("\n");
	scanf_s("%i", &d);
	Node* res = SearchInTree(tree, d);
	printf("This tree has number %i in quantility %i\n", d, res->counter);
	printf("\n");
	PrintTreeStructure(tree);
	printf("Vvedite udalyaemy element ");
	scanf_s("%i",&d);
	DeleteNode(tree, d);
	printf("\n");
	PrintTreeStructure(tree);
	printf("Pryamoi obhod \n");
	Reorder(tree.root);
	printf("\n");
	printf("Simmetrichny obhod \n");
	InOrder(tree.root);
	printf("\n");
	printf("Obratny obhod \n");
	PostOrder(tree.root);
	printf("\n");
	Node* maxres = FindMax(tree.root);
	printf("Maximalnoe chislo %i",maxres->data);
	printf("\n");*/
	BinaryTree tre;
	BalancedTree(tre.root,n);
	PrintTreeStructure(tre);
	return 0;
}