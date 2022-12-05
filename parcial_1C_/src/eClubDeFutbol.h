

#ifndef ECLUBDEFUTBOL_H
#define ECLUBDEFUTBOL_H

#include "eFiguritas.h"

int MostrarListaDeClubs(eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas);
int InicializarListaDeClubs(eClubDeFutbol listaDeClubs[],int sizeDeClubs);
int CantidadDeClubsCargados(eClubDeFutbol listaDeClubs[],int sizeClub);
int CargaForzadaDeClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs,int idDeClub,char descripcion[],int cantidadDeTrofeos,int);
int BuscarLibreClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs);
int PedirUnClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas,char* mensaje,char* mensajeDeErrror,int reitentos);
int BuscarPorIdDeClubDeFutbol(eClubDeFutbol listaDeClubs[],int sizeDeClub,int id);


#endif /* ECLUBDEFUTBOL_H */
