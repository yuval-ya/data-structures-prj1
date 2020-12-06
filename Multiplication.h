#pragma once
class Multiplication
{
private:
	unsigned char* x;
	unsigned char* y;
	int x_size, y_size;

	static void printNumber(unsigned char* arr, int size);
	static void InitNumArr(unsigned char* arr, int size);

public:
	Multiplication(int n1, int n2);
	~Multiplication();

	void RegularMultiplication();
	void KaratsubaRecursive();
	void KaratsubaIterative();

};

