
/*
 * PruebaVias.cpp
 *
 *  Created on: 23 mar. 2019
 *      Author: ruben
 */

#include "PruebaVias.h"

void probarVia() {
	cout << " Iniciando prueba de las vias" << endl;
	Via *v;
	v = new Via(4, "PruebaVia", 504.204, "Avda", 54);

	if (v->getCodigoVia() != 54) {
		cout << "Error Codigo" << endl;
	}
	if (v->getNombreVia() != "PruebaVia") {
		cout << "Error Nombre" << endl;
	}
	if (v->getNumeroVia() != 4) {
		cout << "Error numero" << endl;
	}
	if (v->getTipoVia() != "Avda") {
		cout << "Error TipoVia" << endl;
	}

	if (v->getlongitudVia() - 504.204 > 0.0001) {
		cout << "Error longitudVia" << endl;
	}

	v->setCodigoVia(40);
	if (v->getCodigoVia() != 40) {
		cout << "Error setCodigo" << endl;
	}

	v->setNombreVia("Prueba2");
	if (v->getNombreVia() != "Prueba2") {
		cout << "Error setNombre" << endl;
	}
	//v->setNumeroVia(5);
	if (v->getNumeroVia() != 5) {
		cout << "Error setnumero" << endl;
	}
	v->setTipoVia("Calle");
	if (v->getTipoVia() != "Calle") {
		cout << "Error setTipoVia" << endl;
	}
	v->setlongitudVia(5000);
	if (v->getlongitudVia() != 5000) {
		cout << "Error setlongitudVia" << endl;
	}
	cout << " Fin PruebasVias" << endl;
}

void pruebaInsertarArbol() {
	cout << " Iniciando pruebaInsertarArbol" << endl;
	Arboles *v;
	Via *v2;


	v = new Arboles  ("Acer_negundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3,"NO RIEGO",1,3660);

	v2= new Via(4, "PruebaVia", 504.204, "Avda", 54);

	v2->insertarArbol(v);

	if(v2->contarArboles()!=1){
		cout<<"Error en insertarArbol"<<endl;

	}
	cout<<" Fin de pruebasInsertarArbol"<<endl;



}

void pruebaGenerarFicheroArboles() {
	cout<<" Inicio pruebaGenerarFicheroArboles"<<endl;

	Via *v2;
	Arboles *v;

	v2= new Via(4, "PruebaVia", 504.204, "Avda", 54);
	v = new Arboles  ("Acer_negundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3,"NO RIEGO",1,3660);
	v2->insertarArbol(v);

	v2->generarFicheroArboles();


	ifstream fentVia;

	fentVia.open("PruebaVia.csv");
	if (!fentVia.is_open()) {
		cout<<" Error al generar fichero"<<endl;

	}

	fentVia.close();



	cout<<" Fin pruebaGenerarFicheroArboles"<<endl;


}

void pruebaContarArboles() {
	cout<<" Inicio pruebaContarArboles"<<endl;

	Via *v;
	Arboles *b,*b1,*b2;

	v= new Via(4, "PruebaVia", 504.204, "Avda", 54);


	b= new Arboles ("Acer_negundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3,"NO RIEGO",1,3660);
	b1=	 new Arboles  ("Acersegundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3,"NO RIEGO",1,3660);
	b2 =  new Arboles  ("Acertercero", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3,"NO RIEGO",1,3660);

	v->insertarArbol(b);
	v->insertarArbol(b1);
	v->insertarArbol(b2);

	if(v->contarArboles()!= 3){
		cout <<"Error en contarArboles"<<endl;
	}

	cout <<" Fin de pruebasContarArboles"<<endl;





}

void pruebaBuscarArbolGenero() {
	cout<<" Inicio de pruebaBuscarArbolGenero"<<endl;

	Cola <Arboles*> *aux;
	aux = new Cola <Arboles*> ();

	Arboles *b,*b1,*b2,*b3;
	Via *v;

	v= new Via(4, "PruebaVia", 504.204, "Avda", 54);

	b= new Arboles  ("Acer_negundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3.5,"NO RIEGO",1,3660);
	b1=	 new Arboles ("Acersegundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,9,4,"NO RIEGO",3,3660);
	b2 =  new Arboles ("Acertercero", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,10.7,6,"NO RIEGO",4,3660);

	v->insertarArbol(b);
	v->insertarArbol(b1);
	v->insertarArbol(b2);

	v->buscarArbolGenero("ACER");


	while(!aux->vacia()){
		aux->primero(b3);
		b3->mostrarArbol();
		cout<<" "<<endl;
		aux->desencolar();
	}

	delete aux;

	cout<<" Fin de pruebasBuscarArbolGenero"<<endl;




}

void pruebaEncolarConPrioridad() {
	cout<<" Inicio de pruebasEncolarConPrioridad"<<endl;


	Cola <Arboles*> *aux;
	aux = new Cola <Arboles*> ();

	Arboles *b,*b1,*b2,*b3;
	Via *v;

	v= new Via(4, "PruebaVia", 504.204, "Avda", 54);

	b= new Arboles  ("Acer_negundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3.5,"NO RIEGO",1,3660);
	b1=	 new Arboles  ("Acersegundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,9,4,"NO RIEGO",3,3660);
	b2 =  new Arboles  ("Acertercero", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,10.7,6,"NO RIEGO",4,3660);

	v->insertarArbol(b);
	v->insertarArbol(b1);
	v->insertarArbol(b2);

	v->encolarConPrioridad(aux,b);
	v->encolarConPrioridad(aux,b1);
	v->encolarConPrioridad(aux,b2);

	while(!aux->vacia()){
			aux->primero(b3);
			b3->mostrarArbol();
			cout<<" "<<endl;
			aux->desencolar();
		}

	cout<<" Fin de pruebasEncolarConPrioridad"<<endl;


}

void pruebaInsertarListaOrden() {
	cout<<" Inicio de pruebaInsertarListaOrden"<<endl;


		ListaPI <especieV*> *aux;
		aux = new ListaPI <especieV*> ();

		Arboles *b,*b1,*b2;
		especieV *b3;
		Via *v;

		v= new Via(4, "PruebaVia", 504.204, "Avda", 54);

		b= new Arboles  ("Acertercero", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3.5,"NO RIEGO",1,3660);
		b1=	 new Arboles  ("Acersegundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,9,4,"NO RIEGO",3,3660);
		b2 =  new Arboles ("Acertercero", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,10.7,6,"NO RIEGO",4,3660);

		v->insertarArbol(b);
		v->insertarArbol(b1);
		v->insertarArbol(b2);

		v->insertarListaOrden(aux,b);
		v->insertarListaOrden(aux,b1);
		v->insertarListaOrden(aux,b2);

		aux->moverInicio();
		while(!aux->finLista()){
			aux->consultar(b3);
			cout<<b3->via<<"   "<<b3->unidades<<endl;
			aux->avanzar();
		}

		cout<<" Fin de pruebaInsertaListaOrden"<<endl;


}

void pruebaBuscarArbolEspecie() {

	cout<<" Inicio de pruebaBuscarArbolEspecie"<<endl;


	ListaPI <especieV*> *aux;
	aux = new ListaPI <especieV*> ();

	Arboles *b,*b1,*b2;
	especieV *b3;
	Via *v;

	v= new Via(4, "PruebaVia", 504.204, "Avda", 54);

	b= new Arboles  ("Acersegundo", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,5.5,3.5,"NO RIEGO",1,3660);
	b1=	 new Arboles  ("Acertercero", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,9,4,"NO RIEGO",3,3660);
	b2 =  new Arboles ("Acertercero", "Aceraceae","ARCE DE HOJAS DE FRESNO","ACER",0.06,10.7,6,"NO RIEGO",4,3660);

	v->insertarArbol(b);
	v->insertarArbol(b1);
	v->insertarArbol(b2);

	v->buscarArbolEspecieV(aux,"Acersegundo");

		aux->moverInicio();
	while(!aux->finLista()){
		aux->consultar(b3);
		cout<<b3->via<<"   "<<b3->unidades<<endl;
		aux->avanzar();
	}


	cout<<" Fin de pruebaBuscarArbolEspecie"<<endl;

}


void pruebasVia(){

	cout<<" INICIO DE PRUEBASVIA"<<endl;
	pruebaGenerarFicheroArboles();
	pruebaInsertarArbol();
	pruebaContarArboles();
	pruebaBuscarArbolGenero();
	pruebaEncolarConPrioridad();
	pruebaBuscarArbolEspecie();
	pruebaInsertarListaOrden();
	cout<<" FIN DE PRUEBASVIA"<<endl;


}

