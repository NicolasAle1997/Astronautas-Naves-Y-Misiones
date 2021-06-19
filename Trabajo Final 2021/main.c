#include <stdlib.h>
#include <stdio.h>
#include <string.h>

///SE LLAMAN SOLO A LAS 3 LIBRERIAS AL MISMO TIEMPO EN EL MAIN, SINO PUEDE ROMPERSE EL PROGRAMA.
#include "Astronauta.h"
#include "Nave.h"
#include "Mision.h"
#include "Menu.h"

#define ESC 27


int main()
{
    int opcion;
    int id=0;

    do
    {
        printf("\nOPCION 1 - CARGA ASTRONAUTA.");
        printf("\nOPCION 2 - LISTA DE ASTRONAUTAS.");
        printf("\nOPCION 3 - BUSCA ASTRONAUTA POR ID.");
        printf("\nOPCION 4 - MODIFICA UN ASTRONAUTA.");


        opcion=ingresarOpcion();
        switch(opcion)
        {
        case 1:
        {
            CargaArchivoVariasVeces();
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            MuestraArchivoDeAstronauta();
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            printf("\nINGRESAR ID: \n");
            scanf("%d",&id);
            MuestraAstronautaPorID(id);
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            printf("\nINGRESAR ID PARA MODIFICAR ASTRONAUTA: \n");
            scanf("%d",&id);
            ModificaArchivoDeAstronauta(id);
            system("pause");
            system("cls");
            break;
        }
        }
    }
    while(opcion!=ESC);



    return 0;
}

