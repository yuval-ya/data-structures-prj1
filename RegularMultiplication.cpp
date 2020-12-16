#include <iomanip>
#include <iostream>
#include <chrono>
#include <fstream>
#include "Multiplication.h"
using namespace std;


void  Multiplication::RegularMultiplication(int* x, int* y, long int x_size, long int y_size, int* res) {
    int carry, sum;
	long int idx_x, idx_y, resSize = x_size + y_size;

	for (int i = 0; i < resSize; i++)
		res[i] = 0;

    idx_x = x_size - 1;
    
	for (long int i = x_size - 1; i >= 0; i--)
	{
		carry = 0;
        idx_y = y_size - 1;

		for (long int j = y_size - 1; j >= 0; j--)
		{
			sum = 0;
			sum = x[i] * y[j] + carry + res[idx_x + idx_y + 1];
			carry = sum / 10;
			res[idx_x + idx_y + 1] = sum % 10;
			idx_y--;
		}

		res[idx_x + idx_y + 1] += carry;
		idx_x--;
	}
}

void Multiplication::RegularMultiplicationHelper(int* x, int* y, long int x_size, long int y_size)
{
    int* res = new int[x_size + y_size]();
    
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	RegularMultiplication(x, y, x_size, y_size, res);
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function RegularMultiplication is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Long multiplication : x * y = ";
	printIntArr(res, x_size + y_size);
	delete[] res;
}
