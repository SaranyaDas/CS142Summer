#include <iostream>
using namespace std;
class node {
	public:
	int data;
	node *prev;
	node *next;
	node(int value) {
		data = value;
		prev = NULL;
		next = NULL;
	}
};
class DoublyLinkedList {
	public:
	node *head;
	node *tail;
	DoublyLinkedList() {
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
				node *temp = head;
				head = temp -> next;
				head -> prev = NULL;
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
			temp -> prev = tail;
			tail -> next = temp;
			tail = temp;
		}
	}
	void deletetail() {
		if(head == NULL || head -> next == NULL) {
			deletehead();
		}
		else {
			node *temp = tail;
			tail = temp -> prev;
			tail -> next = NULL;
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
					while(i < pos) {
						current = current -> next;
						i++;
					}
					node *temp = current;
					node *temp1 = current -> prev;
					node *temp2 = current -> next;
					temp2 -> prev = temp1;
					temp1 -> next = temp2;
					delete temp;
				}
			}
		}
	}
	void display() {
		if(head != NULL) {
			node *current = head;
			cout << "NULL <- ";
			while(current != NULL) {
				cout << current -> data << " -> ";
				current = current -> next;
			}
		}
		cout << "NULL" << endl;
	}
	void reversedisplay() {
		if(head != NULL) {
			cout << "NULL <- ";
			revdis(head);
		}
		cout << "NULL" << endl;
	}
	void revdis(node *current) {
		if(current == NULL) {
			return;
		}
		revdis(current -> next);
		cout << current -> data << " -> ";
	}
	void reverse() {
		rev(head);
	}
	void rev(node *current) {
		if(current == NULL) {
			return;
		}
		node *temp = current -> next;
		current -> next = current -> prev;
		current -> prev = temp;
		if(current -> prev == NULL) {
			tail = head;
			head = current;
			return;
		}
		rev(current -> prev);
	}
	int count() {
		int i = 0;
		if(head == NULL) {
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
};
int main() {
	DoublyLinkedList DLL;
	DLL.deleteat(1);
	cout << "Count: " << DLL.count() << endl;
	DLL.insertat(999, 1);
	DLL.display();
	DLL.deleteat(1);
	DLL.reversedisplay();
	for(int i = 1; i < 10; i++) {
		DLL.inserttail(i);
		DLL.display();
	}
	DLL.display();
	DLL.reversedisplay();
	DLL.insertat(100, 4);
	DLL.display();
	DLL.reversedisplay();
	cout << "Count: " << DLL.count() << endl;
	DLL.reverse();
	DLL.display();
	DLL.deletehead();
	DLL.display();
	DLL.deletetail();
	DLL.display();
	DLL.deleteat(6);
	DLL.display();
	return 0;
}
