/*
 * SetBarrio.h
 *
 *  Created on: 20 mar. 2019
 *      Author: ruben
 */

#ifndef SETBARRIO_H_
#define SETBARRIO_H_
#include "BarrioClase.h"

using namespace std;
const int MAX = 1300;

class SetBarrio {

private:
	BarrioClase *setBarrio[MAX];
	int cont;

public:
	SetBarrio();
	//PRE: Tener iniciado los barrios.
	//POST: Devuelve si esta vacio o no el conjunto de barrio.
	//Complejidad:O(1).
	bool estaVaciaBarrio();

	//PRE:	Tener iniciado los barrios.
	//POST:	Deuelve el numero de barrios que hay en el conjunto.
	//Complejidad:O(1).
	int numElementosBarrio();

	//PRE:	Tener iniciado los barrios.
	//POST:	Inserta un nuevo barrio en el conjunto.
	//Complejidad:O(n²)
	void insertarBarrio(BarrioClase *b);

	//PRE:Tener iniciado los barrios,clave>0.
	//POST:	Devuelve si existe un barrio o no segun la clave introducida.
	//Complejidad:O(n)
	bool existeBarrio(int clave);

	//PRE:Tener iniciado los barrios,pos>=0.
	//POST:	Devuelve un barrio segun la posicion.
	//Complejidad:O(1)

	void getBarrio(int pos, BarrioClase *&b);

	//PRE:Tener iniciado los barrios,clave >0.
	//POST: Devuelve un barrio segun la clave.
	//Complejidad:O(n)
	void getBarrioClave(int clave, BarrioClase *&b);

	//PRE:Tener iniciado los barrios, clave>0.
	//POST: Elimina un barrio.
	//Complejidad:O(n²)
	void eliminarBarrio(int clave);

	~SetBarrio();
};

#endif /* SETBARRIO_H_ */
