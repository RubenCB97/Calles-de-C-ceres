/*
 * Via.cpp
 *
 *  Created on: 25 feb. 2019
 *      Author: ruben
 */

#include "Via.h"

Via::Via() {
	numero = 0;
	nombreVia = "";
	longitudVia = 0.0;
	tipoVia = "";
	codigoVia = 0;
	lArbol = NULL;

}

Via::Via(int numero, string nombreVia, float longitudVia, string tipoVia,
		int codigoVia) {
	this->numero = numero;
	this->nombreVia = nombreVia;
	this->longitudVia = longitudVia;
	this->tipoVia = tipoVia;
	this->codigoVia = codigoVia;
	lArbol = NULL;

}

void Via::mostrarVia() {
	cout << "nombreVia: " << this->nombreVia << endl;

}

float Via::getlongitudVia() {
	return longitudVia;
}

string Via::getNombreVia() {
	return nombreVia;
}

int Via::getNumeroVia() {
	return numero;
}

string Via::getTipoVia() {
	return tipoVia;
}

int Via::getCodigoVia() {

	return codigoVia;
}

void Via::setlongitudVia(float longitudVia) {
	this->longitudVia = longitudVia;
}

void Via::setNombreVia(string nombreVia) {

	this->nombreVia = nombreVia;
}

void Via::setNumeroVia(int numero) {
	this->numero = numero;

}

void Via::setTipoVia(string tipoVia) {
	this->tipoVia = tipoVia;
}

void Via::setCodigoVia(int codigoVia) {
	this->codigoVia = codigoVia;
}

string Via::getClave() {
	string clave, cb, cv;
	int ceros;
	cb = to_string(numero);
	if (cb.length() == 1) {
		cb = "0" + cb;
	}

	cv = to_string(codigoVia);
	ceros = 4 - cv.length();
	for (int i = 0; i < ceros; i++) {
		cv = "0" + cv;

	}

	return cb + cv;
}

void Via::insertarArbol(Arboles *a) {

	if (lArbol == NULL) {

		lArbol = new ListaPI<Arboles*>;

	}
	lArbol->insertar(a);

}

void Via::generarFicheroArboles() {
	if (lArbol != NULL) {
		int cont = 0;
		Arboles *a;
		ofstream fsalArbol;
		string nombreFichero = this->nombreVia + ".csv";
		fsalArbol.open(nombreFichero.c_str());
		if (fsalArbol.is_open()) {
			fsalArbol
					<< "Especie;Familia;Nombre común;Genero;Diámetro;Altura;Copa;Riego;Unidades;Códigovía"
					<< endl;

			lArbol->moverInicio();
			while (!lArbol->finLista()) {

				lArbol->consultar(a);
				cont = cont + a->getUnidades();
				fsalArbol << a->getEspecie() << ";" << a->getFamilia() << ";"
						<< a->getNombreComun() << ";" << a->getGenero() << ";"
						<< a->getDiametro() << ";" << a->getAltura() << ";"
						<< a->getCopa() << ";" << a->getRiego() << ";"
						<< a->getUnidades() << ";" << a->getCodigoVia() << endl;
				lArbol->avanzar();
			}
			fsalArbol << "Total arboles: " << cont << endl;
		}
		fsalArbol.close();
	}
}

int Via::contarArboles() {
	Arboles *a;
	int contador = 0;
	if (lArbol != NULL) {

		lArbol->moverInicio();
		while (!lArbol->finLista()) {
			lArbol->consultar(a);
			contador = contador + a->getUnidades();
			lArbol->avanzar();

		}
	}
	return contador;
}
//Algoritmo4
bool Via::buscarArbolGenero(string genero) {
	Arboles *a;
	bool bandera = false;
	if (lArbol != NULL) {
		lArbol->moverInicio();

		while (!lArbol->finLista() && !bandera) {

			lArbol->consultar(a);
			lArbol->avanzar();

			if (a->getGenero() == genero) {

				bandera = true;

			}

		}

	}

	return bandera;
}
//Algoritmo2
void Via::encolarConPrioridad(Cola<Arboles*> * &Pgenero, Arboles *a) {
	bool encontrado = false;
	Cola<Arboles*> *Aux;
	Aux = new Cola<Arboles*>();
	Arboles *b;
	while (!Pgenero->vacia() && !encontrado) {
		Pgenero->primero(b);
		Pgenero->desencolar();

		if (b->getAltura() < a->getAltura()) {
			Aux->encolar(a);
			encontrado = true;

		} else if (b->getAltura() == a->getAltura()) {
			if (b->getCopa() <= a->getCopa()) {
				Aux->encolar(a);
				encontrado = true;

			}
		}
		Aux->encolar(b);

	}

	if (!encontrado) {
		Aux->encolar(a);
	}

	while (!Pgenero->vacia()) {
		Pgenero->primero(a);
		Aux->encolar(a);
		Pgenero->desencolar();
	}
	while (!Aux->vacia()) {
		Aux->primero(a);
		Pgenero->encolar(a);
		Aux->desencolar();
	}

}

//Algoritmo3
//METODO donde comprueba si el tipo de especie existe en la via, si es asi la incluye en una lista
void Via::buscarArbolEspecieV(ListaPI<especieV*>*& lEspecie, string especie) {
	Arboles *a;

	especieV *b;
	if (lArbol != NULL) {
		lArbol->moverInicio();

		while (!lArbol->finLista()) {
			lArbol->consultar(a);

			if (a->getEspecie() == especie) {

				if (lEspecie->estaVacia()) {

					b = new especieV();
					b->via = this->getNombreVia();
					b->unidades = a->getUnidades();
					lEspecie->insertar(b);
					lEspecie->avanzar();
				} else {
					insertarListaOrden(lEspecie, a);

				}
				lArbol->avanzar();

			} else {
				lArbol->avanzar();
			}

		}

	}

}

//Algoritmo3

void Via::insertarListaOrden(ListaPI<especieV*>*& lEspecie, Arboles* a) {
	bool enc = false;
	bool mayor = false;
	especieV *b;
	lEspecie->moverInicio();
	while (!lEspecie->finLista() && !enc && !mayor) {
		lEspecie->consultar(b);
		if (this->getNombreVia() == b->via) {
			b->unidades = b->unidades + a->getUnidades();

			enc = true;
		} else {
			if (this->getNombreVia() < b->via) {
				mayor = true;
			} else {

				lEspecie->avanzar();
			}
		}
	}
	if (!enc) {
		b = new especieV();
		b->via = this->getNombreVia();
		b->unidades = a->getUnidades();
		lEspecie->insertar(b);
	}

}
Via::~Via() {
	Arboles *a;

	if (lArbol != NULL) {
		lArbol->moverInicio();
		while (!lArbol->finLista()) {
			lArbol->consultar(a);
			delete a;
			lArbol->borrar();
		}

	}
}

