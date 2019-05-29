#include <iostream> 
using namespace std;
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
	void insert(int value) { //function to insert node at head
		node *temp = new node(value);
		temp -> next = head;
		head = temp;
	}
	void display() {
		node *current = head;
		while(current != NULL) {
			cout << current -> data << " -> ";
			current = current -> next;
		}
		cout << "NULL" << endl;
	}
	node *removeduplicates(node *head) { //function to delete duplicate-value nodes from sorted linked list
		node *current = head;
		if(head == NULL || head -> next == NULL) {
			return head;
		}
		else {
			while(current -> next != NULL) {
				if(current -> data != current -> next -> data) {
					current = current -> next;
				}
				else {
					node *temp = current -> next;
					current -> next = current -> next -> next;
					delete temp;
				}
				removeduplicates(current -> next);
			}		
		}
	}	
	node *reverse(node *current) { //function to reverse a linked list 
		  if(current == NULL) {
		  	return NULL;
		  }
		  if(current -> next == NULL) {
		  	head = current;
		  	return head;
		  }
		  node *temp = reverse(current -> next);
		  temp -> next = current;
		  current -> next = NULL;
		  return current;
	}
};
	void compare(node *current1, node *current2) { //function to compare two linked lists
		if(current1 == NULL || current2 == NULL) {
			if(current1 == NULL && current2 == NULL) {
				cout << " identical." << endl;
			}
			else {
				cout << " not identical." << endl;
			}
		}
		if(current1 != NULL && current2 != NULL) {
			if(current1 -> data != current2 -> data) {
				cout << " not identical." << endl;
			}
			else {
				compare(current1 -> next, current2 -> next);
			}
		}
	}
int main() {
	LinkedList A;
	LinkedList B;
	LinkedList C;
	LinkedList D;
	LinkedList E;
	E.insert(9);
	for(int i = 9; i > 0; i--) {
		A.insert(i);
		B.insert(i);
		C.insert(10 - i);
		E.insert(i);
	}
	E.insert(1);
	cout << "List A display: ";
	A.display();
	cout << "List B display: ";
	B.display();
	cout << "List C display: ";
	C.display();
	cout << "List D display: ";
	D.display();
	cout << "List E display: ";
	E.display();
	cout << "Lists A and B are";
	compare(A.head, B.head);
	cout << "Lists B and C are";
	compare(B.head, C.head);
	cout << "Lists C and D are";
	compare(C.head, D.head);
	E.removeduplicates(E.head);
	cout << "Removed duplicates from sorted Linked List E." << endl;
	cout << "List E display: ";
	E.display();
	E.reverse(E.head);
	cout << "Reversed Linked List E." << endl;
	cout << "List E display: ";
	E.display();
	return 0;
}
