#ifndef DEBLOCK_HPP
#define DEBLOCK_HPP

#include "ListaDeListas.hpp"

class DeBlock {
private:
    tListaDeListas* listArray;
    int cant_elems;
    int blockSize;

public:

    DeBlock(int* elems, int n, int b);
    ~DeBlock();
    int getBlockSize() const;
    int getCantElems() const;
    int insert(int pos, int elem);
    int get_value(int pos);
    int length();
    int erase(int pos);
    void clear();
};

#endif // DEBLOCK_HPP
