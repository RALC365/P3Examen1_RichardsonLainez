#ifndef PILA_H
#define PILA_H

#include <string>
#include "Simbolo.h"

using namespace std;

class Pila{
	public:
		Pila(){caracter = NULL;};
		Simbolo* caracter;
		void push(Simbolo* caracter);
		char pop();
		char top();
		Simbolo* getSimbolo();
		bool isEmpy();
};

#endif