#include "assignment1.h"
#include <iostream>

int main() {
	int numbers[1] = {0};
	int size = 0;
	int* values = readFile(numbers, size);
	
	bool prompt = true;
	int answer;
	while (prompt) {
		cout << "Select a function:" << endl;
		cout << "1. Search" << endl;
		cout << "2. Modify" << endl;
		cout << "3. Add" << endl;
		cout << "4. Remove" << endl;
		cout << "5. Quit" << endl;
		bool answering = true;
		while (answering) {
			try {
				cin >> answer;
				if (answer > 5 || answer < 1)
					throw out_of_range("Response must be 1, 2, 3, 4, or 5.");
				answering = false;
			}
			catch (out_of_range& e) {
				cout << e.what() << endl;
			}
			catch (...) {
				cout << "Unknown Error Occured" << endl;
			}
		}
		if (answer == 1) {
			int number;
			cout << "\nWhat number do you want to find?" << endl;
			cin >> number;
			int index;
			index = search(values, size, number);
			if (index == -1)
				cout << "Number could not be found in array." << endl;
			else
				cout << "Number found at index of " << index << "." << endl;
		}
		else if (answer == 2) {
			int number;
			int newValue;
			try {
				cout << "\nWhat index position would you like to modify?" << endl;
				cin >> number;
				if (number < 0 || number > size)
					throw out_of_range("Value outside of index range.");
				cout << "\nWhat would you like the new value to be?" << endl;
				cin >> newValue;
				modify(values, number, newValue);
			}
			catch (out_of_range& e) {
				cout << e.what() << "\nValue must be 0 to " << size << endl;
			}
			catch (...) {
				cout << "Unknown Error Occured" << endl;
			}
		}
		else if (answer == 3) {
			int number;
			try {
				cout << "What value would you like to add?" << endl;
				cin >> number;
				values = add(values, size, number);
			}
			catch (...) {
				cout << "Unknown Error Occured" << endl;
			}
		}
		else if (answer == 4) {
			int number;
			try {
				cout << "\nWhat index position would you like to remove?" << endl;
				cin >> number;
				if (number < 0 || number > size)
					throw out_of_range("Value outside of index range.");
				values = remove(values, size, number);
			}
			catch (out_of_range& e) {
				cout << e.what() << "\nValue must be 0 to " << size << endl;
			}
			catch (...) {
				cout << "Unknown Error Occured" << endl;
			}
		}
		else {
			cout << "\nExiting" << endl;
			prompt = false;
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		cout << values[i] << " ";
	}
}