#include <bits/stdc++.h>
#include "BinarySearchTreeTemplate.h"

using namespace std;

int main() {
	BinarySearchTree <int> tree;
	cout << "Inserting nodes...";
	tree.InsertNode(5);
	tree.InsertNode(8);
	tree.InsertNode(3);
	tree.InsertNode(12);
	tree.InsertNode(9);
	tree.InsertNode(7); // -> for two children of '8'
	cout << endl;
	
	//traversing the binary tree
	cout << "Inorder Traversal:\n";
	tree.ShowNodesInOrder();
	cout << "\nPreOrder Traversal:\n";
	tree.ShowNodesPreOrder();
	cout << "\nPostorder Traversal:\n";
	tree.ShowNodesPostOrder();

	//searching an element in the binary tree
	if (tree.SearchNode(3)) {
		cout << "3 is found in the tree.\n";
	} else {
		cout << "3 was not found in the tree.\n";
	}

	//deleting a node in the binary tree
	cout << "Here are the values in the tree:\n";
	tree.ShowNodesInOrder();
	cout << "Deleting 8...\n";
	tree.Remove(8);
	cout << "Deleting 12...\n";
	tree.Remove(12);
	cout << "Now, here are the nodes:\n";
	tree.ShowNodesInOrder();
	return 0;
}
