#ifndef SRC_INTERACCIONES_H_
#define SRC_INTERACCIONES_H_


#include <string>

/*
 * Indica el incio del programa
 */
void mostrarBienvenida();
/*
 * Describe el estado del juego
 */
void mostrarAhorcado(std::string descubierta, int vidasRestantes);
/*
 * Solicita al usuario una letra y devuelve la letra que arriesgada
 */
char arriesgarLetra();

/*
 * Indica al usuario que la letra no esta en la palabra secreta
 */
void mostrarQueNoContiene(char letra);

/*
 * Indica al usuario cómo finalizó el juego
 */
void mostrarResultado(int vidasRestantes);



#endif /* SRC_INTERACCIONES_H_ */
