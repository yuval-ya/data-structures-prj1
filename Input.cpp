//
//  Input.cpp
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 16/12/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#include <iostream>
#include "Input.h"
using namespace std;

long int Input::getSize(int& input_flag) {
    long int res = 0;
    cout << "Enter the number of digits: " << endl;
    char ch;
    cin >> ch;
    if (ch < '1' || ch > '9')
    {    // case ch is not a number or a leading zero
        input_flag = -1;
        return 0;
    }

    while (ch != '\n')
    {
        if (ch < '0' || ch > '9')
        {    // case ch is not a number
            input_flag = -2;
            return 0;
        }
        res *= 10;
        res += ch - '0';
        cin.get(ch);
    }
    return res;
}

int* Input::getNumArr(long int size, int& input_flag) {

    int *res = new int[size];
    char ch;
    int i = 0;
    cout << "Enter the input number: " <<endl;
    
    cin >> ch;
    if (ch < '0' || ch > '9')
    {    // case ch is not a number
        input_flag = -1;
        delete[] res;
        return nullptr;
    }

    while (ch != ' ' && ch != '\t' && ch != '\n' && input_flag > 0)
    {
        if (ch < '0' || ch > '9' || i >= size)
        {    // case ch is not a number or the user enter more digit then size
            input_flag = -2;
            delete[] res;
            return nullptr;
        }
        res[i] = ch - '0';
        cin.get(ch);
        i++;
    }

    if (i < size)
    {    // case the input is smaller than the size received
        input_flag = -2;
        delete[] res;
        return nullptr;
    }

    return res;
}


