#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED

///EN EL CASO DE QUE EN LA ESTRUCTURA HAYA UN TIPO DE DATO DE OTRA ESTRUCTURA, USAR #INCLUDE ..NOMBRE ESTRUCTURA...
///No crear constantes , ni definir nada (no arranca el programa sino)
///HEADER DE ASTRONAUTA , AQUI SE PONEN LAS CABECERAS DE ASTRONAUTA y ESTRUCTURA.

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

///FUNCIONES BASICAS PARA LOS ASTRONAUTAS
Astronauta Crear();
Astronauta Especialidades();
void GuardaUnAstronauta(Astronauta nuevo, char nombreArchivo[]);
void CargaArchivoVariasVeces();
int id_nuevo();

///FUNCIONES BASICAS PARA MOSTRAR ASTRONAUTAS.
void MostrarAstronauta(Astronauta X);
void MuestraArchivoDeAstronauta();
void MuestraAstronautaPorID(int id);

///FUNCIONES PARA MODIFICAR ASTRONAUTA.
int ModificaArchivoDeAstronauta(int id);
Astronauta Modificaciones(Astronauta modifica);
///
int existeAstronauta (int AstronautaId);
int buscaPos(int id);
void bajaAstronauta(int idAstronautaBaja);
/// Función que pasa clientes en alta o baja a un archivo:
void creaArchivo (char nombreArchivo [], int bajaOalta);

///POR FAVOR NO BORRAR NADA

#endif // ASTRONAUTA_H_INCLUDED
