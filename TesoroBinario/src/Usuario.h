

#ifndef SRC_USUARIO_H_
#define SRC_USUARIO_H_

#define s1 "###############################################################"
#define s2 "##############BIENVENIDOS AL JUEGO TESORO BINARIO##############"
#define s3 "#################ALUMNO: ARIEL EDUARDO BRIÑOLI#################"

#include "Tablero.h"

/*
 * Muestra prsentacion en pantalla
 */
void presentacion();
/*
 * Solicita las coordenadas de tesoro o espia
 */
int * solicitarPosicion(int i, char tipo);
/*
 * Setea los 4 tesoros de cada jugador al iniciar la partida
 */
void setTesorosJugador(Tablero * tablero);
/*
 * Muestra mensaje por pantalla
 */
void separador(std::string mensaje);
/*
 * Setea espia
 */
void setEspiaJugador(Tablero * tablero1, Tablero * tablero2);
/*
 * Mueve tesoro dentro del tablero
 */
void moverTesoro(Tablero * tablero1, Tablero * tablero2);

#endif /* SRC_USUARIO_H_ */
