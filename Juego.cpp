#include "Juego.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include "Naipe.hpp"



Juego::Juego(TipoJuego tipo, int numJugadores) : tipoJuego(tipo), numJugadores(numJugadores) {
    // Cargar la baraja desde el archivo binario generado en la sección anterior
    std::ifstream archivo("baraja.dat", std::ios::binary);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo de baraja." << std::endl;
        return;
    }

    int cantidadNaipes;
    archivo.read(reinterpret_cast<char*>(&cantidadNaipes), sizeof(cantidadNaipes));

    for (int i = 0; i < cantidadNaipes; ++i) {
        Naipe naipe;
        archivo.read(reinterpret_cast<char*>(&naipe), sizeof(naipe));
        baraja.push_back(naipe); // Usar 'naipe', no 'i'
    }

    archivo.close();
}


void Juego::crearManos() {
    std::random_device rd;
    std::mt19937 gen(rd());

    if (tipoJuego == TipoJuego::Poker) {
        // Implementa la creación de manos para Poker

        if (numJugadores < 2 || numJugadores > 7) {
            std::cerr << "Número de jugadores inválido para el juego de Poker." << std::endl;
            return;
        }

        // Mezcla la baraja
        std::shuffle(baraja.begin(), baraja.end(), gen);

        for (int i = 0; i < numJugadores; ++i) {
            std::vector<Naipe> mano;
            for (int j = 0; j < 5; ++j) {
                mano.push_back(baraja.back()); // Tomar la última carta de la baraja
                baraja.pop_back(); // Eliminar la carta de la baraja
            }
            manos.push_back(mano); // Agregar la mano al vector de manos del juego
        }

    } else if (tipoJuego == TipoJuego::Canasta) {
        // Implementa la creación de manos para Canasta

        if (numJugadores < 2 || numJugadores > 6) {
            std::cerr << "Número de jugadores inválido para el juego de Canasta." << std::endl;
            return;
        }

        // Cada jugador recibe 15 naipes
        int cartasPorJugador = 15;

        // Mezcla la baraja
        std::shuffle(baraja.begin(), baraja.end(), gen);

        for (int i = 0; i < numJugadores; ++i) {
            std::vector<Naipe> mano;
            for (int j = 0; j < 5; ++j) {
                mano.push_back(baraja.back()); // Tomar la última carta de la baraja
                baraja.pop_back(); // Eliminar la carta de la baraja
            }
            manos.push_back(mano); // Agregar la mano al vector de manos del juego
        }

    } else if (tipoJuego == TipoJuego::Brisca) {
        // Implementa la creación de manos para Brisca

        if (numJugadores < 2 || numJugadores > 6) {
            std::cerr << "Número de jugadores inválido para el juego de Brisca." << std::endl;
            return;
        }

        // Cada jugador recibe 4 naipes
        int cartasPorJugador = 4;

        // Mezcla la baraja
        std::shuffle(baraja.begin(), baraja.end(), gen);

        for (int i = 0; i < numJugadores; ++i) {
            std::vector<Naipe> mano;
            for (int j = 0; j < 5; ++j) {
                mano.push_back(baraja.back()); // Tomar la última carta de la baraja
                baraja.pop_back(); // Eliminar la carta de la baraja
            }
            manos.push_back(mano); // Agregar la mano al vector de manos del juego
        }

    }
}



void Juego::guardarArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para guardar las manos." << std::endl;
        return;
    }

    for (const auto& mano : manos) {
        for (const Naipe& naipeNumero : mano) {
            archivo << naipeNumero << " ";
        }
        archivo << std::endl;
    }

    archivo.close();
}


void Juego::imprimirConteoCartas() {
    int cartasRojas = 0, cartasNegras = 0;

    for (const auto& mano : manos) {
        for (const Naipe& naipe : mano) {
            char color = naipe.color; // Accedemos al color del naipe en la baraja
            if (color == 'R') {
                cartasRojas++;
            } else if (color == 'N') {
                cartasNegras++;
            }
        }
    }

    std::cout << "Cantidad de cartas Rojas: " << cartasRojas << std::endl;
    std::cout << "Cantidad de cartas Negras: " << cartasNegras << std::endl;
}


