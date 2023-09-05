
#include "interacciones.h"
#include "reglas.h"
#include "constantes.h"


int main() {

	mostrarBienvenida();

	int vidasRestantes = VIDAS;
	const std::string palabraSecreta = "otorrinolaringologo";
	std::string palabraDescubierta = ocultar(palabraSecreta);

	while (sigueJugando(vidasRestantes, palabraDescubierta, palabraSecreta)) {

		mostrarAhorcado(palabraDescubierta, vidasRestantes);

		char letraArriesgada = arriesgarLetra();

		int ocurrencias = descubrir(letraArriesgada, palabraDescubierta,
				palabraSecreta);

		actualizar(vidasRestantes, ocurrencias, letraArriesgada);
	}

	mostrarResultado(vidasRestantes);

	return 0;
}


