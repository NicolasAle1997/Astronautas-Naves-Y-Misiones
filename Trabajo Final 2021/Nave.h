#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED


///EN EL CASO DE QUE EN LA ESTRUCTURA HAYA UN TIPO DE DATO DE OTRA ESTRUCTURA, USAR #INCLUDE ..NOMBRE ESTRUCTURA...

///No crear constantes , ni definir nada (no arranca el programa sino)


///EN EL CASO DE QUE EN LA ESTRUCTURA HAYA UN TIPO DE DATO DE OTRA ESTRUCTURA, USAR #INCLUDE ..NOMBRE ESTRUCTURA...
///HEADER DE NAVE , AQUI SE PONEN LAS CABECERAS DE NAVE.

/*
    AQUI PONDREMOS:
    |-> ESTRUCTURAS
    |-> ENCABEZADOS DE NUESTRAS FUNCIONES DE NAVE (NO VAN LAS FUNCIONES ACA).
*/

typedef struct
{
    int Id;
    char TipoDeNave[20];
    int CantidadDeVuelosRealizados;
    int HorasDeVueloAcumuladas;
    int Estado; ///(0- mantenimiento 1- Lista para su uso 2- Actualmente en misi�n 3- De baja)
}Nave;



/********************************************/





///POR FAVOR NO BORRAR NADA
#endif // NAVE_H_INCLUDED
