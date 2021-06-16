/********************************************/
///POR FAVOR NO BORRAR NADA

#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED
///EN EL CASO DE QUE EN LA ESTRUCTURA HAYA UN TIPO DE DATO DE OTRA ESTRUCTURA, USAR #INCLUDE ..NOMBRE ESTRUCTURA...
///HEADER DE ASTRONAUTA , AQUI SE PONEN LAS CABECERAS DE ASTRONAUTA.

/*
    AQUI PONDREMOS:
    |-> ESTRUCTURAS
    |-> ENCABEZADOS DE NUESTRAS FUNCIONES DE ASTRONAUTA (NO VAN LAS FUNCIONES ACA).
*/

typedef struct
{
    int Id;
    char Nombre[25];
    char Apellido[25];
    char Apodo[25];
    int Edad;
    char Nacionalidad[5][25];
    char Especialidad[25];//
    int HorasDeVueloAcumuladas;
    int MisionesEspacialesRealizadas;
    int HorasEnLaEstacionEspacial;
    int Estado; // 1 o 0
} Astronauta;

Astronauta cargaAstronauta();

/********************************************/





///POR FAVOR NO BORRAR NADA
#endif // ASTRONAUTA_H_INCLUDED
