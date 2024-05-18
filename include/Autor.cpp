/*
 * Autor.cpp
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */

#include "Autor.h"
#include <cstring>
#include <iostream>

Autor::Autor(char *name, char *date, char *place) {
	this->name= new char[strlen(name)+1];
	strcpy(this->name,name);
	this->date= new char[strlen(date)+1];
	strcpy(this->date,date);
	this->place= new char[strlen(place)+1];
	strcpy(this->place,place);

}
Autor::Autor() {
	this->name= new char[1];
	strcpy(this->name,"");
	this->date= new char[1];
	strcpy(this->date,"");
	this->place= new char[1];
	strcpy(this->place,"");
}
Autor::Autor(const Autor &a) {
	this->name= new char[strlen(a.name)+1];
	strcpy(this->name,a.name);
	this->date= new char[strlen(a.date)+1];
	strcpy(this->date,a.date);
	this->place= new char[strlen(a.place)+1];
	strcpy(this->place,a.place);
}

char *Autor::getDate() const {
	return date;
}

char *Autor::getName() const {
	return name;
}
char *Autor::getPlace() const {
	return place;
}

void Autor::setName(char *name) {
	this->name = name;
}

void Autor::setPlace(char *place) {
	this->place = place;
}
void Autor::setDate(char *date) {
	this->date = date;
}
 
void Autor::imprimirAutor(){
	printf("Nombre: %s\n",name);
	printf("Fecha de nacimiento: %s\n",date);
	printf("Lugar de nacimiento: %s\n",place);
}

Autor::~Autor() {
	delete[] name;
	delete[] date;
	delete[] place;
}

