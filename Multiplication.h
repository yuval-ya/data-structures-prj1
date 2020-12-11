#pragma once
class Multiplication
{
private:
	int* x;
	int* y;
	int x_size, y_size;

	static void printNumber(int* arr, int size);
	static void InitNumArr(int* arr, int size);

public:
	Multiplication(int n1, int n2);
	~Multiplication();

	void RegularMultiplication();
	void KaratsubaRecursive();
	void KaratsubaIterative();

};

