/*
 * Via.h
 *
 *  Created on: 25 feb. 2019
 *      Author: ruben
 */

#ifndef VIA_H_
#define VIA_H_
#include <string>
#include <iostream>

#include "Arboles.h"
#include "listapi.h"

using namespace std;
struct subcadena{
	string Via;
	string Barrio;
	int unidades;
};
struct especieV {
	string via;
	int unidades;
};


class Via {

private:
	int numero;
	string nombreVia;
	float longitudVia;
	string tipoVia;
	int codigoVia;
	ListaPI<Arboles*> * lArbol;

public:

	Via();
	Via(int numero, string nombreVia, float longitudVia, string tipoVia,
			int codigoVia);

	//METODOS MODIFICADORES

	//POST:Introduce una longitud,longitudVia>0.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	void setlongitudVia(float longitudVia);

	//POST:Introduce una string con el nombre de la via.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	void setNombreVia(string nombreVia);

	//POST:Introduce un string del tipo de la via.
	//PRE:Tener construida una via.
	//Complejidad: O(1)void setNumeroVia(int numero).
	void setTipoVia(string tipoVia);

	//POST:Introduce un Codigo,codigovia>=0.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	void setCodigoVia(int codigoVia);

	//POST:Introduce un numero,numero>=0.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	void setNumeroVia(int numero);

	//METODOS SELECTORES

	//POST:Devuelve un string con la clave de la via
	//PRE:Tener construida una via.
	//Complejidad: O(n).
	string getClave();

	//POST:Devuelve un entero con la longitud de la via.
	//PRE:Tener construida una via.
	//Complejidad: O(1)
	float getlongitudVia();

	//POST:Devuelve un string con el nombre de la via.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	string getNombreVia();

	//POST:Devuelve un entero con el numero de la via.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	int getNumeroVia();

	//POST:Devuelve un string con el tipo de la via.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	string getTipoVia();

	//POST:Devuelve un entero con el codigo de la via.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	int getCodigoVia();

	//POST:Muestra la via en pantalla.
	//PRE:Tener construida una via.
	//Complejidad: O(1).
	void mostrarVia();
	//POST:Inserta un arbol
	//PRE: Tener un arbol creado y una via
	//Complejidad: O(1)
	void insertarArbol(Arboles *a);
	//POST:Genera un fichero  de  arboles
	//PRE: Tener una via creada
	//Complejidad: O(n)
	void generarFicheroArboles();
	//POST: Devuelve un entero con el numero de arboles
	//PRE: Tener una via creada
	//Complejidad: O(n)
	int  contarArboles();
	//POST:  Buscar un arbol por genero, si lo encuentra devuelve true.
	//PRE: Tener una via y una colacreada
	//Complejidad: O(n)
	bool buscarArbolGenero(string genero);
	//POST: Devuelve una cola con los arboles del mismo genero que sean de una altura mayor a 5 y una copa mayor a 3
	//PRE:	Tener una  via y una cola creada
	//Complejidad: 0(n²)
	void encolarConPrioridad(Cola<Arboles*> * &Pgenero, Arboles *a);
	//POST: Devuelve una lista con toda las especies y sus unidades en total ordenadas
	//PRE:	Tener una via y una lista creada
	//Complejidad: O(n)
	void insertarListaOrden(ListaPI<especieV*>* &lEspecie, Arboles *a);
	//POST: Devuelve una lista con toda las especies y sus unidades en total
	//PRE: Tener una via y una lista creada
	//Complejidad: O(n)
	void buscarArbolEspecieV(ListaPI<especieV*>* &lEspecie,string especie);
	~Via();
};

class Comparar{
public:
	int operator() (Via *v1, Via * v2){
		int result;
		if (v1->getNombreVia() == v2->getNombreVia())
			result = 0;
		else if (v1->getNombreVia() > v2->getNombreVia())
			result = 1;
					else result = -1;
		return result;
	}
};

class CompararCodigo{
public:
	int operator() (Via *v1, Via * v2){
		int result;
		if (v1->getCodigoVia() == v2->getCodigoVia())
			result = 0;
		else if (v1->getCodigoVia() > v2->getCodigoVia())
			result = 1;
					else result = -1;
		return result;
	}
};



#endif /* VIA_H_ */
