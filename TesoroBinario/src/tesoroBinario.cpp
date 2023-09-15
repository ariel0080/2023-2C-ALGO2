#include <string>
#include <iostream>
#include "Tablero.h"
#include "Graficos.h"
#include "Registro.h"
#include "Usuario.h"
#include "Imprimir.h"
#include <sstream>

int main() {

	//SETUP INICIAL
	presentacion();
	Tablero *jugador1 = inicializarTablero(20, 20);
	Tablero *jugador2 = inicializarTablero(20, 20);

	separador("TIEMPO PARA QUE JUGADOR 1 ESCONDA LOS TESOROS");
	cargaInicialJugador(jugador1,"Jugador-1-Turno-0.txt");
	std::cin.get();
	separador("TIEMPO PARA QUE JUGADOR 2 ESCONDA LOS TESOROS");
	cargaInicialJugador(jugador2, "Jugador-2-Turno-0.txt");

	Juego(jugador1,jugador2);
	borrarTablero(jugador1);
	borrarTablero(jugador2);
	return 0;
}

