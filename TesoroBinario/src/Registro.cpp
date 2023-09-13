#include "Registro.h"


void setTesoro(Registro &registro){
	registro.tesoro = true;
}

void borrarTesoro(Registro &registro){
	registro.tesoro = false;
}

void setEspia(Registro &registro){
	registro.espia = true;
}

void borrarEspia(Registro &registro){
	registro.espia = false;
}

bool decrementarTurno(Registro &registro){
	bool resultado;
	if(registro.turnosInactivos == 0){
		resultado = false;
	}
	if(registro.turnosInactivos > 0){
		registro.turnosInactivos--;
		resultado = true;
	}
	return resultado;
}

void borrarRegistro(Registro * registro){
	delete registro;
}

Registro * inicializarRegistro(){
	Registro * registro = new Registro();
	registro->espia = false;
	registro->tesoro = false;
	registro->turnosInactivos = 5;
	return registro;
}

