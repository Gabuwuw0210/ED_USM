#ifndef LISTADELISTAS_HPP
#define LISTADELISTAS_HPP

#include "Lista.hpp"

class tListaDeListas {
private:
    tLista* listArray;
    unsigned int maxSize;
    unsigned int listSize;

public:
    tListaDeListas(unsigned int MAXSIZE);
    ~tListaDeListas();

    void clear();
    tLista erase(unsigned int position);
    int append(tLista item);
    int insert(tLista item, unsigned int position);
    tLista get_value(unsigned int position);
    int length();
};

#endif // LISTADELISTAS_HPP
