
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//===============================Task1================================
// 1.Описать в коде улучшенный алгоритм быстрой сортировки

void __fastcall initRandOneDimArray(int* arr, size_t size, int border) {
	srand((unsigned)time(0));
	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % border;
	}
}

void __fastcall printOneDimArray(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void __fastcall swapInt(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void __fastcall qs(int* arr, int first, int last) { // сортировка Хоара
	int i = first;
	int j = last;
	int x = arr[(first + last) / 2];
	do {
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;
		if (i <= j) {
			swapInt(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last) qs(arr, i, last);
	if (first < j) qs(arr, first, j);
}

void __fastcall sortInserts(int* arr, size_t size) { // сортировка вставкой
	int temp, pos;
	for (int i = 1; i < size; ++i) {
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;
	}
}

void __fastcall median(int* arr, int first, int last) {
	if (arr[(first + last) / 2] < arr[first])
	swapInt(&arr[(first + last) / 2], &arr[first]);
		if (arr[last] < arr[first])
		swapInt(&arr[first], &arr[last]);
			if (arr[last] < arr[(first + last) / 2])
				swapInt(&arr[last], &arr[(first + last) / 2]);
			
}

void inline Task1() {
	size_t size = 20;
	int border = 100;
	int* arr = new int[size];

	initRandOneDimArray(arr, size, border);
	cout << "Unsorted array" << endl;
	printOneDimArray(arr, size);
	if (size <= 10) {
		median(arr, 0, (size - 1));
		qs(arr, 0, size - 1);
	}
		else sortInserts(arr, size);
	cout << "Sorted array" << endl;
	printOneDimArray(arr, size);
}

//===============================Task2================================
//2. Сортировать в массиве целых положительных чисел только чётные числа, 
//нечётные оставив на своих местах при помощи алгоритма блочной сортировки, 
//то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 4 5 9 8 8 7 3]


void __fastcall bucketSort(int* arr, size_t size) { //блочная сортировка
	const size_t max = size;
	const size_t b = 10;
	int** buckets = {};
	buckets = new int* [b];
	for (size_t i = 0; i < b; ++i) {
		buckets[i] = new int[max + 1];
	}
	for (size_t i = 0; i < b; ++i) {
		buckets[i][max] = 0;
	}
	for (size_t digit = 1; digit < 1000000000; digit *= 10) {
		for (size_t i = 0; i < max; ++i) {
			int d = (arr[i] / digit) % b;
			int counter = buckets[d][max];
			buckets[d][counter] = arr[i];
			counter++;
			buckets[d][max] = counter;
		}
		int idx = 0;
		for (size_t i = 0; i < b; ++i) {
			for (size_t j = 0; j < buckets[i][max]; ++j) {
				arr[idx++] = buckets[i][j];
			}
			buckets[i][max] = 0;
		}
	}
}

void __fastcall copyEvenNumbers(int* arr, int* copyArr, size_t size) { // функция копирования четных элементов массива в другой массив
	for (size_t i = 0; i < size; i++) {
		copyArr[i] = 0;
		if (arr[i] % 2 == 0) {
			copyArr[i] = arr[i];
		}
	}
}

void inline Task2() {
	size_t size = 30;
	int border = 100;
	int* arr = new int[size];
	int* copyArr = new int[size];
	initRandOneDimArray(arr, size, border);
	copyEvenNumbers(arr, copyArr, size);
	cout << "Unsorted array" << endl;
	printOneDimArray(arr, size);
	bucketSort(copyArr, size);
	cout << "Sorted array" << endl;
	int j = 0;
	while(copyArr[j] == 0) {
		j++;
	}
	for (size_t i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = copyArr[j++];
		}
	}
	printOneDimArray(arr, size);
}


//===============================main==================================

int main()
{
	Task1();
	Task2();
	return 0;
}
