#include "DeBlock.hpp"
#include <iostream>

int main() {
    const int n = 10;
    int elementos[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DeBlock bloque(elementos, n, 3);

    int valor = bloque.get_value(4);
    int longitud = bloque.length();

    std::cout << "Valor en la posición 4: " << valor << std::endl;
    std::cout << "Longitud del bloque: " << longitud << std::endl;

    return 0;
}
