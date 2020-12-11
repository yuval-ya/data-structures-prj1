#pragma once
class Multiplication
{
public:
	static int* RegularMultiplication(int* x, int* y, int x_size, int y_size);
	static int* KaratsubaRecursive(int* x, int* y, long int size, int* res);
	static int* KaratsubaIterative();
	
	static int* adder(int* x, int* y, long int x_size, long int y_size, long int& resSize);
	static int* subtractor(int* x, int* y, long int x_size, long int y_size, long int& resSize);
};

