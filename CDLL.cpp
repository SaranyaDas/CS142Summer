#include <iostream>
using namespace std;
class node {
	public:
	int data;
	node *next;
	node *prev;
	node(int value) {
		data = value;
		prev = NULL;
		next = NULL;
	}
};
class CircularDoublyLinkedList {
	public:
	node *head;
	node *tail;
	CircularDoublyLinkedList() {
		head = NULL;
		tail = NULL;
	}
	void inserthead(int value) {
		node *temp = new node(value);
		if(head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp -> next = head;
			head -> prev = temp;
			head = temp;
			tail -> next = head;
		}
	}
	void deletehead() {
		if(head == NULL) {
			cout << "Not possible." << endl;
		}
		else {
			if(head -> next == NULL) {
				head = NULL;
				tail = NULL;
			}
			else {
				node *temp = head;
				head = temp -> next;
				tail -> next = head;
				head -> prev = tail;
				delete temp;
			}
		}
	}
	void inserttail(int value) {
		node *temp = new node(value);
		if(head == NULL) {
			inserthead(value);
		}
		else {
			tail -> next = temp;
			temp -> prev = tail;
			tail = temp;
			tail -> next = head;
			head -> prev = tail;
		}
	}
	void deletetail() {
		if(head == NULL || head -> next == NULL) {
			deletehead();
		}
		else {
			node *temp2 = tail -> prev;
			node *temp1 = tail;
			tail = temp2;
			tail -> next = head;
			head -> next = tail;
			delete temp1;
		}
	}
	void insertat(int value, int pos) {
		if(pos < 1 || pos > count() + 1) {
			cout << "Not possible." << endl;
		}
		else {
			if(pos == 1) {
				inserthead(value);
			}
			else {
				if(pos == count() + 1) {
					inserttail(value);
				}		
				else {
					node *current = head;
					int i = 1;
					while (i < pos - 1) {
						current = current -> next;
						i++;
					}
					node *temp = new node(value);
					temp -> next = current -> next;
					temp -> prev = current;
					current -> next = temp;
					current = temp -> next;
					current -> prev = temp;
				}
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
					deletetail();
				}
				else {
					node *current = head;
					int i = 1;
					while(i < pos) {
						current = current -> next;
						i++;
					}
					node *temp = current;
					node *temp1 = current -> prev;
					node *temp2 = current -> next;
					temp1 -> next = temp2;
					temp2 -> prev = temp1;
					delete temp;
				}
			}
		}
	}
	int count() {
		int i = 0;
		if(head == NULL) {
			return i;
		}
		if(head -> next == NULL) {
			return i + 1;
		}
		else {
			node *current = head;
			while(current -> next != head) {
				current = current -> next;
				i++;
			}
			return i + 1;
		}
	}
	void display() {
		if(head != NULL) {
			node *current = head;
			while(current -> next != head) {
				cout << current -> data << " -> ";
				current = current -> next;
			}
			if(head -> next != NULL) {	
				cout << current -> data;
			}
		}
		cout << endl;
	}
	void rev(node *current) {
		if(head != NULL) {
			node *temp1 = NULL;
			node *temp2;
			while(current -> next != NULL) {
				temp2 = current -> next;
				current -> next = temp1;
				current -> prev = temp2;
				temp1 = current;
				current = temp2;
			}
			current -> next = tail;
			node *temp = head;
			head = temp1;
			tail = temp;
		}
	}
	void reverse() { 
		rev(head);
	}
	void revdis(node *current) {
		while(current != head) {
			cout << current -> data << " -> ";
			current = current -> prev;
		}
		if(head -> next != NULL) {
			cout << current -> data << endl;
		}
	}
	void reversedisplay() {
		revdis(tail);
	}
};
int main() {
	CircularDoublyLinkedList CDLL;
	CDLL.deleteat(1);
	CDLL.display();
	cout << "Count: " << CDLL.count() << endl;
	CDLL.insertat(999, 1);
	CDLL.inserttail(5);
	CDLL.display();
	cout << "Count: " << CDLL.count() << endl;
	CDLL.deletehead();
	CDLL.display();
	for(int i = 1; i < 10; i++) {
		CDLL.inserttail(i);
		CDLL.display();
	}
	CDLL.insertat(100, 4);
	CDLL.display();
	cout << "Count: " << CDLL.count() << endl;
	CDLL.deleteat(6);
	CDLL.display();
	CDLL.reverse();
	CDLL.display();
	CDLL.reversedisplay();
	return 0;
}
