#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Astronauta.h"
#include "Menu.h"


///ACA SE CREAN LAS FUNCIONES DE ASTRONAUTA, PARA UTILIZARLAS DEBEN LLAMAR A LAS FUNCIONES EN EL MAIN.
const char ArchivoAstronauta[]="AstronautasArch.dat";

#define ESC 27


///**************************************************************************************///
/// PARAMETROS: NO TIENE.
/// RETORNO: Un identificador autoincremental(0-1-2-3-4...) que se le asigna a los astronautas nuevos.
/// FUNCION: SE ENCARGA EN QUE NO SE REPITAN LOS ID.
///**************************************************************************************///

int id_nuevo()
{
    int idnuevo=0;
    Astronauta aux;

    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");

    if(pArchAstronauta!=NULL)
    {
        while(fread(&aux,sizeof(Astronauta),1,pArchAstronauta) > 0)
        {
            idnuevo=aux.Id+1;
        }
        fclose(pArchAstronauta);
    }
    return idnuevo;
}

///**************************************************************************************///
/// PARAMETROS: No tiene.
/// RETORNO: Un tipo de dato "Astronauta" con sus respectivos campos completados por el usuario.
/// FUNCION: ES LA PLANILLA DE REGISTRO QUE USA CADA ASTRONAUTA.
///**************************************************************************************///

Astronauta Crear()
{
    Astronauta nuevo;
    Astronauta aux;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    nuevo.Id=id_nuevo();

    printf("\nNombre: ");
    fflush(stdin);
    gets(nuevo.Nombre);

    printf("\nApellido: ");
    fflush(stdin);
    gets(nuevo.Apellido);

    printf("\nApodo: ");
    fflush(stdin);
    gets(nuevo.Apodo);

    printf("\nEdad: ");
    scanf("%d",&nuevo.Edad);

    printf("\nNacionalidad: ");
    fflush(stdin);
    scanf("%s",&nuevo.Nacionalidad);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    nuevo.Estado=0;
    nuevo.HorasDeVueloAcumuladas=0;
    nuevo.HorasEnLaEstacionEspacial=0;
    nuevo.MisionesEspacialesRealizadas=0;

    aux=Especialidades();
    strcpy(nuevo.Especialidad,aux.Especialidad); ///COPIA EN LA ESPECIALIDAD DEL ASTRONAUTA EL RETORNO DE LA FUNCION ESPECIALIDADES.

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return nuevo;
}


///**************************************************************************************///
/// PARAMETROS: No tiene.
/// RETORNA: Un tipo de dato "Astronauta" con sus respectivos campos completados por el usuario.
/// FUNCION: Modifica los campos de registro de un Astronauta ya creado.
///**************************************************************************************///

Astronauta Especialidades()
{
    Astronauta EspecialidadAstro;

    int opcion=0;
    printf("\n\t\t\t\t\t [ Menu de Especialidades ] \n");
    printf("\n\t\t\t[ OPCIONES ] \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("-> 1 : [ Piloto ].\n");
    printf("-> 2 : [ Astrofisico ].\n");
    printf("-> 3 : [ Ingeniero Espacial ].\n");
    printf("-> 4 : [ Biologo Analista ].\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    opcion=ingresarOpcion();

    switch(opcion)
    {
    case 1:
    {
        strcpy(EspecialidadAstro.Especialidad,"Piloto");
        break;
    }
    case 2:
    {
        strcpy(EspecialidadAstro.Especialidad,"Astrofisico");
        break;
    }
    case 3:
    {
        strcpy(EspecialidadAstro.Especialidad,"Ingeniero Espacial");
        break;
    }
    case 4:
    {
        strcpy(EspecialidadAstro.Especialidad,"Biologo");
        break;
    }

    default:
    {
        printf("\nOPCION INCORRECTA.\n");
        break;
    }
    }

    printf("\nEspecialidad del Astronauta: %s .\n",EspecialidadAstro.Especialidad);

    return EspecialidadAstro;
}


///**************************************************************************************///
/// PARAMETROS: Recibe en primer lugar un dato de tipo Astronauta y en segundo lugar el nombre del archivo donde se guardara el Astronauta.
/// RETORNO: No tiene.
/// FUNCION: Guarda un Astronauta en un registro para conservar sus datos.
///**************************************************************************************///


void GuardaUnAstronauta(Astronauta nuevo, char nombreArchivo[])
{
    FILE *pArchAstronauta=fopen(nombreArchivo,"a+b");

    if(pArchAstronauta!=NULL)
    {
        fwrite(&nuevo,sizeof(Astronauta),1,pArchAstronauta);
        fclose(pArchAstronauta);
    }
}


///**************************************************************************************///
/// PARAMETRO: No tiene.
/// RETORNO: No tiene.
/// FUNCION: Guarda en un registro los Astronautas nuevos de forma secuencial.
///**************************************************************************************///


void CargaArchivoVariasVeces()
{
    Astronauta nuevo;
    int opcion=0;
    do
    {
        nuevo=Crear();             //ABRE EL ARCHIVO Y LO CIERRA, Si nuevo=Crear esta adentro de la funcion CargaArchivo , se abre 2 veces al mismo tiempo.
        GuardaUnAstronauta(nuevo,"AstronautasArch.dat"); //ABRE EL ARCHIVO Y LO CIERRA, Se abre el archivo , llama a la funcion crear, abre el archivo y se pierde el cursor que marca la ubicacion.
        printf("\nESC PARA SALIR, ENTER PARA CONTINUAR CARGANDO ARCHIVO.\n");
        opcion=getch();
        system("pause");
        system("cls");
    }
    while(opcion!=27);
}


///**************************************************************************************///
/// PARAMETROS: Recibe un dato de tipo Astronauta PREVIAMENTE CARGADO.
/// RETORNO: No tiene.
/// FUNCION: Muestra todos los datos del Astronauta.
///**************************************************************************************///


void MostrarAstronauta(Astronauta X)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\nAstronauta %d : %s %s , Alias %s , Nacio en %s el anio %d , su especialidad principal es %s .\n",X.Id,X.Nombre,X.Apellido,X.Apodo,X.Nacionalidad,(2021-X.Edad),X.Especialidad);
    printf("\n");
    printf("\nEstado Astronauta: %d .", X.Estado);
    printf("\nHoras De Vuelo: %d .", X.HorasDeVueloAcumuladas);
    printf("\nHoras En La Estacion Espacial: %d .", X.HorasEnLaEstacionEspacial);
    printf("\nMisiones Espaciales Realizadas: %d .", X.MisionesEspacialesRealizadas);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}


///**************************************************************************************///
/// PARAMETROS: No tiene.
/// RETORNO: No tiene.
/// FUNCION: Muestra una lista de todos los Astronautas registrados.
///**************************************************************************************///


void MuestraArchivoDeAstronauta()
{
    Astronauta nombre;

    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");

    if(pArchAstronauta!=NULL)
    {
        while(fread(&nombre,sizeof(Astronauta),1,pArchAstronauta)>0)
        {
            MostrarAstronauta(nombre);
        }
        fclose(pArchAstronauta);
    }
}


///**************************************************************************************///
/// PARAMETRO: Recibe un ID ingresado por el usuario.
/// RETORNO: El numero donde se posiciona el Astronauta en el registro.
/// FUNCION: Busca la posicion de un Astronauta en el registro.
///**************************************************************************************///


int buscaPos(int id)
{
    int pos = -1;

    Astronauta c;

    FILE * pArchAstronauta = fopen (ArchivoAstronauta, "rb");

    if(pArchAstronauta)
    {
        while(pos==-1 && fread(&c,sizeof(Astronauta),1,pArchAstronauta)> 0)
        {
            if(c.Id==id)
            {
                pos=ftell(pArchAstronauta)/sizeof(Astronauta)-1;
            }
        }
        fclose(pArchAstronauta);
    }

    return pos;
}

///**************************************************************************************///
/// PARAMETRO: Recibe un ID ingresado por el usuario.
/// RETORNO: No tiene.
/// FUNCION: Muestra un registro de tipo Astronauta por un determinado ID.
///**************************************************************************************///


void MuestraAstronautaPorID(int id)
{

    int pos=0;
    pos=buscaPos(id);
    Astronauta aux;

    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");

    if(pArchAstronauta!=NULL)
    {
        fseek(pArchAstronauta,sizeof(Astronauta)*pos,SEEK_SET);
        fread(&aux,sizeof(Astronauta),1,pArchAstronauta);
        MostrarAstronauta(aux);
        system("pause");
    }
    fclose(pArchAstronauta);
}


///**************************************************************************************///
/// PARAMETRO: Recibe un ID cargado por el usuario, tambien recibe el estado del Astronauta, 1 Activado, 2 desactivado.
/// RETORNO: No tiene.
/// FUNCION: Modifica el estado del astronauta.
///**************************************************************************************///

/*
void bajaOaltaAstronauta(int idAstronautaBaja, int bajaOalta)
{
    Astronauta c;

    FILE * pArchAstronauta = fopen(ArchivoAstronauta, "r+b");

    if(pArchAstronauta!=NULL)
    {
        fseek(pArchAstronauta,sizeof(Astronauta)*buscaPos(idAstronautaBaja), SEEK_SET);
        fread(&c,sizeof(Astronauta), 1, pArchAstronauta);
        c.Estado=bajaOalta; ///ESTADO 2 = DESACTIVADO. ///ESTADO 1 = ACTIVADO.
        fseek(pArchAstronauta,sizeof(Astronauta)*buscaPos(idAstronautaBaja), SEEK_SET);
        fwrite(&c, sizeof(Astronauta), 1, pArchAstronauta);
        fclose(pArchAstronauta);
    }
}
*/
///**************************************************************************************///
/// PARAMETRO: Recibe un ID cargado por el usuario, tambien recibe el estado del Astronauta, 1 Activado, 2 desactivado.
/// RETORNO: No tiene.
/// FUNCION: Modifica el estado del astronauta.
///**************************************************************************************///

/// Función que pasa un Astronauta A Activado o Inactivo por su ID:

/*

void EstadoActivoInactivo(int id, int bajaOalta)
{
    Astronauta c;
    int flag=0;
    FILE *pArchAstronauta = fopen(ArchivoAstronauta, "rb");

    if(pArchAstronauta)
    {
        while(flag==0 && fread(&c, sizeof(Astronauta), 1,pArchAstronauta)> 0)
        {
            if(c.Id==id)
            {
                if(c.Estado != bajaOalta)
                {
                    fseek(pArchAstronauta,sizeof(Astronauta)*-1,SEEK_CUR);
                    c.Estado=bajaOalta; ///ESTADO 2 = DESACTIVADO. ///ESTADO 1 = ACTIVADO.
                    GuardaUnAstronauta(c,nombreArchivo);
                }
                else
                {
                    printf("\nEl Astronauta ya esta en %d .\n", bajaOalta);
                }
                flag=1;
            }
        }
        fclose(pArchAstronauta);
    }
}
*/


///**************************************************************************************///
/// PARAMETRO: Recibe un Astronauta previamente creado, para ser modificado.
/// RETORNO: Retorna el Astronauta recibido por parametro pero ya modificado.
/// FUNCION: Modifica un registro de tipo Astronauta.
///**************************************************************************************///

Astronauta Modificaciones(Astronauta modifica)
{
    int opcion=0;

    Astronauta aux;
    do
    {
        printf("\n\n\t\tMENU PARA MODIFICAR ASTRONAUTA: ");
        printf("\n NOMBRE       -> OPCION 1.");
        printf("\n APELLIDO     -> OPCION 2.");
        printf("\n APODO        -> OPCION 3.");
        printf("\n EDAD         -> OPCION 4.");
        printf("\n NACIONALIDAD -> OPCION 5.");
        printf("\n ESPECIALIDAD -> OPCION 6.");
        printf("\n ESTADO       -> OPCION 7.");
        printf("\n\n SALIR        -> OPCION 0.");
        printf("\n\n\n\t\tINGRESAR OPCION A MODIFICAR: ");

        opcion=ingresarOpcion();

        switch(opcion)
        {
        case 1:
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\nNombre: ");
            fflush(stdin);
            gets(modifica.Nombre);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        }
        case 2:
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\nApellido: ");
            fflush(stdin);
            gets(modifica.Apellido);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        }
        case 3:
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\nApodo: ");
            fflush(stdin);
            gets(modifica.Apodo);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        }
        case 4:
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\nEdad: ");
            scanf("%d",&modifica.Edad);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        }
        case 5:
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\nNacionalidad: ");
            fflush(stdin);
            gets(modifica.Nacionalidad);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        }
        case 6:
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            aux=Especialidades();
            strcpy(modifica.Especialidad,aux.Especialidad); ///COPIA EN LA ESPECIALIDAD DEL ASTRONAUTA EL RETORNO DE LA FUNCION ESPECIALIDADES.
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        }
        case 7:
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\nEstado(0/1/2/3): "); /// 0 MUERTO - 1 DESACTIVADO - 2 ACTIVADO  - 3 JUBILADO.
            scanf("%d", &modifica.Estado);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
        case 0:
        {
            opcion=ESC;
            break;
        }
        default:
        {
            printf("\n\nOPCION INCORRECTA.\n");
            break;
        }
        system("pause");
        system("cls");
        }
    }
    while(opcion!=ESC);

    return modifica;
}


///**************************************************************************************///
///
///
///
///**************************************************************************************///


int ModificaArchivoDeAstronauta(int id)
{
    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");
    Astronauta modifica;
    int flag=0;


    if(pArchAstronauta!=NULL)
    {
        while(flag==0 && fread(&modifica, sizeof(Astronauta),1,pArchAstronauta) > 0)
        {
            if(modifica.Id==id)
            {
                fseek(pArchAstronauta,sizeof(Astronauta)*-1,SEEK_CUR);
                modifica=Modificaciones(modifica);
                fwrite(&modifica,sizeof(Astronauta),1,pArchAstronauta);
                printf("\nSe modifico el Registro con exito!.\n");
                flag=1;
            }
        }
        fclose(pArchAstronauta);
    }
    return flag; ///Si es 0 no existe dicho ID.

}
