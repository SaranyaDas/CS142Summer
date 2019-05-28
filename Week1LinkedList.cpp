#include <iostream> //standard input/output streams library
using namespace std; //standard namespace
class node {
        public:
        int data; //data in node
        node *next; //pointer to next node
        node(int value) { //default constructor
                data = value;
                next = NULL;
        }
};
class LinkedList {
        public:
        node *head; //pointer to head node
        LinkedList() { //default constructor
                head = NULL;
        }
        void insert(int value) { //function to insert node at end with given value
                node *temp = new node(value); //pointer to new node (with given value as data and pointer to NULL by default)
                if(head == NULL) { //case: empty list, head = end
                        head = temp; //new node becomes head
                }
                else { //case: non-empty list
                        node *current = head; //temporary pointer to traverse list, starts from head
                        while(current -> next != NULL) { //as long as next node exists
                                current = current -> next; //pointer points to next node; thereby traversing list and reaching last node
                        }
                        current -> next = temp; //(former) last node points to new (last) node
                }
                cout << "Inserted node with data " << value << " at end of list." << endl;
        }
        void insertAt(int position, int value) { //function to insert new node at given position with given value
                node *temp = new node(value); //pointer to new node (with given value as data and pointer to NULL by default)
                node *current = head; //temporary pointer to traverse list, starts from head
                if(position < 1 || position > countItems() + 1) { //case: given position less than 1 (counting starts at 1) or 2 more than total
                        cout << "Cannot insert node with data " << value << " at position " << position << ". "  << "Linked List does not have that many elements." << endl;
                }
                else {
                        if(position == 1) { //new node to be inserted before current head
                                temp -> next = head; //new node points to current head
                                head = temp; //new node becomes head
                        }
                        else { //new node to be inserted between head and end or at end
                                int i = 1; //counter; positioning in list starts with 1
                                while(i < position - 1) { //till counter becomes position's preceding number
                                        i++; //counter increases by 1
                                        current = current -> next; //temporary pointer traverses list till it reaches node preceding node at position
                                }
                                temp -> next = current -> next; //new node points to pre-existing node at position
                                current -> next = temp; //node before node at given position points to new node; new node inserted at given position
                        }
                        cout << "Inserted node with data " << value << " at position " << position << " in list." << endl;
                }
        }
        void Delete() { //function to delete node at end
        	int j; //variable to store data of node to be deleted
                if(head != NULL) { //case: non-emtpy list
                        node *current = head; //temporary pointer to traverse list, starts from head
                	if(current -> next == NULL) { //case: single node in list
                		j = head -> data; //stores node-to-be-deleted's data
                		head = NULL; //list becomes empty
                	}
                        else { //case: more than one node in list
                        	while(current -> next -> next != NULL) { //as long as next node does not point to NULL
                             		current = current -> next; //temporary pointer traverses list and reaches penultimate node
                        	}
                        	node *temp = current -> next; //pointer to last node
                        	j = temp -> data; //stores node-to-be-deleted's data
                        	current -> next = NULL; //penultimate node points to NULL
                        	delete temp; //last node deleted
                	}
                	cout << "Deleted last node with data " << j << "." << endl;
                }
                else { //case: empty list
                        cout << "Empty List. Nothing to delete." << endl;
                }
        }
        void deleteAt(int position) { //function to delete node at given position
                node *current = head; //temporary pointer to traverse list, starts from head
                int j; //variable to store data of node to be deleted
                if(position < 1 || position > countItems()) { //case: given position less than 1 (counting starts at 1) or more than total number of nodes 
                        cout << "Cannot delete node at position " << position << ". " << "Linked List does not have that many elements." << endl;
                }
                else { 
                        if(position == 1) { //node at head to be deleted
                                if(head != NULL) { //case: non-empty list
                                        node *temp = head; //pointer to head
                                        j = temp -> data; //stores head's data
                                        current = temp -> next; //temporary pointer traverses list by one node, i.e., reaches second node
                                        head = current; //second node becomes head
                                        delete temp; //former head deleted
                                }
                                else { //case: empty list
                                        cout << "Empty List." << endl;
                                }
                        }
                        else {
                                int i = 1; //counter, positioning in list starts with 1
                                while(i < position - 1) { //till counter becomes position's preceding number
                                	i++; //counter increases by 1
                                        current = current -> next; //temporary pointer traverses list till it points to node before node at given position
                                }
                                node *temp = current -> next; //pointer to node at given position
                                j = temp -> data; //stores node-to-be-deleted's data
                                current -> next = temp -> next; //node before node at given position points to node after node at given position
                                delete temp; //node at given position deleted
                        }
               		cout << "Deleted node at position " << position << " with data " << j << "." << endl;
                }
        }
        int countItems() { //function to count number of nodes in list
                node *current = head; //temporary pointer to traverse list, starts from head
                int i = 0; //counter, starts from 0
                while(current != NULL) { //till pointer reaches last node
                        current = current -> next; //it traverses list
                        i++; //and counter increases by 1
                }
                return i; //returns count
        }
        void display() { //function to display nodes in list
        	cout << "Linked List display: ";
                if(head == NULL) { //case: empty list
                        cout << "Empty List." << endl;
                }
                else { //case: non-empty list
                        node *current = head; //temporary pointer to traverse list, starts from head
                        while(current != NULL){ //till pointer points to NULL
                                cout << current -> data << " -> ";
                                current = current -> next; //pointer traverses list till it reaches last node
                        }
                        cout << "NULL" << endl;
                }
        }
};
int main() {
        LinkedList LL;
        cout << "Created linked list." << endl;
        cout << "Count: " << LL.countItems() << endl;
        LL.Delete();
        LL.insertAt(1, 6);
        LL.display();
        LL.Delete();
        LL.display();
        LL.insert(4);
        LL.display();
        LL.insertAt(1000, 2);
        LL.display();
        LL.insert(8);
        LL.display();
        LL.Delete();
        LL.display();
        LL.insertAt(1, 2);
        LL.display();
        LL.insertAt(2, 9);
        LL.display();
        cout << "Count: " << LL.countItems() << endl;
        LL.insertAt(4, 1);
        LL.display();
        LL.deleteAt(3);
        LL.display();
        LL.deleteAt(1);
        LL.display();
        LL.deleteAt(-222);
        LL.display();
        cout << "Count: " << LL.countItems() << endl;
        return 0;
}
