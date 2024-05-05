template <class S>
class SearchTree {
public:
	S data; // ������ ���� �
	SearchTree* left; // ��������� �� ���� �����
	SearchTree* right; // ��������� �� ���� ������
	SearchTree* parent; // ��������� �� ������
	SearchTree(S); // �����������
	~SearchTree(); // ����������
	void deleteSearchTree() { delete this; }
	// ������� ������
	void printSearchTree(int);
	// �������������� ������ ������
	void inOrder(SearchTree<S>*);
	// ������������ ����� ������
	void setData(Sdt) { data = dt; }
	// ���������� ������ ��� ����
	SearchTree<S>* next(); // ����� ��������� �������
	SearchTree<S>* prev(); // ����� ���������� �������
	void insertNode(S); // �������� ����
	void deleteNode(S); // ������� ����
	SearchTree<S>* findElement(S); // ����� �������
	SearchTree<S>* findMax(); // ����� ��������
	SearchTree<S>* findMin(); // ����� �������
};