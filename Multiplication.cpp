#include "Multiplication.h"

#include <iostream>
using namespace std;



int* Multiplication::RegularMultiplication(int* x, int* y, int x_size, int y_size) {
	int idx_x, idx_y, carry, sum;
	int resSize = x_size + y_size;
	int* res = new int[resSize];

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
//void Multiplication::KaratsubaRecursive(int* res, int* x, int* y, long int x_size, long int y_size, long int& resSize) {

int* Multiplication::KaratsubaRecursive(int* x, int* y, long int size, int* res) {
	// x*y = (a*c)*10^n + (b*d)  + ((a+b)*(c+d)-a*c-b*d)* 10^(n/2) 

	if (size == 1) 
	{	// res size = 2 * size
		int mul = x[0] * y[0];
		res[1] = mul % 10;
		res[0] = mul / 10;
		return res;
	}

	int *a, *b, *c, *d, *ac, *bd;
	long int aSize, bSize, cSize, dSize, acSize, bdSize;

	aSize = cSize = size / 2;
	bSize = dSize = size - (size / 2);
	acSize = (size / 2) * 2;
	bdSize = (size - (size / 2)) * 2;

	a = x;
	b = x + aSize;
	c = y;
	d = y + cSize;
	ac = res;					
	bd = res + (size / 2) * 2;	

	KaratsubaRecursive(a, c, aSize, ac);	// aSize == cSize
	KaratsubaRecursive(b, d, bSize, bd);	// bSize == dSize

	long int s_aPlusb = 0, s_cPlusd = 0, s_prodOfSum = 0, s_sumOfProd = 0, s_sub;

	// (a+b)
	int* aPlusb = adder(a, b, aSize, bSize , s_aPlusb); 
	//(c+d)
	int* cPlusd = adder(c, d, cSize, dSize, s_cPlusd);
	
	//(a+b)*(c+d)
	s_prodOfSum = s_aPlusb * 2;	// s_aPlusb == s_cPlusd
	int* prodOfSum = new int[s_prodOfSum]();
	KaratsubaRecursive(aPlusb, cPlusd, s_aPlusb, prodOfSum);
	delete[] aPlusb, cPlusd;

	// (a*c)+(b*d)
	int* sumOfProd = adder(ac, bd, acSize, bdSize, s_sumOfProd);
	
	// (a+b)*(c+d) - (a*c)+(b*d)
	int* middle = subtractor(prodOfSum, sumOfProd, s_prodOfSum, s_sumOfProd, s_sub);
	delete[] prodOfSum, sumOfProd;

	// ((a+b)*(c+d) - (a*c)+(b*d))*10^n/2


	// (a*c)*10^n + (b*d)  + ((a+b)*(c+d)-a*c-b*d)* 10^(n/2) 


	//
	

	return res;
}

int* Multiplication::adder(int* x, int* y, long int x_size, long int y_size, long int& resSize)
{
	int *res, sum, carry = 0 , x_idx, y_idx, write;
	resSize = ((x_size > y_size) ? x_size : y_size) + 1; // max size + 1
	res = new int[resSize];

	write = resSize -1;
	x_idx = x_size - 1;
	y_idx = y_size - 1;

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
	
	if(write >= 0)
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
		res[write] = sum % 10;
		carry = ((x[x_idx] - y[y_idx] + carry) < 0) ? -1 : 0;
		write--;
		x_idx--;
		y_idx--;
	}
	while (x_idx >= 0) { 
		sum = x[x_idx] + carry;
		res[write] = sum % 10;
		carry = ((x[x_idx] + carry) < 0) ? -1 : 0;
		write--;
		x_idx--;
	}

	return res;
}


int* Multiplication::KaratsubaIterative() {
	return nullptr;
}
