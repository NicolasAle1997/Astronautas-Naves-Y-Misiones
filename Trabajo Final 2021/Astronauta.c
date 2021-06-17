#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Astronauta.h"


///ACA SE CREAN LAS FUNCIONES DE ASTRONAUTA, PARA UTILIZARLAS DEBEN LLAMAR A LAS FUNCIONES EN EL MAIN.


int id_nuevo()
{
    int idnuevo=0;
    Astronauta aux;

    FILE *pArchAstronauta=fopen("AstronautaRegistro.dat","r+b");

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

    printf("\nINGRESAR OPCION: ");
    scanf("%d", &opcion);
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



void CargaArchivo(Astronauta nuevo)
{
    int opcion=0;
    FILE *pArchAstronauta=fopen("AstronautaRegistro.dat","a+b");

    if(pArchAstronauta!=NULL)
    {
        fwrite(&nuevo,sizeof(Astronauta),1,pArchAstronauta);
        fclose(pArchAstronauta);
    }
    else
    {
        printf("\nERROR - FUNCION CARGA ASTRONAUTA NUEVO.\n");
    }
}



void CargaArchivoVariasVeces()
{
    Astronauta nuevo;
    int opcion=0;
    do
    {
        nuevo=Crear();             //ABRE EL ARCHIVO Y LO CIERRA, Si nuevo=Crear esta adentro de la funcion CargaArchivo , se abre 2 veces al mismo tiempo.
        CargaArchivo(nuevo);       //ABRE EL ARCHIVO Y LO CIERRA, Se abre el archivo , llama a la funcion crear, abre el archivo y se pierde el cursor que marca la ubicacion.
        printf("\nESC PARA SALIR, ENTER PARA CONTINUAR CARGANDO ARCHIVO.\n");
        opcion=getch();
        system("pause");
        system("cls");
    }
    while(opcion!=27);
}



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



void MuestraArchivoDeAstronauta()
{
    Astronauta nombre;

    FILE *pArchAstronauta=fopen("AstronautaRegistro.dat","r+b");

    if(pArchAstronauta!=NULL)
    {
        while(fread(&nombre,sizeof(Astronauta),1,pArchAstronauta)>0)
        {
            MostrarAstronauta(nombre);
        }
        fclose(pArchAstronauta);
    }
    else
    {
        printf("\nERROR - FUNCION MUESTRA ASTRONAUTA.\n");
    }
}



int existeAstronauta(int AstronautaId)
{
    Astronauta aux;

    int flag = 0;

    FILE *pArchAstronauta=fopen("AstronautaRegistro.dat", "rb");

    if(pArchAstronauta!=NULL)
    {
        while(fread(&aux, sizeof(Astronauta),1, pArchAstronauta)> 0)
        {
            if(aux.Id == AstronautaId)
            {
                flag=1;
            }
        }
        fclose(pArchAstronauta);
    }
    return flag;
}


void modificaRegistro(Astronauta Astro, int idAstronauta) /// En Astro están los datos nuevos que se quieren guardar
{
    /// y en idAstro el id del cliente cuyos datos se quieren pisar
    FILE *pArchAstronauta=fopen("AstronautaRegistro.dat", "r+b");

    if(pArchAstronauta!=NULL)
    {
        fseek(pArchAstronauta, sizeof(Astronauta)*idAstronauta, SEEK_SET);
        if(existeAstronauta(Astro.Id) == 0)
        {
            fwrite (&Astro, sizeof(Astronauta), 1, pArchAstronauta);
        }
        fclose(pArchAstronauta);
    }
}
