#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Astronauta.h"
#include "Nave.h"
#include "Mision.h"

int main()
{
    Astronauta nuevo;
    nuevo=cargaAstronauta();
    printf("%s ",nuevo.Nombre);
    return 0;
}
