/*
 * BarrioClase.cpp
 *
 *  Created on: 18 feb. 2019
 *      Author: ruben
 */

#include "BarrioClase.h"
#include <iostream>
using namespace std;

BarrioClase::BarrioClase() {
	nombre = "";
	area = 0.0;
	perimetro = 0.0;
	codigo = 0;
	distrito = "";
	aVias = NULL;

}

void BarrioClase::setNombre(string nombre) {
	this->nombre = nombre;
}

void BarrioClase::setArea(double area) {
	this->area = area;

}

void BarrioClase::setPerimetro(float perimetro) {

	this->perimetro = perimetro;
}

void BarrioClase::setCodigo(int codigo) {

	this->codigo = codigo;
}

void BarrioClase::setDistrito(string distrito) {

	this->distrito = distrito;
}

BarrioClase::BarrioClase(string nombre, float area, float perimetro, int codigo,
		string distrito) {
	this->nombre = nombre;
	this->area = area;
	this->perimetro = perimetro;
	this->codigo = codigo;
	this->distrito = distrito;
	aVias = NULL;
}

void BarrioClase::insertarVia(Via* v) {

	if (aVias == NULL) {

		aVias = new Arbol<Via*, Comparar>;

	}
	aVias->insertar(v);

}

string BarrioClase::getNombre() {

	return nombre;
}

void BarrioClase::getNombre(string& nombre) {
	nombre = this->nombre;

}

double BarrioClase::getArea() {

	return area;
}

float BarrioClase::getPerimetro() {
	return perimetro;
}

int BarrioClase::getCodigo() {
	return codigo;
}

string BarrioClase::getDistrito() {

	return distrito;
}

void BarrioClase::getDistrito(string& distrito) {
	distrito = this->distrito;
}

void BarrioClase::mostrarinOrden(Arbol<Via*, Comparar>* aV) {
	if (!aV->vacio()) {
		if (aV->hijoIzq() != NULL)
			mostrarinOrden(aV->hijoIzq());
		aV->raiz()->mostrarVia();
		if (aV->hijoDer() != NULL)
			mostrarinOrden(aV->hijoDer());
	}
}

void BarrioClase::mostrar() {

	if (aVias != NULL) {
		mostrarinOrden(aVias);
	}
}

// Buscar por codigo en el metodo privado
bool BarrioClase::buscarCodigoVia(int codigo, Via*& v) {

	bool enc = false;

	if (aVias != NULL) {

		if (buscarArbolCodigo(aVias, codigo, v) == true) {
			enc = true;
		}
	}

	return enc;

}
// Busca por codigo la via en el arbol y devuelve true si la encuentra y la via
bool BarrioClase::buscarArbolCodigo(Arbol<Via*, Comparar>* aV, int codigo,
		Via*& v) {
	bool enc;
	v = NULL;

	if (aV != NULL) {
		if (aV->raiz()->getCodigoVia() == codigo) {
			enc = true;
			v = aV->raiz();

		}

		if (aV->hijoIzq() != NULL && !enc) {
			enc = buscarArbolCodigo(aV->hijoIzq(), codigo, v);
		}

		if (aV->hijoDer() != NULL && !enc) {
			enc = buscarArbolCodigo(aV->hijoDer(), codigo, v);
		}

	}

	return enc;

}
//Algoritmo1

bool BarrioClase::buscarEnArbol(Arbol<Via*, Comparar>* aV, string nombre,
		Via*& v) {
	bool enc;
	if (aV != NULL) {
		if (aV->raiz()->getNombreVia() == nombre) {
			enc = true;
			v = aV->raiz();

		} else {
			if (aV->raiz()->getNombreVia() < nombre) {
				enc = buscarEnArbol(aV->hijoDer(), nombre, v);

			} else {
				enc = buscarEnArbol(aV->hijoIzq(), nombre, v);
			}
		}

	}
	return enc;
}

bool BarrioClase::buscarVia(string nombre, Via*& v) {
	v = NULL;
	bool enc = false;
	if (aVias != NULL) {
		enc = buscarEnArbol(aVias, nombre, v);

	}
	return enc;
}
// ALGORITMO 2
void BarrioClase::buscarArbolEspecie(Arbol<Via*, Comparar>* aV, string especie,
		ListaPI<especieV*>* &lEspecie) {
	if (aV != NULL) {

		if (aV->hijoIzq() != NULL) {

			buscarArbolEspecie(aV->hijoIzq(), especie, lEspecie);
		}
		aV->raiz()->buscarArbolEspecieV(lEspecie, especie);

		if (aV->hijoDer() != NULL) {

			buscarArbolEspecie(aV->hijoDer(), especie, lEspecie);
		}

	}
}

void BarrioClase::buscarEspecie(string especie, ListaPI<especieV*>* &lEspecie) {

	if (aVias != NULL) {

		buscarArbolEspecie(aVias, especie, lEspecie);

	}

}

//Algoritmo 3

void BarrioClase::buscarGenero(string genero,
		Arbol<BarrioVia*, CompararBarrio>*&aux) {
	if (aVias != NULL) {

		buscarArbolGenero(aVias, genero, aux);

	}

}
void BarrioClase::buscarArbolGenero(Arbol<Via*, Comparar>* aV, string genero,
		Arbol<BarrioVia*, CompararBarrio>* &aux) {
	BarrioVia *c;
	c = new BarrioVia;

	if (!aV->vacio()) {

		if (aV->hijoIzq() != NULL) {
			buscarArbolGenero(aV->hijoIzq(), genero, aux);
		}

		if (aV->raiz()->buscarArbolGenero(genero) == true) {
			c->v = aV->raiz();
			c->Barrio = this->getNombre();

			aux->insertar(c);

		}
		if (aV->hijoDer() != NULL) {
			buscarArbolGenero(aV->hijoDer(), genero, aux);
		}

	}

}

//Algoritmo 4

void BarrioClase::viasQueEmpiezanPor(string sub,
		ListaPI<subcadena*>*& lSubcadena) {
	Arbol<Via*, Comparar>* aV;
	aV = NULL;
	if (aVias != NULL) {
		arbolEmpiezaPor(aVias, aV, sub);

		if (aV != NULL) {
			filtoInOrden(aV, sub, lSubcadena);
		} else {
			cout << "No hay vias" << endl;
		}
	}
}

void BarrioClase::arbolEmpiezaPor(Arbol<Via*, Comparar>* aV,
		Arbol<Via*, Comparar>*& aux, string subcadena) {
	if (aV != NULL) {
		if (aV->raiz()->getNombreVia().find(subcadena) == 0) {
			aux = aV;
		} else if (aV->raiz()->getNombreVia() < subcadena) {
			arbolEmpiezaPor(aV->hijoDer(), aux, subcadena);
		} else {
			arbolEmpiezaPor(aV->hijoIzq(), aux, subcadena);
		}

	}
}
void BarrioClase::filtoInOrden(Arbol<Via*, Comparar>* aV, string sub,
		ListaPI<subcadena*>* &lSubcadena) {
	subcadena *s;
	if (aV != NULL) {
		if (aV->hijoIzq() != NULL) {
			filtoInOrden(aV->hijoIzq(), sub, lSubcadena);

		}
		if (aV->raiz()->getNombreVia().find(sub) == 0
				&& aV->raiz()->contarArboles() > 0) {
			if (lSubcadena->estaVacia()) {
				s = new subcadena();
				s->unidades = aV->raiz()->contarArboles();
				s->Via = aV->raiz()->getNombreVia();
				s->Barrio = this->getNombre();
				lSubcadena->insertar(s);
				lSubcadena->avanzar();
			} else {
				insertarEnOrden(lSubcadena, aV->raiz());

			}

		}
		if (aV->hijoDer() != NULL) {
			filtoInOrden(aV->hijoDer(), sub, lSubcadena);

		}

	}

}

void BarrioClase::insertarEnOrden(ListaPI<subcadena*>*& lSubcadena, Via *v) {

	bool mayor = false;
	subcadena *b;
	lSubcadena->moverInicio();
	while (!lSubcadena->finLista() && !mayor) {
		lSubcadena->consultar(b);

		if (this->getNombre() < b->Barrio) {
			mayor = true;
		} else {

			lSubcadena->avanzar();
		}

	}

	b = new subcadena();
	b->Via = v->getNombreVia();
	b->Barrio = this->getNombre();
	b->unidades = v->contarArboles();
	lSubcadena->insertar(b);

}

BarrioClase::~BarrioClase() {
	Via *v = NULL;
	if (aVias != NULL) {
		while (!aVias->vacio()) {
			v = aVias->raiz();
			aVias->borrar(v);
			delete v;
		}
		delete aVias;
	}
}

