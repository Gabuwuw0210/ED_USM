#ifndef LISTA_HPP
#define LISTA_HPP

class Lista {
public:
    Lista(); // Constructor
    ~Lista(); // Destructor
    void insertarAlFinal(int valor);
    void limpiar();
    int obtenerValorEnPos(int pos);
    int obtenerLongitud();

private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        Nodo(int d) : dato(d), siguiente(nullptr) {}
    };
    Nodo* primero;

};

#endif // LISTA_HPP
