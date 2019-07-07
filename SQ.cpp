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
class StackLL {
	public:
	node *top;
	linkedlist L1;
	StackLL() {
	        top = NULL;
	}
	void push(int value) {
		L1.insertathead(value);
		top = L1.head;
	}
	int pop() {
		if(empty()) {
			cout << "stack underflow, nothing to pop" << endl;
		}
		else {
			int Data = top -> data;
			L1.deleteathead();
			top = L1.head;
			return Data;
		}
	}
	int size() {
		return L1.count();
	}
	bool empty() {
		if(L1.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
	void isEmpty() {
		if(empty()) {
			cout << "empty" << endl;
		}
		else {
			cout << "non-empty" << endl;
		}
	}
	void display() {
		if(empty()) {
			cout << "empty stack" << endl;
		}
		else {
			L1.display();
		}
	}
	
};
class QueueLL {
	public:
        node *front;
        node *end;
        linkedlist L2;
        QueueLL() {
        	front = NULL;
        	end = NULL;
        }
        void enqueue(int value) {
        	L2.insertathead(value);
        	front = L2.head;
        	end = L2.gettail();
        }
        void dequeue() {
        	if(empty()) {
        		cout << "queue underflow, nothing to dequeue" << endl;
        	}
        	else { 
        		L2.deleteatend();
        		end = L2.gettail();
        	}
        }
        int size() {
        	return L2.count();
        }
        bool empty() {
        	if(L2.empty()) {
			return true;
		}
		else {
			return false;
		}
        }
	void isEmpty() {
		if(empty()) {
			cout << "empty" << endl;
		}
		else {
			cout << "non-empty" << endl;
		}
	}
        void display() {
        	if(empty()) {
        		cout << "empty queue" << endl;
        	}
        	else {
	        	L2.display();
        	}
        }
};
class QueueS {
	public:
	node *front, *end;
	StackLL S;
	QueueS() {
		front = end = NULL;
	}
	void enqueue(int value) {
		if(S.empty()) {
			S.push(value);
			front = end = S.top;
		}
		else {
			S.push(value);
			front = S.top;
		}
	}
	void dequeue() {
		if(S.size() == 1) {
			S.pop();
			return;
		}
		else {
			if(S.size() == 0) {
				cout << "empty queue" << endl;
			}
			else {
				int data = S.pop();
				dequeue();
				S.push(data);
			}
		}
	}
	int size() {
		return S.size();
	}
	bool empty() {
		return S.empty();
	}
	void display() {
		if(S.empty()) {
			cout << "empty queue" << endl;
			return;
		}
		S.display();
	}
};
int main() {
	StackLL S;
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
	cout << "size: " << S.size() << endl;
	QueueLL Q;
	cout << "queue: ";
	Q.isEmpty();
	Q.enqueue(242);
	Q.display();
	Q.enqueue(574);
	Q.enqueue(669);
	Q.display();
	cout << "size: " << Q.size() << endl;
	Q.dequeue();
	Q.display();
	cout << "queue using stack: ";
	QueueS QS;
	QS.enqueue(242);
	QS.display();
	QS.enqueue(574);
	QS.enqueue(669);
	QS.display();
	QS.dequeue();
	QS.display();
	return 0;
}
