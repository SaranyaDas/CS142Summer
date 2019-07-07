#include <iostream>
#include <math.h>
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
	int findmax() {
		int Max = array[size/2];
		for(int i = size/2 + 1; i < size; i++) {
			Max = max(Max, array[i]);
		}
		return Max;
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
	int findmin() {
		int Min = array[size/2];
		for(int i = size/2 + 1; i < size; i++) {
			Min = min(Min, array[i]);
		}
		return Min;
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
bool ArrayMaxHeap(int array[], int i, int size) {
	for(int i = (size/2 - 1); i >= 0; i--) {
		if(array[i] < array[2*i + 1]) {
			return false;
		}
		if(2*i + 2 < size) {
			if(array[i] < array[2*i + 2]) {
				return false;
			}
		}
	}
	return true;
}
void isMaxHeap(int array[], int size) {
	cout << "The given array ";
	if(ArrayMaxHeap(array, 0, size)) {
		cout << "represents ";
	}
	else {
		cout << "does not represent ";
	}
	cout << "a max heap." << endl;
}
bool ArrayMinHeap(int array[], int i, int size) {
	for(int i = (size/2 - 1); i >= 0; i--) {
		if(array[i] > array[2*i + 1]) {
			return false;
		}
		if(2*i + 2 < size) {
			if(array[i] > array[2*i + 2]) {
				return false;
			}
		}
	}
	return true;
}
void isMinHeap(int array[], int size) {
	cout << "The given array ";
	if(ArrayMinHeap(array, 0, size)) {
		cout << "represents ";
	}
	else {
		cout << "does not represent ";
	}
	cout << "a min heap." << endl;
}
void Heap(int array[], int size) {
	if(!ArrayMinHeap(array, 0, size) && !ArrayMaxHeap(array, 0, size)) {
		cout << "The given array does not represent a heap." << endl;
	}
	else {
		isMinHeap(array, size);
		isMaxHeap(array, size);
	}
}
void Display(int array[], int size) {
	for(int i = 0; i < size ; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int height(int size) {
	return ceil(log2(size + 1));
}
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
    	Min.insert(2);
    	Min.display();
    	cout << "Max: " << Min.findmax() << endl;
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
    	Max.insert(9);
    	Max.display();
    	cout << "Min: " << Max.findmin() << endl;
	int size;
	cout << "Enter size of array: ";
	cin >> size;
	int array[size];
	cout << "Enter the elements one by one:" << endl;
	for(int i = 0; i < size; i++) {
		cin >> array[i];
	}
	cout << "Array: ";
	Display(array, size);
	Heap(array, size);
	cout << "Height: " << height(size) << endl;
	return 0;
}
