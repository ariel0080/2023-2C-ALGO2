
#ifndef SRC_USUARIO_H_
#define SRC_USUARIO_H_

const static std::string s1 =
		"###############################################################";
const static std::string s2 =
		"##############BIENVENIDOS AL JUEGO TESORO BINARIO##############";
const static std::string s3 =
		"#################ALUMNO: ARIEL EDUARDO BRIÑOLI#################";

#include "Tablero.h"

/*
 * Muestra prsentacion en pantalla
 */
void presentacion();
/*
 * Solicita las coordenadas de tesoro o espia
 */
int* solicitarPosicion(int i, char tipo);
/*
 * Setea los 4 tesoros de cada jugador al iniciar la partida
 */
void setTesorosJugador(Tablero *tablero);
/*
 * Muestra mensaje por pantalla
 */
void separador(std::string mensaje);
/*
 * Setea espia
 */
void setEspiaJugador(Tablero *tablero1, Tablero *tablero2);
/*
 * Mueve tesoro dentro del tablero
 */
void moverTesoro(Tablero *tablero1, Tablero *tablero2);
/*
 * Seteo inicial de tesoros y tablero para el jugador
 */
void cargaInicialJugador(Tablero *jugador, std::string nombreArchivoInicial);
/*
 * Desarrollo del juego Tesoro Binario
 */
void Juego(Tablero *jugador1, Tablero *jugador2);

#endif /* SRC_USUARIO_H_ */
