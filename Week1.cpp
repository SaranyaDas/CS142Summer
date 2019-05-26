//Linked List
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
        //insert at end
        void insert(int data) {
                node *temp = new node(data);
                if(head == NULL) {
                        head = temp;
                }
                else { 
                        node *current = head;
                        while(current -> next != NULL) {
                                current = current -> next;
                        }
                        current -> next = temp;
                }
        }
        void insertAt(int position, int data) {
                int j = count();
                node *temp = new node(data);
                node *current = head;
                if(position < 1 || position > j + 1) {
                        cout << "Linked List does not have that many elements. Cannot insert at position " << position << "."  << endl;
                }
                else {
                        if(position == 1) {
                                node *temp = new node(data);
                                temp -> next = head;
                                head = temp;
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
        //delete at end
        void Delete() {
                if(head != NULL) {
                        node *current = head;
                        while(current -> next -> next != NULL) {
                                current = current -> next;
                        }
                        node *temp = current -> next;
                        current -> next = NULL;
                        delete temp;
                }
                else {
                        cout << "Empty List." << endl;
                }
        }
        void deleteAt(int position) {
                int j = count();
                node *current = head;
                if(position < 1 || position >= j + 1) {
                        cout << "Linked List does not have that many elements. Cannot delete at position " << position << "." << endl;
                }
                else { 
                        if(position == 1) {
                                if(head != NULL) {
                                        node *temp = head;
                                        node *current = temp -> next;
                                        head = current;
                                        delete temp;
                                }
                                else {
                                        cout << "Empty List." << endl;
                                }
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
        int count() {
                node *current = head;
                int i = 0;
                while(current != NULL) {
                        i++;
                         current = current -> next;
                }
                return i;
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
};
int main() {
        LinkedList LL;
        LL.insert(6);
        LL.display();
        LL.insert(4);
        LL.display();
        LL.insertAt(1000, 2);
        LL.insert(8);
        LL.display();
        LL.Delete();
        LL.display();
        LL.insertAt(1, 2);
        LL.insertAt(2, 9);
        LL.display();
        cout << "Count: " << LL.count() << endl;
        LL.insertAt(5, 1);
        LL.display();
        LL.deleteAt(3);
        LL.display();
        LL.deleteAt(1);
        LL.display();
        LL.deleteAt(-222);
        LL.display();
        cout << "Count: " << LL.count() << endl;
        return 0;
}
