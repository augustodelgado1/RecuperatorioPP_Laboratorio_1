

#ifndef EEQUIPOS_H_
#define EEQUIPOS_H_

#include "eFiguritas.h"

/// @fn int MostrarListaDeEquipos([], int)
/// @brief Muestra la lista de equipos
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return [-1] si hubo error en los parametros o si la lista esta vacia,[1] si esta ok
int MostrarListaDeEquipos(eEquipo[],int );

/// @fn int InicializarListaDeEquipos(eEquipo[], int)
/// @brief Inicializa la lista de equipos
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return [-1] si hubo error en los parametros ,[1] si esta ok
int InicializarListaDeEquipos(eEquipo listaDeEquipos[],int sizeEquipos);

/// @fn int CantidadDeEquiposCargados(eEquipo[], int)
/// @brief Cuenta la cantidad de equipos cargados en la lista
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return [-1] si hubo error en los parametros ,[la cantidad que conto] si esta ok
int CantidadDeEquiposCargados(eEquipo listaDeEquipos[],int sizeEquipos);


/// @fn int CargaForzadaDeEquipo(eEquipo[], int, int, char[], char[])
/// @brief  Permite cargar un equipo validando que los datos a guardar sea validos
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @param int id de equipo
/// @param char[] directorTecnico
/// @param char[] descripcion
/// @return [-1] si hubo error en los parametros ,[1] si esta ok
int CargaForzadaDeEquipo(eEquipo listaDeEquipos[],int sizeEquipos,int idEquipo,char directorTecnico[],char descripcion[]);

/// @fn int OrdenarEquipo([], int)
/// @brief Ordena alfaveticamente de manera acsendete la lista de equipos
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return[-1] si hubo error en los parametros,[1] si esta ok
int OrdenarListaDeEquiposAlfeveticamente(eEquipo[],int );

/// @fn int BuscarIdDeEquipo([], int, int)
/// @brief Busca la primera concidencia con el id pasado por parametro y devuelve el indice
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @param int id A buscar
/// @return [-1] si no encontro coicidencia , [el indice]  donde encontro la coicidencia
int BuscarIdDeEquipo(eEquipo listaDeEquipos[],int sizeDeEquipos,int id);

/// @fn int BuscarEquipoLibre(eEquipo[], int)
/// @brief Busca un espacio libre en la lista de Equipos
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return  [-1] si no encontro espacio , [el indice]  donde encontro el espacio
int BuscarEquipoLibre(eEquipo listaDeEquipos[],int sizeEquipos);

/// @fn int PedirEquipos([], int)
/// @brief Permite pedir un equipo validando que se ingres un equipo que pertenesca a la lista
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
///  @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
///  @param int la cantidad de reitentos
/// @return[-1] si hubo error ,[1] si esta ok
int PedirEquipos(eEquipo[],int,char* mensaje,char* mensajeDeErrror,int reitentos );


#endif /* EEQUIPOS_H_ */
