/*
 * menu.cpp
 *
 *  Created on: 18 may 2024
 *      Author: mikel
 */
//#include "../include/menu.h"
#include <stdio.h> 
#include <stdlib.h>

#include "../include/autor.h"
#include "../include/categoria.h"
#include "../include/editorial.h"
#include "../include/libro.h"
#include "../include/sqlManager.h"

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
		"#  3. Modificar Libro      #\n" 
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

void gestionarSubmenus(int n) { //Funcion para gestionar los submenus

	switch (n) {
	    case 1:
	      MenuDescargar();
	      break;

	    case 2:
	      MenuSubir();
	      break;

	    case 3:
		  MenuBorrarLibro();
		  break;

		case 4:
		  MenuRegistrarAutor();
		  break;

	    case 5:
		    MenuRegistrarEditorial();
		  break;

		case 6:
		
		  MenuRegistrarCategoria();
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

void MenuDescargar() { //Funcion para descargar un libro
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
			//buscarPorAutor();
            break;
        case 2:
		printf("Buscando por titulo\n");
		fflush(stdout);
           // buscarPorTitulo();
            break;
        case 3:
		printf("Buscando por categoria\n");
		fflush(stdout);
           // buscarPorCategoria();
            break;
        case 4:
		printf("Buscando por editorial\n");
		fflush(stdout);
            //buscarPorEditorial();
            break;
        default:
            printf("Opción no válida\n");
            fflush(stdout);
			
    }
}

void MenuSubir(){ //Funcion para subir un libro
	system("cls");
	printf("Recuerde que para subir un libro, es necesario\nhaber registrado previamente el autor, la editorial y la categoria\n");
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

	/*if(comprobarLibroExistente(isbn)==1){
		Libro* objLibro;
		objLibro = crear_libro(isbn, titulo, autor, editorial,categoria,fecha, contenido);
		insertarLibro(*objLibro);
		destruir_libro(objLibro);
	}*/
}
