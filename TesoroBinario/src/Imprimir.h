

#ifndef SRC_IMPRIMIR_H_
#define SRC_IMPRIMIR_H_


#include <string>
#include "Tablero.h"

//Constantes para dibujo del tablero

const static std::string I11 = "╔═════";
const static std::string I12 = "╦═════";
const static std::string I13 = "╦═════╗";
const static std::string I21 = "║ TES ";
const static std::string I22 = "║ ESP ";
const static std::string I23 = "║     ";
const static std::string I24 = "║     ║";
const static std::string I25 = "║ TES ║";
const static std::string I26 = "║ ESP ║";
const static std::string I31 = "╠═════";
const static std::string I32 = "╬═════";
const static std::string I33 = "╬═════╣";
const static std::string I34 = "╚═════";
const static std::string I35 = "╩═════";
const static std::string I36 = "╩═════╝";
/*
 * Dibuja la parte superior del tablero
 */
void imprimirMargenSuperior(std::ofstream &archivo);

/*
 * imprimir la parte inferior del tablero
 */
void imprimirMargenInferior(std::ofstream &archivo);
/*
 * Dibuja Tablero de juego
 */
void imprimirTablero(Tablero * tablero, std::string nombreArch);

/*
 * Dibuja el cuerpo de la celda, mostrando espias y tesoros de corresponder
 */
void imprimirCelda(Tablero * tablero, std::ofstream &archivo);

/*
 * Convierne int a string
 */
std::string to_string(int valor, std::string nombreArchivo);


#endif /* SRC_IMPRIMIR_H_ */
