/*
 * Editorial.h
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */

#ifndef INCLUDE_EDITORIAL_H_
#define INCLUDE_EDITORIAL_H_

class Editorial {
	protected:
	char *name;
	char *fecha;
public:
	Editorial();
	Editorial(const char *name, const char *fecha);
	Editorial(const Editorial &other);
	virtual ~Editorial();
	char* getName();
	char* getFecha();
	void setName(const char *name);
	void setFecha(const char *fecha);
	void imprimirEditorial();
};

#endif /* INCLUDE_EDITORIAL_H_ */
