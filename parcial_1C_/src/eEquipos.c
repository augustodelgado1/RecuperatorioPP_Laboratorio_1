#include "eEquipos.h"

int MostrarListaDeEquipos(eEquipo listaDeEquipos[],int sizeEquipos)
{
	int estado;
	estado = ERROR;

	if(CantidadDeEquiposCargados(listaDeEquipos, sizeEquipos) > 0)
	{
		estado = OK;
		ImprimirCabecera("\t\t--- Lista De Equipos ---\n","ID  | 	   EQUIPOS	 |	DIRECTOR TECNICO	|\n","=","-",57);

		for (int i =0;i<sizeEquipos;i++) {

			if(listaDeEquipos[i].estado == OCUPADO)
			{
				printf("%-3d |%-20s| %-28s |\n",listaDeEquipos[i].idEquipo,listaDeEquipos[i].descripcion,listaDeEquipos[i].directorTecnico);
				MostrarUnMensajeRepetidasVeces("-", 57);
				printf("\n");
			}
		}

	}

	return estado;
}

int InicializarListaDeEquipos(eEquipo listaDeEquipos[],int sizeEquipos)
{
	int retorno;

	retorno = ERROR;

	if(listaDeEquipos != NULL && sizeEquipos >= 0){

		for(int i=0;i<sizeEquipos;i++){
			listaDeEquipos[i].estado = LIBRE;
		}

		retorno = OK;
	}

	return retorno;
}

int CantidadDeEquiposCargados(eEquipo listaDeEquipos[],int sizeEquipos)
{
		int contadorDeEquipos;

		contadorDeEquipos = ERROR;

		if(sizeEquipos > 0)
		{
			contadorDeEquipos = 0;

			for (int i =0;i<sizeEquipos;i++) {

				if(listaDeEquipos[i].estado == OCUPADO)
				{
					contadorDeEquipos++;
				}
			}

		}

		return contadorDeEquipos;
}

int CargaForzadaDeEquipo(eEquipo listaDeEquipos[],int sizeEquipos,int idEquipo,char directorTecnico[],char descripcion[])
{
	int indexDeEquipo;
	int estado;

	estado = ERROR;
	indexDeEquipo = BuscarEquipoLibre(listaDeEquipos, sizeEquipos);

	if(indexDeEquipo != ERROR && sizeEquipos >= 0 && idEquipo >= 0 && directorTecnico != NULL && descripcion != NULL)
	{
		listaDeEquipos[indexDeEquipo].idEquipo = idEquipo;
		strcpy(listaDeEquipos[indexDeEquipo].directorTecnico,directorTecnico);
		strcpy(listaDeEquipos[indexDeEquipo].descripcion,descripcion);
		listaDeEquipos[indexDeEquipo].estado = OCUPADO;
		estado = OK;
	}

	return estado;
}

int BuscarEquipoLibre(eEquipo listaDeEquipos[],int sizeEquipos)
{
	int estado;

	estado = ERROR;

	if(listaDeEquipos != NULL && sizeEquipos >= 0)
	{
		for (int i=0;i<sizeEquipos;i++)
		{
			if(listaDeEquipos[i].estado == LIBRE)
			{
				estado = i;
				break;
			}
		}
	}

	return estado;
}
int PedirEquipos(eEquipo listaDeEquipos[],int sizeEquipos,char* mensaje,char* mensajeDeErrror,int reitentos){
    int id;
    int index;

    index = ERROR;

    if(mensaje != NULL && mensajeDeErrror != NULL && reitentos >= 0 &&
    	MostrarListaDeEquipos(listaDeEquipos,sizeEquipos) != ERROR &&
    	!GetNumero(&id,mensaje,mensajeDeErrror,1,10000,reitentos))
    {
    	do
    	{
    		index =  BuscarIdDeEquipo(listaDeEquipos,sizeEquipos,id);

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

int OrdenarListaDeEquiposAlfeveticamente(eEquipo listaDeEquipo [],int sizeDeEquipo){
    eEquipo auxiliar;
    int estado;

    estado = ERROR;

    	if(sizeDeEquipo >= 0){

			for (int i = 0;i<sizeDeEquipo-1;i++) {
				for (int j =i+1;j<sizeDeEquipo;j++) {

					if(strcmp(listaDeEquipo[i].descripcion,listaDeEquipo[j].descripcion) > 0)
					{
						auxiliar = listaDeEquipo[i];
						listaDeEquipo[i] = listaDeEquipo[j];
						listaDeEquipo[j] = auxiliar;
					}
				}
			}

			estado = OK;

    	}

    	return estado;
}

int BuscarIdDeEquipo(eEquipo listaDeEquipos[],int sizeDeEquipos,int id)
{
	int index;

	index = ERROR;

	if(sizeDeEquipos >= 0 && id >= 0)
	{
		for (int i =0;i<sizeDeEquipos;i++) {

			if(listaDeEquipos[i].estado == OCUPADO && listaDeEquipos[i].idEquipo == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}


