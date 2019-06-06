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
                        cout << "empty list" << endl;
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
//1.1. Stacks using Linked List (Name for class: StackLL) (push, pop, size, isEmpty, top)*/
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
	void pop() {
		if(empty()) {
			cout << "stack underflow, nothing to pop" << endl;
		}
		else {
			L1.deleteathead();
			top = L1.head;
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
//1.2. Queues using Linked List (Name for class: QueueLL) (enqueue, dequeue, size, isEmpty, top)
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
//1.3. Stacks using Arrays (Name for class: StackArr)
class StackArr {
	public:
	int top, array[10];
	StackArr() {
		top = -1;
	}
	void push(int value) {
		if(top == 9) {
			cout << "stack overflow" << endl;
		}
		else {
			++top;
			array[top] = value;
		}	
	}
	void pop() {
		if(empty()) {
			cout << "stack underflow" << endl;
		}
		else {
			--top;
		}
	}
	int size() {
		return top + 1;
	}
	bool empty() {
		if(top == -1) {
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
		if(!empty()) {
			for(int i = top; i >= 0; i--) {
				cout << array[i] << " -> ";
			}
		cout << "NULL" << endl;
		}
		else {
			cout << "empty stack" << endl;
		}
	}
};
//1.4. Queues using Arrays (Name for class: QueueArr)
class QueueArr {
	public:
	int front, end, array[10];
	QueueArr() {
		front = -1;
	}
	void enqueue(int value) {
		if(front == 9) {
			cout << "queue overflow" << endl;
		}
		else {
			++front;
			array[front] = value;
		}
	}
	void dequeue() {
		if(empty()) {
			cout << "queue underflow" << endl;
		}
		else {
			int i = 0;
			while(i < front) {
				array[i] = array[i + 1];
				i++;
			}
			--front;
		}
	}	
	int size() {
		return front + 1;
	}
	bool empty() {
		if(front == -1) {
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
		if(!empty()) {
			for(int i = front; i >= 0; i--) {
				cout << array[i] << " -> ";
			}
		cout << "NULL" << endl;
		}
		else {
			cout << "empty queue" << endl;
		}
	}
};
//2. Implement a queue using two stacks.
class QueueS {
	public:
	StackLL S1, S2;
	void enqueue(int value) {
		S1.push(value);
	}
	void dequeue() {
		if(S1.empty() && S2.empty()) {
			cout << "queue underflow, nothing to dequeue" << endl;
			return;
		}
		if(!S1.empty()) {
			while(!S1.empty()) {
				S2.push(S1.top -> data);
				S1.pop();
			}
			S2.pop();
			while(!S2.empty()) {
				S1.push(S2.top -> data);
				S2.pop();
			}
		}
	}
	void isEmpty() {
		S1.isEmpty();
	}
	void size() {
		cout << "size of queue: " << S1.size() << endl;
	}
	void display() {
		S1.display();
	}
};	
//3. Implement a Stack using Queue(s).
class StackQ {
	public:
	QueueLL Q1, Q2;
	void push(int value) {
		Q1.enqueue(value);
	}
	void pop() {
		if(Q1.empty() && Q2.empty()) {
			cout << "stack underflow, nothing to pop" << endl;
			return;
		}
		if(!Q1.empty()) {
			while(Q1.size() != 1) {
				Q2.enqueue(Q1.end -> data);
				Q1.dequeue();
			}
			Q1.dequeue();
			while(!Q2.empty()) {
				Q1.enqueue(Q2.end -> data);
				Q2.dequeue();
			}
		}
	}
	void isEmpty() {
		Q1.isEmpty();
	}
	void size() {
		cout << "size of stack: " << Q1.size() << endl;
	}
	void display() {
		Q1.display();
	}
};
	
int main() {
	cout << endl << "STACK USING LINKED LIST: " << endl;
	StackLL S1;
	for(int i = 0; i < 5; i++) {
		S1.push(i);
		S1.display();
	}
	for(int i = 0; i < 6; i++) {
		S1.pop();
		S1.display();
	}
	S1.push(6);
	S1.display();
	cout << "stack: ";
	S1.isEmpty();
	cout << "size of stack: " << S1.size() << endl;
	cout << endl << "QUEUE USING LINKED LIST: " << endl;
	QueueLL Q1;
	cout << "queue: ";
	Q1.isEmpty();
	Q1.enqueue(242);
	Q1.display();
	Q1.enqueue(574);
	Q1.display();
	Q1.enqueue(6669);
	Q1.display();
	cout << "size of queue: " << Q1.size() << endl;
	Q1.dequeue();
	Q1.display();
	cout << endl << "STACK USING ARRAY: " << endl;
	StackArr S2;
	for(int i = 0; i <= 10; i++) {
		S2.push(i);
		S2.display();
		if(i == 7) {
			cout << "size of stack: " << S2.size() << endl;
			cout << "stack: ";
			S2.isEmpty();
		}
	}
	for(int i = 0; i <= 10; i++) {
		S2.pop();
		S2.display();
	}
	cout << endl << "QUEUE USING ARRAY: " << endl;
	QueueArr Q2;
	for(int i = 0; i <= 10; i++) {
		Q2.enqueue(i);
		Q2.display();
	}
	for(int i = 0; i <= 10; i++) {
		Q2.dequeue();
		Q2.display();
		if(i == 7) {
			cout << "size of queue: " << Q2.size() << endl;
			cout << "queue: ";
			Q2.isEmpty();
		}
	}
	cout << endl << "QUEUE USING TWO STACKS: " << endl;
	QueueS QS;
	QS.enqueue(48);
	QS.display();
	QS.enqueue(46);
	QS.display();
	cout << "queue: ";
	QS.isEmpty();
	QS.dequeue();
	QS.display();
	QS.size();
	cout << endl << "STACK USING QUEUE(S): " << endl;
	StackQ SQ;
	SQ.push(48);
	SQ.display();
	SQ.push(46);
	SQ.display();
	cout << "stack: ";
	SQ.isEmpty();
	SQ.size();
	SQ.pop();
	SQ.display();
	return 0;
} 
