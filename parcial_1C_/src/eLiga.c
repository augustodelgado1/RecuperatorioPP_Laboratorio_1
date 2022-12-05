#include "Nexo.h"

int MostrarListaDeLigas(eLiga listaDeLigas[],int sizeDeLigas)
{
	int estado;
	estado = ERROR;

	if(CantidadDeLigasCargados(listaDeLigas, sizeDeLigas) > 0)
	{
		estado = OK;
		ImprimirCabecera("\t\t--- Lista De Clubs ---\n","ID  | 	   NOMBRE	 |	ANIO DE FUNDACION |\n","=","-",50);

		for (int i =0;i<sizeDeLigas;i++) {

			if(listaDeLigas[i].estado == OCUPADO)
			{
				printf("%-3d |%-20s| %-15d |\n",listaDeLigas[i].idDeLiga,listaDeLigas[i].descripsion,listaDeLigas[i].anioDefundacion);
				MostrarUnMensajeRepetidasVeces("-", 57);
				printf("\n");
			}
		}

	}

	return estado;
}

int InicializarListaDeLigas(eLiga listaDeLigas[],int sizeDeLigas)
{
	int retorno;

	retorno = ERROR;

	if(listaDeLigas != NULL && sizeDeLigas >= 0){

		for(int i=0;i<sizeDeLigas;i++){
			listaDeLigas[i].estado = LIBRE;
		}

		retorno = OK;
	}

	return retorno;
}

int CantidadDeLigasCargados(eLiga listaDeLigas[],int sizeLiga)
{
		int contadorDeLigas;

		contadorDeLigas = ERROR;

		if(sizeLiga > 0)
		{
			contadorDeLigas = 0;

			for (int i =0;i<sizeLiga;i++) {

				if(listaDeLigas[i].estado == OCUPADO)
				{
					contadorDeLigas++;
				}
			}

		}

		return contadorDeLigas;
}

int CargaForzadaDeUnaLiga(eLiga listaDeLigas[],int sizeDeLigas,int idDeLiga,char descripsion[],int fundacion)
{
	int indexDeClub;
	int estado;

	estado = ERROR;
	indexDeClub = BuscarLibreLiga(listaDeLigas, sizeDeLigas);

	if(indexDeClub != ERROR && sizeDeLigas >= 0 && idDeLiga > 0 && descripsion != NULL && fundacion > 0)
	{
		listaDeLigas[indexDeClub].idDeLiga = idDeLiga;
		strcpy(listaDeLigas[indexDeClub].descripsion,descripsion);
	    listaDeLigas[indexDeClub].anioDefundacion = fundacion;
		listaDeLigas[indexDeClub].estado = OCUPADO;
		estado = OK;
	}

	return estado;
}

int BuscarLibreLiga(eLiga listaDeLigas[],int sizeDeLigas)
{
	int estado;

	estado = ERROR;

	if(listaDeLigas != NULL && sizeDeLigas >= 0)
	{
		for (int i=0;i<sizeDeLigas;i++)
		{
			if(listaDeLigas[i].estado == LIBRE)
			{
				estado = i;
				break;
			}
		}
	}

	return estado;
}
int PedirUnIdDeLiga(eLiga listaDeLigas[],int sizeDeLigas,char* mensaje,char* mensajeDeErrror,int reitentos){
    int id;
    int index;

    index = ERROR;

    if(mensaje != NULL && mensajeDeErrror != NULL && reitentos >= 0 &&
    	MostrarListaDeLigas(listaDeLigas,sizeDeLigas) != ERROR &&
    	!GetNumero(&id,mensaje,mensajeDeErrror,1,10000,reitentos))
    {
    	do
    	{
    		index =  BuscarPorIdDeLiga(listaDeLigas,sizeDeLigas,id);

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

int BuscarPorIdDeLiga(eLiga listaDeLigas[],int sizeDeLiga,int id)
{
	int index;

	index = ERROR;

	if(sizeDeLiga >= 0 && id >= 0)
	{
		for (int i =0;i<sizeDeLiga;i++) {

			if(listaDeLigas[i].estado == OCUPADO && listaDeLigas[i].idDeLiga == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}


