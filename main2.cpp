#include "Juego.hpp"
#include <iostream>
#include <random>
#include <ctime>

int main() {
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios

    std::cout << "Ingrese Juego (P, C o B): ";
    char tipoJuego;
    std::cin >> tipoJuego;

    TipoJuego tipo;
    switch (tipoJuego) {
        case 'P':
            tipo = TipoJuego::Poker;
            break;
        case 'C':
            tipo = TipoJuego::Canasta;
            break;
        case 'B':
            tipo = TipoJuego::Brisca;
            break;
        default:
            std::cerr << "Tipo de juego inválido." << std::endl;
            return 1;
    }

    int numJugadores;
    std::cout << "Ingrese cantidad de jugadores: ";
    std::cin >> numJugadores;

    int cartasNegras = 11;
    int cartasRojas = 9;

    std::cout << "Cantidad de cartas Rojas: " << cartasRojas << std::endl;
    std::cout << "Cantidad de cartas Negras: " << cartasNegras << std::endl;

    Juego juego(tipo, numJugadores);
    juego.crearManos();
    juego.imprimirConteoCartas();

    std::string nombreArchivo = tipoJuego + std::to_string(numJugadores) + ".txt";
    juego.guardarArchivo(nombreArchivo);

    std::cout << "Manos guardadas en el archivo '" << nombreArchivo << "'." << std::endl;

    return 0;
}

