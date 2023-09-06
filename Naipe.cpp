#include "naipe.hpp"
#include <iostream>
#include <fstream>

void generarArchivoBaraja(const char* filename) {
    // Abre un archivo binario para escritura
    std::ofstream archivo(filename, std::ios::binary);

    // Verifica si se pudo abrir el archivo
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return;// Sale de la función si no se pudo abrir
    }

    // Establece la cantidad total de naipes en la baraja (52)
    int cantidadNaipes = 52;

    // Escribe la cantidad de naipes en el archivo
    archivo.write(reinterpret_cast<const char*>(&cantidadNaipes), sizeof(cantidadNaipes));

    // Genera naipes para cada número (1-13) y palo (P, C, D, T)
    for (int numero = 1; numero <= 13; ++numero) {
        for (char palo : "PCDT") {
            Naipe naipe;
            naipe.numero = numero;
            naipe.palo = palo;
            // Determina el color del naipe (R para Rojo, N para Negro)
            naipe.color = (palo == 'P' || palo == 'T') ? 'N' : 'R';

            // Escribe el naipe en el archivo
            archivo.write(reinterpret_cast<const char*>(&naipe), sizeof(naipe));
        }
    }

    archivo.close();
}
