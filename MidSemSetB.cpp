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
class linkedlist {
	public:
	node *head;
	linkedlist() {
		head = NULL;
	}
	bool empty() {
		if(head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void insert(int value) {
		node *temp = new node(value);
		if(empty()) {
			head = temp;
		}
		else {
			node *current = getpos(count());
			current -> next = temp;
		}
	}
	int count() {
		int i = 0;
		if(empty()) {
			return i;
		}
		else {
			node *current = head;
			while(current != NULL) {
				i++;
				current = current -> next;
			}
			return i;
		}
	}
	node *getpos(int pos) {
		if(empty()) {
			return NULL;
		}
		else {
			node *current = head;
			int i = 1;
			while(i < pos) {
				current = current -> next;
				i++;
			}
			return current;
		}
	}
	void display() {
		if(empty()) {
			cout << "empty list" << endl;
		}
		else {
			node *current = head;
			while(current != NULL) {
				cout << current -> data << " -> ";
				current = current -> next;
			}
			cout << "NULL" << endl;
		}
	}	
};
void swap(linkedlist ll, int i, int j) {
	int temp = ll.getpos(i) -> data;
	ll.getpos(i) -> data = ll.getpos(j) -> data;
	ll.getpos(j) -> data = temp;
}
int partition(linkedlist ll, int low, int high) {
	int pivot = high;
	int j = low;
	for(int i = low; i < high; i++) {
		if(ll.getpos(i) -> data <= ll.getpos(pivot) -> data) {
			swap(ll, i, j);
			j++;
		}
	}
	swap(ll, pivot, j);
	return j;
}
void quicksort(linkedlist ll, int low, int high) {
	if(low < high) {
		int pi = partition(ll, low, high);
		quicksort(ll, low, pi - 1);
		quicksort(ll, pi + 1, high);	
	}
}
int main() {
	int size, value;
	linkedlist ll;
	cout << "Enter size of linked list: ";
	cin >> size;
	cout << "Enter elements of linked list one by one:" << endl;
	for(int i = 0; i < size; i++) {
		cin >> value;
		ll.insert(value);
	}
	cout << "Linked list: ";
	ll.display();
	quicksort(ll, 1, ll.count());
	cout << "Sorted linked list: ";
	ll.display();
	return 0;
}	
