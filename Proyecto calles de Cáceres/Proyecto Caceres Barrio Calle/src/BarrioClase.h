/*
 * BarrioClase.h
 *
 *  Created on: 18 feb. 2019
 *      Author: ruben
 */

#ifndef BARRIOCLASE_H_
#define BARRIOCLASE_H_

#include <string>
#include "Via.h"
#include "listapi.h"

using namespace std;

struct BarrioVia {
	Via *v;
	string Barrio;

};
class CompararBarrio {
public:
	int operator()(BarrioVia *Bv1, BarrioVia * Bv2) {
		int result;
		if (Bv1->v->getNombreVia() == Bv2->v->getNombreVia())
			result = 0;
		else if (Bv1->v->getNombreVia() > Bv2->v->getNombreVia())
			result = 1;
		else
			result = -1;
		return result;
	}
};

class BarrioClase {
private:
	string nombre;
	double area;
	float perimetro;
	int codigo;
	string distrito;
	Arbol<Via*, Comparar> *aVias;

	//PRE:Tener creado el Barrio.
	//POST: Devuelve una via si encuentra el codigo introducido y true si se encuentra/false si no.
	//Complejidad:O(log n)

	bool buscarArbolCodigo(Arbol<Via*, Comparar>* aV, int codigo, Via *&v);
	//PRE:Tener creado el Barrio.
	//POST: Devuevle una lista con el nombre de la via y sus unidades si encuentra esa especie.
	//Complejidad:O(log n)

	void buscarArbolEspecie(Arbol<Via*, Comparar>* aV, string especie,
			ListaPI<especieV*>* &lEspecie);
	//PRE:Tener creado el Barrio.
	//POST: devuelve una via si coincide con el nombre introducido y true si se encuentra/false si no.
	//Complejidad:O(log n)

	bool buscarEnArbol(Arbol<Via*, Comparar>* aV, string nombre, Via *&v);
	//PRE:Tener creado el Barrio.
	//POST:Devuelve un arbol nuevo de vias si encuentra el genero en esa via
	//Complejidad:O(log n)

	void buscarArbolGenero(Arbol<Via*, Comparar>* aV, string genero,
			Arbol<BarrioVia*, CompararBarrio>* &aux);
	//PRE:Tener creado el Barrio.
	//POST: Inserta en orden en la lista y la devuelve
	//Complejidad:O(log n)

	void filtoInOrden(Arbol<Via*, Comparar>* aV, string sub,
			ListaPI<subcadena*>* &lSubcadena);
	//PRE:Tener creado el Barrio.
	//POST:Devuelve un arbol  si coincide la subcadena con la via deseada
	//Complejidad:O(log n)

	void arbolEmpiezaPor(Arbol<Via*, Comparar>* aV, Arbol<Via*, Comparar>*&aux,
			string subcadena);
	//PRE:Tener creado el Barrio.
	//POST: Muestra los barrios en pantalla y las vias
	//Complejidad:O(log n)

	void mostrarinOrden(Arbol<Via*, Comparar>* aV);

public:
	BarrioClase(); //constructor
	BarrioClase(string nombre, float area, float perimetro, int codigo,
			string distrito);

	//Metodos modificadores

	//PRE:Tener creado el Barrio.
	//POST:Escribe en un fichero las vias del barrio.
	//Complejidad:
	void crearFichero();

	//PRE:Tener creado el Barrio
	//POST:Introduce un string nombre en el barrio desado
	//Complejidad:O(1)
	void setNombre(string nombre);

	//PRE:Tener creado el Barrio,area>=0
	//POST:Introduce un area en el barrio deseado
	//Complejidad:O(1)
	void setArea(double area);

	//PRE:Tener creado el Barrio, perimetro>=0
	//POST:Introduce un real como perimetro en el barrio deseado
	//Complejidad:O(1)
	void setPerimetro(float perimetro);

	//PRE:Tener creado el Barrio,codigo>=0
	//POST: Introduce un entero como codigo en el barrio deseado
	//Complejidad:O(1)
	void setCodigo(int codigo);

	//PRE:Tener creado el Barrio.
	//POST:Introduce un distrito en el barrio deseado
	//Complejidad:O(1)
	void setDistrito(string distrito);
	//Metodos selectores

	//PRE:Tener creado el Barrio.
	//POST:Devuelve el nombre del barrio
	//Complejidad:O(1)
	string getNombre();

	//PRE:Tener creado el Barrio.
	//POST:Devuelve el nombre del barrio
	//Complejidad:O(1)
	void getNombre(string &nombre);

	//PRE:Tener creado el Barrio.
	//POST:Devuelve el area del barrio
	//Complejidad:O(1)
	double getArea();

	//PRE:Tener creado el Barrio.
	//POST:Devuelve el perimetro del barrio
	//Complejidad:O(1)
	float getPerimetro();

	//PRE:Tener creado el Barrio.
	//POST:Devuelve el codigo del barrio
	//Complejidad:O(1)
	int getCodigo();

	//PRE:Tener creado el Barrio.
	//POST:Devuelve el distrito del barrio
	//Complejidad:O(1)
	string getDistrito();

	//PRE:Tener creado el Barrio.
	//POST:Devuelve el distrito del barrio
	//Complejidad:O(1)

	void getDistrito(string &distrito);

	//PRE:Tener el barrio creado , pos>=0
	//POST:Devuelve una via del barrio
	//Complejidad:O(1)

	void getViasBarrio(int pos, Via *v);

	//PRE:Tener creado el Barrio.
	//POST:Devuelve el numero de vias del barrio
	//Complejidad: O(1)

	int getNumeroConjuntoVia();

	//PRE:Tener creado el Barrio.
	//POST:Busca una subcadena en la vias del barrio y lo imprime por pantalla
	//Complejidad:O(n)
	bool buscarVia(int via);

	//PRE:Tener creado el Barrio.
	//POST: Devuelve el numero de vias del barrio
	//Complejidad: O(1)
	int getNumeroVias();

	//PRE:Tener creado el Barrio.
	//POST:Inserta una via
	//Complejidad:O(1)
	void insertarVia(Via *Via);

	//PRE:Tener creado el Barrio.
	//POST: Busca y devuelve una via por el nombre deseado
	//Complejidad:O(N)
	bool buscarVia(string nombre, Via *&v);

	//PRE:Tener creado el Barrio.
	//POST: Muestra los barrios en pantalla y las vias
	//Complejidad:O(n)

	void mostrar();

	//PRE:Tener creado el Barrio.
	//POST: Devuelve una lista si coincide la subcadena con la via deseada
	//Complejidad:O(log n)

	void viasQueEmpiezanPor(string sub, ListaPI<subcadena*>* &lSubcadena);
	//PRE:Tener creado el Barrio.
	//POST: Devuelve una via si coincidie con el codigo introducido
	//Complejidad:O(log n)

	bool buscarCodigoVia(int codigo, Via *&v);
	//PRE:Tener creado el Barrio.
	//POST: Devuevle una lista con nombre de via y unidades si encuentra una especie en la via
	//Complejidad:O(log n)

	void buscarEspecie(string especie, ListaPI<especieV*>* &lEspecie);
	//PRE:Tener creado el Barrio.
	//POST: Inserta en orden en la lista
	//Complejidad:O(n)

	void insertarEnOrden(ListaPI<subcadena*>* &lSubcadena, Via *v);
	//PRE:Tener creado el Barrio.
	//POST: Devuelve un arbol nuevo de vias si encuentra el genero en esa via
	//Complejidad:O(log n)

	void buscarGenero(string genero, Arbol<BarrioVia*, CompararBarrio>*&aux);
	~BarrioClase(); //destructor
};

#endif /* BARRIOCLASE_H_ */
