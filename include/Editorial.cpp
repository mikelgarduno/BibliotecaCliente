/*
 * Editorial.cpp
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */

#include "Editorial.h"
#include <iostream>
#include <string.h>

Editorial::Editorial(){
	this->name= new char[1];
	strcpy(this->name,"");
	this->fecha= new char[1];
	strcpy(this->fecha,"");

}

Editorial::Editorial(const char *name, const char *fecha) {
	this->name= new char[1];
	strcpy(this->name,"");
	this->fecha= new char[1];
	strcpy(this->fecha,"");
}

Editorial::~Editorial() {
	delete[] name;
	delete[] fecha;
}

Editorial::Editorial(const Editorial &other) {
	this->name= new char[strlen(other.name)+1];
	strcpy(this->name,other.name);
	this->fecha= new char[strlen(other.fecha)+1];
	strcpy(this->fecha,other.fecha);

}
void Editorial::setName(const char *name) {
	delete[] this->name;
	this->name= new char[strlen(name)+1];
	strcpy(this->name,name);
}
void Editorial::setFecha(const char *fecha) {
	delete[] this->fecha;
	this->fecha= new char[strlen(fecha)+1];
	strcpy(this->fecha,fecha);
}
char* Editorial::getName() {
	return name;
}
char* Editorial::getFecha() {
	return fecha;
}
void Editorial::imprimirEditorial(){
	std::cout << "Editorial: " << name << " Fecha: " << fecha << std::endl;
}


