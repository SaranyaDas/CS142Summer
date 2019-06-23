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
	void swap(int posA, int posB) {
		if(posA < 1 || posA > count() || posB < 1 || posB > count()) {
			cout << "not enough elements" << endl;
		}
		else {
			if(posA == posB) {
				return;
			}
			else {
				if(posA == 1 || posA == count() || posB == 1 || posB == count()) {
					node *nodeA = getpos(posA);
					node *nodeB = getpos(posB);
					if(posA == 1) {
						if(posB == count()) {
							if(count() == 2) {
								nodeB -> next = nodeA;
								nodeA -> next = NULL;
								head = nodeB;
								return;
							}
							else {
								node *nextA = nodeA -> next;
								node *prevB = getpos(posB - 1);
								prevB -> next = nodeA;
								nodeB -> next = nextA;
								nodeA -> next = NULL;
								head = nodeB;
								return;
							}
						}
						if(posB == posA + 1) {
							if(count() == 2) {
								return;
							}
							else {
								node *nextB = nodeB -> next;
								nodeB -> next = nodeA;
								nodeA -> next = nextB;
								head = nodeB;
								return;
							}
						}
						if(posB != count()) {
							node *nextA = nodeA -> next;
							node *prevB = getpos(posB - 1);
							node *nextB = nodeB -> next;
							nodeB -> next = nextA;
							prevB -> next = nodeA;
							nodeA -> next = nextB;
							head = nodeB;
							return;
						}
					}
					if(posA == count()) {
						if(posB == 1) {
							swap(posB, posA);
							return;
						}
						if(posB == posA - 1) {
							if(count() == 2) {
								return;
							}
							else {
								node *prevB = getpos(posB - 1);
								prevB -> next = nodeA;
								nodeA -> next = nodeB;
								nodeB -> next = NULL;
								return;
							}
						}
						if(posB != 1) {
							node *prevA = getpos(posA -1);
							node *prevB = getpos(posB - 1);
							node *nextB = nodeB -> next;
							prevB -> next = nodeA;
							nodeA -> next = nextB;
							prevA -> next = nodeB;
							nodeB -> next = NULL;
							return;
						}
					}	
					if(posB == 1 && posA != 1 || posB == count() && posA != 1) {
						swap(posB, posA);
					}
					
				}
				else {
					if(posA == posB + 1) {
						node *nodeA = getpos(posA);
						node *nextA = nodeA -> next;
						node *prevB = getpos(posB - 1);
						node *nodeB = prevB -> next;
						prevB -> next = nodeA;
						nodeA -> next = nodeB;
						nodeB -> next = nextA;
						return;
					}
					if(posA == posB - 1) {
						swap(posB, posA);
						return;
					}
					else {
						node *prevA = getpos(posA - 1);
						node *nodeA = prevA -> next;
						node *nextA = nodeA -> next;
						node *prevB = getpos(posB - 1);
						node *nodeB = prevB -> next;
						node *nextB = nodeB -> next;
						prevA -> next = nodeB;
						nodeB -> next = nextA;
						prevB -> next = nodeA;
						nodeA -> next = nextB;
						return;
					}
				}
			}
		}		
	}
};
int main() {
	int size, value;
	linkedlist ll;
	cout << "Enter size of linked list: ";
	cin >> size;
	int array[size];
	cout << "Enter elements of linked list one by one:" << endl;
	for(int i = 0; i < size; i++) {
		cin >> value;
		ll.insert(value);
	}
	cout << "Linked list: ";
	ll.display();
	ll.swap(1, 7);
	ll.display();
	ll.swap(7, 1);
	ll.display();
	ll.swap(1, 5);
	ll.display();
	ll.swap(5, 1);
	ll.display();
	ll.swap(2, 7);
	ll.display();
	ll.swap(7, 2);
	ll.display();
	ll.swap(3, 5);
	ll.display();
	ll.swap(5, 3);
	ll.display();
	ll.swap(3, 4);
	ll.display();
	return 0;
}	
