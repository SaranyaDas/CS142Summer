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
        	if(empty()) {
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
	node *top; //pointer to top of stack
	linkedlist L1; //linked list
	StackLL() { //default constructor
	        top = NULL;
	}
	void push(int value) { //push function
		L1.insertathead(value); //new element of stack = new head of linked list
		top = L1.head; //head becomes top of stack
	}
	void pop() { //pop function
		if(empty()) {
			cout << "stack underflow, nothing to pop" << endl;
		}
		else {
			L1.deleteathead(); //deletes head of linked list
			top = L1.head; //new head (former second node) becomes top
		}
	}
	int size() { //size function
		return L1.count(); //size of stack = size of linked list
	}
	bool empty() {
		if(L1.empty()) { //empty stack = empty linked list
			return true;
		}
		else {
			return false;
		}
	}
	void isEmpty() { //isEmpty function
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
//1.2. Queues using Linked List (Name for class: QueueLL) (enqueue, dequeue, size, isEmpty, front, end)
class QueueLL {
	public:
        node *front; //pointer to front of queue
        node *end; //pointer to end queue
        linkedlist L2; //linked list
        QueueLL() {//default constructor
        	front = NULL;
        	end = NULL;
        }
        void enqueue(int value) { //enqueue function
        	L2.insertathead(value); //new element of queue = new head of linked list
        	front = L2.head; //head becomes front of queue
        	end = L2.gettail(); //tail (last node) of linked list becomes end of queue
        }
        void dequeue() { //dequeue function
        	if(empty()) {
        		cout << "queue underflow, nothing to dequeue" << endl;
        	}
        	else { 
        		L2.deleteatend(); //deletes tail of linked list
        		end = L2.gettail(); //new tail becomes end of queue
        		front = L2.head; //in case linked list becomes empty
        	}
        }
        int size() { //size function
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
	void isEmpty() { //isEmpty function
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
	int top, array[10]; //top and array (max size: 10)
	StackArr() {
		top = -1; //counting starts at -1, array indexing starts from 0
	}
	void push(int value) { //push function
		if(top == 9) { //if array is full
			cout << "stack overflow" << endl;
		}
		else {
			++top; //top increases by 1 (-1 -> 0 at first)
			array[top] = value; //value is stored in array at index corresponding to top's value
		}	
	}
	void pop() { //pop function
		if(empty()) {
			cout << "stack underflow" << endl;
		}
		else {
			--top; //top decreases by 1, value at old top gets replaced when new element is pushed into the stack
		}
	}
	int size() { //size function
		return top + 1; //because indexing starts from 0
	}
	bool empty() {
		if(top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void isEmpty() { //isEmpty  function
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
	int front, end, array[10]; //front, end and array (max size: 10)
	QueueArr() {
		front = -1; //counting starts from -1, array indexing starts from 0
		end = 0;
	}
	void enqueue(int value) { //enqueue function
		if(front == 9) { //if array is full
			cout << "queue overflow" << endl;
		}
		else {
			++front; //front increases by 1 (-1 -> 0 at first)
			array[front] = value; //value is stored in array at index corresponding to front's value
		}
	}
	void dequeue() { //dequeue function
		if(empty()) {
			cout << "queue underflow" << endl;
		}
		else {
			int i = 0; //since indexing starts from 0
			while(i < front) { //as long as i < front's value
				array[i] = array[i + 1]; //values stored in the array "shift" to left, value at index 0 gets replaced by value at index 1 and so on as loop continues
				i++; //i increases by 1
			}
			--front; //front decreases by 1, after value at index (front - 1) is replaced by value at front, value at old front is replaced when new element is enqueued
		}
	}	
	int size() { //size function
		return front + 1; //since indexing starts from 0
	}
	bool empty() {
		if(front == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void isEmpty() { //isEmpty function
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
	StackLL S1, S2; //stacks
	void enqueue(int value) { //enqueue function
		S1.push(value); //new value becomes top of S1 (newest element or front of queue)
	}
	void dequeue() { //dequeue function
		if(S1.empty() && S2.empty()) { //if both stacks (and hence, queue) are empty
			cout << "queue underflow, nothing to dequeue" << endl;
			return;
		}
		if(!S1.empty()) {
			while(!S1.empty()) { //till S1 is empty
				S2.push(S1.top -> data); //top of S1 becomes top of S2
				S1.pop(); //deletes top of S1
			} //top of S2 = oldest element of S1 (and hence, end of queue)
			S2.pop(); //deletes top of S2 (oldest element or end of queue)
			while(!S2.empty()) { //till S2 is empty
				S1.push(S2.top -> data); //top of S2 becomes top of S1
				S2.pop(); //deletes top of S2
			} //all elements are transferred back to S1
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
	QueueLL Q1, Q2; //queues
	void push(int value) { //push function
		Q1.enqueue(value); //new value becomes front of Q1 (newest element or top of stack)
	}
	void pop() { //pop function
		if(Q1.empty() && Q2.empty()) { //if both queues (and hence, stack) are empty
			cout << "stack underflow, nothing to pop" << endl;
			return;
		}
		if(!Q1.empty()) {
			while(Q1.size() != 1) { //till Q1 has one element left, i.e., front (newest element)
				Q2.enqueue(Q1.end -> data); //end of Q1 becomes front of Q2
				Q1.dequeue(); //deletes end of Q1
			}
			Q1.dequeue(); //deletes front of Q1 (newest element or top of stack)
			while(!Q2.empty()) { //till Q2 is empty
				Q1.enqueue(Q2.end -> data); //end of Q2 becomes front of Q1
				Q2.dequeue(); //deletes end of Q2
			} //all elements are transferred back to Q1
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
