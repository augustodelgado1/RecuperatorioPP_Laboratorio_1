#include "Nexo.h"

int MostrarListaDeClubs(eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
	int estado;
	int indexDeLiga;
	estado = ERROR;

	if(CantidadDeClubsCargados(listaDeClubs, sizeDeClubs) > 0)
	{
		estado = OK;
		ImprimirCabecera("\t\t--- Lista De Clubs ---\n","ID  | 	   NOMBRE	 |	CANTIDAD DE TROFEOS	| 		LIGA 		|\n","=","-",60);

		for (int i =0;i<sizeDeClubs;i++) {

			indexDeLiga = BuscarPorIdDeLiga(listaDeLigas, sizeDeLigas, listaDeClubs[i].idDeLiga);

			if(indexDeLiga != ERROR && listaDeClubs[i].estado == OCUPADO)
			{
				printf("%-3d |%-20s| %-15d | %-20s |\n",listaDeClubs[i].idDeClub,listaDeClubs[i].descripcion,listaDeClubs[i].cantidadDeTrofeos,listaDeLigas[i].descripsion);
				MostrarUnMensajeRepetidasVeces("-", 57);
				printf("\n");
			}
		}

	}

	return estado;
}

int InicializarListaDeClubs(eClubDeFutbol listaDeClubs[],int sizeDeClubs)
{
	int retorno;

	retorno = ERROR;

	if(listaDeClubs != NULL && sizeDeClubs >= 0){

		for(int i=0;i<sizeDeClubs;i++){
			listaDeClubs[i].estado = LIBRE;
		}

		retorno = OK;
	}

	return retorno;
}

int CantidadDeClubsCargados(eClubDeFutbol listaDeClubs[],int sizeClub)
{
		int contadorDeClubDeFutbols;

		contadorDeClubDeFutbols = ERROR;

		if(sizeClub > 0)
		{
			contadorDeClubDeFutbols = 0;

			for (int i =0;i<sizeClub;i++) {

				if(listaDeClubs[i].estado == OCUPADO)
				{
					contadorDeClubDeFutbols++;
				}
			}

		}

		return contadorDeClubDeFutbols;
}

int CargaForzadaDeClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs,int idDeClub,char descripcion[],int cantidadDeTrofeos,int idDeLiga)
{
	int indexDeClub;
	int estado;

	estado = ERROR;
	indexDeClub = BuscarLibreClub(listaDeClubs, sizeDeClubs);

	if(indexDeClub != ERROR && sizeDeClubs >= 0 && idDeClub > 0 && descripcion != NULL && cantidadDeTrofeos >= 0 && idDeLiga > 0)
	{
		listaDeClubs[indexDeClub].idDeClub = idDeClub;
		strcpy(listaDeClubs[indexDeClub].descripcion,descripcion);
	    listaDeClubs[indexDeClub].cantidadDeTrofeos = cantidadDeTrofeos;
	    listaDeClubs[indexDeClub].idDeLiga  = idDeLiga;
		listaDeClubs[indexDeClub].estado = OCUPADO;
		estado = OK;
	}

	return estado;
}

int BuscarLibreClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs)
{
	int estado;

	estado = ERROR;

	if(listaDeClubs != NULL && sizeDeClubs >= 0)
	{
		for (int i=0;i<sizeDeClubs;i++)
		{
			if(listaDeClubs[i].estado == LIBRE)
			{
				estado = i;
				break;
			}
		}
	}

	return estado;
}

int PedirUnClub(eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas,char* mensaje,char* mensajeDeErrror,int reitentos){
    int id;
    int index;

    index = ERROR;

    if(mensaje != NULL && mensajeDeErrror != NULL && reitentos >= 0 &&
    	MostrarListaDeClubs(listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLigas) != ERROR &&
    	!GetNumero(&id,mensaje,mensajeDeErrror,1,10000,reitentos))
    {
    	do
    	{
    		index =  BuscarPorIdDeClubDeFutbol(listaDeClubs,sizeDeClubs,id);

			if(index != ERROR)
			{
				break;
			}
			GetNumero(&id,mensajeDeErrror,mensajeDeErrror,1,10000,reitentos);
            reitentos--;
        }while(reitentos >= 0);
    }

    return index;
}

int BuscarPorIdDeClubDeFutbol(eClubDeFutbol listaDeClubs[],int sizeDeClub,int id)
{
	int index;

	index = ERROR;

	if(sizeDeClub >= 0 && id >= 0)
	{
		for (int i =0;i<sizeDeClub;i++) {

			if(listaDeClubs[i].estado == OCUPADO && listaDeClubs[i].idDeClub == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}


