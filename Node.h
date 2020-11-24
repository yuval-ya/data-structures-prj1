//
//  Node.h
//  data-structures-prj1
//
//  Created by Yuval  Yakovskind  on 23/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#pragma once

namespace stk {
struct ItemType {
    int x;
};

class Node {
private:
    ItemType _val;
    Node* _next;
public:
    Node() : _next(nullptr) {}
    Node(ItemType val, Node* next = nullptr) : _val(val), _next(next) {}
    Node* getNext() const { return _next; }
    ItemType& getVal() { return _val; }
};
}
