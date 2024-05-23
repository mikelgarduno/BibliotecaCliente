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
#include "../include/Categoria.h"
#include "../include/Editorial.h"
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
	int bytesEnviados;
    int bytesRecibidos;

	strcpy(sendBuffer, "REGISTRAR_AUTOR");
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar comando REGISTRAR_AUTOR\n");
		return;
	}

	strcpy(sendBuffer, a.getName());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el nombre del autor\n");
		return;
	}

	strcpy(sendBuffer, a.getDate());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar la fecha del autor\n");
		return;
	}

	strcpy(sendBuffer, a.getPlace());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el lugar del autor\n");
		return;
	}
}

void enviarComandoRegistrarLibro(SOCKET* s, Libro& l){
	char sendBuffer[1024]; char recvBuffer[1024];
	int bytesEnviados;
    int bytesRecibidos;

	strcpy(sendBuffer, "REGISTRAR_LIBRO");
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar comando REGISTRAR_LIBRO\n");
		return;
	}
	strcpy(sendBuffer, l.getTitulo());
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el titulo\n");
		return;
	}

	strcpy(sendBuffer, l.getIsbn());
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el isbn\n");
		return;
	}

	strcpy(sendBuffer, l.getAutor()->getName());
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el nombre del autor\n");
		return;
	}
	
	strcpy(sendBuffer, l.getAutor()->getDate());
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar la fecha del autor\n");
		return;
	}
	strcpy(sendBuffer, l.getAutor()->getPlace());
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el lugar del autor\n");
		return;
	}

	strcpy(sendBuffer, l.getEditorial()->getName());
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el nombre de la editorial\n");
		return;
	}
	strcpy(sendBuffer, l.getEditorial()->getFecha());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar la fecha de la editorial\n");
		return;
	}

	strcpy(sendBuffer, l.getFechaCreacion());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar la fecha de creacion del libro\n");
		return;
	}

	strcpy(sendBuffer, l.getCategoria()->getName());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el nombre de la categoria\n");
		return;
	}

	strcpy(sendBuffer, l.getContenido());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el contenido del libro\n");
		return;
	}
}
void enviarComandoRegistrarCategoria(SOCKET* s, Categoria& c) {
    char sendBuffer[1024];
    char recvBuffer[1024]; 
	int bytesEnviados;
    int bytesRecibidos;

    strcpy(sendBuffer, "REGISTRAR_CATEGORIA");
    bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
    if (bytesEnviados == SOCKET_ERROR) {
        fprintf(stderr, "Error al enviar comando REGISTRAR_CATEGORIA\n");
        return;
    }

    strcpy(sendBuffer, c.getName());
    bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
        fprintf(stderr, "Error al enviar el nombre\n");
        return;
    }

    bytesRecibidos = recv(*s, recvBuffer, sizeof(recvBuffer) - 1, 0);
    if (bytesRecibidos == SOCKET_ERROR) {
        fprintf(stderr, "Error al recibir datos del servidor\n");
        return;
    }
	if (bytesRecibidos > 0) {
        recvBuffer[bytesRecibidos] = '\0'; // Terminar la cadena recibida
        printf("Respuesta del servidor: %s\n", recvBuffer);
    } else {
        fprintf(stderr, "El servidor cerró la conexión o no se recibieron datos\n");
    }

}

void enviarComandoRegistrarEditorial(SOCKET* s, Editorial& e) {
	char sendBuffer[1024];
	char recvBuffer[1024];
	int bytesEnviados;
    int bytesRecibidos;

	strcpy(sendBuffer, "REGISTRAR_EDITORIAL");
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar comando REGISTRAR_EDITORIAL\n");
		return;
	}

	strcpy(sendBuffer, e.getName());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el nombre de la editorial\n");
		return;
	}

	strcpy(sendBuffer, e.getFecha());
	bytesEnviados = send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar la fecha de la editorial\n");
		return;
	}

	bytesRecibidos = recv(*s, recvBuffer, sizeof(recvBuffer) - 1, 0);
	if (bytesRecibidos == SOCKET_ERROR) {
		fprintf(stderr, "Error al recibir datos del servidor\n");
		return;
	}
	if (bytesRecibidos > 0) {
		recvBuffer[bytesRecibidos] = '\0';
		printf("Respuesta del servidor: %s\n", recvBuffer);
	} else {
		fprintf(stderr, "El servidor cerró la conexión o no se recibieron datos\n");
	}
}

void enviarComandoBorrarLibro(SOCKET* s, char* isbn) {
    char sendBuffer[1024]; char recvBuffer[1024];
	int bytesEnviados;
    int bytesRecibidos;
	strcpy(sendBuffer, "BORRAR_LIBRO");
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar comando BORRAR_LIBRO\n");
		return;
	}

	strcpy(sendBuffer, isbn);
	bytesEnviados= send(*s, sendBuffer, strlen(sendBuffer), 0);
	if (bytesEnviados == SOCKET_ERROR) {
		fprintf(stderr, "Error al enviar el isbn\n");
		return;
	}


}

