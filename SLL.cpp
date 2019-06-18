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
class SinglyLinkedList { //LINKED LIST
	public:
	node *head;
	SinglyLinkedList() {
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
	void rev(node *current) { //12. REVERSE
		if(!empty()) {
			node *temp1 = NULL;
			node *temp2;
			while(current != NULL) {
				temp2 = current -> next;
				current -> next = temp1;
				temp1 = current;
				current = temp2;
			}
			head = temp1;
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
	void duplicates(node *current) { //14. REMOVEDUPLICATES
		if(empty() || current -> next == NULL) {
			return;
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
	void duplicatesunsorted(node *current) {
		node *temp1, *temp2, *temp;
		temp1 = current;
		while(temp1 != NULL && temp1 -> next != NULL) {
			temp2 = temp1;
			while(temp2 -> next != NULL) {
				if(temp1 -> data == temp2 -> next -> data) {
					temp = temp2 -> next;
					temp2 -> next = temp2 -> next -> next;
					delete temp;
				}
				else {
					temp2 = temp2 -> next;
				}	
			}
			temp1 = temp1 -> next;
		}
	}
	void removeduplicatesunsorted() {
		duplicatesunsorted(head);
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
void comparelists(SinglyLinkedList x, SinglyLinkedList y) { //15.5
	compare(x.head, y.head);
}
int main() { //MAIN
	SinglyLinkedList SLL;
	SLL.deletehead();
	SLL.display();
	SLL.reversedisplay();
	SLL.reverse();
	SLL.display();
	SLL.insertend(4);
	SLL.display();
	SLL.reversedisplay();
	SLL.reverse();
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
	SLL.reversedisplay();
	SLL.reverse();
	SLL.display();
	SLL.rotate(3);
	SLL.display();
	SLL.deletehead();
	SLL.display();
	SLL.deleteat(1);
	SLL.display();
	SLL.deleteat(2);
	SLL.display();
	SLL.deleteat(2);
	SLL.display();
	SLL.inserthead(100);
	SLL.inserthead(1);
	SLL.inserthead(2);
	SLL.inserthead(2);
	SLL.inserthead(3);
	SLL.inserthead(3);
	SLL.display();
	SLL.removeduplicates();
	SLL.display();
	SinglyLinkedList EU = SLL;
	EU.display();
	comparelists(EU, SLL);
	EU.reverse();
	EU.display();
	comparelists(EU, SLL);
	EU.insertat(999, 3);
	EU.insertend(999);
	EU.display();
	EU.removeduplicatesunsorted();
	EU.display();
	return 0;
}
