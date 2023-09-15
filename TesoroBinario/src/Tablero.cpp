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

Registro  getRegistro(Tablero *tablero, int fila, int columna) {
	return tablero->matriz[fila][columna];
}

int cuentaTesoros(Tablero * tablero) {
	int cantidadTesoros = 0;
	for(int i = 0;i < tablero->alto;i++){
		for(int j = 0;j < tablero->ancho;j++){
			bool tesoro =tablero->matriz[i][j].tesoro;
			if(tesoro && !isBlock(tablero->matriz[i][j])){
				cantidadTesoros++;
			}
		}
	}
	return cantidadTesoros;
}

void decrementaTurnos(Tablero * propio, Tablero *ajeno) {
	for(int i = 0;i < propio->alto;i++){
		for(int j = 0;j < propio->ancho;j++){
			if(propio->matriz[i][j].bloqueada && propio->matriz[i][j].turnosInactivos > 0){
				propio->matriz[i][j].turnosInactivos--;
				ajeno->matriz[i][j].turnosInactivos--;
			}
			if(propio->matriz[i][j].bloqueada && propio->matriz[i][j].turnosInactivos == 0){
				if(propio->matriz[i][j].espia){
					borrarTesoro(ajeno->matriz[i][j]);
				}
				if(ajeno->matriz[i][j].espia){
					borrarTesoro(propio->matriz[i][j]);
				}

				unBlock(propio->matriz[i][j]);
				unBlock(ajeno->matriz[i][j]);
			}
		}
	}
}

void borrarTablero(Tablero *tablero) {

	for (int i = 0; i < tablero->alto; i++) {
		delete[] tablero->matriz[i];
	}

	delete[] tablero->matriz;
	delete tablero;

}
