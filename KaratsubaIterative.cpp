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
            long int aPlusbSize = 0, cPlusdSize = 0;

            // (a+b)
            int* aPlusb = adder(curr.getX(), curr.getX() + firstHalf, firstHalf, secondHalf, aPlusbSize);
            curr.set_aPlusB(aPlusb); // (size - (size / 2)) + 1
            // (c+d)
            int* cPlusd = adder(curr.getY(), curr.getY() + firstHalf, firstHalf, secondHalf, cPlusdSize);
            curr.set_cPlusd(cPlusd); // (size - (size / 2)) + 1

            if (aPlusb[0] == 0 && cPlusd[0] == 0) {
                aPlusbSize--;				// aPlusbSize == cPlusdSize
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
		else if (curr.get_line() == Line::AFTER_THIRD) {
			curr.delete_aPlusB();
			curr.delete_cPlusd();
			
			int* prodOfSum = curr.get_prodOfSum();
			int* currRes = curr.get_res();
			long int prodOfSumSize = curr.get_prodOfSumSize();
			subtractor(prodOfSum, currRes, prodOfSumSize, firstHalf * 2);
			subtractor(prodOfSum, currRes + firstHalf * 2, prodOfSumSize, secondHalf * 2);

			int carry = 0, sum;
			long int size = curr.getSize(), i, j;
			for (i = size * 2 - (size + 1) / 2 - 1, j = prodOfSumSize - 1; j >= 0 && i >= 0; i--, j--) {
				sum = currRes[i] + prodOfSum[j] + carry;
				currRes[i] = sum % 10;
				carry = sum / 10;
			}
			while (carry && i >= 0) {
				sum = currRes[i] + carry;
				currRes[i] = sum % 10;
				carry = sum / 10;
				i--;
			}
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
	KaratsubaIterative(x, y, size, res);		// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function KaratsubaIterative is : " << fixed << time_taken /*<< setprecision(9)*/;
	myfile << " sec" << endl;
	myfile << "\n===================================================================\n";
	myfile.close();

	cout << "\nKaratsuba(Iterative) : x * y = ";
	printIntArr(res, 2 * size);
	delete[] res;
}
