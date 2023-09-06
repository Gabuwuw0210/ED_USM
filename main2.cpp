#include "Juego.hpp"
#include <iostream>
#include <random>
#include <ctime>

int main() {
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios

    std::cout << "Ingrese Juego (P, C o B): ";//elegir el juego
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

    int cartasNegras;
    int cartasRojas;

    // Usar puntero a Juego en lugar de un objeto directo
    Juego* juego = new Juego(tipo, numJugadores);

    // Crear las manos
    juego->crearManos();

    // Imprimir el conteo de cartas
    juego->imprimirConteoCartas();

    // Generar el nombre del archivo
    std::string nombreArchivo = tipoJuego + std::to_string(numJugadores) + ".txt";

    // Guardar las manos en el archivo
    juego->guardarArchivo(nombreArchivo);

    std::cout << "Manos guardadas en el archivo '" << nombreArchivo << "'." << std::endl;

    // Liberar la memoria del objeto Juego
    delete juego;

    return 0;
}
