#pragma once
class Multiplication
{
public:
	static void RegularMultiplicationHelper(int* x, int* y, long int x_size, long int y_size);
	static void KaratsubaRecursiveHelper(int* x, int* y, long int size);
	static void KaratsubaIterativeHelper();

	static int* RegularMultiplication(int* x, int* y, long int x_size, long int y_size);
	static void KaratsubaRecursive(int* x, int* y, long int size, int* res);
	static void KaratsubaIterative();
	
	static int* adder(int* x, int* y, long int x_size, long int y_size, long int& resSize);
	static int* subtractor(int* x, int* y, long int x_size, long int y_size, long int& resSize);
    static void subtractorV2(int* x, int* y, long int x_size, long int y_size);
	static void printIntArr(int * arr,long int size);

};

