#include <iostream>
using namespace std;
class MinHeap {
	public:
	int *array, capacity, size;
	MinHeap(int cap) {
		array = new int[cap];
		capacity = cap;
		size = 0;
	}
	int parent(int i) {
		return (i - 1)/2;
	}
	int left(int i) {
		return 2*i + 1;
	}
	int right(int i) {
		return 2*i + 2;
	}
	void swap(int i, int j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	void MinHeapify(int i) {
		int smallest = i;
		if(left(i) < size && array[left(i)] < array[i]) {
			smallest = left(i);
		}
		if(right(i) < size && array[right(i)] < array[smallest]) {
			smallest = right(i);
		}
		if(smallest != i) {
			swap(i, smallest);
			MinHeapify(smallest);
		}
	}
	void display() {
		for(int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
	int getMin() {
		return array[0];
	}
	int extractMin() {
		if(size == 0) {
			cout << "Heap underflow." << endl;
		}
		if(size == 1) {
			size--;
			return array[0];
		}
		if(size > 1) {
			int root = array[0];
			array[0] = array[--size];
			MinHeapify(0);
			return root;
		}
	}
	void decreaseKey(int i, int new_value) {
		if(size == 0 || i < 0 || i >= size) {
			cout << "Nothing to decrease here." << endl;
			return;
		}
		array[i] = new_value;
		while(i != 0 && array[i] < array[parent(i)]) {
			swap(i, parent(i));
			i = parent(i);
		}
	}
	void insert(int val) {
		if(size == capacity) {
			cout << "Heap overflow." << endl;
			return;
		}
		int i = size;
		array[i] = val;
		size++;
		while(i != 0 && array[i] < array[parent(i)]) {
			swap(i, parent(i));
			i = parent(i);
		}
	}
	void deleteK(int i) {
		if(size == 0 || i < 0 || i >= size) {
			cout << "Nothing to delete here." << endl;
			return;
		}
		array[i] = array[--size];
		MinHeapify(i);
		
	}
};
class MaxHeap {
	public:
	int *array, capacity, size;
	MaxHeap(int cap) {
		array = new int[cap];
		capacity = cap;
		size = 0;
	}
	int parent(int i) {
		return (i - 1)/2;
	}
	int left(int i) {
		return 2*i + 1;
	}
	int right(int i) {
		return 2*i + 2;
	}
	void swap(int i, int j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	void MaxHeapify(int i) {
		int largest = i;
		if(left(i) < size && array[left(i)] >= array[i]) {
			largest = left(i);
		}
		if(right(i) < size && array[right(i)] >= array[largest]) {
			largest = right(i);
		}
		if(largest != i) {
			swap(i, largest);
			MaxHeapify(largest);
		}
	}
	void display() {
		for(int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
	int getMax() {
		return array[0];
	}
	int extractMax() {
		if(size == 0) {
			cout << "Heap underflow." << endl;
		}
		if(size == 1) {
			return array[--size];
		}
		if(size > 1) {
			int root = array[0];
			array[0] = array[--size];
			MaxHeapify(0);
			return root;
		}
	}
	void increaseKey(int i, int new_value) {
		if(size == 0 || i < 0 || i >= size) {
			cout << "Nothing to increase here." << endl;
			return;
		}
		array[i] = new_value;
		while(i != 0 && array[i] >= array[parent(i)]) {
			swap(i, parent(i));
			i = parent(i);
		}
	}
	void insert(int val) {
		if(size == capacity) {
			cout << "Heap overflow." << endl;
			return;
		}
		int i = size;
		array[i] = val;
		size++;
		while(i != 0 && array[i] >= array[parent(i)]) {
			swap(i, parent(i));
			i = parent(i);
		}
	}
	void deleteK(int i) {
		if(size == 0 || i < 0 || i >= size) {
			cout << "Nothing to delete here." << endl;
			return;
		}
		array[i] = array[--size];
		MaxHeapify(i);
		
	}
};
int main() {
	MinHeap Min(19);
	Min.extractMin();
	for(int i = 10; i > 0; i--) {
        	Min.insert(i);
        	Min.display();
    	}
    	Min.extractMin();
    	Min.display();
    	Min.deleteK(3);
    	Min.display();
    	Min.decreaseKey(4, 4);
    	Min.display();
    	MaxHeap Max(19);
	Max.extractMax();
	for(int i = 10; i > 0; i--) {
        	Max.insert(i);
        	Max.display();
    	}
    	Max.extractMax();
    	Max.display();
    	Max.deleteK(3);
    	Max.display();
    	Max.increaseKey(4, 4);
    	Max.display();
	return 0;
}
