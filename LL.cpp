#include <iostream>
using namespace std;
class node {
        public:
        int value;
        node *next;
        node(int data) {
                value = data;
                next = NULL;
        }
};
class LinkedList {
        public:
        node *head;
        LinkedList() {
                head = NULL;
        }
        void insert(int data) { //insert at head
                node *temp = new node(data);
        	if(head == NULL) {
        		head = temp;
        	}
        	else {
                	temp -> next = head;
                	head = temp;
                }
        }
        void display() {
                if(head == NULL) {
                        cout << "Empty List." << endl;
                }
                else {
                        node *current = head;
                        while(current != NULL){
                                cout << current -> value;
                                if(current -> next != NULL) {
                                        cout << " -> ";
                                }
                                current = current -> next;
                        }
                        cout << endl;
                }
        }
        void Delete() { //delete at head
                if(head != NULL) {
                        node *temp = head;
                        node *current = temp -> next;
                        head = current;
                        delete temp;
                }
                else {
                        cout << "Nothing to delete. Empty List." << endl;
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
        void insertAt(int position, int data) {
                int j = count();
                node *temp = new node(data);
                node *current = head;
                if(position < 1 || position >= j + 1) {
                        cout << "Not possible." << endl;
                }
                else {
                        if(position == 1) {
                                insert(data);
                        }
                        else {
                                int i = 1;
                                while(i < position - 1) {
                                        current = current -> next;
                                        i++;
                                }
                                temp -> next = current -> next;
                                current -> next = temp;
                        }
                }
        }
        void deleteAt(int position) {
                int j = count();
                node *current = head;
                if(position < 1 || position >= j + 1) {
                        cout << "Not possible." << endl;
                }
                else { 
                        if(position == 1) {
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
        LL.insert(6);
        LL.insert(4);
        LL.insert(8);
        LL.display();
        cout << LL.count() << endl;
        LL.Delete();
        LL.display();
        cout << LL.count() << endl;
        LL.insertAt(1, 6);
        LL.display();
        LL.insertAt(3, 5);
        LL.display();
        LL.insertAt(5, 2);
        LL.display();
        LL.insertAt(100, 2);
        LL.display();
        LL.deleteAt(5);
        LL.display();
        LL.deleteAt(2);
        LL.display();
        LL.deleteAt(-3);
        LL.display();
        return 0;
}
