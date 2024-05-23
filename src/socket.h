/*
 * socket.h
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */
#ifndef SOCKET_H_
#define SOCKET_H_

#include <winsock2.h>
#include "../include/Autor.h"
#include "../include/Libro.h"
#include "../include/Categoria.h"
#include "../include/Editorial.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int inicializarSocket(SOCKET* s);
void enviarComandoRegistrarAutor(SOCKET* s, Autor& a);
void enviarComandoRegistrarLibro(SOCKET* s, Libro& l);
void enviarComandoRegistrarCategoria(SOCKET* s, Categoria& c);
void enviarComandoRegistrarEditorial(SOCKET* s, Editorial& e);
void enviarComandoBorrarLibro(SOCKET* s, char* isbn);

//Autor* pedirListaAutores ();
//Libro* pedirListaLibros ();
//Categoria* pedirListaCategorias ();
//Editorial* pedirListaAutores ();


#endif /* SOCKET_H_ */
