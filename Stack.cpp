//
//  Stack.cpp
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 23/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#include "Stack.h"

namespace stk {
Stack::Stack(){
    _top = nullptr;
}

Stack::~Stack(){
    MakeEmpty();
}

void Stack::MakeEmpty(){
    Node* temp;
    while(_top != nullptr){
        temp = _top;
        _top = _top->getNext();
        delete temp;
    }
}

void Stack::Push(ItemType item){
    _top = new Node(item,_top);
}

ItemType Stack::Pop(){
    if (IsEmpty()) {
        // Handle Error
    }
    
    Node* temp = _top;
    ItemType item = _top->getVal();
    _top = _top->getNext();
    delete temp;
    return item;
}

bool Stack::IsEmpty(){
    return _top == nullptr;
}

ItemType Stack::Top() {
    return _top->getVal();
}

}
