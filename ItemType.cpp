#include "ItemType.h"

namespace stk {

ItemType::ItemType(Line line, int*x, int*y, long int size,  int*res, int*aPlusb, int* cPlusd, int* prodOfSum, long int prodOfSumSize) :    line(line), x(x), y(y),
                        res(res), size(size),
                        aPlusb(aPlusb), cPlusd(cPlusd),
                        prodOfSum(prodOfSum), prodOfSumSize(prodOfSumSize) {}


ItemType::ItemType(const ItemType& other) : line(other.line), x(other.x), y(other.y),
                                            res(other.res), size(other.size),
                                            aPlusb(other.aPlusb), cPlusd(other.cPlusd),
                                            prodOfSum(other.prodOfSum), prodOfSumSize(other.prodOfSumSize) {}


ItemType::~ItemType() {
}

void ItemType::delete_aPlusB() {
	delete[] aPlusb;
	aPlusb = nullptr;
}

void ItemType::delete_cPlusd() {
	delete[] cPlusd;
	cPlusd = nullptr;
}

void ItemType::delete_prodOfSum() {
	delete[] prodOfSum;
	prodOfSum = nullptr;
}

void ItemType::operator=(const ItemType& other){
    line = other.line;
    x = other.x;
    y = other.y;
    res = other.res;
    size = other.size;
    aPlusb = other.aPlusb;
    cPlusd = other.cPlusd;
    prodOfSum = other.prodOfSum;
    prodOfSumSize = other.prodOfSumSize;
}

}
