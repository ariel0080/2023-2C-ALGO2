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


void borrarRegistro(Registro * registro){
	delete registro;
}

bool isBlock(Registro  &registro){
	return registro.bloqueada;
}

void block(Registro  &registro){
	registro.bloqueada = true;
}

void unBlock(Registro  &registro){
	registro.bloqueada = false;
}

Registro * inicializarRegistro(){
	Registro * registro = new Registro();
	registro->espia = false;
	registro->tesoro = false;
	registro->turnosInactivos = 5;
	registro->bloqueada = false;
	return registro;
}

