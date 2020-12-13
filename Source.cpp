#include "Multiplication.h"

#include <iostream>
using namespace std;


//void Multiplication::KaratsubaRecursive(int* x, int* y, long int size, int* res)
//{
//	// x*y = (a*c)*10^n + (b*d)  + ((a+b)*(c+d)-a*c-b*d)* 10^(n/2)
//
//	if (size == 1)
//	{	// res size = 2
//		int mul = x[0] * y[0];
//		res[1] = mul % 10;
//		res[0] = mul / 10;
//		return;
//	}
//	if (size <= 2)
//	{
//		int* mul = RegularMultiplication(x, y, size, size);
//		memcpy(res, mul, (size * 2) * sizeof(int));
//		return;
//	}
//
//
//	int *a, *b, *c, *d, *ac, *bd;
//	long int firstHalf, secondHalf, acSize, bdSize;
//
//	firstHalf = size / 2;
//	secondHalf = size - (size / 2);
//	acSize = firstHalf * 2;
//	bdSize = secondHalf * 2;
//
//	a = x;
//	b = x + firstHalf;
//	c = y;
//	d = y + firstHalf;
//
//	ac = new int[acSize]();
//	bd = new int[bdSize]();
//	KaratsubaRecursive(a, c, firstHalf, ac);			// acSize = (size / 2) * 2
//	KaratsubaRecursive(b, d, secondHalf, bd);			// bdSize = (size - (size / 2)) * 2
//
//	long int s_aPlusb = 0, s_cPlusd = 0;
//	int* aPlusb = adder(a, b, firstHalf, secondHalf, s_aPlusb); // s_aPlusb = size - (size / 2)
//	int* cPlusd = adder(c, d, firstHalf, secondHalf, s_cPlusd);	// s_cPlusd = size - (size / 2)
//
//	long int s_prodOfSum = s_aPlusb * 2;
//	int* prodOfSum = new int[s_prodOfSum]();
//	KaratsubaRecursive(aPlusb, cPlusd, s_aPlusb, prodOfSum); // s_prodOfSum = (size - (size / 2)) * 2
//
//	long int s_sub = 0, s_mid = 0;
//	int* sub = subtractor(prodOfSum, ac, s_prodOfSum, acSize, s_sub);	// s_sub = (size - (size / 2)) * 2
//	int* mid = subtractor(sub, bd, s_sub, bdSize, s_mid);				//s_mid = (size - (size / 2)) * 2
//
//	// (ac)*10^size + (bd)
//	memcpy(res, ac, acSize * sizeof(int));
//	memcpy(res + acSize, bd, bdSize * sizeof(int));
//
//	int carry = 0;
//	// (ac)*10^size + mid* 10^(size/2) + (bd)
//	for (int i = size * 2 - size / 2 - 1, j = s_mid - 1; j >= 0; i--, j--)
//	{
//		int sum = res[i] + mid[j] + carry;
//		res[i] = sum % 10;
//		carry = sum / 10;
//	}
//
//	delete[] ac;
//	delete[] bd;
//	delete[] aPlusb;
//	delete[] cPlusd;
//	delete[] sub;
//	delete[] mid;
//}

//
//void Multiplication::KaratsubaRecursive(int* x, int* y, long int size, int* karatsubaRes)
//{
//	// x*y = (a*c)*10^n + (b*d)  + ((a+b)*(c+d)-a*c-b*d)* 10^(n/2) 
//
//	if (size <= 2)
//	{
//		karatsubaRes = RegularMultiplication(x, y, size, size);
//		return;
//	}
//	int* res = new int[size * 2]();
//
//	int *a, *b, *c, *d, *ac, *bd;
//	long int firstHalf, secondHalf, acSize, bdSize;
//
//	firstHalf = size / 2;
//	secondHalf = size - (size / 2);
//	acSize = firstHalf * 2;
//	bdSize = secondHalf * 2;
//
//	a = x;
//	b = x + firstHalf;
//	c = y;
//	d = y + firstHalf;
//
//	ac = bd = nullptr;
//	KaratsubaRecursive(a, c, firstHalf, ac);			// acSize = (size / 2) * 2
//	KaratsubaRecursive(b, d, secondHalf, bd);			// bdSize = (size - (size / 2)) * 2
//
//	long int s_aPlusb = 0, s_cPlusd = 0;
//	int* aPlusb = adder(a, b, firstHalf, secondHalf, s_aPlusb); // s_aPlusb = size - (size / 2)
//	int* cPlusd = adder(c, d, firstHalf, secondHalf, s_cPlusd);	// s_cPlusd = size - (size / 2)
//
//	int* prodOfSum = nullptr;
//	long int s_prodOfSum = s_aPlusb * 2;
//	KaratsubaRecursive(aPlusb, cPlusd, s_aPlusb, prodOfSum); // s_prodOfSum = (size - (size / 2)) * 2
//
//	long int s_sub = 0, s_mid = 0;
//	int* sub = subtractor(prodOfSum, ac, s_prodOfSum, acSize, s_sub);	// s_sub = (size - (size / 2)) * 2
//	int* mid = subtractor(sub, bd, s_sub, bdSize, s_mid);				//s_mid = (size - (size / 2)) * 2
//
//	// (ac)*10^size + (bd)
//	memcpy(res, ac, acSize * sizeof(int));
//	memcpy(res + acSize, bd, bdSize * sizeof(int));
//
//	int carry = 0;
//	// (ac)*10^size + mid* 10^(size/2) + (bd)
//	for (int i = size * 2 - size / 2 - 1, j = s_mid - 1; j >= 0; i--, j--)
//	{
//		int sum = res[i] + mid[j] + carry;
//		res[i] = sum % 10;
//		carry = sum / 10;
//	}
//
//	delete[] ac;
//	delete[] bd;
//	delete[] aPlusb;
//	delete[] cPlusd;
//	delete[] sub;
//	delete[] mid;
//
//	karatsubaRes = res;
//}

//
//
//int* Multiplication::KaratsubaRecursive(int* x, int* y, long int size)
//{
//	// x*y = (a*c)*10^n + (b*d)  + ((a+b)*(c+d)-a*c-b*d)* 10^(n/2)
//
//	if (size <= 4)
//	{
//		return RegularMultiplication(x, y, size, size);
//	}
//
//	int* res = new int[size * 2];
//
//	int *a, *b, *c, *d;
//	long int firstHalf, secondHalf, acSize, bdSize;
//
//	firstHalf = size / 2;
//	secondHalf = size - (size / 2);
//	acSize = firstHalf * 2;
//	bdSize = secondHalf * 2;
//
//	a = x;
//	b = x + firstHalf;
//	c = y;
//	d = y + firstHalf;
//
//	int* ac = KaratsubaRecursive(a, c, firstHalf);            // acSize = (size / 2) * 2
//	int* bd = KaratsubaRecursive(b, d, secondHalf);            // bdSize = (size - (size / 2)) * 2
//
//
//
//	long int s_aPlusb = 0, s_cPlusd = 0;
//	int* aPlusb = adder(a, b, firstHalf, secondHalf, s_aPlusb);		// s_aPlusb = size - (size / 2) + 1
//	int* cPlusd = adder(c, d, firstHalf, secondHalf, s_cPlusd);    // s_cPlusd = size - (size / 2) + 1
//
//	long int s_prodOfSum = s_aPlusb * 2;
//	int* prodOfSum = KaratsubaRecursive(aPlusb, cPlusd, s_aPlusb); // s_prodOfSum = (size - (size / 2)) * 2
//
//
//	long int s_sub = 0, s_mid = 0;
//	int* sub = subtractor(prodOfSum, ac, s_prodOfSum, acSize, s_sub);    // s_sub = (size - (size / 2)) * 2
//	int* mid = subtractor(sub, bd, s_sub, bdSize, s_mid);                //s_mid = (size - (size / 2)) * 2
//
//	// (ac)*10^size + (bd)
//	memcpy(res, ac, acSize * sizeof(int));
//	memcpy(res + acSize, bd, bdSize * sizeof(int));
//
//	int carry = 0;
//	// (ac)*10^size + mid* 10^(size/2) + (bd)
//	for (long int i = size * 2 - (size + 1) / 2 - 1, j = s_mid - 1; j >= 0; i--, j--)
//	{
//		int sum = res[i] + mid[j] + carry;
//		res[i] = sum % 10;
//		carry = sum / 10;
//	}
//
//	if (ac)
//		delete[] ac;
//	if (bd)
//		delete[] bd;
//
//	delete[] aPlusb;
//	delete[] cPlusd;
//	delete[] sub;
//	delete[] mid;
//
//	return res;
//
//    // x*y = (a*c)*10^n + (b*d)  + ((a+b)*(c+d)-a*c-b*d)* 10^(n/2)
//
//    if (size <= 4)
//    {
//        return RegularMultiplication(x, y, size, size);
//    }
//    
//    int* res = new int[size * 2]();
//    
//    int *a, *b, *c, *d, *ac, *bd;
//    long int firstHalf, secondHalf, acSize, bdSize;
//
//    firstHalf = size / 2;
//    secondHalf = size - (size / 2);
//    acSize = firstHalf * 2;
//    bdSize = secondHalf * 2;
//
//    a = x;
//    b = x + firstHalf;
//    c = y;
//    d = y + firstHalf;
//    
//    ac = KaratsubaRecursive(a, c, firstHalf);            // acSize = (size / 2) * 2
//    bd = KaratsubaRecursive(b, d, secondHalf);            // bdSize = (size - (size / 2)) * 2
//    
//    
//
//    long int s_aPlusb = 0, s_cPlusd = 0;
//    int* aPlusb = adder(a, b, firstHalf, secondHalf, s_aPlusb); // s_aPlusb = size - (size / 2)
//    int* cPlusd = adder(c, d, firstHalf, secondHalf, s_cPlusd);    // s_cPlusd = size - (size / 2)
//    
//    long int s_prodOfSum = s_aPlusb * 2;
//    int* prodOfSum = KaratsubaRecursive(aPlusb, cPlusd, s_aPlusb); // s_prodOfSum = (size - (size / 2)) * 2
//
//
//    long int s_sub = 0, s_mid = 0;
//    int* sub = subtractor(prodOfSum, ac, s_prodOfSum, acSize, s_sub);    // s_sub = (size - (size / 2)) * 2
//    int* mid = subtractor(sub, bd, s_sub, bdSize, s_mid);                //s_mid = (size - (size / 2)) * 2
//    
//    // (ac)*10^size + (bd)
//    memcpy(res, ac, acSize * sizeof(int));
//    memcpy(res + acSize, bd, bdSize * sizeof(int));
//
//    int carry = 0;
//    // (ac)*10^size + mid* 10^(size/2) + (bd)
//    for (long int i = size * 2 - size / 2 - 1, j = s_mid - 1; j >= 0; i--, j--)
//    {
//        int sum = res[i] + mid[j] + carry;
//        res[i] = sum % 10;
//        carry = sum / 10;
//    }
//
//    delete[] ac;
//    delete[] bd;
//    delete[] aPlusb;
//    delete[] cPlusd;
//    delete[] sub;
//    delete[] mid;
//    
//    return res;
//}
