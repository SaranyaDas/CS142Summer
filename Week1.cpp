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
        //delete at head
        void Delete() {
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
        int count() {
                node *current = head;
                int i = 0;
                while(current != NULL) {
                        i++;
                         current = current -> next;
                }
                return i;
        }
};
int main() {
        LinkedList LL;
        LL.insert(6);
        LL.display();
        LL.insert(4);
        LL.display();
        LL.insert(8);
        LL.display();
        return 0;
}
