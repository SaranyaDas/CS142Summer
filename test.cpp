/*classes: node and linked list, functions: empty, getpos, count, inserthead, insertend, insertat, deletehead, deleteend, deleteat, display, reverse display, reverse, rotate, removeduplicates, compare, main*/
#include <iostream>
using namespace std;
class node { //NODE
	public:
	int data;
	node *next;
	node(int value) {
		data = value;
		next = NULL;
	}
};
class linkedlist { //LINKED LIST
	public:
	node *head;
	linkedlist() {
		head = NULL;
	}
	bool empty() { //1. EMPTY
		if(head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	node *getpos(int pos) { //2. GETPOS
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
	int count() { //3. COUNT
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
	void inserthead(int value) { //4. INSERTHEAD
		node *temp = new node(value);
		if(empty()) {
			head = temp;
		}
		else {
			temp -> next = head;
			head = temp;
		}	
	}
	void insertend(int value) { //5. INSERTEND
		node *temp = new node(value);
		if(empty()) {
			head = temp;
		}
		else {
			node *current = getpos(count());
			current -> next = temp;
		}
	}
	void insertat(int value, int pos) { //6. INSERTAT
		if(pos < 1 || pos > count() + 1) {
			cout << "no can do" << endl;
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
	void deletehead() { //7. DELETEHEAD
		if(empty()) {
			cout << "no can do" << endl;
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
	void deleteend() { //8. DELETEEND
		if(empty()) {
			cout << "no can do" << endl;
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
	void deleteat(int pos) { //9. DELETEAT
		if(pos < 1 || pos > count()) {
			cout << "no can do" << endl;
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
	void display() { //10. DISPLAY
		if(!empty()) {
			node *current = head;
			while(current != NULL) {
				cout << current -> data << " -> ";
				current = current -> next;
			}
		}
		cout << "NULL" << endl;
	}
	node *revdis(node *current) { //11. REVERSE DISPLAY
		if(current == NULL) {
			return current;
		}
		revdis(current -> next);
		cout << current -> data << " -> ";
	}
	void reversedisplay() { //11.5
		revdis(head);
		cout << "NULL" << endl;
	}
	node *rev(node *current) { //12. REVERSE
		if(empty()) {
			return NULL;
		}
		else { 
			if(current -> next == NULL) {
				head = current;
				return current;
			}
			rev(current -> next);
			node *temp = current -> next;
			temp -> next = current;
			current -> next = NULL;
		}
	}
	void reverse() { //12.5
		rev(head);
	}
	void rotate(int k) { //13. ROTATE
		if(k < 1 || k >= count()) {
			cout << "no can do" << endl;
		}
		else { 
			node *current = getpos(k);
			node *temp1 = current -> next;
			node *temp2 = getpos(count());
			temp2 -> next = head;
			head = temp1;
			current -> next = NULL;
		}
	}
	node *duplicates(node *current) { //14. REMOVEDUPLICATES
		if(empty() || current -> next == NULL) {
			return current;
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
	void removeduplicates() { //14.5
		duplicates(head);
	}
};
node *compare(node *current1, node *current2) { //15
	if(current1 == NULL || current2 == NULL) {
		if(current1 == NULL && current2 == NULL) {
			cout << "ye" << endl;
		}
		else {
			cout << "nay" << endl;
		}
	}
	else {
		if(current1 -> data != current2 -> data) {
			cout << "nay" << endl;
		}
		else {
			compare(current1 -> next, current2 -> next);
		}
	}
}
void comparelists(linkedlist x, linkedlist y) { //15.5
	compare(x.head, y.head);
}
int main() { //MAIN
	linkedlist LL;
	LL.deletehead();
	LL.display();
	LL.reversedisplay();
	LL.reverse();
	LL.display();
	LL.insertend(4);
	LL.display();
	LL.reversedisplay();
	LL.reverse();
	LL.display();
	LL.deletehead();
	LL.display();
	LL.inserthead(2);
	LL.display();
	LL.insertend(3);
	LL.display();
	LL.insertat(100, 3);
	LL.display();
	LL.insertat(12, 1);
	LL.insertat(9, 3);
	LL.display();
	LL.reversedisplay();
	LL.reverse();
	LL.display();
	LL.rotate(3);
	LL.display();
	LL.deletehead();
	LL.display();
	LL.deleteat(1);
	LL.display();
	LL.deleteat(2);
	LL.display();
	LL.deleteat(2);
	LL.display();
	LL.inserthead(100);
	LL.inserthead(1);
	LL.inserthead(2);
	LL.inserthead(2);
	LL.inserthead(3);
	LL.inserthead(3);
	LL.display();
	LL.removeduplicates();
	LL.display();
	linkedlist EU = LL;
	EU.display();
	comparelists(EU, LL);
	EU.reverse();
	EU.display();
	comparelists(EU, LL);
	return 0;
}
