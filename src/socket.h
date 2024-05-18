/*
 * socket.h
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */
#ifndef SOCKET_H_
#define SOCKET_H_

#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int inicializarSocket(SOCKET* s);
//void registrarAutor(Autor);
//void registrarCategoria(Categoria);
//void registrarLibro(Libro);
//void registrarEditorial(Editorial);
//void mandarBorrado();

#endif /* SOCKET_H_ */
