#include "Multiplication.h"

#include <iostream>
using namespace std;

Multiplication::Multiplication(int n1, int n2) : x_size(n1), y_size(n2),
	x(new int[n1]) ,y(new int[n2]) 
{
	InitNumArr(x, x_size);
	InitNumArr(y, y_size);

	printNumber(x, x_size);
	printNumber(y, y_size);
}
Multiplication::~Multiplication() {
	delete[] x;
	delete[] y;
}

void Multiplication::InitNumArr(int* arr, int size) {
	char ch;
	cout << "Enter the input number: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> ch;
		arr[i] = ch - '0';
	}
}

void Multiplication::printNumber(int* arr, int size) {
	int j;
	for (j = 0; (j < size - 1) && (arr[j] == 0); j++) { // skip all leading zero's
	}
	for (int i = j; i < size; i++)
		cout << arr[i];
	cout << endl;
}

void Multiplication::RegularMultiplication() {
	int idx_x, idx_y, carry, sum;
	int* res = new int[x_size + y_size];

	for (int i = 0; i < x_size + y_size; i++)
		res[i] = 0;

	idx_x = idx_y = 0;

	for (int i = x_size - 1; i >= 0; i--)
	{
		carry = 0;
		idx_y = 0;

		for (int j = y_size - 1; j >= 0; j--)
		{
			sum = 0;
			sum = x[i] * y[j] + carry + res[idx_x + idx_y];
			carry = sum / 10;
			res[idx_x + idx_y] = sum % 10;
			idx_y++;
		}

		res[idx_x + idx_y] += carry;
		idx_x++;
	}

	for (int i = x_size + y_size - 1; i >= 0; i--)
		cout << res[i];

	delete[] res;
}

void Multiplication::KaratsubaRecursive() {

}

void Multiplication::KaratsubaIterative() {

}
