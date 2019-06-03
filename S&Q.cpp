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
        node *gettail() {
        	if(head == NULL) {
        		return NULL;
        	}
                else {
                	node *current = head;
                	while(current -> next != NULL) {
                        	current = current -> next;
                	}
                	return current;
        	}
        }
        node *getpos(int pos) {
        	if(pos < 1 || pos > count()) {
        		cout << "not possible" << endl;
        		return NULL;
        	}
        	else {
        		int i = 1;
			node *current = head;
			while(i < pos) {
				current = current -> next;
					i++;
				}
				return current;
		}
	}
	void insertathead(int value) {
		node *temp = new node(value);
		if(empty()) {
			head = temp;
		}
		else {
			temp -> next = head;
			head = temp;
		}	
	}
	void insertatend(int value) {
		node *temp = new node(value);
		if(empty()) {
			head = temp;
		}
		else {
			node *current = gettail();
			current -> next = temp;
		}
        }
        void deleteathead() {
		if(empty()) {
			cout << "not possible" << endl;
		}
		else {
			if(head -> next == NULL) {
				head = NULL;
			}
			else {
				node *temp = head;
				head = head -> next;
				delete temp;
			}
		}
	}
	void deleteatend() {
		if(empty()) {
			cout << "not possible" << endl;
		}
		else {
			if(head -> next == NULL) {
				head = NULL;
			}
			else {
				node *current = getpos(count() - 1);
				node *temp = current -> next;
				current -> next = NULL;
				delete temp;
			}
		}
        }
        void display() {
                if(empty()) {
                        cout << "Empty List." << endl;
                }
                else {
                        node *current = head;
                        while(current != NULL){
                                cout << current -> data << " -> ";
                                current = current -> next;
                        }
                        cout << "NULL" << endl;
                }
	}
};
class stack {
	public:
	node *top;
	linkedlist L1;
	stack() {
	        top = NULL;
	}
	void push(int value){
		L1.insertathead(value);
		top = L1.head;
	}
	void pop() {
		if(L1.count() == 0) {
			cout << "nothing to pop" << endl;
		}
		else {
			L1.deleteathead();
		}
	}
	void display() {
		L1.display();
	}
	void size() {
		cout << "size of stack: " << L1.count() << endl;
	}
	bool isEmpty() {
		if(L1.empty()) {
			cout << "empty" << endl;
		}
		else {
			cout << "not empty" << endl;
		}
	}
};
class queue {
	public:
        node *front;
        node *end;
        linkedlist L2;
        queue() {
        	front = NULL;
        	end = NULL;
        }
        void enqueue(int value) {
        	L2.insertathead(value);
        	front = L2.head;
        }
        void dequeue() {
        	if(L2.count() == 0) {
        		cout << "nothing to dequeue" << endl;
        	}
        	else { 
        		L2.deleteatend();
        		end = L2.gettail();
        	}
        }
        void size() {
        	cout << "size of queue: " << L2.count() << endl;
        }
        void isEmpty() {
        	if(L2.empty()) {
			cout << "empty" << endl;
		}
		else {
			cout << "not empty" << endl;
		}
        }
        void display() {
        	L2.display();
        }
};
int main() {
	stack S;
	/*TEST CASE
	push 5 elements
	pop 1 by 1 6 times and print each time
	push 1 more
	pop 1 more	
	*/
	for(int i = 1; i < 6; i++) {
		S.push(i);
		S.display();
	}
	S.display();
	for(int i = 0; i < 6; i++) {
		S.pop();
		S.display();
	}
	S.push(6);
	S.display();
	S.pop();
	S.display();
	cout << "stack: ";
	S.isEmpty();
	S.size();
	queue Q;
	cout << "queue: ";
	Q.isEmpty();
	Q.enqueue(242);
	Q.display();
	Q.enqueue(574);
	Q.enqueue(669);
	Q.display();
	Q.size();
	Q.dequeue();
	Q.display();
	return 0;
}	
