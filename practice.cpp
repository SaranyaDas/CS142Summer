#include <iostream>
using namespace std;
/*classes: node and linkedlist, functions: insert at head, end, pos, delete at head, end, pos, display, reversedisplay, count, reverse, removeduplicates, compare, empty, getpos, rotate*/
class node { //CLASS NODE
	public:
	int data;
	node *next;
	node(int value) {
		data = value;
		next = NULL;
	}
};
class list { //CLASS NODE
	public:
	node *head;
	list() {
		head = NULL;
	}
	int count() { //1. count
		node *current = head;
		int i = 0;
		while(current != NULL) {
			i++;
			current = current -> next;
		}
		return i;
	}
	node *getpos(int pos) { //2. getpos
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
	bool empty() { //3. empty
		if(head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void inserthead(int value) { //4. inserthead
		node *temp = new node(value);
		if(empty()) { //case: empty list
			head = temp;
		}
		else { //case: non-empty list
			temp -> next = head;
			head = temp;
		}
	}
	void insertend(int value) { //5. insertend
		node *temp = new node(value);
		node *current = head;
		if(empty()) {
			head = temp;
		}
		else {
			while(current -> next != NULL) {
				current = current -> next;
			}
			current -> next = temp;
		}
			
	}
	void insertat(int value, int pos) { //6. insertat
		node *temp = new node(value);
		if(pos < 1 || pos > count() + 1) {
			cout << "No can do." << endl;
		}
		else {
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
	void deletehead() { //7. deletehead
		node *temp = head;
		if(empty()) {
			cout << "No can do." << endl;
		}
		else {
			if(head -> next == NULL) {
				head = NULL;
			}
			else {
				head = temp -> next;
				delete temp;
			}
		}	 
	}
	void deleteend() { //8. deleteend
		if(empty()) {
			cout << "No can do." << endl;
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
	void deleteat(int pos) { //9. deleteat
		if(pos < 1 || pos > count()) {
			cout << "No can do." << endl;
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
	void display() { //10. display
		node *current = head;
		if(empty()) {
			cout << "No can do." << endl;
		}
		else {
			while(current != NULL) {
				cout << current -> data << " -> ";
				current = current -> next;
			}
		cout << "NULL" << endl;
		}
	}
	node *revdis(node *current) { //11. reversedisplay
		if(current == NULL) {
			return current;
		}
		revdis(current -> next);
		cout << current -> data << " -> ";
	}
	void revdisplay() { //11.5. dummy function
		revdis(head);
		cout << "NULL" << endl;
	}	
	node *reverse(node *current) { //12. reverse
		if(current == NULL || current -> next == NULL) {
			head = current;
			return current;
		}
		reverse(current -> next);
		node *temp = current -> next;
		temp -> next = current;
		current -> next = NULL;
	}
	node *removeduplicates(node *head) { //13. removeduplicates
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
					current -> next = temp -> next;
					delete temp;
				}
			}
		}
	}
	void rotate(int k) { //14. rotate
		node *current = getpos(k);
		if(k < 1 || k >= count()) {
			cout << "No can do." << endl;
		}
		else {
			node *temp1 = current -> next;
			node *temp2 = getpos(count());
			temp2 -> next = head;
			head = temp1;
			current -> next = NULL;
		}
	}
};
void compare(node *current1, node *current2) { //15. compare
	if(current1 != NULL && current2 != NULL) {
		if(current1 -> data == current2 -> data) {
			compare(current1 -> next, current2 -> next);
		}
		else {
			cout << "Nah." << endl;
		}
	}
	else { //if(current1 == NULL || current2 == NULL)
		if(current1 == NULL && current2 == NULL) {
			cout << "Yeah." << endl;
		}
		else {
			cout << "Nah." << endl;
		}
	}
}
int main() {
	list LL;
	list EL;
	list DL;
	list TL;
	for(int i = 1; i < 10; i++) {
		LL.insertend(i);
		EL.inserthead(i);
		DL.insertend(i);
		TL.inserthead(i);
	}
	LL.display();
	LL.deleteend();
	LL.display();
	LL.rotate(4);
	LL.display();
	LL.reverse(LL.head);
	LL.display();
	LL.revdisplay();
	cout << "EL: ";
	EL.display();
	cout << "DL: ";
	DL.display();
	cout << "TL: ";
	TL.display();
	cout << "EL & DL: ";
	compare(EL.head, DL.head);
	cout << "EL & TL: ";
	compare(EL.head, TL.head);
	LL.inserthead(1);
	LL.display();
	LL.insertend(1);
	LL.display();
	LL.deletehead();
	LL.display();
	LL.deleteend();
	LL.display();
	LL.insertat(100, 9);
	LL.display();
	LL.insertat(100, 1);
	LL.display();
	LL.deleteat(10);
	LL.display();
	LL.deleteat(1);
	LL.display();
	LL.insertat(500, 5);
	LL.display();
	LL.deleteat(5);
	LL.display();
	return 0;
}
