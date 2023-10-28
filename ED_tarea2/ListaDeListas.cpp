#include "ListaDeListas.hpp"

tListaDeListas::tListaDeListas(unsigned int MAXSIZE) {
    maxSize = MAXSIZE;
    listSize = 0;
    listArray = new tLista(maxSize);
}

tListaDeListas::~tListaDeListas() {
    delete[] listArray;
}

void tListaDeListas::clear() {
    listSize = 0;
}

tLista tListaDeListas::erase(unsigned int position) {
    tLista item(listSize);
    if (position < 0 || position >= listSize)
        return item;

    item = listArray[position];
    for (unsigned int i = position; i < listSize-1; i++) {
        listArray[i] = listArray[i+1];
    }

    listSize--;
    return item;
}

int tListaDeListas::append(tLista item) {
    if (listSize >= maxSize)
        return -1;

    listArray[listSize++] = item;
    return listSize-1;
}

int tListaDeListas::insert(tLista item, unsigned int position) {
    if (listSize >= maxSize || position > listSize)
        return -1;

    for (unsigned int i = listSize; i > position; i--) {
        listArray[i] = listArray[i-1];
    }

    listArray[position] = item;
    listSize++;
    return position;
}

tLista tListaDeListas::get_value(unsigned int position) {
    tLista item(listSize);
    if (position < 0 || position >= listSize)
        return item;

    return listArray[position];
}

int tListaDeListas::length() {
    return listSize;
}
