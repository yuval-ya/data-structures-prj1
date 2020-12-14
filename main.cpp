//
//  main.cpp
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 23/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

//#define _CRTDB_MAP_ALLOC
//#include <crtdbg.h>

#include "main.h"
#include "Multiplication.h"

#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

int main(void) {

	int input_flag = 1;

	long int n = getSize(input_flag);
	if (input_flag < 0) {
		cout << "wrong output";  //wrong input?
		return 0;
	}

	int* x = getNumArr(n, input_flag);
	if (input_flag < 0) {
		cout << "wrong output"; //wrong input?
		return 0;
	}

	int* y = getNumArr(n, input_flag);
	if (input_flag < 0) {
		cout << "wrong output"; //wrong input?
		delete[] x;
		return 0;
	}

	cout << "------------" << endl;
	cout << "Number 1 = ";
	printIntArr(x, n);
	cout << "\nNumber 2 = ";
	printIntArr(y, n);
	cout << "\n------------" << endl;
	cout << "Result = " << endl;

	Multiplication::RegularMultiplicationHelper(x, y, n, n);
	Multiplication::KaratsubaRecursiveHelper(x, y, n);
	Multiplication::KaratsubaIterativeHelper(x, y, n);

	//** adder check **
	//long int size = 0;
	//int* res = Multiplication::adder(x, y, n, n, size);
	//printIntArr(res, size);
	//delete[] res;
	
	////** func1 check **
	//int* res1 = Multiplication::RegularMultiplication(x, y, n, n);
	//cout << "Long multiplication : x * y = ";
	//printIntArr(res1, 2 * n);
	////delete[] res1;

	////** func2 check **
	//int* res2 = new int[n * 2]();
	//Multiplication::KaratsubaRecursive(x, y, n, res2);
	//cout << "\nKaratsuba(recursive) : x * y = ";
	//printIntArr(res2, 2 * n);
	////delete[] res2;

	////** func3 check **
	//int* res3 = new int[n * 2]();
	//Multiplication::KaratsubaIterative(x, y, n, res3);
	//cout << "\nKaratsuba(iterative) : x * y = ";
	//printIntArr(res3, 2 * n);
	////delete[] res3;

	//cout << "\n-------------------------------------------" << endl;
	//cout << cmpNum(res1, res3, n * 2) << endl;
	//cout << "-------------------------------------------" << endl;

	//delete[] res1;
	//delete[] res2;
	//delete[] res3;
	delete[] x;
	delete[] y;

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtDumpMemoryLeaks();
	return 0;
}



long int getSize(int& input_flag) {
	long int res = 0;
	cout << "Enter the number of digits: " << endl;	
	char ch;
	cin >> ch;
	if (ch < '1' || ch > '9')
	{	// case ch is not a number or a leading zero
		input_flag = -1;
		return 0;
	}

	while (ch != '\n')
	{
		if (ch < '0' || ch > '9') 
		{	// case ch is not a number
			input_flag = -2;
			return 0;
		}	
		res *= 10;
		res += ch - '0';
		cin.get(ch);
	}
	return res;
}

int* getNumArr(long int size, int& input_flag) {

    int *res = new int[size];
    char ch;
	int i = 0;
    cout << "Enter the input number: " <<endl;
	
	cin.get(ch);
	if (ch < '0' || ch > '9')
	{	// case ch is not a number
		input_flag = -1;
		delete[] res;
		return nullptr;
	}

	while (ch != ' ' && ch != '\t' && ch != '\n' && input_flag > 0)
	{
		if (ch < '0' || ch > '9' || i >= size)
		{	// case ch is not a number or the user enter more digit then size
			input_flag = -2;
			delete[] res;
			return nullptr;
		}
		res[i] = ch - '0';
		cin.get(ch);
		i++;
	}

	if (i < size) 
	{	// case the input is smaller than the size received
		input_flag = -2;
		delete[] res;
		return nullptr;
	}

	return res;
}

