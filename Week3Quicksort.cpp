#include <iostream>
using namespace std;
void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
int partition(int array[], int low, int high) {
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
void quicksort(int array[], int low, int high) {
	if(low < high) {
		int pi = partition(array, low, high);
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}
void display(int array[], int size) {
	for(int i = 0; i < size - 1; i++) {
		cout << array[i] << " ";
	}
	cout << array[size - 1] << endl;
}
int main() {
	int size;
	cout << "Enter size of array: ";
	cin >> size;
	int array[size];
	cout << "Enter elements of array one by one:" << endl;
	for(int i = 0; i < size; i++) {
		cin >> array[i];
	}
	cout << "Array: ";
	display(array, size);
	cout << "Sorted array: ";
	quicksort(array, 0, size - 1);
	display(array, size);
	return 0;
}
