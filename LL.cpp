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
        //insert at the start
        void insert(int data) {
                node *temp = new node(data);
                temp -> next = head;
                head = temp;
                }
        void display() {
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
};
int main() {
        LinkedList LL;
        LL.display();
        LL.insert(6);
        LL.insert(4);
        LL.insert(8);
        LL.display();
        return 0;
}
