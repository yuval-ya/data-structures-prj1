#include "Multiplication.h"

#include <iostream>
using namespace std;

int* Multiplication::RegularMultiplication(int* x, int* y, long int x_size, long int y_size) {
	int idx_x, idx_y, carry, sum;
	int resSize = x_size + y_size;
	int* res = new int[resSize]();

	for (int i = 0; i < resSize; i++)
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

	int* reversedRes = new int[resSize];
	for (int i = 0; i < resSize; i++)
		reversedRes[i] = res[resSize - 1 - i];

	delete[] res;
	return reversedRes;
}

void Multiplication::KaratsubaRecursive_tmp(int* x, int* y, long int size, int* res) {
	// x*y = (a*c)*10^n + (b*d)  + ((a+b)*(c+d)-a*c-b*d)* 10^(n/2) 

	if (size == 1) 
	{	// res size = 2
		int mul = x[0] * y[0];
		res[1] = mul % 10;
		res[0] = mul / 10;
		return;
	}

	//if (size <= 2)
	//{
	//	int * mul = RegularMultiplication(x, y, size, size);
	//	memcpy(res, mul, size * 2 * sizeof(int));
	//	delete[] mul;
	//	return;
	//}

	int *a, *b, *c, *d, *ac, *bd;
	long int firstHalf, secondHalf, acSize, bdSize;

	firstHalf = size / 2;
	secondHalf = size - (size / 2);
	acSize = (size / 2) * 2;
	bdSize = (size - (size / 2)) * 2;

	a = x;
	b = x + firstHalf;
	c = y;
	d = y + firstHalf;
	ac = res;
	bd = res + acSize;

	KaratsubaRecursive_tmp(a, c, firstHalf, ac);	// return size = (size / 2) * 2
	KaratsubaRecursive_tmp(b, d, secondHalf, bd);	// return size = (size - (size / 2)) * 2

	long int aPlusbSize = 0, cPlusdSize = 0, prodOfSumSize = 0, subSize = 0, middleSize = 0;

	// (a+b)
	int* aPlusb = adder(a, b, firstHalf, secondHalf, aPlusbSize);	// (size - (size / 2)) + 1
	// (c+d)
	int* cPlusd = adder(c, d, firstHalf, secondHalf, cPlusdSize);		// (size - (size / 2)) + 1

	// (a+b)*(c+d)
	int* prodOfSum;
	if (aPlusb[0] == 0 && cPlusd[0] == 0)
	{	// aPlusbSize == cPlusdSize
		prodOfSumSize = (aPlusbSize - 1) * 2;
		prodOfSum = new int[prodOfSumSize]();
		KaratsubaRecursive_tmp(aPlusb + 1, cPlusd + 1, aPlusbSize - 1, prodOfSum);	// prodOfSumSize = (size - (size / 2)) * 2 
	}
	else
	{
		prodOfSumSize = aPlusbSize * 2;
		prodOfSum = new int[prodOfSumSize]();
		KaratsubaRecursive_tmp(aPlusb, cPlusd, aPlusbSize, prodOfSum);	// prodOfSumSize = (size - (size / 2)) * 2 + 2
	}


	// (a+b)*(c+d)- (a*c)
	int* sub = subtractor(prodOfSum, ac, prodOfSumSize, acSize, subSize);	// subSize = prodOfSumSize
																			//	(size - (size / 2)) * 2	 OR  (size - (size / 2)) * 2 + 2

	// (a+b)*(c+d) - (a*c) - (b*d)
	int* middle = subtractor(sub, bd, subSize, bdSize, middleSize);		// middleSize = prodOfSumSize
																		//	(size - (size / 2)) * 2	 OR  (size - (size / 2)) * 2 + 2
	// (ac)*10^size + mid* 10^(size/2) + (bd)
	int carry = 0, sum;
	long int i, j;
	for (i = size * 2 - (size + 1) / 2 - 1, j = middleSize - 1; j >= 0 && i >= 0; i--, j--)
	{
		sum = res[i] + middle[j] + carry;
		res[i] = sum % 10;
		carry = sum / 10;
	}
	while (carry && i >= 0) {
		sum = res[i] + carry;
		res[i] = sum % 10;
		carry = sum / 10;
		i--;
	}

	delete[] aPlusb;
	delete[] cPlusd;
	delete[] sub;
	delete[] middle;
	return;
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
		res[write] = (10 + sum) % 10;  // ? sum % 10;
		carry = ((x[x_idx] - y[y_idx] + carry) < 0) ? -1 : 0;
		write--;
		x_idx--;
		y_idx--;
	}
	while (x_idx >= 0) {
		sum = x[x_idx] + carry;
		res[write] = (10 + sum) % 10;  // ? sum % 10;
		carry = ((x[x_idx] + carry) < 0) ? -1 : 0;
		write--;
		x_idx--;
	}

	return res;
}

void Multiplication::KaratsubaIterative() {

}
