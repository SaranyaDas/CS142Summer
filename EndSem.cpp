#include <iostream>
#include <math.h>
using namespace std;
//QUESTION 1: Binary Search Tree using an array
//array[i] = current -> data, i = current
class BinarySearchTree {
	public:
	int *array, capacity;
	BinarySearchTree(int cap) {
		array = new int[cap];
		capacity = cap;
	}
	int parent(int i) {
		if(array[i] != 0) {
			return (i - 1)/2;
		}
	}
	int left(int i) {
		if(array[i] != 0) {
			return 2*i + 1;
		}
	}
	int right(int i) {
		if(array[i] != 0) {
			return 2*i + 2;
		}
	}
	void Insert(int i, int value) {
		if(array[0] == 0) {
			array[0] = value;
			return;
		}
		if(count() == capacity) {
			cout << "Cannot insert new values. Count = capacity." << endl;
			return;
		}
		else {
			if(value < array[i]) {
				if(array[left(i)] == 0) {
					array[left(i)] = value;
				}
				else {
					Insert(left(i), value);
				}
			}
			else {
				if(array[right(i)] == 0) {
					array[right(i)] = value;
				}
				else {
					Insert(right(i), value);
				}
			}
		}
	}
	void insert(int value) {
		Insert(0, value);
	}
	
	int find_min(int i) {
		while(array[left(i)] != 0) {
			i = left(i);
		}
		return i;
	}
	void Delete(int i) {
		if(i < 0 || i > capacity - 1 || array[i] == 0) {
			cout << "Nothing to delete here." << endl;
			return;
		}
		if(array[left(i)] == 0 && array[right(i)] == 0) {
			array[i] = 0;
			return;
		}
		else {
			int child;
			if(array[left(i)] != 0 && array[right(i)] != 0) {
				child = find_min(right(i));
				array[i] = array[child];
				Delete(child);
			}
			else {
				if(array[left(i)] != 0) {
					child = left(i);
				}
				if(array[right(i)] != 0) {
					child = right(i);
				}
				if(left(parent(i)) == i) {
					array[left(parent(i))] = array[child];
					array[child] = 0;
				}
				if(right(parent(i)) == i) {
					array[right(parent(i))] = array[child];
					array[child] = 0;
				}
			}
		}
	}
	int count() {
		int j = 0;
		for(int i = 0; i < capacity; i++) {
			if(array[i] != 0) {
				j++;
			}
		}
		return j;
	}
	void display() {
		for(int i = 0; i < capacity; i++) {
			if(array[i] != 0) {
				cout << array[i] << " ";
			}
			else {
				cout << "NULL ";
			}
		}
		cout << endl;
	}
};
//QUESTION 2: Linked List with Alternating Split function
class node {
	public:
	int data;
	node *next;
	node(int value) {
		data = value;
		next = NULL;
	}
};
class LinkedList {
	public:
	node *head;
	LinkedList() {
		head = NULL;
	}
	bool empty() {
		return(head == NULL);
	}
	node *getpos(int pos) {
		if(pos < 1 || pos > count()) {
			return NULL;
		}
		else { 
			node *current = head;
			int i = 1;
			while(i < pos) {
				current = current -> next;
				i++;
			}
			return current;
		}
	}
	int count() {
		int i = 0;
		if(empty()) {
			return i;
		}
		else {
			node *current = head;
			while(current != NULL) {
				i++;
				current = current -> next;
			}
			return i;
		}
	}
	void inserthead(int value) {
		node *temp = new node(value);
		if(empty()) {
			head = temp;
		}
		else {
			temp -> next = head;
			head = temp;
		}	
	}
	void insertend(int value) {
		node *temp = new node(value);
		if(empty()) {
			head = temp;
		}
		else {
			node *current = getpos(count());
			current -> next = temp;
		}
	}
	void insertat(int value, int pos) {
		if(pos < 1 || pos > count() + 1) {
			cout << "Not possible." << endl;
		}
		else {
			node *temp = new node(value);
			if(pos == 1) {
				inserthead(value);
			}
			else {
				if(pos == count() + 1) {
					insertend(value);
				}
				else {
					node *current = getpos(pos - 1);
					temp -> next = current -> next;
					current -> next = temp;
				}
			}
		}
	}
	void deletehead() {
		if(empty()) {
			cout << "Not possible." << endl;
		}
		else {
			if(head -> next == NULL) {
				head = NULL;
			}
			else {
				node *temp = head;
				head = head -> next;
				delete temp;
			}
		}
	}
	void deleteend() {
		if(empty()) {
			cout << "Not possible." << endl;
		}
		else {
			if(head -> next == NULL) {
				head = NULL;
			}
			else {
				node *current = getpos(count() - 1);
				node *temp = current -> next;
				current -> next = NULL;
				delete temp;
			}
		}
	}
	void deleteat(int pos) {
		if(pos < 1 || pos > count()) {
			cout << "Not possible." << endl;
		}
		else {
			if(pos == 1) {
				deletehead();
			}
			else {
				if(pos == count()) {
					deleteend();
				}
				else {
					node *current = getpos(pos - 1);
					node *temp = current -> next;
					current -> next = temp -> next;
					delete temp;
				}
			}
		}
	}
	void display() {
		if(!empty()) {
			node *current = head;
			while(current != NULL) {
				cout << current -> data << " -> ";
				current = current -> next;
			}
		}
		cout << "NULL" << endl;
	}
	node *AlternatingSplit() {
		if(empty()) {
			return NULL;
		}
		node *current = head;
		node *newhead = head -> next;
		node *temp1, *temp2;
		while(current -> next != NULL) {
			temp1 = current -> next -> next;
			temp2 = current -> next;
			current -> next = temp1;
			current = temp2;
		}
		return newhead;
	}
};
int main() {
	BinarySearchTree BST(20);
	BST.insert(4);
	BST.display();
	BST.insert(2);
	BST.display();
	BST.insert(5);
	BST.display();
	BST.insert(1);
	BST.display();
	BST.insert(6);
	BST.display();
	BST.insert(3);
	BST.display();
	BST.Delete(6);
	BST.display();
	BST.Delete(1);
	BST.display();
	BST.Delete(1);
	BST.display();
	cout << endl;
	LinkedList SLL;
	SLL.insertend(4);
	SLL.display();
	SLL.deletehead();
	SLL.display();
	SLL.inserthead(2);
	SLL.display();
	SLL.insertend(3);
	SLL.display();
	SLL.insertat(100, 3);
	SLL.display();
	SLL.insertat(12, 1);
	SLL.insertat(9, 3);
	SLL.display();
	SLL.deleteat(1);
	SLL.display();
	SLL.deleteat(2);
	SLL.display();
	SLL.inserthead(100);
	SLL.inserthead(1);
	SLL.inserthead(69);
	SLL.inserthead(2);
	SLL.inserthead(4222);
	SLL.inserthead(5);
	SLL.display();
	LinkedList LL;
	LL.head = SLL.AlternatingSplit();
	cout << "Splitting lists:" << endl;
	LL.display();
	SLL.display();
}
