#include <iostream>
using namespace std;
class node {
	public:
	int data; //data stored in node
	node *parent, *left, *right; //pointers to parent node and left and right child nodes
	node(int value) { //default constructor
		data = value;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};
class BinarySearchTree {
	public:
	node *root; //pointer to root node
	BinarySearchTree() { //default constructor
		root = NULL;
	}
	void Insert(node *current, int value) { //1. Insert, current: temporary pointer to traverse tree
		node *temp = new node(value); //creates new node with given value as data
		if(root == NULL) { //case 1: empty tree
			root = temp; //temp becomes root node
		}
		else { //case 2: root exists
			if(current -> data > temp -> data) { //case 2.1: temp's data is less than current node's data
				if(current -> left == NULL) { //case 2.1.1: current node has no left child
					current -> left = temp; //temp becomes current node 's left child
				}
				else { //case 2.1.2: current node already has a left child
					Insert(current -> left, value); //current node's left child becomes current till it reaches a node with no left child (temp then becomes current node's left child)
				}
			}
			else { //case 2.2: temp's data is more than or equal to current node's data
				if(current -> right == NULL) { //case 2.2.1: current node has no right child
					current -> right = temp; //temp becomes current node's right child
				}
				else { //case 2.2.2: current node already has a right child
					Insert(current -> right, value); //current node's right child becomes current till it reaches a node with no right child (temp then becomes new current node's right child)
				}
			}
			temp -> parent = current; //current becomes temp's parent	
		}
	}
	void insert(int value) { //insert helper
		Insert(root, value);
	}
	node *find_min(node *root) { //function to find node with minimum data
		node *current = root; //current: temporary pointer to traverse tree starting from root node
		while(current -> left != NULL) { //as long as current node has left child
			current = current -> left; //current node's left child becomes current
		}
		return current;
	}
	node *Delete(node *current, int value) { //2. Delete, current: temporary pointer to traverse tree
		if(current == NULL) { //case 1: empty tree
		        cout << "Empty tree. Nothing to delete." << endl;
			return NULL;
		}
		node *temp = Search(current, value); //temp: node with given value to be deleted
		if(temp == NULL) { //case 2: node with given value does not exist
			return NULL;
		}
		if(temp -> left == NULL && temp -> right == NULL) { //case 3: node to be deleted has no children
			if(temp == root) { //case 3.1: node to be deleted is root node
				root = NULL;
			}
			else { //case 3.2: node to be deleted is intermediate or leaf node
				if(temp -> parent -> left = temp) { //case: 3.2.1: temp is its parent's left child
					temp -> parent -> left = NULL;
				}
				else { //case: 3.2.2: temp is its parent's right child
					temp -> parent -> right = NULL;
				}
				delete temp;
			}
		}
		else { //case 4: node to be deleted has at least one child
			node *child; //pointer to child node
			if(temp -> left != NULL && temp -> right != NULL) { //case 4.1: node to be deleted has two children
				child = find_min(temp -> right); //node with minimum data (only slightly bigger than temp node's) in temp's right subtree becomes child
				int i = child -> data; //temporary variable to store child node's data
				Delete(root, child -> data); //deletes child node (case 1)
				temp -> data = i; //i becomes temp's new data
			}
			else { //case 4.2: node to be deleted has one child
				if(temp -> left != NULL) { //case 4.2.1: node to be deleted has only left child
					child = temp -> left; //left child becomes child
				}
				else { //case 4.2.2: node to be deleted has only right child
					child = temp -> right; //right child becomes child
				}
				if(temp == root) { //case 4.2.a: node to be deleted is root node
					root = child; //child becomes new root
				}
				else { //case 4.2.b: node to be deleted is intermediate or leaf node
					if(temp -> parent -> left = current) { //case 4.2.b.1: temp is its parent's left child
						temp -> parent -> left = child; //temp's child becomes temp's parent's new left child
					}
					else { //case 4.2.b.2: temp is its parent's right child
						temp -> parent -> right = child; //temp's child becomes temp's parent's new right child
					}
				}
				delete temp; //deletes temp
			}
		}
	}
	void delet(int value) { //delete helper
		Delete(root, value);
	}
	void inDisplay(node *current) { //3. Display (in-order), current: temporary pointer to traverse tree
		if(current == NULL) { //recursion's exit condition
			return; //also when tree is empty
		}
		inDisplay(current -> left); //displays left child's data first
		cout << current -> data << " "; //then displays current node's data
		inDisplay(current -> right); //and then displays right child's data
	}
	void indisplay() { //in-order display helper
		inDisplay(root);
		cout << endl;
	}
	void preDisplay(node *current) { //3. Display (pre-order), current: temporary pointer to traverse tree
		if(current == NULL) { //recursion's exit condition
			return; //also when tree is empty
		}
		cout << current -> data << " "; //displays current node's data first
		preDisplay(current -> left); //then displays left child's data
		preDisplay(current -> right); //and then displays right child's data
	}
	void predisplay() { //pre-order display helper
		preDisplay(root);
		cout << endl;
	}
	void postDisplay(node *current) { //3. Display (post-order), current: temporary pointer to traverse tree
		if(current == NULL) { //recursion's exit condition
			return; //also when tree is empty
		}
		postDisplay(current -> left); //displays left child's data first
		postDisplay(current -> right); //then displays right child's data
		cout << current -> data << " "; //and then displays current node's data
	}
	void postdisplay() { //post-order display helper
		postDisplay(root);
		cout << endl;
	}
	node *Search(node *current, int value) { //4. Search, current: temporary pointer to traverse tree
		if(current == NULL) { //case: if node with given value does not exist
			cout << "Value not found. " << endl;
			return NULL;
		}
		if(current -> data == value) { //case: if node with given data exists
			cout << "Value found. " << endl;
			return current;
		}
		if(value < current -> data) { //case 1: given value is less than current node's data
			Search(current -> left, value); //current node's left child becomes current and search continues
		}
		else { //case 2: given value is more than or equal to current node's data
			Search(current -> right, value); //current node's right child becomes current and search continues
		}
	}
	void search(int value) { //search helper
		Search(root, value);
	}
	int Count(node *current) { //5. Count, current: temporary pointer to traverse tree
		if(current == NULL) { //recursion's exit condition
			return 0; //also when tree is empty
		}
		return 1 + Count(current -> left) + Count(current -> right); //counts nodes in each node's subtrees (if any, returns 1 in each case or else 0) and adds
	}
	void count() { //count helper
		cout << "Count: " << Count(root) << endl;
	}
	int max(int i, int j) { //function to find maxmimum between two integers
		if(i > j) {
			return i;
		}
		else {
			return j;
		}
	}
	int Height(node *current) { //6. Height, current: temporary pointer to traverse tree
	        if(current == NULL) { //recursion's exit condition
	                return 0; //also when tree is empty
	        }
	        return 1 + max(Height(current -> left), Height(current -> right)); //counts nodes in each node's subtrees (if any, returns 1 in each case or else 0), finds maxmimum height between subtrees and adds
	}
	void height() { //height helper
		cout << "Height: " << Height(root) << endl;
	}
	void print2DUtil(node *current, int spaces) { //function to display tree in 2D view 
		if(current == NULL) { //base case
			return; //also when the tree is empty
		}
		spaces += 5; //increases distance between levels
		print2DUtil(current -> right, spaces); //processes right child first
		cout << endl;
		for(int i = 5; i < spaces; i++) { 
			cout << " ";
		}
		cout << current -> data << endl; //displays current node's data
		print2DUtil(current -> left, spaces); //processes left child
	}
	void print2D() { // Wrapper over print2DUtil()
		cout << "2D display: " << endl;
		cout << "******************************" << endl;
		print2DUtil(root, 0); //passes initial space count as 0
		cout << endl;
		cout << "******************************" << endl;
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
	BST.delet(4);
	BST.indisplay();
	cout << "Delete 9: ";
	BST.delet(9);
	BST.indisplay();
	BST.predisplay();
	BST.postdisplay();
	BST.print2D();
	return 0;
}
