void AddToSubTree(Node*& node, Node* newnode)
{
	if(node==NULL)//���� ������ ���������, �� �������
	{
		node = newnode;
		return;
	}
	if (newnode->data==node->data)//���� ����� ����� ��������� � ������� 
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
	AddToSubTree(tree, root, d);
}

PrintNode(Node* node)
{
	if (node == NULL) return;
	PrintNode(node->left);
	print("%i",node->data)//������ ����� ������
	PrintNode(node->right);
}

void PrintTree(BinaryTree& tree, int d)
{
	PrintNode(tree.root);
}
int SeaarchInTree(BinaryTree& tree, int d);