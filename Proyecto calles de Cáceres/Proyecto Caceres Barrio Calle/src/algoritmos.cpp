/*
 * Algoritmos.cpp
 *
 *  Created on: 02/03/2019
 *      Author: Profesores de EDI
 */

#include <fstream>
#include <iostream>

#include "algoritmos.h"

using namespace std;

// MAIN function
int main() {
//	pruebasGeneral();
	Algoritmos Algoritmos;
}

// ******************** PRIVATE OPERATIONS ********************

void Algoritmos::run() {
	cout << "Empieza run" << endl;
	Arbol<BarrioVia*, CompararBarrio>* aux;
	aux = new Arbol<BarrioVia*, CompararBarrio>;

	string nombre = "Gredos";
	string especie = "Celtis_australis";
	string genero = "PLATANUS";
	string subcadena = "C";


	//mostrarBarrios();

	algoritmo1(nombre);
	algoritmo2(especie);
	algoritmo3(genero,aux);
	algoritmo4(subcadena);

	delete aux;

}

void Algoritmos::cargarDatos() {
	BarrioClase *b;
	string cadBarrio[5];
	ifstream fentBarrio;
	int i;

	//Cargar Barrios
	fentBarrio.open("Barrio.csv");
	if (fentBarrio.is_open()) {
		getline(fentBarrio, cadBarrio[0]);
		while (!fentBarrio.eof()) {
			for (i = 0; i < 4; i++) {
				getline(fentBarrio, cadBarrio[i], ';');
			}
			getline(fentBarrio, cadBarrio[4]);
			if (!fentBarrio.eof()) {
				b = new BarrioClase(cadBarrio[0], atof(cadBarrio[1].c_str()),
						atof(cadBarrio[2].c_str()), atoi(cadBarrio[3].c_str()),
						cadBarrio[4]);
				cjtoBarrios->insertarBarrio(b);

			}

		}

	}

	fentBarrio.close();
	cout << "Barrios Cargados" << endl;

	//Cargar Vias
	Via *v;
	string cadVia[5];

	ifstream fentVia;
	fentVia.open("Via.csv");
	if (fentVia.is_open()) {
		getline(fentVia, cadVia[0]);
		while (!fentVia.eof()) {
			for (i = 0; i < 4; i++) {
				getline(fentVia, cadVia[i], ';');
			}
			getline(fentVia, cadVia[4]);
			cjtoBarrios->getBarrioClave(atoi(cadVia[0].c_str()), b);
			v = new Via(atoi(cadVia[0].c_str()), cadVia[1],
					atof(cadVia[2].c_str()), cadVia[3],
					atoi(cadVia[4].c_str()));

			b->insertarVia(v);

		}

	}
	fentVia.close();
	cout << "Vias Cargadas" << endl;



	//Cargar Arboles
	Arboles *a;
	string cadArbol[10];
	ifstream fentArb;
	fentArb.open("Arbol.csv");
	if (fentArb.is_open()) {
		getline(fentArb, cadArbol[0]);
		while (!fentArb.eof()) {
			for (i = 0; i < 9; i++) {
				getline(fentArb, cadArbol[i], ';');
			}
			getline(fentArb, cadArbol[9]);
			if (!fentArb.eof()) {

				a = new Arboles(cadArbol[0], cadArbol[1], cadArbol[2],
						cadArbol[3], atof(cadArbol[4].c_str()),
						atof(cadArbol[5].c_str()), atof(cadArbol[6].c_str()),
						cadArbol[7], atoi(cadArbol[8].c_str()),
						atoi(cadArbol[9].c_str()));

				if (buscarViaBarrio(atoi(cadArbol[9].c_str()), v) == true) {

					v->insertarArbol(a);
				}
			}
		}

	}

	fentArb.close();

	cout << "Arboles Cargados" << endl;

}

// ******************** PUBLIC INTERFACE ********************

Algoritmos::Algoritmos() {

	cout << "Programming Project v3.00 (EDI)." << endl;
	cout << "           Author: Rubén Costa Barriga y Óscar Flores Gil." << endl;
	cout << "           Date:   June 3, 2019." << endl;

	cjtoBarrios = new SetBarrio();
	this->cargarDatos();
	this->run();
}

// Algoritmo para la introduccion de los arboles

bool Algoritmos::buscarViaBarrio(int codigo, Via *&v) {
	BarrioClase *b;

	bool bandera = false;
	for (int i = 0; i < cjtoBarrios->numElementosBarrio() && !bandera; i++) {
		cjtoBarrios->getBarrio(i, b);
		if (b->buscarCodigoVia(codigo, v) == true) {

			bandera = true;
		}
	}
	return bandera;

}

void Algoritmos::mostrarBarrios() {
	BarrioClase *b;


	for (int i = 0; i < cjtoBarrios->numElementosBarrio(); i++) {
		cjtoBarrios->getBarrio(i, b);

		b->mostrar();
	}
}

void Algoritmos::algoritmo1(string nombre) {
	BarrioClase *b;
	Via *v;


	for (int i = 0; i < cjtoBarrios->numElementosBarrio(); i++) {
		cjtoBarrios->getBarrio(i, b);

		if (b->buscarVia(nombre, v) == true) {

			v->generarFicheroArboles();
		}
	}
}

void Algoritmos::algoritmo2(string especie) {
	ListaPI<especieV*> *lEspecies;
	lEspecies = new ListaPI<especieV*>();
	especieV *e;
	int contador = 0;

	if (cjtoBarrios != NULL) {
		BarrioClase *b;

		for (int i = 0; i < cjtoBarrios->numElementosBarrio(); i++) {
			cjtoBarrios->getBarrio(i, b);
			b->buscarEspecie(especie, lEspecies);

		}

		ofstream fsalEspecie;
		string nombreFichero = "Algoritmo2.csv";

		fsalEspecie.open(nombreFichero.c_str());
		if (fsalEspecie.is_open()) {

			fsalEspecie << "Fichero de vías con el n de árboles de la especie "
					<< especie << endl;
			fsalEspecie << "Nombre vía" << "..........................."
					<< "nº de árboles" << endl;
			lEspecies->moverInicio();
			while (!lEspecies->finLista()) {

				lEspecies->consultar(e);
				fsalEspecie << e->via << "..........................."
						<< e->unidades << endl;
				contador = contador + e->unidades;
				lEspecies->avanzar();

			}
			fsalEspecie << "Total de árboles " << especie << ": " << contador
					<< endl;
		}
		fsalEspecie.close();
		delete lEspecies;
		delete e;

	}
}

void Algoritmos::algoritmo3(string genero,Arbol<BarrioVia*, CompararBarrio>* &aux) {
	if (cjtoBarrios != NULL) {
		BarrioClase *b;

		for (int i = 0; i < cjtoBarrios->numElementosBarrio(); i++) {
		cjtoBarrios->getBarrio(i, b);
		b->buscarGenero(genero, aux);


		}

		mostrarArbol(aux);
	}
}

void Algoritmos::mostrarArbol(Arbol<BarrioVia*, CompararBarrio>* aV) {
	if (aV != NULL) {
		mostrarInOrdenArbol(aV);
	}
}

void Algoritmos::mostrarInOrdenArbol(Arbol<BarrioVia*, CompararBarrio>* aV) {
	if (!aV->vacio()) {

		if (aV->hijoIzq() != NULL)
			mostrarInOrdenArbol(aV->hijoIzq());

		cout << aV->raiz()->v->getNombreVia() << "............"
				<< aV->raiz()->Barrio << endl;

		if (aV->hijoDer() != NULL)
			mostrarInOrdenArbol(aV->hijoDer());

	}
}
void Algoritmos::algoritmo4(string sub) {
	ListaPI<subcadena*> *lSubcadena;
	lSubcadena = new ListaPI<subcadena*>();
	subcadena *c;
	if (cjtoBarrios != NULL) {
		BarrioClase *b;
		for (int i = 0; i < cjtoBarrios->numElementosBarrio(); i++) {
			cjtoBarrios->getBarrio(i, b);
			if (b->getNombre().find(sub) == 0) {
				b->viasQueEmpiezanPor(sub, lSubcadena);
			}
		}

		ofstream fsalSubcadena;
		string nombreFichero = "Algoritmo4.csv";

		fsalSubcadena.open(nombreFichero.c_str());
		if (fsalSubcadena.is_open()) {

			fsalSubcadena << "Vías y barrio que comienzan por " << sub << endl;
			fsalSubcadena << "Nombre vía" << "..........................."
					<< "nº de árboles" << "............................."
					<< "Barrio" << endl;
			lSubcadena->moverInicio();

			while (!lSubcadena->finLista()) {
				lSubcadena->consultar(c);
				fsalSubcadena << c->Via << "..........................."
						<< c->unidades << ".........................."
						<< c->Barrio << endl;
				lSubcadena->avanzar();

			}
		}
		fsalSubcadena.close();
		delete lSubcadena;
		delete c;

	}
}


Algoritmos::~Algoritmos() {

	// Complete memory deallocation

	delete cjtoBarrios;
}

