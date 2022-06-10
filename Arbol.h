//Arbol.h
#pragma once
#include <iostream>
#include "Nodo.h"

using namespace std;

class Tree {
protected:
	Nodo* tree;//Vamos a comenzar a plantar el arbol, por ende esta protegida esa funcion para que no se modifique a la larga.
public:
	Tree();//Constructor
	~Tree();//Destructor

	//Funciones que requerirá el programa.
	void insert_Data(Nodo*&, int, Nodo*);
	void Destroy_Data(Nodo*);
	void Show(Nodo*, int);
	void show_All(Nodo*, int);
	void Delete_All(Nodo*, int);
	//bool search_Data(Nodo*, int);
	void Delete_Data(Nodo*);
	void Show_Data_Preorder(Nodo*);
	int Count_Data(Nodo*);
	int Count_Data_leaf(Nodo*);
	void Delete_Data_Leaf(Nodo*&, Nodo*&);
	int Tree_Height(Nodo*);
	bool right_Branch(Nodo*&);
	void Change_Someone(Nodo*, Nodo*);

	Nodo* minumium_Data(Nodo*);
	Nodo* maximium_Data(Nodo*);
};
