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
        //insert at head
        void insert(int data) {
                node *temp = new node(data);
                temp -> next = head;
                head = temp;
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
        void count() {
                node *current = head;
                int count = 0;
                while(current != NULL) {
                        count++;
                        current = current -> next;
                }
                cout << "Count: " << count << "." << endl;
        }
};
int main() {
        LinkedList LL;
        LL.insert(6);
        LL.insert(4);
        LL.insert(8);
        LL.display();
        LL.count();
        LL.Delete();
        LL.display();
        LL.count();
        return 0;
}
