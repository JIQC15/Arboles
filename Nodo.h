//Nodo.h
#pragma once
#include <iostream>

using namespace std;

class Nodo {
private://Implementación para la creación de arbol binario con valores de izquierda y derecha como raices.
	int Dato;//Nuestro valor recibido será entero.
	Nodo* Principal;
	Nodo* Der;//Raices y hojas.
	Nodo* Izq;//Raices y hojas.

	friend class Arbol;

public:
	Nodo(int, Nodo*);//Constructor Parametrizado
	~Nodo();//Destructor

	//Seters y geters
	void set_Data(int);
	int get_Data();
	void set_Principal(Nodo*);
	Nodo*& get_Principal();
	void set_Der(Nodo*);
	Nodo*& get_Der();
	void set_Izq(Nodo*);
	Nodo*& get_Izq();
};
