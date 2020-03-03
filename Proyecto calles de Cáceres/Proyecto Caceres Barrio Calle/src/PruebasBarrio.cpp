/*
 * PruebasBarrio.cpp
 *
 *  Created on: 8 jun. 2019
 *      Author: ruben
 */

#include "PruebasBarrio.h"
#include "BarrioClase.h"
#include <iostream>
using namespace std;

void pruebasViasQueEmpiezanPor() {
	cout<<"Inicio pruebasViasQueEmpiezanPor"<<endl;

	ListaPI<subcadena*>* lSubcadena;
		lSubcadena = new ListaPI<subcadena*>();
		Via *v, *v2, *v3, *v4;
		subcadena  *s;

		BarrioClase *b;

		b = new BarrioClase("PruebaBarrio", 504.204, 50.432, 54, "Sur");

		v = new Via(4, "EstoNoEsUnaVia", 504.204, "Avda", 54);
		v2 = new Via(2, "PruebaVia2", 503.3232, "Calle", 5);
		v3 = new Via(5, "ViaDejajas", 421, "Avda", 3);
		v4 = new Via(192, "PruebaVia4", 69293.5323, "Calle", 100);
		b->insertarVia(v);
		b->insertarVia(v2);
		b->insertarVia(v3);
		b->insertarVia(v4);


		Arboles *a, *a1, *a2,*a4;

		a = new Arboles("Acersegundo", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
				"ACER", 0.06, 5.5, 3.5, "NO RIEGO", 1, 3660);
		a1 = new Arboles("Acertercero", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
				"ACER", 0.06, 9, 4, "NO RIEGO", 3, 3660);
		a2 = new Arboles("Acertercero", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
				"ACER", 0.06, 10.7, 6, "NO RIEGO", 4, 3660);
		a4 = new Arboles("Ace", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
						"ACER", 2.06, 5530.7, 612, "NO RIEGO", 432, 60);

		v->insertarArbol(a);
		v2->insertarArbol(a2);
		v3->insertarArbol(a1);
		v4->insertarArbol(a4);

		b->viasQueEmpiezanPor("Prueba",lSubcadena);

		lSubcadena->moverInicio();
		while(!lSubcadena->finLista()){
			lSubcadena->consultar(s);
			cout<<s->Via<<endl;
			lSubcadena->avanzar();

		}


		cout<<"Fin pruebasViasQueEmpiezanPor"<<endl;


}

void pruebasBuscarCodigoVia() {
	cout << "Inicio pruebasBuscarCodigoVia" << endl;
	Via *v, *v2, *v3, *v4, *v5;

	BarrioClase *b;
	b = new BarrioClase("PruebaBarrio", 504.204, 50.432, 54, "Sur");
	v = new Via(4, "PruebaVia", 504.204, "Avda", 54);
	v2 = new Via(2, "PruebaVia2", 503.3232, "Calle", 5);
	v3 = new Via(5, "PruebaVia3", 421, "Avda", 3);
	v4 = new Via(192, "PruebaVia4", 69293.5323, "Calle", 100);
	b->insertarVia(v);
	b->insertarVia(v2);
	b->insertarVia(v3);
	b->insertarVia(v4);

	if (b->buscarCodigoVia(100, v5) == true) {
		cout << v5->getNombreVia() << "   " << v5->getCodigoVia() << endl;

	} else {
		cout << "Error en BuscarCodigoVia" << endl;
	}

	cout << "Fin pruebasBuscarCodigoVia" << endl;

}

void pruebasBuscarEspecie() {

	cout << "Inicio pruebasBuscarEspeicie" << endl;
	ListaPI<especieV*> *aux;
	aux = new ListaPI<especieV*>();

	BarrioClase *b;
	b = new BarrioClase("PruebaBarrio", 504.204, 50.432, 54, "Sur");
	Via *v, *v2, *v3, *v4;
	v = new Via(4, "PruebaVia", 504.204, "Avda", 54);
	v2 = new Via(2, "PruebaVia2", 503.3232, "Calle", 5);
	v3 = new Via(5, "PruebaVia3", 421, "Avda", 3);
	v4 = new Via(192, "PruebaVia4", 69293.5323, "Calle", 100);
	b->insertarVia(v);
	b->insertarVia(v2);
	b->insertarVia(v3);
	b->insertarVia(v4);

	Arboles *a, *a1, *a2;
	especieV *b3;

	a = new Arboles("Acersegundo", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
			"ACER", 0.06, 5.5, 3.5, "NO RIEGO", 1, 3660);
	a1 = new Arboles("Acertercero", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
			"ACER", 0.06, 9, 4, "NO RIEGO", 3, 3660);
	a2 = new Arboles("Acertercero", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
			"ACER", 0.06, 10.7, 6, "NO RIEGO", 4, 3660);

	v->insertarArbol(a);
	v2->insertarArbol(a1);
	v3->insertarArbol(a2);
	b->buscarEspecie("Acertercero", aux);

	aux->moverInicio();
	while (!aux->finLista()) {
		aux->consultar(b3);
		cout << b3->via << "   " << b3->unidades << endl;
		aux->avanzar();
	}

	cout << "FIn pruebasBusarEspecie" << endl;

}

void pruebasInsertarEnOrden() {
	cout << "Inicio pruebasInsertarEnOrden" << endl;
	ListaPI<subcadena*>* lSubcadena;
	lSubcadena = new ListaPI<subcadena*>();
	Via *v, *v2, *v3, *v4;
	subcadena *s1, *s;

	BarrioClase *b, *b2, *b3, *b4;

	b = new BarrioClase("PruebaBarrio", 504.204, 50.432, 54, "Sur");

	b2 = new BarrioClase("PruebaBarrio2", 504.204, 50.432, 54, "Sur");

	b3 = new BarrioClase("PruebaBarrio3", 504.204, 50.432, 54, "Sur");
	b4 = new BarrioClase("PruebaBarrio4", 504.204, 50.432, 54, "Sur");
	v = new Via(4, "PruebaVia", 504.204, "Avda", 54);
	v2 = new Via(2, "PruebaVia2", 503.3232, "Calle", 5);
	v3 = new Via(5, "PruebaVia3", 421, "Avda", 3);
	v4 = new Via(192, "PruebaVia4", 69293.5323, "Calle", 100);
	b->insertarVia(v);
	b2->insertarVia(v2);
	b3->insertarVia(v3);
	b4->insertarVia(v4);

	s1 = new subcadena();
	s1->Via = v4->getNombreVia();
	s1->Barrio = b->getNombre();
	s1->unidades = v4->contarArboles();
	lSubcadena->insertar(s1);

	b3->insertarEnOrden(lSubcadena, v2);

	b4->insertarEnOrden(lSubcadena, v);

	b2->insertarEnOrden(lSubcadena, v3);

	lSubcadena->moverInicio();

	while (!lSubcadena->finLista()) {
		lSubcadena->consultar(s);
		cout << s->Via << "   " << s->Barrio << endl;
		lSubcadena->avanzar();

	}
	cout << "Fin pruebasInsertarEnOrden" << endl;

}

void pruebasBuscarGenero() {
	cout << "Inicio pruebasBuscarGenero" << endl;
	Arbol<BarrioVia*, CompararBarrio>* aux;
	aux = new Arbol<BarrioVia*, CompararBarrio>();

	BarrioClase *b;
	b = new BarrioClase("PruebaBarrio", 504.204, 50.432, 54, "Sur");
	Via *v, *v2, *v3, *v4;
	v = new Via(4, "PruebaVia", 504.204, "Avda", 54);
	v2 = new Via(2, "PruebaVia2", 503.3232, "Calle", 5);
	v3 = new Via(5, "PruebaVia3", 421, "Avda", 3);
	v4 = new Via(192, "PruebaVia4", 69293.5323, "Calle", 100);
	b->insertarVia(v);
	b->insertarVia(v2);
	b->insertarVia(v3);
	b->insertarVia(v4);

	Arboles *a, *a1, *a2;

	a = new Arboles("Acersegundo", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
			"ACER", 0.06, 5.5, 3.5, "NO RIEGO", 1, 3660);
	a1 = new Arboles("Acertercero", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
			"ACERMB", 0.06, 9, 4, "NO RIEGO", 3, 3660);
	a2 = new Arboles("Acertercero", "Aceraceae", "ARCE DE HOJAS DE FRESNO",
			"ACERNO", 0.06, 10.7, 6, "NO RIEGO", 4, 3660);

	v4->insertarArbol(a);
	v2->insertarArbol(a1);
	v3->insertarArbol(a2);

	b->buscarGenero("ACER", aux);

	if (aux->raiz()->v->getNombreVia() != "PruebaVia4") {
		cout << "Error en pruebasBuscarGenero" << endl;
	}

	cout << "Fin pruebasBuscarGenero" << endl;
}

void pruebasGeneral() {
	cout << "Inicio pruebas de barrioClase" << endl;
	pruebasBuscarCodigoVia();
	pruebasBuscarEspecie();
	pruebasInsertarEnOrden();
	pruebasBuscarGenero();
	pruebasViasQueEmpiezanPor();

	cout << "Fin pruebas de barrioClase" << endl;
}
