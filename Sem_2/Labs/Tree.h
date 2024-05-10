struct Node
{
	int num;
	Node* left, * right;
};

struct BinaryTree
{
	Node* root;
	int counter;
	int node_count = 0;

};

void AddToSubTree(Node*& node, Node* newnode);//функция поддерева, предаем ссылку на указатель  

void AddToTree(BinaryTree& tree, int d);
void PrintNode(Node* node);
void PrintTree(BinaryTree tree, int d);
int SeaarchInTree(BinaryTree  tree, int d); 