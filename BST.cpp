#include <iostream>
using namespace std;
class node {
	public:
	int data;
	node *parent, *left, *right;
	node(int value) {
		data = value;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};
class BinarySearchTree {
	public:
	node *root;
	BinarySearchTree() {
		root = NULL;
	}
	void Insert(node *current, int value) {
		node *temp = new node(value);
		if(root == NULL) {
			root = temp;
		}
		else {
			if(current -> data > temp -> data) {
				if(current -> left == NULL) {
					current -> left = temp;
				}
				else {
					Insert(current -> left, value);
				}
			}
			else {
				if(current -> right == NULL) {
					current -> right = temp;
				}
				else {
					Insert(current -> right, value);
				}
			}
			temp -> parent = current;	
		}
	}
	void insert(int value) {
		Insert(root, value);
	}
	void Display(node *current) {
		if(current == NULL) {
			return;
		}
		Display(current -> left);
		cout << current -> data << " ";
		Display(current -> right);
	}
	void display() {
		Display(root);
		cout << endl;
	}
	node *Search(node *current, int value) {
		if(current == NULL) {
			cout << "Value not found. " << endl;
			return NULL;
		}
		if(current -> data == value) {
			cout << "Value found. " << endl;
			return current;
		}
		if(value < current -> data) {
			Search(current -> left, value);
		}
		else {
			Search(current -> right, value);
		}
	}
	void search(int value) {
		Search(root, value);
	}
	node *find_min(node *root) {
		node *current = root;
		while(current -> left != NULL) {
			current = current -> left;
		}
		return current;
	}
	node *Delete(node *current, int value) {
		if(current == NULL) {
			return NULL;
		}
		node *temp = Search(current, value);
		if(temp == NULL) {
			return NULL;
		}
		if(temp -> left == NULL && temp -> right == NULL) { //case 1: no children
			if(temp == root) {
				root = NULL;
			}
			else {
				if(temp -> parent -> left = temp) {
					temp -> parent -> left = NULL;
				}
				else {
					temp -> parent -> right = NULL;
				}
				delete temp;
			}
		}
		else {
			node *child;
			if(temp -> left != NULL && temp -> right != NULL) { //case 2: two children
				child = find_min(temp -> right);
				int i = child -> data;
				Delete(root, child -> data);
				temp -> data = i;
			}
			else {
				if(temp -> left != NULL) { //case 3: one child
					child = temp -> left;
				}
				else {
					child = temp -> right;
				}
				if(temp == root) {
					root = child;
				}
				else {
					if(temp -> parent -> left = current) {
						temp -> parent -> left = child;
					}
					else {
						temp -> parent -> right = child;
					}
				}
				delete temp;
			}
		}
	}
	void delet(int value) {
		Delete(root, value);
	}
};
int main() {
	BinarySearchTree BST;
	BST.insert(32);
	BST.insert(4);
	BST.insert(463);
	BST.insert(7);
	BST.insert(34);
	BST.display();
	cout << "Search for 4: ";
	BST.search(4);
	cout << "Delete 4: ";
	BST.delet(4);
	BST.display();
	cout << "Delete 9: ";
	BST.delet(9);
	BST.display();
	return 0;
}
