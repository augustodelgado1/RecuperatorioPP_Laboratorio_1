

#ifndef ECLUBDEFUTBOL_H
#define ECLUBDEFUTBOL_H

#include "eFiguritas.h"



/// @fn int MostrarListaDeclub([], int)
/// @brief Muestra la lista de clubes de futbol con su liga
///
/// @param eLiga[] la lista De club
/// @param int el tamanio de la lista de club
/// @return [-1] si hubo error en los parametros,[1] si esta ok
int MostrarListaDeClubs(eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga [],int );

/// @fn int InicializarLista(eFiguritas[], int)
/// @brief Inicializa la lista de club
///
/// @param eLiga[] la lista de club
/// @param int el tamaño del array
/// @return [-1] si hubo error en los parametros,[1] si esta ok
int InicializarListaDeClubs(eClubDeFutbol listaDeClubs[],int sizeDeClubs);


/// @fn int CantidadDeclubCargados(eLiga[], int)
/// @brief Cuenta la cantidad de club cargados en la lista
///
/// @param eEquipo[] la lista De club
/// @param int el tamanio de la lista de club
/// @return [-1] si hubo error en los parametros ,[la cantidad que conto] si esta ok
int CantidadDeClubsCargados(eClubDeFutbol listaDeClubs[],int sizeClub);

/// @fn int CargaForzadaDeUnaLiga(eEquipo[], int, int, char[], char[])
/// @brief  Permite cargar un club validando que los datos a guardar sea validos
///
/// @param eLiga[] la lista De club
/// @param int el tamanio de la lista de club
/// @param char[] descripcion
/// @param int anioDefundacion
/// @return [-1] si hubo error en los parametros ,[1] si esta ok
int CargaForzadaDeClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs,int idDeClub,char descripcion[],int cantidadDeTrofeos,int);


/// @fn int BuscarLibreClub(eEquipo[], int)
/// @brief Busca un espacio libre en la lista de club
///
/// @param eClubDeFutbol[] la lista De club
/// @param int el tamanio de la lista de club
/// @return  [-1] si no encontro espacio , [el indice]  donde encontro el espacio
int BuscarLibreClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs);

/// @fn int PedirUnClub([], int)
/// @brief Permite pedir una liga validando que se ingres un equipo que pertenesca a la lista
///
/// @param eLiga[] la lista De club
/// @param int el tamanio de la lista de club
///  @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
///  @param int la cantidad de reitentos
/// @return[-1] si hubo error ,[1] si esta ok
int PedirUnClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga [],int ,char* mensaje,char* mensajeDeErrror,int reitentos);

/// @fn int BuscarPorIdDeLiga(eLiga[], int, int)
/// @brief Busca la primera concidencia con el id pasado por parametro y devuelve el indice
///
/// @param eLiga[] la lista De club
/// @param int el tamanio de la lista de club
/// @param int id A buscar
/// @return [-1] si no encontro coicidencia , [el indice]  donde encontro la coicidencia
int BuscarPorIdDeClubDeFutbol(eClubDeFutbol listaDeClubs[],int sizeDeClub,int id);


#endif /* ECLUBDEFUTBOL_H */
