#include <string>
#include <iostream>
#include "Tablero.h"
#include "Registro.h"

Tablero* inicializarTablero(int filas, int columnas) {
	Registro **punteroMatriz;
	Tablero *tablero = new Tablero();
	tablero->alto = filas;
	tablero->ancho = columnas;

	punteroMatriz = new Registro*[filas];
	for (int nFilas = 0; nFilas < filas; nFilas++) {
		punteroMatriz[nFilas] = new Registro[columnas];
	}

	for (int nFilas = 0; nFilas < filas; nFilas++) {
		for (int nCol = 0; nCol < columnas; nCol++) {
			punteroMatriz[nFilas][nCol] = *inicializarRegistro();
		}
	}
	tablero->matriz = punteroMatriz;
	return tablero;
}

Registro getRegistro(Tablero *tablero, int fila, int columna) {
	return tablero->matriz[fila][columna];
}

int cuentaTesoros(Tablero * tablero){
	int cantidadTesoros = 0;
	for(int i = 0;i < tablero->alto;i++){
		for(int j = 0;j < tablero->ancho;j++){
			bool tesoro =tablero->matriz[i][j].tesoro;
			if(tesoro){
				cantidadTesoros++;
			}
		}
	}
	return cantidadTesoros;
}

void borrarTablero(Tablero *tablero) {

	for (int i = 0; i < tablero->alto; i++) {
		delete[] tablero->matriz[i];
	}

	delete[] tablero->matriz;
	delete tablero;

}
