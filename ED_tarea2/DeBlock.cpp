#include "DeBlock.hpp"

DeBlock::DeBlock(int* elems, int n, int b) : cant_elems(b) {
    int bloques = n / b;
    if (n % b != 0) {
        bloques++;
    }
    for (int i = 0; i < bloques; i++) {
        Lista bloque;
        for (int j = i * b; j < (i + 1) * b && j < n; j++) {
            bloque.insertarAlFinal(elems[j]);
        }
        l.insertarAlFinal(bloque.obtenerLongitud());
    }
}

int DeBlock::insert(int pos, int elem) {
    int bloqueIdx = pos / cant_elems;
    int idxDentroBloque = pos % cant_elems;

    int longitudBloque = l.obtenerValorEnPos(bloqueIdx);
    if (idxDentroBloque >= longitudBloque) {
        return 0; // Posición fuera de rango
    }

    l.insertarAlFinal(elem);
    return 1;
}

int DeBlock::erase(int pos) {
    int bloqueIdx = pos / cant_elems;
    int idxDentroBloque = pos % cant_elems;

    int longitudBloque = l.obtenerValorEnPos(bloqueIdx);
    if (idxDentroBloque >= longitudBloque) {
        return -1; // Error, posición fuera de rango
    }

    int valor = l.obtenerValorEnPos(pos);
    l.limpiar();
    return valor;
}

int DeBlock::get_value(int pos) {
    int bloqueIdx = pos / cant_elems;
    int idxDentroBloque = pos % cant_elems;

    int longitudBloque = l.obtenerValorEnPos(bloqueIdx);
    if (idxDentroBloque >= longitudBloque) {
        return -1; // Error, posición fuera de rango
    }

    return l.obtenerValorEnPos(pos);
}

int DeBlock::length() {
    int n = 0;
    for (int i = 0; i < l.obtenerLongitud(); i++) {
        n += l.obtenerValorEnPos(i);
    }
    return n;
}

void DeBlock::clear() {
    l.limpiar();
}
