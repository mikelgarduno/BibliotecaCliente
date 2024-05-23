/*
 * Libro.cpp
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */

#include "Libro.h"
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

Libro::Libro() {
	this->isbn= new char[1];
	strcpy(this->isbn,"");
	this->titulo= new char[1];
	strcpy(this->titulo,"");
	this->fechaCreacion= new char[1];
	strcpy(this->fechaCreacion,"");
	this->autor= new Autor();
	this->editorial= new Editorial();
	this->categoria= new Categoria();
	this->contenido= new char[1];
	strcpy(this->contenido,"");
}
Libro::Libro(char *isbn ,const char *titulo, Autor *autor, Editorial *editorial, Categoria *categoria, char *contenido, char *fechaCreacion) {
	this->isbn= new char[strlen(isbn)+1];
	strcpy(this->isbn,isbn);
	this->titulo= new char[strlen(titulo)+1];
	strcpy(this->titulo,titulo);
	this->fechaCreacion= new char[strlen(fechaCreacion)+1];
	strcpy(this->fechaCreacion,fechaCreacion);
	this->autor= new Autor(*autor);
	this->editorial= new Editorial(*editorial);
	this->categoria= new Categoria(*categoria);
	this->contenido= new char[strlen(contenido)+1];
	strcpy(this->contenido,contenido);
}

Libro::~Libro() {
	delete[] isbn;
	delete[] titulo;
	delete[] fechaCreacion;
	delete[] contenido;
}

Libro::Libro(const Libro &other) {
	this->isbn= new char[strlen(other.isbn)+1];
	strcpy(this->isbn,other.isbn);
	this->titulo= new char[strlen(other.titulo)+1];
	strcpy(this->titulo,other.titulo);
	this->fechaCreacion= new char[strlen(other.fechaCreacion)+1];
	strcpy(this->fechaCreacion,other.fechaCreacion);
	this->autor= new Autor(*other.autor);
	this->editorial= new Editorial(*other.editorial);
	this->categoria= new Categoria(*other.categoria);
	this->contenido= new char[strlen(other.contenido)+1];
	strcpy(this->contenido,other.contenido);

}

char* Libro::getIsbn(){
	return this->isbn;

}
char* Libro::getTitulo(){
	return this->titulo;

}
char* Libro::getFechaCreacion(){
	return this->fechaCreacion;
}

Autor* Libro::getAutor(){
	return this->autor;
}

Editorial* Libro::getEditorial(){
	return this->editorial;
}

Categoria* Libro::getCategoria(){
	return this->categoria;
}

char* Libro::getContenido(){
	return this->contenido;
}

void Libro::setIsbn(char* isbn){
	delete[] this->isbn;
	this->isbn = new char[strlen(isbn)+1];
	strcpy(this->isbn, isbn);
}

void Libro::setTitulo(const char *titulo){
	delete[] this->titulo;
	this->titulo = new char[strlen(titulo)+1];
	strcpy(this->titulo, titulo);
}

void Libro::setFechaCreacion(char* fechaCreacion){
	delete[] this->fechaCreacion;
	this->fechaCreacion = new char[strlen(fechaCreacion)+1];
	strcpy(this->fechaCreacion, fechaCreacion);
}

void Libro::setAutor(Autor *autor){
	delete this->autor;
	this->autor = new Autor(*autor);
}
void Libro::setEditorial(Editorial *editorial){
	delete this->editorial;
	this->editorial = new Editorial(*editorial);
}

void Libro::setCategoria(Categoria *categoria){
	delete this->categoria;
	this->categoria = new Categoria(*categoria);
}

void Libro::setContenido(char* contenido){
	delete[] this->contenido;
	this->contenido = new char[strlen(contenido)+1];
	strcpy(this->contenido, contenido);
}

void Libro::imprimirLibro(){
	cout << "ISBN: " << this->isbn << endl;
	cout << "Título: " << this->titulo << endl;
	cout << "Fecha de Creación: " << this->fechaCreacion << endl;
	cout << "Autor: " << this->autor->getName() << endl;
	cout << "Editorial: " << this->editorial->getName() << endl;
	cout << "Categoría: " << this->categoria->getName() << endl;
	cout << "Contenido: " << this->contenido << endl;
}
	