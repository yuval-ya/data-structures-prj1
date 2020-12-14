#include "Multiplication.h"

#include <iostream>
#include <chrono>
#include <fstream>
#include "Stack.h"
using namespace std;
using namespace stk;

void Multiplication::KaratsubaIterative(int* x, int* y, long int size, int* res) {
    Stack s;
    ItemType curr;
    int returnFromRecursion = 0;
    
    curr = ItemType(Line::START, x, y, size, res);
    
    do {
        if (returnFromRecursion)
            curr = s.Pop();
        
        long int firstHalf = curr.getSize()/2;
        long int secondHalf = curr.getSize() - firstHalf;
        
        if (curr.get_line() == Line::START)
        {
            if (curr.getSize() == 1){
                int mul = curr.getX()[0] * curr.getY()[0];
                curr.get_res()[1] = mul % 10;
                curr.get_res()[0] = mul / 10;
                returnFromRecursion = 1;
            }
            else {
                curr.set_line(Line::AFTER_FIRST);
                s.Push(curr);
                curr = ItemType(Line::START, curr.getX(), curr.getY(), curr.getSize() / 2, curr.get_res());
                returnFromRecursion = 0;
            }
        }
        else if (curr.get_line() == Line::AFTER_FIRST){
            curr.set_line(Line::AFTER_SECOND);
            s.Push(curr);
        
            curr = ItemType(Line::START, curr.getX() + firstHalf , curr.getY() + firstHalf ,secondHalf, curr.get_res() + firstHalf*2);
            returnFromRecursion = 0;
        }
        else if (curr.get_line() == Line::AFTER_SECOND){
            curr.set_line(Line::AFTER_THIRD);
            
            long int aPlusbSize = 0, cPlusdSize = 0, prodOfSumSize = 0;

            // (a+b)
            int* aPlusb = adder(curr.getX(), curr.getX() + firstHalf, firstHalf, secondHalf, aPlusbSize);
            curr.set_aPlusB(aPlusb); // (size - (size / 2)) + 1
            // (c+d)
            int* cPlusd = adder(curr.getY(), curr.getY() + firstHalf, firstHalf, secondHalf, cPlusdSize);
            curr.set_cPlusd(cPlusd); // (size - (size / 2)) + 1

            int *prodOfSum;
            
            if (aPlusb[0] == 0 && cPlusd[0] == 0)
            {
                prodOfSumSize = (aPlusbSize - 1) * 2;    // aPlusbSize == cPlusdSize
                

            }
            else
            {
                prodOfSumSize = aPlusbSize * 2;
            }
            
            s.Push(curr);
            
        }
    }
    while (!s.IsEmpty());
}

void Multiplication::KaratsubaIterativeHelper(int* x, int* y, long int size) {

}
