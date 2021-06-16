#include <stdio.h>
#include <stdlib.h>
#include "Astronauta.h"

int main()
{
    Astronauta nuevo;
    nuevo=cargaAstronauta();
    printf("%s ",nuevo.Nombre);
    return 0;
}
