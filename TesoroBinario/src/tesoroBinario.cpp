#include <string>
#include <iostream>
#include "Tablero.h"
#include "Graficos.h"
#include "Registro.h"
#include "Usuario.h"

int main() {


	presentacion();
	Tablero * jugador1 = inicializarTablero(20,20);
	setTesoro(jugador1->matriz[2][2]);
	std::cout << cuentaTesoros(jugador1) << std::endl;
	dibujarTablero(jugador1);


	return 0;
}



