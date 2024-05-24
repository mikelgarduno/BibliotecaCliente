
#include <stdio.h> 
#include <stdlib.h>
#include "menu.h"
#include "../include/Autor.h"
#include "../include/Categoria.h"
#include "../include/Editorial.h"
#include "../include/Libro.h"
#include "socket.h"
#include <winsock2.h>
#include <windows.h>
#include <unistd.h>
#include <string>




void imprimirMenuPrincipal(){ 		//Funcion para imprimir el menu principal


printf(
		"\n############################\n" 
		"#//////////////////////////#\n"
		"#     	  BIBLIOTECA        #\n" 
		"#//////////////////////////#\n" 
		"############################\n" 
		"#                          #\n" 
	 	"#  1. Descargar Libro      #\n" 
		"#  2. Subir Libro          #\n" 
		"#  3. Borrar Libro         #\n"
		"#  4. Registrar Autor      #\n" 
		"#  5. Registrar Editorial  #\n" 
		"#  6. Registrar Categoria  #\n" 
		"#  7. Salir                #\n"
		"#                          #\n"
		"############################\n" 
		"#      Inserte numero      #\n" 
		"############################\n"
	);
fflush(stdout);
}

int seleccionarOpcionMenus() { //Funcion para seleccionar una opcion del menu
	int input;
	scanf("%d", &input);
	fflush(stdin);
	return input;

}

//Funcion para gestionar los submenus
void gestionarSubmenus(int n, SOCKET* s) {

	switch (n) {
	    case 1:
	      MenuDescargar(s);
	      break;

	    case 2:
	      MenuSubir(s);
	      break;

	    case 3:
		  MenuBorrarLibro(s);
		  break;

		case 4:
		  MenuRegistrarAutor(s);
		  break;

	    case 5:
		    MenuRegistrarEditorial(s);
		  break;

		case 6:
		
		  MenuRegistrarCategoria(s);
		  break;

		case 7:
		printf("Saliendo...\n");
		fflush(stdout);
		exit(0);
		break;
		

	    default:
			
			printf(
				"############################\n" 
				"#   INSERTE VALOR VALIDO   #\n"  
				"############################\n"
			);
			fflush(stdout);
			sleep(1);
			
			

	}

}
//Funcion para descargar un libro
void MenuDescargar(SOCKET* s) { 
system("cls");
	int opcion;

	printf("############################\n");
	printf("#--------------------------#\n");
    printf("Buscar por:\n");
    printf("1) Autor\n");
    printf("2) Titulo\n");
    printf("3) Categoria\n");
    printf("4) Editorial\n");
	printf("#--------------------------#\n");
	printf("############################\n");
    printf("Ingrese el numero correspondiente a la opcion deseada: ");
	fflush(stdout);
    scanf("%d", &opcion);
	
	switch (opcion) {
        case 1:
		printf("Buscando por autor\n");
		fflush(stdout);
		//enviarComandoBuscarPorAutor(s);
			//buscarPorAutor();
            break;
        case 2:
		printf("Buscando por titulo\n");
		fflush(stdout);
		//enviarComandoBuscarPorTitulo(s);
           // buscarPorTitulo();
            break;
        case 3:
		printf("Buscando por categoria\n");
		fflush(stdout);
		//enviarComandoBuscarPorCategoria(s);
           // buscarPorCategoria();
            break;
        case 4:
		printf("Buscando por editorial\n");
		fflush(stdout);
		//enviarComandoBuscarPorEditorial(s);
            //buscarPorEditorial();
            break;
        default:
            printf("### Opción no válida ###\n");
            fflush(stdout);
			
    }
}
 //Funcion para subir un libro
void MenuSubir(SOCKET* s){
	system("cls");
	printf("Recuerde que para subir un libro, es necesario\nhaber registrado previamente el autor, la \neditorial y la categoria\n");
	fflush(stdout);
	char isbn[50];
	char titulo[50];
	int autor;
	int categoria;
	int editorial;
	char fecha[5];
	char contenido[5000];


	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          ISBN            #\n"
		"############################\n"
		"#     Inserte el ISBN      #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", isbn);
	system("cls");

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Titulo          #\n"
		"############################\n"
		"# Inserte nombre completo  #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%[^\n]s", titulo);
	system("cls");

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Fecha           #\n"
		"############################\n"
		"#      Inserte anyo        #\n"
		"#      de publicacion      #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", fecha);
	system("cls");

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#        Contenido         #\n"
		"############################\n"
		"#      Inserte texto       #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%[^\n]s", contenido);
	system("cls");
	
	//autor =  seleccionarAutor();
	//categoria = seleccionarCategoria();
	//editorial = seleccionarEditorial();
	Libro* objLibro;
	objLibro->setIsbn(isbn);
	objLibro->setTitulo(titulo);
	objLibro->setFechaCreacion(fecha);
	objLibro->setContenido(contenido);
	//objLibro->setAutor(autor);
	//objLibro->setCategoria(categoria);
	//objLibro->setEditorial(editorial);
	//enviarComandoSubirLibro(s, *objLibro);
}

//Menu para borrar un libro
void MenuBorrarLibro(SOCKET* s){ 
	system("cls");
	char isbn[50];
	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          ISBN            #\n"
		"############################\n"
		"#     Inserte el ISBN      #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", isbn);
	system("cls");
	enviarComandoBorrarLibro(s, isbn);
}

//Menu para registrar un autor
void MenuRegistrarAutor(SOCKET* s){
	system("cls");
	char nombre[50];
	char lugar[50];
	char fecha[5];
	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Nombre          #\n"
		"############################\n"
		"#     Inserte el nombre    #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", nombre);
	system("cls");

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#     Lugar nacimiento     #\n"
		"############################\n"
		"#     Inserte el lugar  #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", lugar);
	system("cls");

	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Fecha           #\n"
		"############################\n"
		"#      Inserte anyo        #\n"
		"#      de nacimiento       #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", fecha);
	system("cls");
	Autor* objAutor;
	objAutor->setDate(fecha);
	objAutor->setName(nombre);
	objAutor->setPlace(lugar);
	enviarComandoRegistrarAutor(s, *objAutor);
}

//Menu para registrar una editorial
void MenuRegistrarEditorial(SOCKET* s){
	system("cls");
	char nombre[50];
	char fecha[50];
	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Nombre          #\n"
		"############################\n"
		"#     Inserte el nombre    #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", nombre);
	system("cls");
	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Fecha           #\n"
		"############################\n"
		"#  Inserte anyo fundacion  #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", fecha);
	system("cls");

	Editorial* objEditorial;
	objEditorial->setFecha(fecha);
	objEditorial->setName(nombre);
	enviarComandoRegistrarEditorial(s, *objEditorial);
}

//Menu para registrar una categoria
void MenuRegistrarCategoria(SOCKET* s){
	system("cls");
	char nombre[50];
	printf(
		"############################\n"
		"#        Introducir        #\n"
		"#          Nombre          #\n"
		"############################\n"
		"#     Inserte el nombre    #\n"
		"############################\n"
	);
	fflush(stdout);
	scanf("%s", nombre);
	system("cls");
	Categoria* objCategoria = new Categoria();
	objCategoria->setName(nombre);
	enviarComandoRegistrarCategoria(s, *objCategoria);
}


#include <fstream> 
#include <iostream>

void descargarLibro(char* titulo, char* contenido){
	std::string nombre = std::string(titulo) + ".txt";
	std::ofstream file(nombre);

	
	if (file.is_open()) {
		file << contenido;
		file.close();
		std::cout << "File created successfully: " << nombre << std::endl;
	} else {
		std::cout << "Failed to create file: " << nombre << std::endl;
	}
}
