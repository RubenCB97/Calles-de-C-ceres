/*
 * SetBarrio.cpp
 *
 *  Created on: 20 mar. 2019
 *      Author: ruben
 */

#include "SetBarrio.h"

SetBarrio::SetBarrio() {
	cont = 0;
}

bool SetBarrio::estaVaciaBarrio() {
	if (cont == 0) {
		return true;
	}
	return false;
}

int SetBarrio::numElementosBarrio() {
	return cont;
}

void SetBarrio::insertarBarrio(BarrioClase* b) {
	int i = 0, j;
	bool enc = false;

	while (i < cont && !enc) {
		if (setBarrio[i]->getNombre() > b->getNombre()) {
			enc = true;

		} else {
			i++;
		}
	}
	if (enc) {
		for (j = cont; j > i; j--) {
			setBarrio[j] = setBarrio[j - 1];

		}
	}
	setBarrio[i] = b;
	cont++;
}

bool SetBarrio::existeBarrio(int clave) {
	bool bandera = false;
	for (int i = 0; i < cont && bandera == false; i++) {
		if (clave == setBarrio[i]->getCodigo()) {
			bandera = true;
		}

	}
	return bandera;
}

void SetBarrio::getBarrio(int pos, BarrioClase*& b) {
	if (setBarrio[pos] != NULL) {

		b = setBarrio[pos];

	}
}

void SetBarrio::getBarrioClave(int clave, BarrioClase*& b) {
	bool bandera = false;
	for (int i = 0; i < cont && bandera == false; i++) {
		if (clave == setBarrio[i]->getCodigo()) {
			b = setBarrio[i];
			bandera = true;

		}
	}
}

void SetBarrio::eliminarBarrio(int clave) {
	int acumulador = 0;
	for (int i = 0; i < cont; i++) {
		if (clave == setBarrio[i]->getCodigo()) {
			acumulador++;

		} else {
			setBarrio[i - 1] = setBarrio[i];
		}

	}
	cont = cont - acumulador;

}

SetBarrio::~SetBarrio() {
	for (int i = 0; i < cont; i++) {

		delete setBarrio[i];
	}
}

