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
	void levelorder() {
		for(int i = 1; i <= Height(root); i++) {
        		leveldisplay(root, i);
        	}
        	cout << endl;
	}
	void leveldisplay(node *current, int level) {  
    		if(!current) { 
		        return;  
		}
    		if(level == 1) { 
        		cout << current -> data << " ";
        	}  
    		else {
    			if(level > 1) {  
        			leveldisplay(current -> left, level - 1);  
        			leveldisplay(current -> right, level - 1);  
    			}  
    		}
	}  
	int RangeCount(node *current, int low, int high) {
		if(!current) {
			return 0;
		}
		if(current -> data <= high && current -> data >= low) {
			return 1 + RangeCount(current -> left, low, high) + RangeCount(current -> right, low, high);
		}
		else {
			if(current -> data < low) {
				return RangeCount(current -> right, low, high);
			}
			else {
				return RangeCount(current -> left, low, high);
			}
		}
	}
	void rangecount(int low, int high) {
		cout << "Count of nodes in range (" << low << ", " << high << "): ";
		if(low <= high) {
			cout << RangeCount(root, low, high) << endl;
		}
		else {
			cout << RangeCount(root, high, low) << endl;
		}
	}
	void PrintRange(node *current, int low, int high) {
		if(current == NULL) {
			return;
		}
		if(current -> data > low) {
			PrintRange(current -> left, low, high);
		}
		if(current -> data >= low && current -> data <= high) {
			cout << current -> data << " ";
		}
		if(current -> data < high) {
			PrintRange(current -> right, low, high);
		}
	}
	void printrange(int low, int high) {
		cout << "Nodes in range (" << low << ", " << high << "): ";
		if(low <= high) {
			PrintRange(root, low, high);
		}
		else {
			PrintRange(root, high, low);
		}
		cout << endl;
	}
	node *RemoveInsideRange(node *current, int low, int high) {
		if(!current) {
			return NULL;
		}
		current -> left = RemoveInsideRange(current -> left, low, high);
		current -> right = RemoveInsideRange(current -> right, low, high);
		if(current -> data >= low && current -> data <= high) { 
       			delete current;
       			return NULL;
       		}
		return current;
	}
	void removeinsiderange(int low, int high) {
		if(low <= high) {
			RemoveInsideRange(root, low, high);
		}
		else {
			RemoveInsideRange(root, high, low);
		}
	}
	node *RemoveOutsideRange(node *current, int low, int high) {
		if(!current) {
			return NULL;
		}
		current -> left = RemoveOutsideRange(current -> left, low, high);
		current -> right = RemoveOutsideRange(current -> right, low, high);
		if(current -> data < low) { 
       			node *child = current -> right;
       			delete current;
       			return child;
       		}
       		if(current -> data > high) {
       			node *child = current -> left;
       			delete current;
       			return child;
       		}
		return current;
	}
	void removeoutsiderange(int low, int high) {
		if(low <= high) {
			RemoveOutsideRange(root, low, high);
		}
		else {
			RemoveOutsideRange(root, high, low);
		}
	}
	node *deleteleaves(node *current) {
		if(!current) {
			return NULL;
		}
		if(!(current -> left) && !(current -> right)) {
			delete current;
			return NULL;
		}
		current -> left = deleteleaves(current -> left);
		current -> right = deleteleaves(current -> right);
		return current;
	}
	void deleteleaf() {
		deleteleaves(root);
	}
	int RootDistance(node *current, int value) {
		if(!current) {
			return 0;
		}
		else {
			if(current -> data > value) {
				return 1 + RootDistance(current -> left, value);
			}
			else {
				return 1 + RootDistance(current -> right, value);
			}
		}
	}
	void rootdistance(int value) {
		cout << "Distance of " << value << " from root: " << RootDistance(root, value) << endl;
	}
	int NodeDistance(node *current, int a, int b) {
		if(!current) {
			return 0;
		}
		if(current -> data > a && current -> data > b){
			return NodeDistance(current -> left, a, b);
		}
		if(current -> data < a && current -> data < b) {
			return NodeDistance(root -> right, a, b);
		}
		if(current -> data >= a && current -> data <= b) {
			return RootDistance(current, a) + RootDistance(current, b);
		}
	}
	void nodedistance(int a, int b) {
		cout << "Distance between " << a << " and " << b << ": " << NodeDistance(root, a, b) << endl;
	}
	bool CountSubtrees(node *current, int low, int high, int countS) {
		if(!current) {
			return true;
		}
		bool left = CountSubtrees(current -> left, low, high, countS);
		bool right = CountSubtrees(current -> right, low, high, countS);
		if(left && right && current -> data >= low && current -> data <= high) {
			++countS;
			return true;
		}
		return false;
	}
	int countsubtrees(int low, int high) {
		int countS = 0;
		CountSubtrees(root, low, high, countS);
		return countS;
	}
	void subtrees(int low, int high) {
		cout << "Number of subtrees between " << low << " and " << high << ": " << countsubtrees(low, high) << endl;
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
	BST.levelorder();
	cout << "Delete 32: ";
	BST.Delete(32);
	BST.print2D();
	BST.rangecount(234, 34);
	BST.printrange(500, 34);
	BST.removeinsiderange(1, 7);
	BST.print2D();
	BST.deleteleaf();
	BST.print2D();
	BST.removeoutsiderange(30, 100);
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
