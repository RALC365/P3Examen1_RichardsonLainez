#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <string>

using namespace std;

class Simbolo{
	public:
		Simbolo(char, Simbolo*);
		char simbolo;
		Simbolo* anterior;
		Simbolo* getAnterior();
		char getSimbolo();
		bool tieneAnterior();
};

#endif