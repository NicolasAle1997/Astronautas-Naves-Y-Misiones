#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"

#define ESC 27
///ACA SE CREAN LAS FUNCIONES DE MENU, PARA UTILIZARLAS DEBEN LLAMAR A LAS FUNCIONES EN EL MAIN.


///**************************************************************************************///
///
///
///
///**************************************************************************************///

void imprimirCabecera(char cabecera[])
{
    int i;
    printf ("\t\t\t\t %c", 201);
    for(i= 0; i<52; i++)
    {
        printf ("%c", 205);
    }
    printf("%c\n", 187);
    printf("\t\t\t\t  %32s  \n",cabecera);
    printf("\t\t\t\t %c", 200);
    for(i=0; i<52;i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
}

///**************************************************************************************///
///
///
///
///**************************************************************************************///

void iniciarMenu()
{
    system("cls");
    printf("\n\n\n\n");
    imprimirOpcionesMenu();

}

///**************************************************************************************///
///
///
///
///**************************************************************************************///

void imprimirOpcionesMenu()
{
    printf ("\n\n\n\n");
    imprimirCabecera("[MENÚ PRINCIPAL]");
    printf ("\n\n\n\t\t\t\t 1. ASTRONAUTAS. \n");
    printf ("\t\t\t\t 2. NAVES. \n");
    printf ("\n\t\t\t 3. MISIONES. \n");
    printf ("\t\t\t\t 0. Salir \n");
}

///**************************************************************************************///
///
///
///
///**************************************************************************************///

int ingresarOpcion()
{
    int opcion;
    printf ("\n\n\n\t Ingrese opcion:");
    scanf("%i", &opcion);
    return opcion;
}

///**************************************************************************************///
///
///
///
///**************************************************************************************///

///falta crear las funciones con los printf y menu con sus respectivas opciones.

