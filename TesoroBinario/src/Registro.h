
#ifndef SRC_REGISTRO_H_
#define SRC_REGISTRO_H_

typedef struct {
	bool tesoro;
	bool espia;
	short int turnosInactivos;
}Registro;

/*
 * Setea tesoro en el registro dado
 */
void setTesoro(Registro &registro);
/*
 * Borra un tesoro de un registro
 */
void borrarTesoro(Registro &registro);
/*
 * Setea espía en el registro dado
 */
void setEspia(Registro &registro);
/*
 * Borra un espia de un registro
 */
void borrarEspia(Registro &registro);
/*
 * Decrementa turno una vez que el espia encuentra el tesoro, devolviendo true
 * si pudo, y false si el turno ya esta en cero
 */
bool decrementarTurno(Registro &registro);
/*
 * Hace un delete del registro
 */
void borrarRegistro(Registro registro);
/*
 * Inicializa el registro con valores estandard
 */
Registro * inicializarRegistro();


#endif /* SRC_REGISTRO_H_ */
