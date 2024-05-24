
#include "socket.h"
#include "menu.h"
#include <winsock2.h>
#include <stdio.h>

int main(void) {
	printf("¡Bienvenido a la Biblioteca virtual del futuro!\n");
	SOCKET s;
	inicializarSocket(&s);
while (1){
	imprimirMenuPrincipal();
	gestionarSubmenus(seleccionarOpcionMenus(),&s);
	}
	return 0;
}

