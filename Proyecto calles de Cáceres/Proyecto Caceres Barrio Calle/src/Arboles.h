/*
 * Arbol.h
 *
 *  Created on: 20 abr. 2019
 *      Author: ruben
 */

#ifndef ARBOLES_H_
#define ARBOLES_H_

#include <string>
#include <iostream>

#include <fstream>
#include <string>
#include <cstdlib>
#include "cola.h"
#include "pila.h"
#include "arbol.h"
using namespace std;

class Arboles {

private:
	string especie;
	string familia;
	string nombreComun;
	string genero;
	float diametro;
	float altura;
	float copa;
	string riego;
	int unidades;
	int codigoVia;

public:
	Arboles();
	Arboles(string especie, string familia, string nombreComun, string genero,
			float diametro, float altura, float copa, string riego,
			int unidades, int codigoVia);

	//POST: Introduce un atributo a la clase arbol
	//Compeljidad: o(1)
	//Modificadores
	void setEspecie(string especie);
	void setFamilia(string familia);
	void setNombreComun(string nombreComun);
	void setGenero(string genero);
	void setDiametro(float diametro);
	void setAltura(float altura);
	void setCopa(float copa);
	void setRiego(string riego);
	void setUnidades(int unidades);
	void setCodigoVia(int codigoVia);


	//POST: devuelve un atributo a la clase arbol
	//Compeljidad: o(1)
	//Selectores
	string getEspecie();
	string getFamilia();
	string getNombreComun();
	string getGenero();
	float getDiametro();
	float getAltura();
	float getCopa();
	string getRiego();
	int getUnidades();
	int getCodigoVia();

	void mostrarArbol();

	~Arboles();
};

#endif /* ARBOLES_H_ */
