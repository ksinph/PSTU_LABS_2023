#include <iostream>
#include <stdio.h>
#include "tree.h"
using namespace std;

int main()
{
	BinaryTree tree;
	int n;
	scanf_s("%i", &n);
	int d;
	for (int i=0;i<n;i++)
	{
		scanf_s("%i", &d);
		AddToTree(tree, d);
	}
	PrintTree(tree);
	cout << endl;
	scanf_s("%i", &d);
	int res = SearchInTree(tree, d);
	printf("This tree has number %i in quantility %i\n", d, res);
	cout << endl;
	PrintTreeStructure(tree);
	return 0;
}