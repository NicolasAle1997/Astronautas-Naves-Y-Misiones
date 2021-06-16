#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Astronauta.h"

///ACA SE CREAN LAS FUNCIONES DE ASTRONAUTA, PARA UTILIZARLAS DEBEN LLAMAR A LAS FUNCIONES EN EL MAIN.



Astronauta cargaAstronauta()
{
    Astronauta p;
    printf("\nIngresar el nombre:  ");
    scanf("%s", &p.Nombre);

    return p;
}
