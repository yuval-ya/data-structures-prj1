//
//  Stack.h
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 23/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#pragma once
#include "ItemType.h"

namespace stk {


class Stack {
private:
    struct Node{
        ItemType data;
        Node* next;
    };
    Node* _top;
public:
    Stack();
    ~Stack();
    void MakeEmpty();
    bool IsEmpty();
    void Push(const ItemType& item);
    ItemType Pop();
    ItemType& Top();
};


}
