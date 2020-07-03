#pragma once
#include <functional>
#include <vector>
using namespace std;

template<typename T, typename R = T, T NONE = 0>
class AVL_Tree
{
private:
	struct Node {
		T     element;
		Node* left;
		Node* right;
		int   height;

		Node(T element)	: element(element), height(0),
			left(nullptr), right(nullptr) {}
	};

	Node* root;
	function<R(T)>  key;
	int len;

	//Vector de la búsqueda
	vector<T> all_search;

public:
	AVL_Tree(function<R(T)> key = [](T a) { return a; })
		: key(key), root(nullptr), len(0) {}
	~AVL_Tree() { clear(root); }

	int height() { return height(root); }
	int size() { return len; }
	void clear() { clear(root); len = 0; }

	void add(T elem) { add(root, elem); }
	void remove(R val) { remove(root, val); }

	T find(R val) { return find(root, val); }

	//Igual a
	vector<T> find_all(R val) {
		all_search.clear();
		find_all(root, val);
		return all_search;
	}
	//Mayor a
	vector<T> find_upper(R val) {
		all_search.clear();
		find_upper(root, val);
		return all_search;
	}
	//Menor a
	vector<T> find_lower(R val) {
		all_search.clear();
		find_lower(root, val);
		return all_search;
	}
	//Contenido
	vector<T> find_ContaiN(R val, function<R(T)> start) {
		all_search.clear();
		find_ContaiN(root, val, start);
		return all_search;
	}


	T greaterThan(R val) { return greaterThan(root, val); }

	void inOrder(function<void(T)> proc) { inOrder(root, proc); }
	void postOrder(function<void(T)> proc) { inOrder(root, proc); }

private:
	void    clear(Node*& node);
	int     height(Node* node);
	void    add(Node*& node, T elem);
	T       max(Node*& node);
	void    removeAux(Node*& node);
	void    remove(Node*& node, R val);

	T       find(Node* node, R val);
	void	find_all(Node* node, R val);
	void	find_upper(Node* node, R val);
	void	find_lower(Node* node, R val);
	void	find_ContaiN(Node* node, R val, function<R(T)> start);

	T       greaterThan(Node* node, R val);
	void    inOrder(Node* node, function<void(T)> proc);
	void    postOrder(Node* node, function<void(T)> proc);

	void    updateHeight(Node* node);
	void    rotateLeft(Node*& node);
	void    rotateRight(Node*& node);
	void    balance(Node*& node);
};

template<typename T, typename R, T NONE>
void AVL_Tree<T,R,NONE>::clear(Node*& node) {
	if (node != nullptr) {
		clear(node->left);
		clear(node->right);
		delete node;
		node = nullptr;
	}
}

template<typename T, typename R, T NONE>
int AVL_Tree<T, R, NONE>::height(Node* node) {
	return node == nullptr ? -1 : node->height;
}

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::add(Node*& node, T elem) {
	if (node == nullptr) {
		node = new Node(elem);
		++len;
	}
	else {
		if (key(elem) < key(node->element)) {
			add(node->left, elem);
		}
		else {
			add(node->right, elem);
		}
		balance(node);
	}
}

template<typename T, typename R, T NONE>
T AVL_Tree<T, R, NONE>::max(Node*& node) {
	if (node->right == nullptr) {
		auto aux = node;
		node = node->left;
		auto auxElem = aux->elem;
		delete aux;
		return auxElem;
	}
	else {
		auto auxElem = max(node->right);
		balance(node);
		return auxElem;
	}
}

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::removeAux(Node*& node) {
	if (node->left == nullptr) {
		auto aux = node;
		node = node->right;
		delete aux;
	}
	else {
		node->elem = max(node->left);
	}
}

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::remove(Node*& node, R val) {
	if (node != nullptr) {
		if (val == key(node->elem)) {
			removeAux(node);
		}
		else {
			if (val < key(node->elem)) {
				remove(node->left, val);
			}
			else {
				remove(node->right, val);
			}
			balance(node);
		}
	}
}

template<typename T, typename R, T NONE>
T AVL_Tree<T, R, NONE>::find(Node* node, R val) {
	if (node == nullptr) {
		return NONE;
	}
	else if (val == key(node->element)) {
		return node->element;
	}
	else if (val < key(node->element)) {
		return find(node->left, val);
	}
	else {
		return find(node->right, val);
	}
}

//Obtener vector de busqueda
template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::find_all(Node* node, R val) {
	if (node != nullptr) {
		if (val == key(node->element)) {
			all_search.push_back(node->element);
		}
		find_all(node->left, val);

		find_all(node->right, val);
	}
}
template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::find_upper(Node* node, R val) {
	if (node != nullptr) {
		if (val < key(node->element)) {
			all_search.push_back(node->element);
		}
		find_upper(node->left, val);

		find_upper(node->right, val);
	}
}
template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::find_lower(Node* node, R val) {
	if (node != nullptr) {
		if (val > key(node->element)) {
			all_search.push_back(node->element);
		}
		find_lower(node->left, val);

		find_lower(node->right, val);
	}
}
template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::find_ContaiN(Node* node, R val, function<R(T)> start) {
	if (node != nullptr) {
		if (val == start(node->element)) {
			all_search.push_back(node->element);
		}
		find_ContaiN(node->left, val, start);

		find_ContaiN(node->right, val, start);
	}
}

template<typename T, typename R, T NONE>
T AVL_Tree<T, R, NONE>::greaterThan(Node* node, R val) {
	if (node == nullptr) {
		return NONE;
	}
	else if (val < key(node->element)) {
		return node->element;
	}
	return greaterThan(node->right, val);
}

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::inOrder(Node* node,	function<void(T)> proc) {
	if (node != nullptr) {
		inOrder(node->left, proc);
		proc(node->element);
		inOrder(node->right, proc);
	}
}

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::postOrder(Node* node, function<void(T)> proc) {
	if (node != nullptr) {
		postOrder(node->left, proc);
		postOrder(node->right, proc);
		proc(node->element);
	}
}

//**********************//
//		Balanceo		//
//**********************//

#define max(a, b) (a > b? a : b)

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::updateHeight(Node* node) {
	if (node != nullptr) {
		int hl = height(node->left);
		int hr = height(node->right);

		node->height = max(hl, hr) + 1;
	}
}

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::rotateLeft(Node*& node) {
	Node* aux = node->right;
	node->right = aux->left;
	updateHeight(node);
	aux->left = node;
	updateHeight(aux);
	node = aux;
}

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::rotateRight(Node*& node) {
	Node* aux = node->left;
	node->left = aux->right;
	updateHeight(node);
	aux->right = node;
	updateHeight(aux);
	node = aux;
}

template<typename T, typename R, T NONE>
void AVL_Tree<T, R, NONE>::balance(Node*& node) {
	int hl = height(node->left);
	int hr = height(node->right);

	if (hr - hl < -1) {
		hl = height(node->left->left);
		hr = height(node->left->right);
		if (hr > hl) {
			rotateLeft(node->left);
		}
		rotateRight(node);
	}
	else if (hr - hl > 1) {
		hl = height(node->right->left);
		hr = height(node->right->right);
		if (hl > hr) {
			rotateRight(node->right);
		}
		rotateLeft(node);
	}
	else {
		updateHeight(node);
	}
}