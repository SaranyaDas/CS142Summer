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
class CircularSinglyLinkedList {
	public:
	node *head;
	node *tail;
	CircularSinglyLinkedList() {
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
			head = temp;
			tail -> next = head;
		}
	}
	void deletehead() {
		if(head == NULL) {
			cout << "Not possible" << endl;
		}
		else {
			if(head -> next == NULL) {
				head = NULL;
				tail = NULL;
			}
			else {
				node *temp1 = head;
				if(count() == 2) {
					node *temp2 = tail;
					int i = tail -> data;
					delete temp1;
					delete temp2;
					inserthead(i);
				}
				else {
					head = temp1 -> next;
					tail -> next = head;
					delete temp1;
				}
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
			tail = temp;
			tail -> next = head;
		}
	}
	void deletetail() {
		if(head == NULL || head -> next == NULL) {
			deletehead();
		}
		else {
			node *current = head;
			while(current -> next != tail) {
				current = current -> next;
			}
			node *temp = tail;
			current -> next = head;
			tail = current;
			delete temp;
		}
	}
	void insertat(int value, int pos) {
		if(pos < 1 || pos > count() + 1) {
			cout << "Not possible" << endl;
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
					while(i < pos - 1) {
						current = current -> next;
						i++;
					}
					node *temp = new node(value);
					temp -> next = current -> next;
					current -> next = temp;
				}
			}
		}
	}
	void deleteat(int pos) {
		if(pos < 1 || pos > count()) {
			cout << "Not possible" << endl;
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
					while(i < pos - 1) {
						current = current -> next;
						i++;
					}
					node *temp = current -> next;
					current -> next = temp -> next;
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
				cout << current -> data << " -> ";
			}
		}
		cout << "NULL" << endl;
	}
};
int main() {
	CircularSinglyLinkedList CSLL;
	CSLL.deleteat(1);
	CSLL.display();
	cout << "Count: " << CSLL.count() << endl;
	CSLL.insertat(999, 1);
	CSLL.inserttail(5);
	CSLL.display();
	cout << "Count: " << CSLL.count() << endl;
	CSLL.deletehead();
	CSLL.display();
	for(int i = 1; i < 10; i++) {
		CSLL.inserttail(i);
		CSLL.display();
	}
	CSLL.insertat(100, 4);
	CSLL.display();
	cout << "Count: " << CSLL.count() << endl;
	CSLL.deleteat(6);
	CSLL.display();
	return 0;
}		
