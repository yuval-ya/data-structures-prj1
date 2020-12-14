#pragma once

namespace stk {

enum class Line { START, AFTER_FIRST, AFTER_SECOND, AFTER_THIRD };

class ItemType {
    
private:
    int *x, *y, *aPlusb, *cPlusd, *prodOfSum, *res;
    long int size, prodOfSumSize;
    Line line;
public:
    ItemType(Line line = Line::START, int *x = nullptr, int *y = nullptr, long int size = 0, int *res = nullptr, int *aPlusb = nullptr, int *cPlusd = nullptr,int *prodOfSum = nullptr, long int prodOfSumSize = 0);
    ItemType(const ItemType&);
    
    int* getX() const { return x;}
    int* getY() const { return y;}
    int* get_aPlusB() const { return aPlusb;}
    int* get_cPlusd() const { return cPlusd;}
    int* get_prodOfSum() const { return prodOfSum;}
    int* get_res() const { return res;}
    long int getSize() const { return size;}
    long int get_prodOfSumSize() const { return prodOfSumSize;}
    Line get_line() const { return line; }
    
    
    void setX(int* pnt) { x = pnt ;}
    void setY(int* pnt) { y = pnt;}
    void set_aPlusB(int* pnt) { aPlusb = pnt;}
    void set_cPlusd(int* pnt) { cPlusd = pnt ;}
    void set_prodOfSum(int* pnt) { prodOfSum = pnt;}
    void set_res(int* pnt) { res = pnt;}
    void setSize(long int size) { this->size = size ;}
    void set_prodOfSumSize(long int size) { prodOfSumSize = size; }
    void set_line(Line line) { this->line = line;}

    void operator=(const ItemType& other);
};


}
