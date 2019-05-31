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
	void insert(int value) { //function to insert node at head
		node *temp = new node(value); //pointer to new node (with given value as data and pointer to NULL by default)
		if(head == NULL) { //case: empty list
			head = temp;
		}
		else { //case: non-empty list
			temp -> next = head; //new node now points to head
			head = temp; //new node becomes head
		}
	}
	void display() { //function to display nodes in list
		if(head == NULL) { //case: empty list
			cout << "Empty List." << endl;
		}
		else { //case: non-empty list
			node *current = head; //temporary pointer to traverse list, starts from head
			while(current != NULL) { //till pointer points to NULL
				cout << current -> data << " -> ";
				current = current -> next; //pointer traverses list till it reaches last node
			}
			cout << "NULL" << endl;
		}
	}
	node *removeduplicates(node *current) { //function to delete duplicate-value nodes from sorted linked list
		if(current == NULL || current -> next == NULL) { //cases: empty list or single node
			return current;
		}
		else { //case: non-empty list
			while(current -> next != NULL) { //as long as pointer does not point to NULL
				if(current -> data != current -> next -> data) { //case: consecutive nodes store uneuqal data
					current = current -> next; //pointer traverses list
				}
				else { //case: consecutive nodes store equal data
					node *temp = current -> next; //another temporary pointer points to duplicate node
					current -> next = temp -> next; //current node now points to node after duplicate node
					delete temp; //deletes duplicate node
				}
			}		
		}
	}
	void *duplicates() { //dummy function
		removeduplicates(head);
	}	
	node *reverselist(node *current) { //function to reverse a linked list 
		if(current == NULL || current -> next == NULL) { //i.e., till original current (temporary pointer) points to secondlast node and (original) current -> next = last node AT FIRST
			head = current; //last node becomes head, head points to NULL now
			return current; //returns last node (current -> next) AT FIRST
		}
		reverselist(current -> next); //recursion; repeats till first node (now last) points to NULL (instead of pointing to second node)
		node *temp = current -> next; //current points to secondlast node which points to last node (now head), temp points to last node
		temp -> next = current; //last node (now head) points to secondlast node now (instead of pointing to NULL)
		current -> next = NULL; //secondlast node points to NULL (instead of pointing to last node)
	}
	void reverse() { //dummy function
		reverselist(head);
	}
};
void comparelists(node *current1, node *current2) { //function to compare two linked lists
	if(current1 != NULL && current2 != NULL) { //case: temporary pointers do not point to NULL in either list
		if(current1 -> data != current2 -> data) { //case: unequal data in corresponding nodes
			cout << " not identical." << endl;
		}
		else { //case: equal data in corresponding nodes
			comparelists(current1 -> next, current2 -> next); //pointers traverse lists
		}
	}
	if(current1 == NULL || current2 == NULL) { //case: corresponding temporary pointers point to NULL in one or both lists  
		if(current1 == NULL && current2 == NULL) { //case: pointers point to NULL in both lists (either both empty or pointers have traversed two identical lists)
			cout << " identical." << endl;
		}
		else { //case: pointer points to NULL in only one list, i.e., one list shorter than other
			cout << " not identical." << endl;
		}
	}
}
void compare(LinkedList x, LinkedList y) { //dummy function
	comparelists(x.head, y.head);
}
int main() { //driver function
	LinkedList A;
	LinkedList B;
	LinkedList C;
	LinkedList D;
	LinkedList E;
	LinkedList F;
	E.insert(10);
	E.insert(9);
	for(int i = 9; i > 0; i--) {
		A.insert(i);
		B.insert(i);
		C.insert(10 - i);
		E.insert(i);
	}
	E.insert(1);
	E.insert(1);
	F.insert(1);
	cout << "List A display: ";
	A.display();
	cout << "List B display: ";
	B.display();
	cout << "List C display: ";
	C.display();
	cout << "List D display: ";
	D.display();
	cout << "List E display: ";
	E.display();
	cout << "List F display: ";
	F.display();
	cout << "Lists A and B are";
	compare(A, B);
	cout << "Lists B and C are";
	compare(B, C);
	cout << "Lists C and D are";
	compare(C, D);
	E.duplicates();
	cout << "Removed duplicates from sorted Linked List E." << endl;
	cout << "List E display: ";
	E.display();
	E.reverse();
	cout << "Reversed Linked List E." << endl;
	cout << "List E display: ";
	E.display();
	D.reverse();
	cout << "Reversed Linked List D." << endl;
	cout << "List D display: ";
	D.display();
	F.reverse();
	cout << "Reveresed Linked List F." << endl;
	cout << "List F display: ";
	F.display();
	return 0;
}
