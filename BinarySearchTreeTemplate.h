#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <bits/stdc++.h>

using namespace std;

template <class T>
class BinarySearchTree {
	private:
		struct TreeNode {
			T value;
			TreeNode *left;
			TreeNode *right;
		};
		TreeNode *root;
		void DestorySubTree(TreeNode *);
		void DeleteNode(T, TreeNode *&);
		void MakeDeletion(TreeNode *&);
		void DisplayInOrder(TreeNode *);
		void DisplayPreOrder(TreeNode *);
		void DisplayPostOrder(TreeNode *);
	public:
		BinarySearchTree();
		~BinarySearchTree();
		void InsertNode(T);
		bool SearchNode(T);
		void Remove(T);
		void ShowNodesInOrder();
		void ShowNodesPreOrder();
		void ShowNodesPostOrder();
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	//DestorySubTree(root);
}

template <class T>
void BinarySearchTree<T>::ShowNodesInOrder() {
	DisplayInOrder(root);
}

template <class T>
void BinarySearchTree<T>::ShowNodesPreOrder() {
	DisplayPreOrder(root);
}

template <class T>
void BinarySearchTree<T>::ShowNodesPostOrder() {
	DisplayPostOrder(root);
}

template <class T>
void BinarySearchTree<T>::InsertNode(T num) {
	TreeNode *newNode, *nodePtr;
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = NULL;
	if (!root) {
		root = newNode;
	} else {
		nodePtr = root;
		while (nodePtr != NULL) {
			if (num < nodePtr->value) {
				if (nodePtr->left) {
					nodePtr = nodePtr->left;
				} else {
					nodePtr->left = newNode;
					break;
				}
			} else if (num > nodePtr->value) {
				if (nodePtr->right) {
					nodePtr = nodePtr->right;
				} else {
					nodePtr->right = newNode;
					break;
				}
			} else {
				cout << "Duplicate value found in tree.\n";
				break;
			}
		}
	}
}

template <class T>
void BinarySearchTree<T>::DisplayInOrder(TreeNode *nodePtr) {
	if (nodePtr) {
		DisplayInOrder(nodePtr->left);
		cout << nodePtr->value << '\n';
		DisplayInOrder(nodePtr->right);
	}
}

template <class T>
void BinarySearchTree<T>::DisplayPreOrder(TreeNode *nodePtr) {
	if (nodePtr) {
		cout << nodePtr->value << '\n';
		DisplayInOrder(nodePtr->left);
		DisplayInOrder(nodePtr->right);
	}
}

template <class T>
void BinarySearchTree<T>::DisplayPostOrder(TreeNode *nodePtr) {
	if (nodePtr) {
		DisplayInOrder(nodePtr->left);
		DisplayInOrder(nodePtr->right);
		cout << nodePtr->value << '\n';
	}
}

template <class T>
bool BinarySearchTree<T>::SearchNode(T num) {
	TreeNode *nodePtr = root;
	while (nodePtr) {
		if (nodePtr->value == num) {
			return true;
		} else if (num < nodePtr->value) {
			nodePtr = nodePtr->left;
		} else {
			nodePtr = nodePtr->right;
		}
	}
	return false;
}

template <class T>
void BinarySearchTree<T>::Remove(T num) {
	DeleteNode(num, root);
}

template <class T>
void BinarySearchTree<T>::DeleteNode(T num, TreeNode *&nodePtr) {
	if (num < nodePtr->value) {
		DeleteNode(num, nodePtr->left);
	} else if (num > nodePtr->value) {
		DeleteNode(num, nodePtr->right);
	} else {
		MakeDeletion(nodePtr);
	}
}

template <class T>
void BinarySearchTree<T>::MakeDeletion(TreeNode *&nodePtr) {
	TreeNode *tempNodePtr;
	if (nodePtr == NULL) {
		//cout << "Cannot delete empty node.\n";
	} else if (nodePtr->right == NULL) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	} else if (nodePtr->left == NULL) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	} else {
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left) {
			tempNodePtr = tempNodePtr->left;
		}
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

#endif
