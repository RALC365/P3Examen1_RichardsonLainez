#include "Pila.h"
#include <iostream>

void Pila::push(Simbolo* pCaracter){
	this->caracter = pCaracter;
}


char Pila::pop(){
	Simbolo* temp = this-> caracter;
	//delete caracter;
	caracter = NULL;
	if(temp->tieneAnterior()){
		this-> caracter = temp->getAnterior();
	}else{
		cout << "Ahora la pila está vacía" << endl;
	}
	return temp->getSimbolo();
}

char Pila::top(){
	return caracter->getSimbolo();
}

Simbolo* Pila::getSimbolo(){
	return this->caracter;
}

bool Pila::isEmpy(){
	if(caracter == NULL){
		return true;
	}
	return false;
}