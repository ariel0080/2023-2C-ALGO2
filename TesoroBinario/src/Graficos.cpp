#include "Graficos.h"
#include "Tablero.h"
#include <iostream>

void dibujarMargenSuperior() {
	std::cout << M11;
	for (int i = 1; i < 19; i++) {
		std::cout << M12;
	}
	std::cout << M13 << std::endl;
}
void dibujarCuerpoCelda() {
	for (int i = 0; i < 19; i++) {
		std::cout << M23;
	}
	std::cout << M24 << std::endl;

	for (int i = 0; i < 19; i++) {
		std::cout << M23;
	}
	std::cout << M24 << std::endl;
}
void dibujarBordeInferior() {
	std::cout << M31;
	for (int i = 1; i < 19; i++) {
		std::cout << M32;
	}
	std::cout << M33 << std::endl;
}
void dibujarMargenInferior() {
	std::cout << M34;
	for (int i = 1; i < 19; i++) {
		std::cout << M35;
	}
	std::cout << M36 << std::endl;
}
void dibujarTablero() {


	dibujarMargenSuperior();
	dibujarCelda();
	dibujarMargenInferior();
}

void dibujarCelda(){
	for (int i = 0; i < 20 - 1; i++) {
			dibujarCuerpoCelda();
			dibujarBordeInferior();
		}
		dibujarCuerpoCelda();
}
