#include "Simbolo.h"

Simbolo::Simbolo(char pSimbolo, Simbolo* pAnterior){
	this->simbolo = pSimbolo;
	this->anterior = pAnterior;
}

Simbolo* Simbolo::getAnterior(){
	return anterior;
}

char Simbolo::getSimbolo(){
	return simbolo;
}

bool Simbolo::tieneAnterior(){
	if(anterior != NULL){
		return true;
	}
	return false;
}