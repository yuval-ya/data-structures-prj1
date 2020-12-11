//
//  main.cpp
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 23/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#include "main.h"
#include <iostream>

#include <chrono>
#include <fstream>
using namespace std;

int main() {
	int input_flag = 1;
	long int n = 0;
	
	input_flag = getSize(n);
	
	if (input_flag < 0) {
		cout << "wrong output";
		return 0;
	}

    int *x, *y;
	x = getNumArr(n, input_flag);
	if (input_flag < 0) {
		cout << "wrong output";
		return 0;
	}
	y = getNumArr(n, input_flag);
	if (input_flag < 0) {
		cout << "wrong output";
		return 0;
	}
    
    cout << "------------" << endl;
    cout << "Number 1 = ";
	printIntArr(x, n);
    cout << "\nNumber 2 = ";
	printIntArr(y, n);
    cout << "\n------------" << endl;
    cout << "Result = ";

	
	cout << "Long multiplication : x * y =";
	multiplyA(x, y, n, n);
	cout << "\nKaratsuba(recursive) : x * y =";
	cout << "\nKaratsuba(iterative) : x * y =";

    return 0;
}

void printIntArr(int * arr, int size) {
	int j;
	for (j = 0; (j < size - 1) && (arr[j] == 0); j++) { // skip all leading zero's
	}
	for (int i = j; i < size; i++)
		cout << arr[i];
}

int getSize(long int& n) {
	long int res = 0;
	cout << "Enter the number of digits: " << endl;	
	char ch;
	cin >> ch;
	if (ch < '1' || ch > '9')
		return -1;			// case ch is not a number or a leading zero
	while (/*ch != ' ' && ch != '\t' && */ch != '\n')
	{
		if (ch < '0' || ch > '9') 
			return -2;		// case ch is not a number
		res *= 10;
		res += ch - '0';
		cin.get(ch);
	}
	n = res;
	return 1;
}

int* getNumArr(int size, int& input_flag) {

    int *res = new int[size];
    char ch;

    cout << "Enter the input number: " <<endl;
    for(int i = 0; i < size; i++)
    {
        cin >> ch;
        res[i] = ch - '0';
    }
	input_flag = 1;
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