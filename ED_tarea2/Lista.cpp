#include "Lista.hpp"

Lista::Lista() : primero(nullptr) {}

Lista::~Lista() {
    limpiar();
}

void Lista::insertarAlFinal(int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    if (!primero) {
        primero = nuevoNodo;
    } else {
        Nodo* actual = primero;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void Lista::limpiar() {
    while (primero) {
        Nodo* temp = primero;
        primero = primero->siguiente;
        delete temp;
    }
}

int Lista::obtenerValorEnPos(int pos) {
    Nodo* actual = primero;
    for (int i = 0; i < pos; i++) {
        if (!actual) {
            // Tratamiento de posición fuera de rango
            return -1; // Por ejemplo, podrías usar un valor especial para indicar este caso
        }
        actual = actual->siguiente;
    }
    return actual ? actual->dato : -1; // También aquí puedes usar un valor especial
}

int Lista::obtenerLongitud() {
    int count = 0;
    Nodo* actual = primero;
    while (actual) {
        count++;
        actual = actual->siguiente;
    }
    return count;
}
