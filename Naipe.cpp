#include "naipe.hpp"
#include <iostream>
#include <fstream>

void generarArchivoBaraja(const char* filename) {
    std::ofstream archivo(filename, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return;
    }

    int cantidadNaipes = 52;
    archivo.write(reinterpret_cast<const char*>(&cantidadNaipes), sizeof(cantidadNaipes));

    for (int numero = 1; numero <= 13; ++numero) {
        for (char palo : "PCDT") {
            Naipe naipe;
            naipe.numero = numero;
            naipe.palo = palo;
            naipe.color = (palo == 'P' || palo == 'T') ? 'N' : 'R';

            archivo.write(reinterpret_cast<const char*>(&naipe), sizeof(naipe));
        }
    }

    archivo.close();
}
