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


int main() {

    int n;
    cout << "Enter the number of digits: " <<endl;
    cin >> n;

    int *x, *y;
    x = getNumArr(n);
    y = getNumArr(n);
    
    cout << "------------" << endl;
    cout << "Num1 = (" << x[0] << x[1] << ")" << endl;
    cout << "Num2 = (" << y[0] << y[1] << ")" << endl;
    cout << "------------" << endl;

    cout << "res = ";

    multipliesA(x, y, n, n);

    return 0;
}


int* getNumArr(int size) {

    int *numArr = new int[size];
    char ch;

    cout << "Enter the input number: " <<endl;
    for(int i = 0; i < size; i++){
        cin >> ch;
        numArr[i] = ch - '0';
    }

    return numArr;
}

void multipliesA(int* num1, int* num2, int size1, int size2){
    int idx_num1, idx_num2, carry, sum;
    
    if (size1 + size2 == 0)
        cout << "0" << endl;
    
    int* res = new int[size1 + size2];

    for(int i = size1 + size2 - 1; i >= 0; i--)
        res[i] = 0;
    
    idx_num1 = idx_num2 = 0;
    
    for (int i = size1 - 1; i >= 0; i--){
        
        carry = 0;
        idx_num2 = 0;
        
        for (int j = size2 - 1; j >= 0; j--){
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
    
    
}
