void AddToSubTree(Node*& node, Node* newnode)
{
	if(node==NULL)//если пустое поддерево, то выходим
	{
		node = newnode;
		return;
	}
	if (newnode->data==node->data)//если новое число совпадает с текущим 
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
	AddToSubTree(tree, root, d);
}

PrintNode(Node* node)
{
	if (node == NULL) return;
	PrintNode(node->left);
	print("%i",node->data)//вывели левый корень
	PrintNode(node->right);
}

void PrintTree(BinaryTree& tree, int d)
{
	PrintNode(tree.root);
}
int SeaarchInTree(BinaryTree& tree, int d);