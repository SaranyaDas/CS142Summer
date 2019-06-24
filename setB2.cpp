#include <iostream>
using namespace std;
class node {
	public:
	int data;
	node *next;
	node(int value) { //default constructor
		data = value;
		next = NULL;
	}
};
class linkedlist {
	public:
	node *head;
	linkedlist() { //default constructor
		head = NULL;
	}
	void insert(int value) { //function to insert new node at head
		node *temp = new node(value);
		if(empty()) {
			head = temp;
		}
		else {
			temp -> next = head;
			head = temp;
		}
			
	}
	int count() { //function to count total number of nodes in linked list
		int i = 0;
		if(!empty()) {
			node *current = head;
			while(current != NULL) {
				i++;
				current = current -> next;
			}
		}
		return i;
	}
	node *getpos(int pos) { //function to get node at given position
		if(empty()) {
			cout << "Empty list." << endl;
			return NULL;
		}
		else {
			if(pos < 1 || pos > count()) {
				cout << "Linked list does not have that many elements." << endl;
				return NULL;
			}
			else {
				node *current = head;
				int i = 1;
				while (i < pos) {
					current = current -> next;
					i++;
				}
				return current;
			}
		}
	}
	void display() { //function to display linked list
		if(!empty()) {
			node *current = head;
			while(current != NULL) {
				cout << current -> data << " -> ";
				current = current -> next;
			}
			cout << "NULL" << endl;
		}
		else {
			cout << "Empty list." << endl;
		}
	}
	bool empty() { //function to check if linked list is empty
		if(head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void swap(int i, int j) { //function to swap data between nodes at positions i and j 
		int temp = getpos(i) -> data;
		getpos(i) -> data = getpos(j) -> data;
		getpos(j) -> data = temp;
	}
};
int partition(linkedlist ll, int low, int high) { //partition function
	int pivot = high;
	int j = low;
	for(int i = low; i < high; i++) {
		while(ll.getpos(i) -> data <= ll.getpos(pivot) -> data) {
			ll.swap(i, j);
			j++;
		}
	}
	ll.swap(pivot, j);
	return j;
}
void quicksort(linkedlist ll, int low, int high) { //quicksort function
	if(low < high) {
		int pi = partition(ll, low, high); //pi = partitioning index
		quicksort(ll, low, pi - 1);
		quicksort(ll, pi + 1, high);
	}
}
int main() {
	linkedlist ll;
	cout << "Count: " << ll.count() << endl;
	ll.insert(13);
	ll.insert(39);
	for(int i = 0; i < 10; i++) {
		ll.insert(2*i + 1);
	}	
	ll.insert(46);
	ll.insert(48);
	ll.display();
	cout << "Count: " << ll.count() << endl;
	ll.swap(3,9);
	ll.display();
	quicksort(ll, 1, ll.count());
	cout << "Sorted linked list: ";
	ll.display();
	return 0;
}
