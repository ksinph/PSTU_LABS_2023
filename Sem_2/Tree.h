template <class S>
class SearchTree {
public:
	S data; // Данные типа Т
	SearchTree* left; // Указатель на узел слева
	SearchTree* right; // Указатель на узел справа🧙‍♀️🧙‍♀️🧙‍♀️
	SearchTree* parent; // Указатель на предка
	SearchTree(S); // Конструктор
	~SearchTree(); // Деструктор
	void deleteSearchTree() { delete this; }
	// Удалить дерево
	void printSearchTree(int);
	// Горизонтальная печать дерева
	void inOrder(SearchTree<S>*);
	// Симметричный обход дерева
	void setData(Sdt) { data = dt; }
	// Установить данные для узла
	SearchTree<S>* next(); // Найти следующий элемент
	SearchTree<S>* prev(); // Найти предыдущий элемент
	void insertNode(S); // Вставить узел
	void deleteNode(S); // Удалить узел
	SearchTree<S>* findElement(S); // Найти элемент
	SearchTree<S>* findMax(); // Найти максимум
	SearchTree<S>* findMin(); // Найти минимум
};