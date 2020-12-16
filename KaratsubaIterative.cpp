#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include "Multiplication.h"
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
		Line line = curr.get_line();
        if (line == Line::START)
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
        else if (line == Line::AFTER_FIRST){
            curr.set_line(Line::AFTER_SECOND);
            s.Push(curr);
        
            curr = ItemType(Line::START, curr.getX() + firstHalf , curr.getY() + firstHalf ,secondHalf, curr.get_res() + firstHalf*2);
            returnFromRecursion = 0;
        }
        else if (line == Line::AFTER_SECOND){
            curr.set_line(Line::AFTER_THIRD); 
            long int aPlusbSize = 0, cPlusdSize = 0;

            // (a+b)
            int* aPlusb = adder(curr.getX(), curr.getX() + firstHalf, firstHalf, secondHalf, aPlusbSize);
            curr.set_aPlusB(aPlusb);
            // (c+d)
            int* cPlusd = adder(curr.getY(), curr.getY() + firstHalf, firstHalf, secondHalf, cPlusdSize);
            curr.set_cPlusd(cPlusd);

            if (aPlusb[0] == 0 && cPlusd[0] == 0) { // removes leading zero
                aPlusbSize--;		                // aPlusbSize == cPlusdSize
				aPlusb = aPlusb + 1;
				cPlusd = cPlusd + 1;
            }

            long int prodOfSumSize = aPlusbSize * 2;
			int *prodOfSum = new int[prodOfSumSize]();
			curr.set_prodOfSum(prodOfSum);
			curr.set_prodOfSumSize(prodOfSumSize);
            s.Push(curr);

			curr = ItemType(Line::START, aPlusb, cPlusd, aPlusbSize, prodOfSum);
			returnFromRecursion = 0;
        }
		else if (line == Line::AFTER_THIRD) {
			curr.delete_aPlusB();
			curr.delete_cPlusd();
			
			int* prodOfSum = curr.get_prodOfSum();
			int* currRes = curr.get_res();
			long int prodOfSumSize = curr.get_prodOfSumSize();
            
            //(a+b)*(c+d) - (a*c)
			subtractor(prodOfSum, currRes, prodOfSumSize, firstHalf * 2);
            //(a+b)*(c+d) - (a*c) - (b*d)
			subtractor(prodOfSum, currRes + firstHalf * 2, prodOfSumSize, secondHalf * 2);
            // (ac)*10^size + middle * 10^(size/2) + (bd)
            sumMiddlePart(currRes, prodOfSum, curr.getSize(), prodOfSumSize);

			curr.delete_prodOfSum();
			returnFromRecursion = 1;
		}
    }
    while (!s.IsEmpty());
}

void Multiplication::KaratsubaIterativeHelper(int* x, int* y, long int size) {
	int* res = new int[size * 2]();

	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	KaratsubaIterative(x, y, size, res);
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function KaratsubaIterative is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl << endl;
	myfile.close();
	cout << "\nKaratsuba(Iterative) : x * y = ";
	printIntArr(res, 2 * size);
	delete[] res;
}


