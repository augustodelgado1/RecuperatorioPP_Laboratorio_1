/**
 * @def MENU_H_
 * @brief  Esta bibloteca contiene las opciones del menu y
 *
 * @Autor : Augusto Delgado
 * @Division B
 */

#ifndef MENU_H_
#define MENU_H_

#include "Input.h"

/// @fn int menu(int*, char[], char[], int, int)
/// @brief Muestra un menu
///
/// @param int* Donde se va a guarda la opcion ingresada
/// @param char[] mensajeDeBienvenida
/// @param char[]
/// @param int el minimo de opciones que va tener el menu
/// @param int el maximo de opciones que va tener el menu
/// @return si se ingreso la opcion correctamente
void menu(char mensajeDeBienvenida[],char mensaje[]);


int ImprimirCabecera(char cabecera[],char mensaje[],char segundoMensaje[],char tercerMensaje[],int cantidadDeVeces);

int MostrarUnMensajeRepetidasVeces(char mensaje[],int cantidadDeVeces);





#endif /* MENU_H_ */
