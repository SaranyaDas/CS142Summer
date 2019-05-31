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
        void insert(int value) { //insert at head
                node *temp = new node(value);
        	if(isEmpty()) {
        		head = temp;
        	}
        	else {
                	temp -> next = head;
                	head = temp;
                }
        }	
        void Delete() { //delete at head
                if(isEmpty()) {
                        cout << "Nothing to delete. Empty List." << endl;
                }
                else {
                        node *temp = head;
                        node *current = temp -> next;
                        head = current;
                        delete temp;
                }
        }
        void display() {
                if(isEmpty()) {
                        cout << "Empty List." << endl;
                }
                else {
                        node *current = head;
                        while(current != NULL){
                                cout << current -> data << " -> ";
                                current = current -> next;
                        }
                        cout << "NULL" << endl;
                }
        }
        int count() {
                node *current = head;
                int i = 0;
                while(current != NULL) {
                        i++;
                        current = current -> next;
                }
                return i;
        }
        bool isEmpty() {
        	if(head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	node *getpos(int pos) {
		node *current = head;
		int i = 1;
		if(pos < 1 || pos > count()) {
			return NULL;
		}
		else { 
			while(i < pos) {
				current = current -> next;
				i++;
			}
			return current;
		}
	}
        node *reversedisplay(node *current) { //function to display nodes in list in reverse
        	if(current == NULL) {
        		return current;
        	}
        	reversedisplay(current -> next);
        	cout << current -> data << " -> ";
        }
        void *reverse() {
        	reversedisplay(head);
        	cout << "NULL" << endl;
        }
        void rotate(int k) { //function to rotate list counter-clockwise by k nodes
        	node *current = head; //temporary pointer to traverse list
        	int i = 1;
        	if(k >= 1 && k < count()) {
        		while(i < k) {
				current = current -> next;
				i++;
			} //current at kth node now
			node *temp1 = current; //points to kth node
			node *temp2 = current -> next; //points to (k+1)th node
        		while(current -> next != NULL) {
				current = current -> next;
			} //current at last node now
        		temp1 -> next = NULL; //kth node points to NULL, becomes last node
			current -> next = head; //(former) last node points to head
			head = temp2; //(k+1)th node becomes head
		}
		else {
			cout << "Not possible. " << endl;
		}
	}
        void insertAt(int position, int value) {
                node *temp = new node(value);
                if(position < 1 || position > count() + 1) {
                        cout << "Not possible." << endl;
                }
                else {
                        if(position = 1) {
                                insert(value);
                        }
                        else {
                                node *current = getpos(position - 1);
                                temp -> next = current -> next;
                                current -> next = temp;
                        }
                }
        }
        void deleteAt(int position) {
                node *current = head;
                if(position < 1 || position >= count() + 1) {
                        cout << "Not possible." << endl;
                }
                else { 
                        if(position = 1) {
                                Delete();
                        }
                        else {
                                int i = 1;
                                while(i < position - 1) {
                                        current = current -> next;
                                        i++;
                                }
                                node *temp = current -> next;
                                current -> next = temp -> next;
                                delete temp;
                        }
                }
        }
};
int main() {
        LinkedList LL;
        LL.display();
        cout << "Rotate counter-clockwise by 1 node: ";
        LL.rotate(1);
        cout << "Insert at head: ";
        LL.insert(6);
   	LL.display();
   	cout << "Rotate counter-clockwise by 1 node: ";
   	LL.rotate(1);
   	cout << "Insert at head: ";
        LL.insert(4);
        LL.insert(8);
        LL.display();
        cout << "Count: " << LL.count() << endl;
        cout << "Delete at 1: ";
        LL.deleteAt(1);
        LL.display();
        cout << "Count: " << LL.count() << endl;
        cout << "Insert at 1: ";
        LL.insertAt(1, 7);
        LL.display();
        cout << "Insert at 3: ";
        LL.insertAt(3, 5);
        LL.display();
        cout << "Insert at 5: ";
        LL.insertAt(5, 2);
        LL.display();
        cout << "Insert at 100: ";
        LL.insertAt(100, 2);
        LL.display();
        cout << "Delete at 5: ";
        LL.deleteAt(5);
        LL.display();
        cout << "Delete at 2: ";
        LL.deleteAt(2);
        LL.display();
        cout << "Delete at -3: ";
        LL.deleteAt(-3);
        LL.display();
        cout << "Reverse: ";
        LL.reverse();
        for(int i = 0; i < 10; i++) {
        	LL.insert(i);
        }
        LL.display();
        cout << "Rotate counter-clockwise by 6 nodes: ";
        LL.rotate(6);
        LL.display();
        return 0;
}
