//Nodo.cpp
#include "Nodo.h"

Nodo::Nodo(int dato, Nodo* principal) {
    Dato = dato;
    Principal = principal;
    Der = NULL;//Tanto el nodo izquierdo como el derecho deben ser inicializados en NULL porque serán valores de entrada a esperar.
    Izq = NULL;
}

Nodo::~Nodo() {}//Destructor sencillo.

//Implementación de los seters y geters.
void Nodo::set_Data(int dato) {
    Dato = dato;
}

int Nodo::get_Data() {
    return Dato;
}

void Nodo::set_Principal(Nodo* principal) {
    Principal = principal;
}

Nodo*& Nodo::get_Principal() {
    return Principal;
}

void Nodo::set_Der(Nodo* der) {
    Der = der;
}

Nodo*& Nodo::get_Der() {
    return Der;
}

void Nodo::set_Izq(Nodo* izq) {
    Izq = izq;
}

Nodo*& Nodo::get_Izq() {
    return Izq;
}