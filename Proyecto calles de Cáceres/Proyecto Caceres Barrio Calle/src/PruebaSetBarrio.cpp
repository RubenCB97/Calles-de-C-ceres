/*
 * PruebaSetBarrio.cpp
 *
 *  Created on: 23 mar. 2019
 *      Author: ruben
 */

#include "PruebaSetBarrio.h"

void pruebasSetBarrio() {
	cout << " Inicio de las pruebas de SetBarrio" << endl;
	SetBarrio setBarrio[200];
	BarrioClase *b, *b2, *baux;

	b = new BarrioClase("Canovas", 117.72, 178, 12, "Centro");
	b2 = new BarrioClase("El Vivero", 159960.55, 2129.98, 29, "oeste");

	setBarrio->insertarBarrio(b);
	setBarrio->insertarBarrio(b2);

	if (setBarrio->numElementosBarrio() == 0) {
		cout << "Error en numElementosBarrio y Error en insertar" << endl;

	}
	if (setBarrio->existeBarrio(12) != true) {
		cout << "Error en existeBarrio" << endl;
	}

	if (setBarrio->estaVaciaBarrio() != false) {
		cout << "Error en estaVaciaBarrio" << endl;
	}
	setBarrio->getBarrio(0, baux);
	if (baux->getNombre() != "Canovas") {
		cout << "Error en getBarrio" << endl;
	}
	setBarrio->getBarrioClave(29, baux);
	if (baux->getNombre() != "El Vivero") {
		cout << "Error en getBarrioClave" << endl;
	}
	setBarrio->eliminarBarrio(29);
	if (setBarrio->existeBarrio(29) != false) {
		cout << "Error en eliminarBarrio" << endl;
	}

	cout << " Fin de las pruebas de SetBarrio" << endl;
}
