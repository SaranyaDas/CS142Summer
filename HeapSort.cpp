#include <iostream>
using namespace std;
int left(int i) {
	return 2*i + 1;
}
int right(int i) {
	return 2*i + 2;
}
void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
void MaxHeapify(int array[], int size, int i) {
	int largest = i;
	if(left(i) < size && array[left(i)] >= array[i]) {
		largest = left(i);
	}
	if(right(i) < size && array[right(i)] >= array[largest]) {
		largest = right(i);
	}
	if(largest != i) {
		swap(array, i, largest);
		MaxHeapify(array, size, largest);
	}
}
void MinHeapify(int array[], int size, int i) {
	int smallest = i;
	if(left(i) < size && array[left(i)] < array[i]) {
		smallest = left(i);
	}
	if(right(i) < size && array[right(i)] < array[smallest]) {
		smallest = right(i);
	}
	if(smallest != i) {
		swap(array, i, smallest);
		MaxHeapify(array, size, smallest);
	}
}
void MaxHeapSort(int array[], int size) {
	for(int i = size/2 - 1; i >= 0; i--) {
		MaxHeapify(array, size, i);
	}
	for(int i = size - 1; i >= 0; i--) {
		swap(array, 0, i);
		MaxHeapify(array, i, 0);
	}
}
void MinHeapSort(int array[], int size) {
	for(int i = size/2 - 1; i >= 0; i--) {
		MinHeapify(array, size, i);
	}
	for(int i = size - 1; i >= 0; i--) {
		swap(array, 0, i);
		MinHeapify(array, i, 0);
	}
}
void Display(int array[], int size) {
	for(int i = 0; i < size ; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main() {
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
	MaxHeapSort(array, size);
	cout << "Sorted array: ";
	Display(array, size);
	MinHeapSort(array, size);
	cout << "Sorted array: ";
	Display(array, size);
	return 0;
}
