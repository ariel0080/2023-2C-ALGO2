

#ifndef SRC_GRAFICOS_H_
#define SRC_GRAFICOS_H_

//===Color font code===/
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"
//===Color background code===/
#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN    "\x1B[46m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_LGREEN  "\x1B[48;2;17;245;120m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define BG_ROSE    "\x1B[48;2;255;151;203m"

#include <string>
#include "Tablero.h"

//Constantes para dibujo del tablero

const static std::string M11 = "╔═════";
const static std::string M12 = "╦═════";
const static std::string M13 = "╦═════╗";
const static std::string M21 = "║ TES ";
const static std::string M22 = "║ ESP ";
const static std::string M23 = "║     ";
const static std::string M24 = "║     ║";
const static std::string M25 = "║ TES ║";
const static std::string M26 = "║ ESP ║";
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
void dibujarTablero();//Tablero *tablero);

void dibujarCelda();


#endif /* SRC_GRAFICOS_H_ */
