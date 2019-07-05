#include <iostream>
#include <math.h>
using namespace std;
class node {
	public:
	int data;
	node *parent, *left, *right;
	node(int value) {
		data = value;
		parent = left = right = NULL;
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
			if(temp -> data < current -> data) {
				if(!(current -> left)) {
					current -> left = temp;
				}
				else {
					Insert(current -> left, value);
				}
			}
			else {
				if(!(current -> right)) {
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
	node *Search(node *current, int value) {
		if(current == NULL) {
			cout << "Value not found." << endl;
			return NULL;
		}
		if(current -> data == value) {
			cout << "Value found." << endl;
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
	node *find_min(node *current) {
		while(current -> left != NULL) {
			current = current -> left;
		}
		return current;
	}
	void Delete(int value) {
		if(root == NULL) {
			cout << "Nothing to delete here." << endl;
		}
		node *temp = Search(root, value);
		if(temp == NULL) {
			return;
		}
		if(!(temp -> left) && !(temp -> right)) {
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
			}
			delete temp;
		}
		else {
			node *child;
			if((temp -> left) && (temp -> right)) {
				child = find_min(temp -> right);
				temp -> data = child -> data;
				child -> parent -> left = NULL;
				delete child;
			}
			else {
				if(temp -> left) {
					child = temp -> left;
				}
				else {
					child = temp -> right;
				}
				if(temp == root) {
					root = child;
				}
				else {
					if(temp -> parent -> left = temp) {
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
	void inorder(node *current) {
		if(current == NULL) {
			return;
		}
		inorder(current -> left);
		cout << current -> data << " ";
		inorder(current -> right);
	}
	void indisplay() {
		inorder(root);
		cout << endl;
	}
	void preorder(node *current) {
		if(current == NULL) {
			return;
		}
		cout << current -> data << " ";
		preorder(current -> left);
		preorder(current -> right);
	}
	void predisplay() {
		preorder(root);
		cout << endl;
	}
	void postorder(node *current) {
		if(current == NULL) {
			return;
		}
		postorder(current -> left);
		postorder(current -> right);
		cout << current -> data << " ";
	}
	void postdisplay() {
		postorder(root);
		cout << endl;
	}
	int Count(node *current) {
		if(current == NULL) {
			return 0;
		}
		return 1 + Count(current -> left) +Count(current -> right);
	}
	void count() {
		cout << "Count: " << Count(root) << endl;
	}
	int Height(node *current) {
		if(current == NULL) {
			return 0;
		}
		return 1 + max(Height(current -> left), Height(current -> right));
	}
	void height() {
		cout << "Height: " << Height(root) << endl;
	}
	void print2DUtil(node *current, int spaces) {
		if(current == NULL) {
			return;
		}
		spaces += 5;
		print2DUtil(current -> right, spaces);
		cout << endl;
		for(int i = 5; i < spaces; i++) {
			cout << " ";
		}
		cout << current -> data << endl;
		print2DUtil(current -> left, spaces);
	}
	void print2D() {
		cout << "2D Display:" << endl;
		cout << "---------------------------" << endl;
		print2DUtil(root, 0);
		cout << endl;
		cout << "---------------------------" << endl;
	}
	bool complete(node *current, int i, int count) {
		if(current == NULL) {
			return true;
		}
		if(i >= count) {
			return false;
		}
		return complete(current -> left, 2*i + 1, count) && complete(current -> right, 2*2 + 2, count);
	}
	bool maxheap(node *current) {
		if(!(current -> left) && !(current -> right)) {
			return true;
		}
		if(!(current -> right)) {
			return (current -> data >= current -> left -> data);
		}
		else {
			if(current -> data >= current -> left -> data && current -> data >= current -> right -> data) {
				return maxheap(current -> left) && maxheap(current -> right);
			}
			else {
				return false;
			}
		}
	}
	bool minheap(node *current) {
		if(!(current -> left) && !(current -> right)) {
			return true;
		}
		if(!(current -> right)) {
			return (current -> data <= current -> left -> data);
		}
		else {
			if(current -> data <= current -> left -> data && current -> data <= current -> right -> data) {
				return minheap(current -> left) && minheap(current -> right);
			}
			else {
				return false;
			}
		}
	}
	void Heap() {
		int count = Count(root);
		if(root == NULL || complete(root, 0, count) && maxheap(root) || complete(root, 0, count) && minheap(root)) {
			cout << "The tree is a heap." << endl;
			if(root == NULL) {
				return;
			}
			if(minheap(root)) {
				cout << "The tree is a min heap." << endl;
			}
			if(maxheap(root)) {
				cout << "The tree is a max heap." << endl;
			}
		}
		else {
			cout << "The tree is not a heap." << endl;
		}
	}
};
int main() {
	BinarySearchTree BST;
	BST.insert(32);
	BST.insert(4);
	BST.insert(8);
	BST.insert(48);
	BST.insert(463);
	BST.insert(7);
	BST.insert(34);
	BST.insert(100);
	BST.indisplay();
	BST.count();
	BST.height();
	cout << "Search for 4: ";
	BST.search(4);
	cout << "Delete 4: ";
	BST.Delete(4);
	BST.indisplay();
	cout << "Delete 9: ";
	BST.Delete(9);
	BST.indisplay();
	BST.predisplay();
	BST.postdisplay();
	BST.print2D();
	cout << "Delete 32: ";
	BST.Delete(32);
	BST.print2D();
	BST.Heap();
	BinarySearchTree Tree1;
	Tree1.print2D();
	Tree1.Heap();
	BinarySearchTree Tree2;
	Tree2.insert(6);
	Tree2.insert(3);
	Tree2.print2D();
	Tree2.Heap();
	return 0;
}
