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
	/*prueba*/
	jugador1->matriz[0][0].tesoro = true;
	jugador1->matriz[0][1].tesoro = true;
	jugador1->matriz[0][2].tesoro = true;
	jugador1->matriz[0][3].tesoro = true;

	jugador2->matriz[1][0].tesoro = true;
	jugador2->matriz[1][1].tesoro = true;
	jugador2->matriz[1][2].tesoro = true;
	jugador2->matriz[1][3].tesoro = true;
	//fin prueba

	//separador("TIEMPO PARA QUE JUGADOR 1 ESCONDA LOS TESOROS");
	//setTesorosJugador(jugador1);
	//dibujarTablero(jugador1);
	//std::cin.get();
	//separador("TIEMPO PARA QUE JUGADOR 2 ESCONDA LOS TESOROS");
	//setTesorosJugador(jugador2);
	//dibujarTablero(jugador2);

	/// JUEGO
	bool seguir = true;
	int turno = 1;
	while (seguir) {
		separador("TURNO JUGADOR 1");
		setEspiaJugador(jugador1, jugador2);
		moverTesoro(jugador1, jugador2);
		std::cin.get();
		dibujarTablero(jugador1);
		imprimirTablero(jugador1,to_string(turno, "Jugador-1-Turno-"));
		decrementaTurnos(jugador1,jugador2);

		if (cuentaTesoros(jugador2) == 0) {
			seguir = false;
			separador("EL JUGADOR 1 HA GANADO LA PARTIDA!!! FELICITACIONES");
		} else {
			std::cin.get();
			separador("TURNO JUGADOR 2");
			std::cin.get();
			setEspiaJugador(jugador2, jugador1);
			moverTesoro(jugador2, jugador1);
			std::cin.get();
			dibujarTablero(jugador2);
			imprimirTablero(jugador2,to_string(turno, "Jugador-2-Turno"));
			decrementaTurnos(jugador2,jugador1);

			if (cuentaTesoros(jugador1) == 0) {
				seguir = false;
				separador("EL JUGADOR 2 HA GANADO LA PARTIDA!!! FELICITACIONES");
			}
		}
	}
	return 0;
}

