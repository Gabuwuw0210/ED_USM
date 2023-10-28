#include "Lista.hpp"

tLista::tLista(unsigned int MAXSIZE) {
    maxSize = MAXSIZE;
    size = 0;
    elements = new int[maxSize];
}

tLista::~tLista() {
    delete[] elements;
}

tLista::tLista() {
    maxSize=0;
    size=0;
    elements= nullptr;
}

void tLista::clear() {
    size = 0;
}

int tLista::erase(unsigned int position) {
    if (position < 0 || position >= size)
        return -1;

    int item = elements[position];
    for (unsigned int i = position; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }

    size--;
    return item;
}

int tLista::append(int item) {
    if (size >= maxSize)
        return -1;

    elements[size++] = item;
    return size - 1;
}

int tLista::insert(unsigned int position, int item) {
    if (size >= maxSize || position > size)
        return -1;

    for (unsigned int i = size; i > position; i--) {
        elements[i] = elements[i - 1];
    }

    elements[position] = item;
    size++;
    return position;
}

int tLista::get_value(unsigned int position) {
    if (position < 0 || position >= size)
        return -1;

    return elements[position];
}

int tLista::length() {
    return size;
}
