#include <iostream>
#include <fstream>
#include "DeBlock.hpp"

int main() {
    std::ifstream inputFile("pruebas.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return 1;
    }

    int n, b;
    inputFile >> n >> b;
    int* elems = new int[n];
    for (int i = 0; i < n; i++) {
        inputFile >> elems[i];
    }

    DeBlock deBlock(elems, n, b);
    std::cout << "blockSize: " << deBlock.getBlockSize() << std::endl;
    std::cout << "cant_elems: " << deBlock.getCantElems() << std::endl;

    int q;
    inputFile >> q;

    for (int i = 0; i < q; i++) {
        char op;
        inputFile >> op;

        if (op == 'I') {
            int pos, val;
            inputFile >> pos >> val;
            deBlock.insert(pos, val);
        } else if (op == 'G') {
            int pos;
            inputFile >> pos;
            int value = deBlock.get_value(pos);
            std::cout << value << std::endl;
        } else if (op == 'L') {
            int len = deBlock.length();
            std::cout << len << std::endl;
        }
    }

    delete[] elems;
    return 0;
}

