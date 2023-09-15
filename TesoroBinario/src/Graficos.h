

#ifndef SRC_GRAFICOS_H_
#define SRC_GRAFICOS_H_

//===Color font code===/
#define GREEN   "\x1b[32m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define RESET   "\x1b[0m"


#include <string>
#include "Tablero.h"

//Constantes para dibujo del tablero

const static std::string M11 = "╔═════";
const static std::string M12 = "╦═════";
const static std::string M13 = "╦═════╗";
const static std::string M21 = "║ \x1B[38;2;17;245;120mTES \x1b[0m";
const static std::string M22 = "║ \x1b[33mESP \x1b[0m";
const static std::string M23 = "║     ";
const static std::string M24 = "║     ║";
const static std::string M25 = "║ \x1B[38;2;17;245;120mTES \x1b[0m║";
const static std::string M26 = "║ \x1b[33mESP \x1b[0m║";
const static std::string M31 = "╠═════";
const static std::string M32 = "╬═════";
const static std::string M33 = "╬═════╣";
const static std::string M34 = "╚═════";
const static std::string M35 = "╩═════";
const static std::string M36 = "╩═════╝";
/*
 * Dibuja la parte superior del tablero
 */
void dibujarMargenSuperior();
/*
 * Dibuja el cuerpo de cada celda
 */
void dibujarCuerpoCelda();
/*
 * Dibujar el borde inferior de la celda
 */
void dibujarBordeInferior();
/*
 * Dibujar la parte inferior del tablero
 */
void dibujarMargenInferior();
/*
 * Dibuja Tablero de juego
 */
void dibujarTablero(Tablero * tablero);

/*
 * Dibuja el cuerpo de la celda, mostrando espias y tesoros de corresponder
 */
void dibujarCelda(Tablero * tablero);


#endif /* SRC_GRAFICOS_H_ */
