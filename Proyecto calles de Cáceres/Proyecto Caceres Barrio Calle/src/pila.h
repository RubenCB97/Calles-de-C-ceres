/*
 * pila.h
 *
 *  Created on: Marzo. 2018
 *  Author: Profesores de la asignatura EDI
 *  Definición de una Pila genérica
 */

#ifndef PILA_H_
#define PILA_H_

#include <iostream>
/**
* Clase genérica Pila
* contiene Nodos de tipo genérico también y un puntero (cima) a último nodo introducido
*/
template <class TipoDato> class Pila {
private:
	/**
	* Clase genÃ©rica Nodo
	* representa los Nodos que se almacenan en la Pila
	* cada Nodo contiene un dato de tipo genÃ©rico y un puntero al siguiente nodo
	*/
	class Nodo {

	public:
		/** Dato almacenado en cada nodo */
		TipoDato  dato;
		/** Enlace al siguiente elemento */
		Nodo     *siguiente;

		Nodo (TipoDato dato) {
			this->dato      = dato;
			this->siguiente = NULL;
		}
	};
private:
	/** Puntero a la cima de la pila*/
	Nodo* pCima;

public:
	/*
	 * Constructor por defecto
	 * Pre ={}
	 * Post= {Crea/inicializa la instancia de la clase}
	 * \param ""  No recibe parametros
	 * \return Retorna Objeto Pila
	 */
	Pila ();


	/*
	 * MÃ©todo que comprueba si la pila esta vacia
	 * Pre= {La instancia debe estar creada }
	 * \param ""  No recibe parametros
 	 * \return Devuelve true si la pila estÃ¡ vacÃ­a o false en caso contrario
 	 * Complejidad: O(1)
 	 */
	bool vacia () const;

	/*
	 * MÃ©todo que inserta un elemento en la cima de la pila
	 * Pre= {La instancia debe estar creada }
	 * \param dato es el elemento que se va a insertar
 	 * \return  No retorna ningun valor
 	 * Complejidad: O(1)
 	 */
	void apilar (const TipoDato &dato);

	/*
	 * MÃ©todo que devuelve el elemento en la cima de la pila
	 * Pre= {La instancia debe estar creada }
	 * \param dato es el elemento de la cima de la pila
 	 * \return  No retorna ningun valor
 	 * Complejidad: O(1)
 	 */
	void cima (TipoDato &dato);


	/*
	 * MÃ©todo que elimina el elemento en la cima de la pila
	 * Pre= {La instancia debe estar creada }
	 * Post = {El nÃºmero de elementos en la pila se reduce en 1}
	 * \param ""  No recibe parametros
 	 * \return No retorna ningun valor
 	 * Complejidad: O(1)
 	 */
	void desapilar();

	/**
	* Metodo destructor de la clase Pila
	* \param ""  No recibe parametros
	* \return No retorna ningun valor
	* Complejidad: O(1)
	*/
	~Pila ();
};

template <class TipoDato> Pila<TipoDato>::Pila () {
	pCima = NULL;
}



template <class TipoDato> bool Pila<TipoDato>::vacia () const {
	return (pCima == NULL);
}

//TODO: implementar el mÃ©todo
template <class TipoDato>
void Pila<TipoDato>::apilar (const TipoDato &dato) {
	Nodo *nuevo;
	nuevo = new Nodo(dato);
	nuevo->siguiente = pCima;
	pCima = nuevo;
}

template <class TipoDato>
void Pila<TipoDato>::cima (TipoDato &dato){
	dato = pCima->dato;
}


template <class TipoDato>
void  Pila<TipoDato>::desapilar(){

	Nodo *aux = pCima;
	if (! vacia()){
		pCima = pCima->siguiente;
		delete aux;
	}
}

template <class TipoDato>
Pila<TipoDato>::~Pila (){
	Nodo *aux;
	while (! vacia()){
		aux = pCima;
		pCima = pCima->siguiente;
		delete aux;
	}
}
#endif /* PILA_H_ */

