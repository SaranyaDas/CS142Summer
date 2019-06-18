#include <iostream>
using namespace std;
void swap(int array[], int i, int j) { //function to swap data between two indices
	int temp = array[i]; //temporary variable to store data at index i
	array[i] = array[j]; //data at index i becomes equal to data at index j 
	array[j] = temp; //data at index j becomes equal to temp
}
int Partition(int array[], int low, int high) { //function to partition array
	int pivot = high; //partition happens around index corresponding to pivot's value 
	int j = low; //index of smaller element
	for(int i = low; i < high; i++) { //temporary variable to virtually traverse array
		if(array[i] <= array[pivot]) { //data at index i is less than or equal to data at index corresponding to pivot's value
			swap(array, i, j);
			j++; //j increases by 1
		}
	}
	swap(array, pivot, j);
	return j; //j becomes partitioning index
}
void Quicksort(int array[], int low, int high) { //function to sort array such that elements are in ascending order
	if(low < high) { //exit condition of recursion: low >= high
		int pi = Partition(array, low, high); //pi = partitioning index = j
		Quicksort(array, low, pi - 1); //sorts array segment left of pi
		Quicksort(array, pi + 1, high); //sorts array segment right of pi
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
