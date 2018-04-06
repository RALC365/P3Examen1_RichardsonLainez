#include <iostream>
#include <string>
#include <vector>
#include "Pila.h"

using namespace std;

//metodos
int menu();
void IngresarStringPila();
void PUSH(char);
void POP();
void TOP();
void ISEMPY();
void analizadorString();
double operacion(double, double, char);
double buscadorNumero(char);
double ValorVariable(char);
void verificarValores();


//variables globales
Pila* pila;
string inputUsuario;
vector<char> variables;
vector<double> valores;

int main(){
	char resp = 's';
	pila = new Pila();
	do{
		int op = menu();
		switch(op){
			case 1:
				cout << "Ingrese la cadena" << endl;
				cin >> inputUsuario;
				IngresarStringPila();
				cout << "Se ha ingresado a la pila" << endl;
				analizadorString();
				verificarValores();
				break;
			case 2:
				cout << "Ingrese un caracter" << endl;
				char caracter;
				cin >> caracter;
				PUSH(caracter);
				cout << "Se ha añadado el elemento" << endl;
				break;
			case 3:
				if(pila->isEmpy())
					cout << "La pila está vacía" << endl;
				else
					POP();
				break;
			case 4:
				if(pila->isEmpy())
					cout << "La pila está vacía" << endl;
				else
					TOP();
				break;
			case 5:
				ISEMPY();
				break;
			default:
				cout << "¡Gracias por probarme! Att. El programa" << endl;
		};
		if(op == 0){
			resp = 'd';
		}else{
			cout << "¿Desea continuar? [S/N]" << endl;
			cin >> resp;
		}
		
	}while(resp == 's' || resp == 'S');

	return 0;
}

int menu(){
	int op = 0;
	do{
		cout << "--Menú--" << endl;
		cout << "1.- Ingresar un string" << endl;
		cout << "2.- PUSH()" << endl;
		cout << "3.- POP()" << endl;
		cout << "4.- TOP()" << endl;
		cout << "5.- isEmpy()" << endl;
		cout << "0.- Salir" << endl;
		cout << "Ingrese una opción válida" << endl;
		cin >> op;
	}while(op < 0 || op > 5);
	return op;
}


void IngresarStringPila(){
		pila->push(new Simbolo(inputUsuario.at(0), NULL));
		for(int i = 1; i < inputUsuario.length(); i++){
			pila->push(new Simbolo(inputUsuario.at(i), pila->getSimbolo()));
		}
}

void PUSH(char caracter){
	pila->push(new Simbolo(caracter, ((pila->isEmpy())? NULL : pila->getSimbolo())));
}

void POP(){
	cout << "El último simbolo de la pila era: " << pila->pop() << endl;
}

void TOP(){
	cout << "El último símbolo de la pila es: " << pila->top() << endl;
}

void ISEMPY(){
	if(pila->isEmpy()){
		cout << "La pila está vacía" << endl;
	}else{
		cout << "La pila tine un símbolo" << endl;
	}
}

/*void analizadorString(){
	bool isOperador;
	double total = 0;
	int num1 = 0, num2 = 0, numPar1 = 0, numPar2 = 0;
	for(int i = 0; i < inputUsuario.length(); i++){
		isOperador = false;
		char temp = inputUsuario.at(i);
		int nTemp = (int)temp;
		int nTemp1 = (int)(i+2 != inputUsuario.length() ? inputUsuario.at(i+2) : '&');//&
		if(nTemp >47 && nTemp < 58){
			if(!(nTemp1 == 40 || nTemp1 == 41 || n == 38)){

			}
		}

		
	}
}*/

void analizadorString(){
	bool declaracion = false;
	double Total = 0;
	vector <char> operadores;
	vector <int> numeros;
	vector <char> variables2;
	//vector <double> parentesis;
	for(int i = 0; i < inputUsuario.length(); i++){
		int temp = (int) inputUsuario.at(i);
		if(temp > 47 && temp < 58){//numeros
			numeros.push_back(temp - 48);
		}else if((temp > 96 && temp < 123) || (temp > 64 && temp < 91)){ //letras
			//(i == 0) ? (variables.push_back((char) temp)) : variables2.push_back((char) temp);
			declaracion = (((i == 0) && (inputUsuario.at(i+1) == '=')) ? true : false);
			//declaracion = (i == 0  ? true : false);
			(declaracion) ? (variables.push_back((char) temp)) : numeros.push_back(ValorVariable((char) temp));
			(declaracion) ? i++ : (i = i);
		}else{
			operadores.push_back((char) temp);
		}
	}
	
	int op = 0;
	int num = 0;
	int val = 0;
	for(int i = (declaracion ? 2 : 0); i < inputUsuario.length(); i++){
		if(operadores[op] == '('){
			double pTotal = 0;
			int tempOp = op + 1;
			int tempNum = num + 1;
			pTotal += operacion((double)numeros[tempNum], (double)numeros[tempNum+1], operadores[tempOp]);
			tempNum += 2;
			tempOp++;
			do{
				pTotal += operacion(pTotal, (double)numeros[tempNum], operadores[tempOp]);
				tempNum++;
				tempOp++;
			}while(operadores[tempOp] != ')');
			Total += operacion(numeros[num], pTotal, operadores[op]);
			op = tempOp;
			num = tempNum;
		} else{
			Total += operacion(numeros[num], numeros[num+1], operadores[op]);
			num += 2;
			op++;
		}
		//((op+num+val) == inputUsuario.length()) ? (break) : ;
		if((op+num+val) == inputUsuario.length()){
			break;
		}
	}
	if(variables.size() > valores.size())
		valores.push_back(Total);

	cout << "El total es: " << Total << endl;
}

double operacion(double a, double b, char z){
	switch(z){
		case '+':
			return (a + b);
				break;
		case '-':
			return (a - b);
				break;
		case '*':
			return (a * b);
				break;
		case '/':
			return (a / b);
				break;
	}
}

double ValorVariable(char a){
	int pos = 0;
	for(int i = 0; i < variables.size(); i++){
		if(a == variables[i]){
			pos = i;
			break;
		} 
	}
	return valores[pos];
}

void verificarValores(){
	for(int i = 0; i < variables.size(); i++){
		cout << "Variable: " << variables[i] << endl;
		cout << "Valor: " << valores[i] <<  endl;
	}
}