//
//  main.cpp
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 23/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//
#include <iostream>
#include "Input.h"
#include "Multiplication.h"
using namespace std;

int main(void) {

	int input_flag = 1;

	long int n = Input::getSize(input_flag);
	if (input_flag < 0) {
		cout << "wrong input";
		return 0;
	}

	int* x = Input::getNumArr(n, input_flag);
	if (input_flag < 0) {
		cout << "wrong input";
		return 0;
	}

	int* y = Input::getNumArr(n, input_flag);
	if (input_flag < 0) {
		cout << "wrong input";
		delete[] x;
		return 0;
	}

	Multiplication::RegularMultiplicationHelper(x, y, n, n);
	Multiplication::KaratsubaRecursiveHelper(x, y, n);
	Multiplication::KaratsubaIterativeHelper(x, y, n);
    
	delete[] x;
	delete[] y;
	return 0;
}
