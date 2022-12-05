

#ifndef ELIGA_H_
#define ELIGA_H_

#include "eFiguritas.h"



int MostrarListaDeLigas(eLiga listaDeLigas[],int sizeDeLigas);

/// @fn int InicializarLista(eFiguritas[], int)
/// @brief Inicializa la lista de ligas
///
/// @param eLiga[] la lista
/// @param int el tamaño del array
/// @return [-1] si hubo error ,[1] si no hubo error
int InicializarListaDeLigas(eLiga listaDeLigas[],int sizeDeLigas);


int CantidadDeLigasCargados(eLiga listaDeLigas[],int sizeLiga);
int CargaForzadaDeUnaLiga(eLiga listaDeLigas[],int sizeDeLigas,int idDeLiga,char descripsion[],int fundacion);
int BuscarLibreLiga(eLiga listaDeLigas[],int sizeDeLigas);
int PedirUnIdDeLiga(eLiga listaDeLigas[],int sizeDeLigas,char* mensaje,char* mensajeDeErrror,int reitentos);
int BuscarPorIdDeLiga(eLiga listaDeLigas[],int sizeDeLiga,int id);



#endif /* ELIGA_H_ */
