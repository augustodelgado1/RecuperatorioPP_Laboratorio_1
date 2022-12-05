

#ifndef ELIGA_H_
#define ELIGA_H_

#include "eFiguritas.h"

/// @fn int MostrarListaDeLigas([], int)
/// @brief Muestra la lista de ligas
///
/// @param eLiga[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return [-1] si hubo error en los parametros,[1] si esta ok
int MostrarListaDeLigas(eLiga listaDeLigas[],int sizeDeLigas);

/// @fn int InicializarLista(eFiguritas[], int)
/// @brief Inicializa la lista de ligas
///
/// @param eLiga[] la lista de ligas
/// @param int el tamaño del array
/// @return [-1] si hubo error en los parametros,[1] si esta ok
int InicializarListaDeLigas(eLiga listaDeLigas[],int sizeDeLigas);

/// @fn int CantidadDeLigasCargados(eLiga[], int)
/// @brief Cuenta la cantidad de ligas cargados en la lista
///
/// @param eEquipo[] la lista De equipos
/// @param int el tamanio de la lista de equipos
/// @return [-1] si hubo error en los parametros ,[la cantidad que conto] si esta ok
int CantidadDeLigasCargados(eLiga listaDeLigas[],int sizeLiga);

/// @fn int CargaForzadaDeUnaLiga(eEquipo[], int, int, char[], char[])
/// @brief  Permite cargar un ligas validando que los datos a guardar sea validos
///
/// @param eLiga[] la lista De ligas
/// @param int el tamanio de la lista de equipos
/// @param char[] descripcion
/// @param int anioDefundacion
/// @return [-1] si hubo error en los parametros ,[1] si esta ok
int CargaForzadaDeUnaLiga(eLiga listaDeLigas[],int sizeDeLigas,int idDeLiga,char descripsion[],int fundacion);

/// @fn int BuscarEquipoLibre(eEquipo[], int)
/// @brief Busca un espacio libre en la lista de Ligas
///
/// @param eLiga[] la lista De Ligas
/// @param int el tamanio de la lista de Ligas
/// @return  [-1] si no encontro espacio , [el indice]  donde encontro el espacio
int BuscarLibreLiga(eLiga listaDeLigas[],int sizeDeLigas);

/// @fn int PedirEquipos([], int)
/// @brief Permite pedir una liga validando que se ingres un equipo que pertenesca a la lista
///
/// @param eLiga[] la lista De ligas
/// @param int el tamanio de la lista de ligas
///  @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
///  @param int la cantidad de reitentos
/// @return[-1] si hubo error en los parametros ,[1] si esta ok
int PedirUnIdDeLiga(eLiga listaDeLigas[],int sizeDeLigas,char* mensaje,char* mensajeDeErrror,int reitentos);

/// @fn int BuscarPorIdDeLiga(eLiga[], int, int)
/// @brief Busca la primera concidencia con el id pasado por parametro y devuelve el indice
///
/// @param eLiga[] la lista De Ligas
/// @param int el tamanio de la lista de Ligas
/// @param int id A buscar
/// @return [-1] si no encontro coicidencia , [el indice]  donde encontro la coicidencia
int BuscarPorIdDeLiga(eLiga listaDeLigas[],int sizeDeLiga,int id);



#endif /* ELIGA_H_ */
