/*
 * socket.cpp
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */
#include <winsock2.h>
#include "socket.h"
#include "../include/Autor.h"
#include "../include/Libro.h"
#include <iostream>


using namespace std;

int inicializarSocket(SOCKET* s){
	WSADATA wsaData;
	struct sockaddr_in server;

	cout << "Iniciando libreria socket\n" << endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << " No se ha podido inicializar la libreria socket. Codigo de error: "<< WSAGetLastError() << endl;
		return -1;
	}
	cout << "Libreria socket inicializada" << endl;

	//SOCKET creation
	if ((*s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		cout << "No se ha podido crear el socket. Codigo de error: "<< WSAGetLastError() << endl;
		WSACleanup();
		return -1;
	}
	cout << "Socket creado correctamente" << endl;

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(*s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		cout << "Error al conectar el socket. Codigo de error: "
				<< WSAGetLastError() << endl;
		closesocket(*s);
		WSACleanup();
		return -1;
	}

	cout << "Conexion establecida con: " << inet_ntoa(server.sin_addr) << " ("
			<< ntohs(server.sin_port) << ")" << endl;
	return 0;
}

void enviarComandoRegistrarAutor(SOCKET* s, Autor& a){
	char sendBuffer[1024];
	char recvBuffer[1024];

	strcpy(sendBuffer, "REGISTRAR_AUTOR");
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, a.getName());
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, a.getDate());
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, a.getPlace());
	send(*s, sendBuffer, strlen(sendBuffer), 0);
}

void enviarComandoRegistrarLibro(SOCKET* s, Libro& l){
	char sendBuffer[1024]; char recvBuffer[1024];
	strcpy(sendBuffer, "REGISTRAR_LIBRO");
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, l.getTitulo());
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, l.getIsbn());
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, l.getAutor()->getName());
	send(*s, sendBuffer, strlen(sendBuffer), 0);
	strcpy(sendBuffer, l.getAutor()->getDate());
	send(*s, sendBuffer, strlen(sendBuffer), 0);
	strcpy(sendBuffer, l.getAutor()->getPlace());
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, l.getEditorial()->getName());
	send(*s, sendBuffer, strlen(sendBuffer), 0);
	strcpy(sendBuffer, l.getEditorial()->getFecha());
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, l.getFechaCreacion());
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, l.getCategoria()->getName());
	send(*s, sendBuffer, strlen(sendBuffer), 0);

	strcpy(sendBuffer, l.getContenido());
	send(*s, sendBuffer, strlen(sendBuffer), 0);
}
void enviarComandoRegistrarCategoria(SOCKET* s, Categoria& c) {
    char sendBuffer[1024];
    char recvBuffer[1024];

    strcpy(sendBuffer, "REGISTRAR_CATEGORIA");
    send(*s, sendBuffer, strlen(sendBuffer), 0);

    strcpy(sendBuffer, c.getName());
    send(*s, sendBuffer, strlen(sendBuffer), 0);

    int bytesRecibidos = recv(*s, recvBuffer, 1024, 0);
    if (bytesRecibidos > 0) {
        recvBuffer[bytesRecibidos] = '\0';
        printf("Respuesta del servidor: %s\n", recvBuffer);
	}
}

void enviarComandoRegistrarEditorial(SOCKET* s, Editorial& e) {
    char sendBuffer[1024];
    char recvBuffer[1024];

    strcpy(sendBuffer, "REGISTRAR_EDITORIAL");
    send(*s, sendBuffer, strlen(sendBuffer), 0);

    strcpy(sendBuffer, e.getName());
    send(*s, sendBuffer, strlen(sendBuffer), 0);

    strcpy(sendBuffer, e.getFecha());
    send(*s, sendBuffer, strlen(sendBuffer), 0);

    // Aquí puedes agregar más campos de la editorial si los hay

    // Recibir la respuesta del servidor
    int bytesRecibidos = recv(*s, recvBuffer, 1024, 0);
    if (bytesRecibidos > 0) {
        recvBuffer[bytesRecibidos] = '\0'; // Asegurarse de que la cadena esté terminada
        printf("Respuesta del servidor: %s\n", recvBuffer);
    }
}
