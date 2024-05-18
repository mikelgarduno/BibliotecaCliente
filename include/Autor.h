/*
 * Autor.h
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */

#ifndef INCLUDE_AUTOR_H_
#define INCLUDE_AUTOR_H_

class Autor {
	protected: 
	char *name;
	char *date;
	char *place;
public:
	Autor();
	Autor(char *name, char *date, char *place);
	Autor(const Autor &a);
	virtual ~Autor();
	char *getName() const;
	void setName(char *name);
	char *getDate() const;
	void setDate(char *date);
	char *getPlace() const;
	void setPlace(char *place);
	void imprimirAutor();
};

#endif /* INCLUDE_AUTOR_H_ */
