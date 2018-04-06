EJECUTABLE: main.o Pila.o Simbolo.o
	g++ main.o Pila.o Simbolo.o -o EJECUTABLE

main.o: main.cpp 
	g++ -c main.cpp

Pila.o: Pila.h Pila.cpp Simbolo.h
	g++ -c Pila.cpp

Simbolo.o: Simbolo.h Simbolo.cpp
	g++ -c Simbolo.cpp

clean:
	rm *.o main.out