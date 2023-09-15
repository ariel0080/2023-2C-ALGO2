#include <iostream>
#include <string>
#include "Usuario.h"
#include "Graficos.h"
#include "Tablero.h"

void presentacion() {
	std::cout << s1 << std::endl << s2 << std::endl << s1 << std::endl
			<< std::endl;
	std::cout << s1 << std::endl << s3 << std::endl << s1 << std::endl
			<< std::endl;
}

int* solicitarPosicion(int i, char tipo) {
	int *xy;
	int posicion[2];
	if (tipo == 'T' && i != 0) {
		std::cout << "Por favor ingrese coordenada del Tesoro " << i
				<< std::endl;
	}
	if (tipo == 'T' && i == 0) {
		std::cout << "Por favor ingrese coordenada del Tesoro " << std::endl;
	}
	if (tipo == 'E') {
		std::cout << "Por favor ingrese coordenada del Espia: " << std::endl;
	}

	std::cout << "Fila(1-20): ";
	std::cin >> posicion[1];
	std::cout << "Columna(1-20): ";
	std::cin >> posicion[0];
	posicion[0]--;
	posicion[1]--;
	xy = posicion;
	return xy;
}

void setTesorosJugador(Tablero *tablero) {
	for (int tesoros = 1; tesoros < 5; tesoros++) {
		int *coordenadas = solicitarPosicion(tesoros, 'T');
		while (tablero->matriz[coordenadas[0]][coordenadas[1]].tesoro) {
			std::cout << std::endl << "YA EXISTE UN TESORO EN ESA COORDENADA"
					<< std::endl;
			coordenadas = solicitarPosicion(tesoros, 'T');
		}

		setTesoro(tablero->matriz[coordenadas[0]][coordenadas[1]]);
	}
}

void separador(std::string mensaje) {
	std::cout << GREEN << s1 << std::endl << RESET;
	std::cout << LGREEN << "->  " << mensaje << std::endl;
	std::cout << GREEN << s1 << std::endl << RESET;
}

void setEspiaJugador(Tablero *propio, Tablero *ajeno) {
	int *coordenadas = solicitarPosicion(0, 'E');

	int fil = coordenadas[0];
	int col = coordenadas[1];

	Registro *reg = &propio->matriz[coordenadas[0]][coordenadas[1]];
	while (reg->bloqueada) {
		std::cout << std::endl << "Casilla bloqueada por "
				<< reg->turnosInactivos << " turnos"
				<< "No puede acceder a ella, favor de intentarlo de nuevo"
				<< std::endl;

		coordenadas = solicitarPosicion(0, 'E');
		fil = coordenadas[0];
		col = coordenadas[1];
		reg = &propio->matriz[fil][col];
	}

	Registro *reg2 = &ajeno->matriz[fil][col];

	if (reg2->espia && !reg->bloqueada) {
		borrarEspia(*reg2);
		std::cout << std::endl
				<< "Encontraste un espia del otro jugador, ambos espias han sido eliminados"
				<< std::endl;
	} else {
		setEspia(propio->matriz[fil][col]);
		if (ajeno->matriz[fil][col].tesoro) {
			std::cout
					<< "HAS CAPTURADO UN TESORO CONTRARIO! - CASILLA BLOQUEADA POR 5 TURNOS"
					<< std::endl;
		}
	}

	if (reg2->tesoro && !reg2->bloqueada) {
		block(propio->matriz[fil][col]);
		block(ajeno->matriz[fil][col]);
	}
}

void moverTesoro(Tablero *propio, Tablero *ajeno) {
	char respuesta;
	int fil, col = 0;
	std::cout << std::endl << "Desea mover un tesoro (s/n)?: ";
	std::cin >> respuesta;
	if (respuesta == 's' || respuesta == 'S') {
		std::cout << std::endl << "POSICION ACTUAL " << std::endl;

		int *coordenadas = solicitarPosicion(0, 'T');
		fil = coordenadas[0];
		col = coordenadas[1];

		Registro reg = getRegistro(propio, fil, col);

		while (isBlock(reg) || reg.tesoro == false) {
			if (isBlock(reg)) {
				std::cout << std::endl << "Casilla bloqueada por "
						<< reg.turnosInactivos << " turnos" << std::endl;
			}

			if (reg.tesoro == false) {
				std::cout << std::endl
						<< "NO HAY UN TESORO PROPIO EN ESA POSICION"
						<< std::endl;
			}

			coordenadas = solicitarPosicion(0, 'T');
			fil = coordenadas[0];
			col = coordenadas[1];
			std::cout << fil << "-----" << col << std::endl; ////////sdsdsdsdddddddddddddddddddddddddddddddddddddddddddddddddd
			reg = getRegistro(propio, fil, col);
		}

		borrarTesoro(propio->matriz[fil][col]);

		std::cout << std::endl << "NUEVA POSICION " << std::endl;

		coordenadas = solicitarPosicion(0, 'T');
		fil = coordenadas[0];
		col = coordenadas[1];
		std::cout << fil << "-----" << col << std::endl; ////////sdsdsdsdddddddddddddddddddddddddddddddddddddddddddddddddd
		Registro reg2 = getRegistro(propio, fil, col);

		while (isBlock(reg2)) {
			std::cout << std::endl << "Casilla bloqueada por "
					<< reg2.turnosInactivos << " turnos" << std::endl;

			coordenadas = solicitarPosicion(0, 'T');
			fil = coordenadas[0];
			col = coordenadas[1];

			reg2 = getRegistro(propio, fil, col);
		}

		setTesoro(propio->matriz[fil][col]);
		Registro regAjeno = getRegistro(ajeno, fil,
				col);
		if (regAjeno.tesoro) {
			std::cout << std::endl << "ATENCION! TESORO ADVERSARIO EN FILA "
					<< fil << " COLUMNA " << col
					<< std::endl;
		}
		if (regAjeno.espia) {
			std::cout << std::endl
					<< "ATENCION! UN ESPIA ADVERSARIO HA CAPTURADO TU TESORO "
					<< std::endl;
			block(propio->matriz[fil][col]);

			block(ajeno->matriz[fil][col]);
		}
	}
}

