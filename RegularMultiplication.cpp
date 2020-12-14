#include "Multiplication.h"

#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;


int* Multiplication::RegularMultiplication(int* x, int* y, long int x_size, long int y_size) {
	int idx_x, idx_y, carry, sum;
	long int resSize = x_size + y_size;
	int* res = new int[resSize]();

	for (int i = 0; i < resSize; i++)
		res[i] = 0;

	idx_x = idx_y = 0;

	for (long int i = x_size - 1; i >= 0; i--)
	{
		carry = 0;
		idx_y = 0;

		for (long int j = y_size - 1; j >= 0; j--)
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

	int* reversedRes = new int[resSize];
	for (int i = 0; i < resSize; i++)
		reversedRes[i] = res[resSize - 1 - i];

	delete[] res;
	return reversedRes;
}

void Multiplication::RegularMultiplicationHelper(int* x, int* y, long int x_size, long int y_size)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	int* res1 = RegularMultiplication(x, y, x_size, y_size);
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << endl;								////////////////////****************************** change to ios::trunc and del this line
	myfile << "Time taken by function RegularMultiplication is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Long multiplication : x * y = ";
	printIntArr(res1, x_size + y_size);
	delete[] res1;
}
