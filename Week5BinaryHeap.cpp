#include <iostream>
using namespace std;
class BinaryHeap {
	public:
	int *array; //pointer to array of elements in binary heap
	int capacity; //maximum possible number of elements in array/heap
	int size; //current number of elements in array/heap
	BinaryHeap(int cap) { //parameterized constructor
		array = new int[cap];
		capacity = cap;
		size = 0;
	}
	int parent(int i) { //function to return index of parent of node at index i
		return (i - 1)/2;
	}
	int left(int i) { //function to return index of left child of node at index i
		return 2*i + 1;
	}
	int right(int i) { //function to return index of right child of node at index i
		return 2*i + 2;
	}
	void swap(int i, int j) { //function to swap data stored at two given indices
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	void MinHeapify(int i) { //function to heapify subtre with root at i
		int smallest = i; //assumes the subtree is already heapified
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
	void display() { //function to display elements in array
		for(int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
	int getMin() { //function to return the minimum (root) element of the heap
		return array[0];
	}
	int extractMin() { //function to remove the minimum element from the heap
		if(size == 0) {
			cout << "Heap underflow. " << endl;
		}
		if(size == 1) {
			size--;
			return array[0];
		}
		if(size > 1) {
			int root = array[0];
			array[0] = array[--size]; //index 0 stores data at index (size - 1) and size decreases by 1
			MinHeapify(0);
			return root;
		}
	}
	void decreaseKey(int i, int new_value) { //function to decrease the value (with new_value) of a particular node indexed at i
		if(size == 0 || i < 0 || i >= size) {
			cout << "Nothing to decrease here." << endl;
			return;
		}
		array[i] = new_value;
		while(i != 0 && array[parent(i)] > array[i]) { //as long as tree root has not been reached and parent node's data is more than its child's 
			swap(i, parent(i));
			i = parent(i); //i traverses up the tree
		}
	}
	void insert(int val) { //function to add a new value to the binary heap
		if(size == capacity) {
			cout << "Heap overflow." << endl;
			return;
		}
		int i = size;
		array[i] = val;
		size++;
		while(i != 0 && array[parent(i)] > array[i]) {
			swap(i, parent(i));
			i = parent(i);
		}
	}
	void deleteK(int i) { //function to delete a particular value/node (indexed at i) in the binary heap
		if(size == 0 || i < 0 || i >= size) {
			cout << "Nothing to delete here." << endl;
			return;
		}
		array[i] = array[size - 1];
		size--;
		MinHeapify(i);
	}
};
int main() {
	BinaryHeap BH(19);
	BH.extractMin();
	for(int i = 10; i > 0; i--) {
        	BH.insert(i);
        	BH.display();
    	}
    	BH.extractMin();
    	BH.display();
    	BH.deleteK(3);
    	BH.display();
    	BH.decreaseKey(4, 4);
    	BH.display();
	return 0;
}
