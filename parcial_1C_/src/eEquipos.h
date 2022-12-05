

#ifndef EEQUIPOS_H_
#define EEQUIPOS_H_

#include "eFiguritas.h"

/// @fn void eEquipo_MostraLista([], int)
/// @brief Muestra la lista de equipos
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
int MostrarListaDeEquipos(eEquipo[],int );

/// @fn int InicializarListaDeEquipos(eEquipo[], int)
/// @brief
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return
int InicializarListaDeEquipos(eEquipo listaDeEquipos[],int sizeEquipos);

/// @fn int CantidadDeEquiposCargados(eEquipo[], int)
/// @brief Cuenta la cantidad de equipos cargados en la lista
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return [-1] si h
int CantidadDeEquiposCargados(eEquipo listaDeEquipos[],int sizeEquipos);


/// @fn int CargaForzadaDeEquipo(eEquipo[], int, int, char[], char[])
/// @brief Ca
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @param int
/// @param char directorTecnico
/// @param char descripcion
/// @return
int CargaForzadaDeEquipo(eEquipo listaDeEquipos[],int sizeEquipos,int idEquipo,char directorTecnico[],char descripcion[]);

/// @fn int OrdenarEquipo([], int)
/// @brief Ordena alfaveticamente de manera acsendete la lista de equipos
///
/// @param eEquipo
/// @param
/// @return[-1] si hubo error ,[1] si no hubo error
int OrdenarListaDeEquiposAlfeveticamente(eEquipo[],int );

/// @fn int BuscarIdDeEquipo([], int, int)
/// @brief Busca la primera concidencia con el id pasado por parametro
/// y devuelve el indice
///
/// @param eEquipo
/// @param
/// @param
/// @return [-1] si no encontro coicidencia , [el indice]  donde encontro la coicidencia
int BuscarIdDeEquipo(eEquipo listaDeEquipos[],int sizeDeEquipos,int id);

/// @fn int BuscarEquipoLibre(eEquipo[], int)
/// @brief
///
/// @param listaDeEquipos
/// @param sizeEquipos
/// @return
int BuscarEquipoLibre(eEquipo listaDeEquipos[],int sizeEquipos);

/// @fn int PedirEquipos([], int)
/// @brief Permite pedir un quipo validando que se ingres un equipo que
/// pertenesca a la lista
///
/// @param eEquipo
/// @param
/// @return[-1] si hubo error ,[1] si no hubo error
int PedirEquipos(eEquipo[],int,char* mensaje,char* mensajeDeErrror,int reitentos );


#endif /* EEQUIPOS_H_ */
