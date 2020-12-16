//
//  Input.h
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 16/12/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#pragma once

class Input {
    
    // A class for getting the input from the user
    
public:
    static long int getSize(int& input_flag);
    static int* getNumArr(long int size, int& input_flag);
};
