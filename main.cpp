//
//  main.cpp
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 23/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#include "main.h"
#include "Multiplication.h"

#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

int main() {
	int input_flag = 1;	

	long int n = getSize(input_flag);	
	if (input_flag < 0) {
		cout << "wrong output";  //wrong input?
		return 0;
	}

    int *x, *y;
	x = getNumArr(n, input_flag);
	if (input_flag < 0) {
		cout << "wrong output"; //wrong input?
		return 0;
	}

	y = getNumArr(n, input_flag);
	if (input_flag < 0) {
		cout << "wrong output"; //wrong input?
		return 0;
	}
    
    cout << "------------" << endl;
    cout << "Number 1 = ";
	printIntArr(x, n);
    cout << "\nNumber 2 = ";
	printIntArr(y, n);
    cout << "\n------------" << endl;
    cout << "Result = ";

	int* res1 = Multiplication::RegularMultiplication(x, y, n, n);
	int* res2 = new int[2 * n]();
	Multiplication::KaratsubaRecursive(x, y, n, res2);
	//int* res3 = Multiplication::RegularMultiplication(x, y, n, n);
	
	cout << "Long multiplication : x * y =";
	printIntArr(res1, 2 * n);
	cout << "\nKaratsuba(recursive) : x * y =";
	printIntArr(res2, 2 * n);
	//cout << "\nKaratsuba(iterative) : x * y =";
	//printIntArr(res3, 2 * n);

	delete[] res1;
	delete[] res2;
    return 0;
}

void printIntArr(int * arr, int size) {
	int j = 0;
	//for (j = 0; (j < size - 1) && (arr[j] == 0); j++) { // skip all leading zero's
	//}
	for (int i = j; i < size; i++)
		cout << arr[i];
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
	{ // case the input is smaller than the size received
		input_flag = -2;
		delete[] res;
		return nullptr;
	}

	//if (i < size) 
	//{	// fill with zeros from the left of the number if the digits are smaller than the size received
	//	int diff = size - i;
	//	for (int j = size - 1; j >= 0 ; j--)
	//	{
	//		if (j - diff >= 0)
	//			res[j] = res[j - diff];
	//		else
	//			res[j] = 0;
	//	}
	//}
	return res;
}

void multiplyA(int* num1, int* num2, int size1, int size2){
    
    int idx_num1, idx_num2, carry, sum;
    int* res = new int[size1 + size2];

    for(int i = size1 + size2 - 1; i >= 0; i--)
        res[i] = 0;
    
    idx_num1 = idx_num2 = 0;
    
    for (int i = size1 - 1; i >= 0; i--)
    {
        carry = 0;
        idx_num2 = 0;
        
        for (int j = size2 - 1; j >= 0; j--)
        {
            sum = 0;
            sum = num1[i] * num2[j] + carry + res[idx_num1 + idx_num2];
            carry = sum / 10;
            res[idx_num1 + idx_num2] = sum % 10;
            idx_num2++;
        }
        
        res[idx_num1 + idx_num2] += carry;
        idx_num1++;
    }
    
    for(int i = size1 + size2 - 1; i >= 0; i--)
        cout << res[i];

	delete[] res;
}


void file_writer()
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	//fun();		// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <name-of-fun> is : " << fixed
		<< time_taken/* << setprecision(9)*/;
	myfile << " sec" << endl;
	myfile.close();
}