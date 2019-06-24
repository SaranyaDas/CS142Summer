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
};
void swap(int array[], int i, int j) { //function to swap data
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
}
int partition(int array[], int low, int high) { //partition function
	int pivot = high;
	int j = low;
	for(int i = low; i < high; i++) {
		while(array[i] <= array[pivot]) {
			swap(array, i, j);
			j++;
		}
	}		
	swap(array, pivot, j);
	return j;
}
void quicksort(int array[], int low, int high) { //quicksort function
	if(low < high) {
		int pi = partition(array, low, high); //pi = partitioning index
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}
void arraydisplay(int array[], int size) {
	for(int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main() {
	linkedlist ll;
	ll.insert(10);
	ll.insert(14);
	ll.insert(32);
	ll.insert(1);
	ll.insert(21);
	ll.insert(15);
	ll.insert(9);
	ll.insert(12);
	ll.insert(18);
	ll.display();
	int size = ll.count();
	int array[size];
	for(int i = 0; i < size; i++) {
		array[i] = ll.getpos(i + 1) -> data;
	}
	arraydisplay(array, size);
	quicksort(array, 0, size - 1);
	arraydisplay(array, size);
	for(int i = 0; i < size; i++) {
		ll.getpos(i + 1) -> data = array[i];
	}
	cout << "Sorted linked list: ";
	ll.display();
	return 0;
}
