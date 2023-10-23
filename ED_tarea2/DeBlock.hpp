#ifndef DEBLOCK_HPP
#define DEBLOCK_HPP

#include "Lista.hpp"

class DeBlock {
public:
    DeBlock(int* elems, int n, int b);
    int insert(int pos, int elem);
    int erase(int pos);
    int get_value(int pos);
    int length();
    void clear();

private:
    Lista l;
    int cant_elems;
};

#endif // DEBLOCK_HPP
