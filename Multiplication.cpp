#include "Multiplication.h"

#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;


void Multiplication::printIntArr(int * arr, long int size) {
	int j = 0;
	for (j = 0; (j < size - 1) && (arr[j] == 0); j++) 
	{ // skip all leading zero's
	}
	for (int i = j; i < size; i++)
		cout << arr[i];
}


int* Multiplication::adder(int* x, int* y, long int x_size, long int y_size, long int& resSize)
{
	int *res, sum, carry, x_idx, y_idx, write;
	resSize = ((x_size > y_size) ? x_size : y_size) + 1; // max size + 1
	res = new int[resSize]();

	write = resSize - 1;
	x_idx = x_size - 1;
	y_idx = y_size - 1;
	carry = 0;

	while (x_idx >= 0 && y_idx >= 0) {
		sum = carry + x[x_idx] + y[y_idx];
		res[write] = sum % 10;
		carry = sum / 10;
		write--;
		x_idx--;
		y_idx--;
	}
	while (x_idx >= 0) {
		sum = carry + x[x_idx];
		res[write] = sum % 10;
		carry = sum / 10;
		write--;
		x_idx--;
	}
	while (y_idx >= 0) {
		sum = carry + y[y_idx];
		res[write] = sum % 10;
		carry = sum / 10;
		write--;
		y_idx--;
	}
	if (write >= 0)
		res[write] = carry;

	return res;
}

int* Multiplication::subtractor(int* x, int* y, long int x_size, long int y_size, long int& resSize)
{	//Assuming the x > y
	int *res, sum, carry = 0, x_idx, y_idx, write;
	resSize = ((x_size > y_size) ? x_size : y_size); // max size
	res = new int[resSize];

	write = resSize - 1;
	x_idx = x_size - 1;
	y_idx = y_size - 1;

	while (x_idx >= 0 && y_idx >= 0) {
		sum = x[x_idx] - y[y_idx] + carry;
		res[write] = (10 + sum) % 10;
		carry = ((x[x_idx] - y[y_idx] + carry) < 0) ? -1 : 0;
		write--;
		x_idx--;
		y_idx--;
	}
	while (x_idx >= 0) {
		sum = x[x_idx] + carry;
		res[write] = (10 + sum) % 10;
		carry = ((x[x_idx] + carry) < 0) ? -1 : 0;
		write--;
		x_idx--;
	}

	return res;
}

void Multiplication::subtractorV2(int* x, int* y, long int x_size, long int y_size)
{    //Assuming the x > y
    int sum, carry = 0;
    long int x_idx, y_idx;

    x_idx = x_size - 1;
    y_idx = y_size - 1;

    while (x_idx >= 0 && y_idx >= 0) {
        sum = x[x_idx] - y[y_idx] + carry;
        x[x_idx] = (10 + sum) % 10;
        carry = sum < 0 ? -1 : 0;
        x_idx--;
        y_idx--;
    }
    
    while (carry && x_idx >= 0) {
        sum = x[x_idx] + carry;
        x[x_idx] = (10 + sum) % 10;
        carry = sum < 0 ? -1 : 0;
        x_idx--;
    }
}
