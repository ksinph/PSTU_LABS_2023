//поиск элемента
template <class S>
SearchTree<S>* SearchTree<S>::findElement(S dt) {
	if ((this == NULL) || (dt == this->data))
		return this;
	if (dt < this->data) return this->left->findElement(dt);
	else return this->right->findElement(dt);
}

//вставка узла
template <class S>
void SearchTree<S>::insertNode(S dt) {
	SearchTree<S>* tree = this;
	while (tree != NULL) {
		if (dt >= tree->data) {
			if (tree->right != NULL) {
				tree = tree->right;
			}
			else {
				SearchTree<S>* t = new SearchTree<S>(dt);
				t->parent = tree;
				tree->right = t;
				break;
			}
		}
		else if (dt < tree->data) {
			if (tree->left != NULL) {
				tree = tree->left;
			}
			else {
				SearchTree<S>* t = new SearchTree<S>(dt);
				t->parent = tree;
				tree->left = t;
				break;
			}
		}
	}
}

//удаление узла
template<class S>
void SearchTree<S>::deleteNode(S dt) {
	SearchTree<S>* e = this->findElement(dt);
	SearchTree<S>* p = e->parent; //предок удаляемого элемента
	33
		// Первый случай: удаляемый элемент не имеет потомков
		if ((e->left == NULL) && (e->right == NULL)) {
			if (p->left == e) p->left = NULL;
			if (p->right == e) p->right = NULL;
		}
}

// Второй случай: удаляемый элемент имеет одного потомка
else if ((e->left == NULL) || (e->right == NULL)) {
	if (e->left == NULL) {
		if (p->left == e) p->left = e->right;
		else p->right = e->right;
		e->right->parent = p;
	}
	перенос части кода
	else {
		if (p->left == e) p->left = e->left;
		else p->right = e->left;
		e->left->parent = p;
	}
}

// Третий случай: удаляемый элемент имеет двух потомков
else {
	SearchTree<S>* s = e->next();
	// Следующий элемент за удаляемым
	e->data = s->data;
	if (s->parent->left == s) {
		s->parent->left = s->right;
		if (s->right != NULL)
			s->right->parent = s->parent;
	}
	else {
		s->parent->right = s->right;
		if (s->right != NULL)
			s->right->parent = s->parent;
	}
}