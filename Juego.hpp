#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <string>
#include <vector>
#include "Naipe.hpp"

enum class TipoJuego {
    Poker,
    Canasta,
    Brisca
};

class Juego {
public:
    Juego(TipoJuego tipo, int numJugadores);
    void crearManos();
    void guardarArchivo(const std::string& nombreArchivo);
    void imprimirConteoCartas();

private:
    TipoJuego tipoJuego;
    int numJugadores;
    std::vector<std::vector<Naipe>> manos;
    std::vector<Naipe> baraja;



};

#endif // JUEGO_HPP
