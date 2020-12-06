//
//  main.cpp
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 23/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#include "main.h"
#include <iostream>
using namespace std;

#include "Multiplication.h";

int main() {

    int n;
    cout << "Enter the number of digits: " <<endl;
    cin >> n;
	Multiplication m(n, n);
	m.RegularMultiplication();

 //   int *x, *y;
 //   x = getNumArr(n);
 //   y = getNumArr(n);
 //   
 //   cout << "------------" << endl;
 //   cout << "Number 1 = ";
	//printIntArr(x, n);
 //   cout << "\nNumber 2 = ";
	//printIntArr(y, n);
 //   cout << "\n------------" << endl;
 //   cout << "Result = ";

	//multiplyA(x, y, n, n);

    return 0;
}
void printIntArr(int * arr, int size) {
	int j;
	for (j = 0; (j < size - 1) && (arr[j] == 0); j++) { // skip all leading zero's
	}
	for (int i = j; i < size; i++)
		cout << arr[i];
}

int* getNumArr(int size) {

    int *numArr = new int[size];
    char ch;

    cout << "Enter the input number: " <<endl;
    for(int i = 0; i < size; i++)
    {
        cin >> ch;
        numArr[i] = ch - '0';
    }

    return numArr;
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
