#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

#include "Registro.h"

/*
 * Estructura Tablero
 */
typedef struct {
	Registro **matriz;
	int alto;
	int ancho;
} Tablero;

/*
 * Inicializa el tablero para poder comenzar el juego
 */
Tablero * inicializarTablero(int filas, int columnas);
/*
 * Elimina de la memoria el tablero pasado por parámetro
 */
void borrarTablero(Tablero *tablero);
/*
 * Obtiene el registro de un tablero para una coordenada dada
 */
Registro getRegistro(Tablero * tablero, int ancho, int largo);
/*
 * Cuenta la cantidad de tesoros que hay en el tablero
 */
int cuentaTesoros(Tablero * tablero);
#endif /* SRC_TABLERO_H_ */
