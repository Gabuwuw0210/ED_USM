#ifndef NAIPE_HPP
#define NAIPE_HPP
#include <string>

struct Naipe {
    int numero;
    char palo;
    char color;

    friend std::ostream& operator<<(std::ostream& os, const Naipe& naipe) {
        os << std::to_string(naipe.numero); // Convertir naipe.numero en chaîne de caractères et l'afficher
        return os;
    }

};

void generarArchivoBaraja(const char* filename);

#endif // NAIPE_HPP
