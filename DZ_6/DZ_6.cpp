

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

//===============================Task1================================

void __fastcall initRandArr(int** arr, size_t size, int border) {
	srand((unsigned)time(0));
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			arr[i][j] = rand() % border;
		}
	}
}

void __fastcall printArray(int** arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
		cout << endl;
	}
}

void __fastcall bubbleSort(int** arr, size_t size) {
	size_t inext, jnext;
	size_t i, j;
	int temp;
	bool s = false;
	while (!s) {
		s = true;
		i = 0; j = 0;
		for (inext = 0; inext < size; inext++)
			for (jnext = (inext ? 0 : 1); jnext < size; jnext++) {
				if (arr [i][j] > arr [inext][jnext]) {
					temp = arr[i][j];
					arr[i][j] = arr[inext][jnext];
					arr[inext][jnext] = temp;
					s = false;
				}
				i = inext;
				j = jnext;
			}
	}
}

void inline Task1() {
	int border = 20;
	size_t size = 4;
	int** arr = new int* [size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}
	initRandArr (arr, size, border);
	cout << "   Unsorted array" << endl;
	printArray(arr, size);
	bubbleSort(arr, size);
	cout << "   Sorted array" << endl;
	printArray(arr, size);
	for (size_t i = 0; i < size; i++) {
		delete[] arr[i]; 
	}
	delete[] arr; 
	arr = nullptr;
}

//===============================Task2================================

void __fastcall printOneDimArray(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void __fastcall initOneDimArray(int* arr, size_t size) {
	cout << "Enter " << size << " numbers" << endl;
	for (size_t i = 0; i < size; i++) {
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
}

void __fastcall invertOneDimArray(int* arr, size_t size) {
	for (size_t i = 0; i < size / 2; i++) {
		int tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
	}
}

void __fastcall formulaCalculate(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		int n = i + 1;
		arr[i] = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
		if (arr[i] > 400)
			cout << "The result of calculating the " << n << " element is greater than 400" << endl;
	}
}

void inline Task2() {
	size_t size = 4;
	int* arr2 = new int [size];
	initOneDimArray(arr2, size);
	printOneDimArray(arr2, size);
	invertOneDimArray(arr2, size);
	printOneDimArray(arr2, size);
	formulaCalculate(arr2, size);
	printOneDimArray(arr2, size);
	delete[] arr2;
	arr2 = nullptr;
}

//===============================main==================================

int main()
{
	Task1();
	Task2();
	return 0;
}



