#include "Imprimir.h"
#include "Tablero.h"
#include <iostream>
#include <fstream>
#include <sstream>

void imprimirMargenSuperior(std::ofstream &archivo) {

	archivo << I11;
	for (int i = 1; i < 19; i++) {
		archivo << I12;
	}
	archivo << I13 << std::endl;
}

void imprimirMargenInferior(std::ofstream &archivo) {
	archivo << I34;
	for (int i = 1; i < 19; i++) {
		archivo << I35;
	}
	archivo << I36 << std::endl;
}

// DIBUJANDO EL CUERPO DE LA CELDA

void imprimirCelda(Tablero *tablero, std::ofstream &archivo ) {
	for (int K = 0; K < tablero->alto - 1; K++) { // COLUMNAS
		for (int i = 0; i < tablero->ancho - 1; i++) { //FILAS
			if (getRegistro(tablero, i, K).tesoro) {
				archivo << I21;
			} else {
				archivo << I23;
			}

		}
		if (getRegistro(tablero, tablero->ancho-1, K).tesoro) {
						archivo << I25 << std::endl;
					} else {
						archivo << I24 << std::endl;
					}

		for (int i = 0; i < tablero->ancho - 1; i++) { // FILAS
			if (getRegistro(tablero, i, K).espia) {
				archivo << I22;
			} else {
				archivo << I23;
			}

		}
		if (getRegistro(tablero, tablero->ancho -1, K).espia){
			archivo << I26 << std::endl;
		}else{
			archivo << I24 << std::endl;
		}

		archivo << I31;
		for (int i = 1; i < tablero->ancho - 1; i++) { //FILAS
			archivo << I32;
		}
		archivo << I33 << std::endl;

	}

	for (int i = 0; i < tablero->ancho - 1; i++) { // FILAS
		if (getRegistro(tablero, i, tablero->alto-1).tesoro){
			archivo << I21;
		}
		else{
			archivo << I23;
		}
	}
	if (getRegistro(tablero, tablero->ancho -1, tablero->alto-1).tesoro){
		archivo << I25 << std::endl;
	}else{
		archivo << I24 << std::endl;
	}


	for (int i = 0; i < tablero->ancho - 1; i++) { //FILAS
		if (getRegistro(tablero, i, tablero->alto-1).espia){
			archivo << I22;
		}
		else{
			archivo << I23;
		}
	}
	if (getRegistro(tablero, tablero->ancho -1, tablero->alto-1).espia){
		archivo << I26 << std::endl;
	}
	else{
		archivo << I24 << std::endl;
	}

}

// METODO PRINCIPAL

void imprimirTablero(Tablero *tablero, std::string nombreArch ) {

	std::ofstream archivo;

	archivo.open(nombreArch.c_str(),std::fstream::out);

	imprimirMargenSuperior(archivo);
	imprimirCelda(tablero,archivo);
	imprimirMargenInferior(archivo);

	archivo.close();
}

std::string to_string(int valor, std::string nombreArchivo){
	std::stringstream turno_s;
	std::string valor_s;
	turno_s << valor;
	turno_s >> valor_s;
	std::string nombreArch = nombreArchivo;
	nombreArch.append(valor_s).append(".txt");
	return nombreArch;
}
