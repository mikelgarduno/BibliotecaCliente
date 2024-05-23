/*
 * main.cpp
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */
#include "socket.h"
#include "menu.cpp"
#include <winsock2.h>

int main(void) {
	SOCKET s;
	inicializarSocket(&s);
	imprimirMenuPrincipal();
	int opcion = seleccionarOpcionMenus();
	gestionarSubmenus(opcion);
	
	return 0;
}

