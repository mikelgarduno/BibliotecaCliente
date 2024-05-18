/*
 * Categoria.h
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */

#ifndef INCLUDE_CATEGORIA_H_
#define INCLUDE_CATEGORIA_H_

class Categoria {
	protected:
	char *name;
public:
	Categoria();
	Categoria(const char *nombre);
	Categoria(const Categoria &other);
	virtual ~Categoria();
	char* getName();
	void setName(const char *nombre);
	void imprimirCategoria();
};

#endif /* INCLUDE_CATEGORIA_H_ */
