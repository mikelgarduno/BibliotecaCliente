/*
 * socket.cpp
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */
#include <winsock2.h>
#include "socket.h"
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



