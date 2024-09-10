#pragma once

using namespace std;

int* readFile(int original[], int& size);

int search(int data[], int& size, int num);

void modify(int data[], int index, int newNum);

int* add(int data[], int& size, int num);

int* remove(int data[], int& size, int index);