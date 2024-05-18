/*
 * Categoria.cpp
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */

#include "Categoria.h"
#include <cstring>
#include <iostream>

Categoria::Categoria(const char *nombre) {
	this->name= new char[strlen(nombre)+1];
	strcpy(this->name,nombre);

}
Categoria::Categoria() {
	this->name= new char[1];
	strcpy(this->name,"");

}

Categoria::Categoria(const Categoria &other) {
	this->name= new char[strlen(other.name)+1];
	strcpy(this->name,other.name);
}

Categoria::~Categoria() {
	delete[] name;
}

char* Categoria::getName() {
	return name;
}
void Categoria::setName(const char *nombre) {
	delete[] name;
	this->name= new char[strlen(nombre)+1];
	strcpy(this->name,nombre);
}
void Categoria::imprimirCategoria(){
	std::cout << "Categoria: " << name << std::endl;
}
