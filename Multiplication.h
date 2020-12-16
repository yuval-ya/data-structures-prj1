#pragma once
class Multiplication
{
	// A class that has the algorithms for multiplying long numbers

public:
	
	// Regular Multiplication
	static void RegularMultiplicationHelper(int* x, int* y, long int x_size, long int y_size);
	static void RegularMultiplication(int* x, int* y, long int x_size, long int y_size, int* res);

	// Karatsuba Algorithm (Recursive)
	static void KaratsubaRecursiveHelper(int* x, int* y, long int size);
	static void KaratsubaRecursive(int* x, int* y, long int size, int* res);

	// Karatsuba Algorithm (Iterative)
	static void KaratsubaIterativeHelper(int* x, int* y, long int size);
	static void KaratsubaIterative(int* x, int* y, long int size, int* res);

	// Utilities
	static int* adder(int* x, int* y, long int x_size, long int y_size, long int& resSize);
    static void subtractor(int* x, int* y, long int x_size, long int y_size);
	static void printIntArr(int * arr,long int size);
    static void sumMiddlePart( int* res, int* prodOfSum, long int size, long int prodOfSumSize);


};

