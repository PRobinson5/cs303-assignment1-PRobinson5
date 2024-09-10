#include "assignment1.h"
#include <fstream>
#include <iostream>
#include <array>

//reads input file and adds each number in the file as a member of the 1 dimensional array
int* readFile(int original[], int& size) {
	int newData;

	ifstream inFile;
	inFile.open("A1input.txt");
	if (!inFile.is_open()) {
		cout << "File is not open" << endl;
	}

	while (inFile.good()) {
		inFile >> newData;
		original = add(original, size, newData);
	}

	inFile.close();
	return original;
}

//iterates through the array and returns the index if 'num' is found in the array, returns -1 if not
int search(int data[], int& size, int num) {
	for (int i = 0; i < size; i++) {
		if (data[i] == num)
			return i;
	}
	return -1;
}

//outputs the original value at the index, replaces the value, and outputs the new value at that index
void modify(int data[], int index, int newNum) {
	cout << "Original value: " << data[index] << endl;
	data[index] = newNum;
	cout << "New value: " << data[index] << endl;
}

//creates new array with a size 1 greater than the original, copies values of the original, adds new value 'num' at end, replaces original with new array
int* add(int data[], int& size, int num) {
	int *newData = new int[size + 1];
	newData[size] = num;
	for (int i = 0; i < size; i++)
		newData[i] = data[i];
	size += 1;
	data = newData;
	return data;
}

//creates new array with a size 1 less than the original, copies all values of the original except at 'index', replaces original with new array
int* remove(int data[], int& size, int index) {
	int *newData = new int[size - 1];
	for (int i = 0; i < size; i++) {
		if (i == index)
			continue;
		else if (i > index) //stops from leaving a blank space where the removed value would be
			newData[i - 1] = data[i];
		else
			newData[i] = data[i];
	}
	size -= 1;
	return newData;
}