#ifndef MISION_H_INCLUDED
#define MISION_H_INCLUDED

///EN EL CASO DE QUE EN LA ESTRUCTURA HAYA UN TIPO DE DATO DE OTRA ESTRUCTURA, USAR #INCLUDE ..NOMBRE ESTRUCTURA...

///No crear constantes , ni definir nada (no arranca el programa sino)

///EN EL CASO DE QUE EN LA ESTRUCTURA HAYA UN TIPO DE DATO DE OTRA ESTRUCTURA, USAR #INCLUDE ..NOMBRE ESTRUCTURA...
///HEADER DE ASTRONAUTA , AQUI SE PONEN LAS CABECERAS DE ASTRONAUTA.

/*
    AQUI PONDREMOS:
    |-> ESTRUCTURAS
    |-> ENCABEZADOS DE NUESTRAS FUNCIONES DE ASTRONAUTA (NO VAN LAS FUNCIONES ACA).
*/


/********************************************/

typedef struct
{
    int Id;
    int IDnave;
    char Estado[20]; /// (Listo, En vuelo, Retornada, Cancelada, Fallida)
    char Destino[20]; ///  Destino (EEI, Órbita terrestre, Luna, etc)
    char Cargamento[20]; /// Satelite, Insumos para la EEI, El auto de Elon musk , etc )
    int Tripulantes;  /// (Guardar sus ID)
    char DetalleDeLaMision[20];
}Mision;



///POR FAVOR NO BORRAR NADA
#endif // MISION_H_INCLUDED
