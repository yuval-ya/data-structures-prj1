#pragma once
class Multiplication
{
public:
	static int* RegularMultiplication(int* x, int* y, int x_size, int y_size);
	static void KaratsubaRecursive(int* x, int* y, long int size, int* res);
	static void KaratsubaRecursive_tmp(int* x, int* y, long int size, int* res);
	static void KaratsubaIterative();
	
	static int* adder(int* x, int* y, long int x_size, long int y_size, long int& resSize);
	static int* subtractor(int* x, int* y, long int x_size, long int y_size, long int& resSize);
	static void printIntArr(int * arr, int size);
};

