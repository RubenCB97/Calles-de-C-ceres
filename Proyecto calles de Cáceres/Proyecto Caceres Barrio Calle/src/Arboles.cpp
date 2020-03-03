/*
 * Arbol.cpp
 *
 *  Created on: 20 abr. 2019
 *      Author: ruben
 */

#include "Arboles.h"

Arboles::Arboles() {
	especie = "";
	familia = "";
	nombreComun = "";
	genero = "";
	diametro = 0.0;
	altura = 0.0;
	copa = 0.0;
	riego = "";
	unidades = 0;
	codigoVia = 0;
}

Arboles::Arboles(string especie, string familia, string nombreComun, string genero,
		float diametro, float altura, float copa, string riego, int unidades,
		int codigoVia) {
	this->especie = especie;
	this->familia = familia;
	this->nombreComun = nombreComun;
	this->genero = genero;
	this->diametro = diametro;
	this->altura = altura;
	this->copa = copa;
	this->riego = riego;
	this->unidades = unidades;
	this->codigoVia = codigoVia;

}

void Arboles::setEspecie(string especie) {

	this->especie = especie;
}

void Arboles::setFamilia(string familia) {
	this->familia = familia;
}

void Arboles::setNombreComun(string nombreComun) {
	this->nombreComun = nombreComun;
}

void Arboles::setGenero(string genero) {
	this->genero = genero;
}

void Arboles::setDiametro(float diametro) {
	this->diametro = diametro;
}

void Arboles::setAltura(float altura) {
	this->altura = altura;
}

void Arboles::setCopa(float copa) {
	this->copa = copa;
}

void Arboles::setRiego(string riego) {
	this-> riego = riego;
}

void Arboles::setUnidades(int unidades) {
	this ->unidades = unidades;
}

void Arboles::setCodigoVia(int codigoVia) {

	this->codigoVia = codigoVia;
}

string Arboles::getEspecie() {
	return especie;
}

string Arboles::getFamilia() {
	return familia;
}

string Arboles::getNombreComun() {
	return nombreComun;
}

string Arboles::getGenero() {
	return genero;
}

float Arboles::getDiametro() {
	return diametro;
}

float Arboles::getAltura() {
	return altura;
}

float Arboles::getCopa() {
	return copa;
}

string Arboles::getRiego() {
	return riego;
}

int Arboles::getUnidades() {
	return unidades;
}

int Arboles::getCodigoVia() {
	return codigoVia;
}

Arboles::~Arboles() {
	// TODO Auto-generated destructor stub
}

void Arboles::mostrarArbol() {

	cout<<	"Genero: "<<getGenero()<<
			"     	\t Diametro: "<<getDiametro()<<
			"      	\t  Altura: "<<getAltura()<<
			"      	\t  Copa:   "<<getCopa()<<
			"      	\t  Unidades: "<<getUnidades()<<
			"            ";

}
