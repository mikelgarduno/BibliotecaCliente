/*
 * menu.h
 *
 *  Created on: 23 may 2024
 *      Author: ikera
 */

#ifndef MENU_H_
#define MENU_H_
#include <winsock2.h>

void imprimirMenuPrincipal();
int seleccionarOpcionMenus();
void gestionarSubmenus(int n, SOCKET* s);

void MenuDescargar();
void MenuSubir();
void MenuModificar();
void MenuRegistrarAutor(SOCKET* s);
void MenuRegistrarEditorial(SOCKET* s);
void MenuRegistrarCategoria(SOCKET* s);
void MenuBorrarLibro(SOCKET* s);



#endif /* MENU_H_ */
