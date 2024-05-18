/*
 * Libro.h
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */

#ifndef INCLUDE_LIBRO_H_
#define INCLUDE_LIBRO_H_
#include "Autor.h"
#include "Editorial.h"
#include "Categoria.h"

class Libro {
	protected:
	char *isbn;
	char *titulo;
	char *fechaCreacion;
	Autor *autor;
	Editorial *editorial;
	Categoria *categoria;
	char* contenido;

public:
	Libro();
	Libro(char* isbn ,const char *titulo, Autor *autor, Editorial *editorial, Categoria *categoria, char* contenido, char* fechaCreacion);
	Libro(const Libro &other); 
	virtual ~Libro();
	char* getIsbn();
	char* getTitulo();
	char* getFechaCreacion();
	Autor* getAutor();
	Editorial* getEditorial();
	Categoria* getCategoria();
	char* getContenido();
	void setIsbn(char* isbn);
	void setTitulo(const char *titulo);
	void setFechaCreacion(char* fechaCreacion);
	void setAutor(Autor *autor);
	void setEditorial(Editorial *editorial);
	void setCategoria(Categoria *categoria);
	void setContenido(char* contenido);
	void imprimirLibro();
	
};

#endif /* INCLUDE_LIBRO_H_ */
