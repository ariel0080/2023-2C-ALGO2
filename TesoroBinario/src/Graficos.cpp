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

void dibujarMargenInferior() {
	std::cout << M34;
	for (int i = 1; i < 19; i++) {
		std::cout << M35;
	}
	std::cout << M36 << std::endl;
}

// METODO PRINCIPAL

void dibujarTablero(Tablero *tablero) {

	dibujarMargenSuperior();
	dibujarCelda(tablero);
	dibujarMargenInferior();
}

// DIBUJANDO EL CUERPO DE LA CELDA

void dibujarCelda(Tablero *tablero) {
	for (int K = 0; K < tablero->alto - 1; K++) { // COLUMNAS
		for (int i = 0; i < tablero->ancho - 1; i++) { //FILAS
			if (getRegistro(tablero, i, K).tesoro) {
				std::cout << M21;
			} else {
				std::cout << M23;
			}

		}
		if (getRegistro(tablero, tablero->ancho-1, K).tesoro) {
						std::cout << M25 << std::endl;
					} else {
						std::cout << M24 << std::endl;
					}

		for (int i = 0; i < tablero->ancho - 1; i++) { // FILAS
			if (getRegistro(tablero, i, K).espia) {
				std::cout << M22;
			} else {
				std::cout << M23;
			}

		}
		if (getRegistro(tablero, tablero->ancho -1, K).espia){
			std::cout << M26 << std::endl;
		}else{
			std::cout << M24 << std::endl;
		}

		std::cout << M31;
		for (int i = 1; i < tablero->ancho - 1; i++) { //FILAS
			std::cout << M32;
		}
		std::cout << M33 << std::endl;

	}

	for (int i = 0; i < tablero->ancho - 1; i++) { // FILAS
		if (getRegistro(tablero, tablero->ancho -1, tablero->alto-1).tesoro){
			std::cout << M21;
		}
		else{
			std::cout << M23;
		}
	}
	if (getRegistro(tablero, tablero->ancho -1, tablero->alto-1).tesoro){
		std::cout << M25 << std::endl;
	}else{
		std::cout << M24 << std::endl;
	}


	for (int i = 0; i < tablero->ancho - 1; i++) { //FILAS
		if (getRegistro(tablero, tablero->ancho -1, tablero->alto-1).espia){
			std::cout << M22;
		}
		else{
			std::cout << M23;
		}
	}
	if (getRegistro(tablero, tablero->ancho -1, tablero->alto-1).espia){
		std::cout << M26 << std::endl;
	}
	else{
		std::cout << M24 << std::endl;
	}

}
/* metodos a borrar
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
 }*/

