/*
 * Algoritmos.h
 *
 *  Created on: 03/03/2019
 *      Author: Profesores de EDI
 */

#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include "SetBarrio.h"
#include "PruebasBarrio.h"
#include "PruebaVias.h"
#include "PruebaSetBarrio.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Algoritmos {

private:


	SetBarrio *cjtoBarrios;

	// carga los datos desde los ficheros de texto
	void cargarDatos();
	// ejecuta todos los algoritmos del proyecto
	void run();
	//PRE:Tener barrios en el conjunto barrios
			//POST:muestra en orden el arbol deseado
			//COMPLEJIDAD:o(log n)
		void mostrarInOrdenArbol(Arbol<BarrioVia*, CompararBarrio>* aV);



public:

	Algoritmos();
	//PRE:Tener barrios en el conjunto barrios
	//POST:muestra los barrios
	//COMPLEJIDAD:o(n)
	void mostrarBarrios();
	//PRE:Tener barrios en el conjunto barrios ,un entero codigo >=0 y una via creada
		//POST:Devuelve una via segun el codigo de via introducido
		//COMPLEJIDAD:o(log n)
	bool buscarViaBarrio(int codigo, Via *&v);

	//PRE:Tener barrios en el conjunto barrios
		//POST:genera un fichero con todos los árboles de una determinada vía
		//COMPLEJIDAD:o(log n)
	void algoritmo1(string nombre);
	//PRE:Tener barrios en el conjunto barrios
		//POST:genera un fichero con el nombre de las calles en laque existan árboles de una determinada especie que debe ser aportada por elusuario
		//COMPLEJIDAD:o(log n)
	void algoritmo2(string especie);
	//PRE:Tener barrios en el conjunto barrios
		//POST:genera un árbol con todas las vías que tengan árboles de un determinado género aportado por el usuari
		//COMPLEJIDAD:o(n*log n)
	void algoritmo3(string genero,Arbol<BarrioVia*, CompararBarrio>* &aux);
	//PRE:Tener barrios en el conjunto barrios ,un entero codigo >=0 y una via creada
		//POST:Devuelve una via segun el codigo de via introducido
		//COMPLEJIDAD:o(n²)
	void algoritmo4(string sub);
	//PRE:Tener barrios en el conjunto barrios.
		//POST: escribe en un fichero con todas las vías quecomiencen por una determinada subcadena de todos los barrios que tambiéncomiencen por dichas subcadena, junto con el número de árboles
		//COMPLEJIDAD:o(log n)
	void mostrarArbol(Arbol<BarrioVia*, CompararBarrio>* aV);


	~Algoritmos();

};

#endif /* ALGORITMOS_H_ */
