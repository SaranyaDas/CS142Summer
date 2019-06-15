#include <iostream>
using namespace std;
void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
int Partition(int array[], int low, int high) {
	int pivot = high;
	int j = low;
	for(int i = low; i < high; i++) {
		if(array[i] <= array[pivot]) {
			swap(array, i, j);
			j++;
		}
	}
	swap(array, pivot, j);
	return j;
}
void Quicksort(int array[], int low, int high) {
	if(low < high) {
		int pi = Partition(array, low, high);
		Quicksort(array, low, pi - 1);
		Quicksort(array, pi + 1, high);
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
	Quicksort(array, 0, size - 1);
	cout << "Sorted array: ";
	Display(array, size);
	return 0;
}
