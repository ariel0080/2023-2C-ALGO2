#include <string>
#include <iostream>
#include "Tablero.h"
#include "Graficos.h"
#include "Registro.h"

int main() {



	Tablero * jugador1 = inicializarTablero(20,20);
	Registro r = getRegistro(jugador1, 10,10);
	Registro j = getRegistro(jugador1, 10,11);
	setTesoro(jugador1->matriz[2][2]);
	std::cout << r.turnosInactivos << std::endl;
	std::cout << r.tesoro << std::endl;
	std::cout << j.tesoro << std::endl;
	std::cout << cuentaTesoros(jugador1) << std::endl;
	dibujarTablero();



	return 0;
}



