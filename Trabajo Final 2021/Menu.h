#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

///EN EL CASO DE QUE EN LA ESTRUCTURA HAYA UN TIPO DE DATO DE OTRA ESTRUCTURA, USAR #INCLUDE ..NOMBRE ESTRUCTURA...

///No crear constantes , ni definir nada (no arranca el programa sino)

///HEADER DE MENU , AQUI SE PONEN LAS CABECERAS DEL MENU.

/*
    AQUI PONDREMOS:
    |-> ESTRUCTURAS
    |-> ENCABEZADOS DE NUESTRAS FUNCIONES DE MENU (NO VAN LAS FUNCIONES ACA).
*/
void imprimirCabecera(char cabecera[]);
void iniciarMenu();
void imprimirOpcionesMenu();
int ingresarOpcion();

///POR FAVOR NO BORRAR NADA
#endif // MENU_H_INCLUDED
