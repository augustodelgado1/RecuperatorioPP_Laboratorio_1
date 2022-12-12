
#include "Nexo.h"

int GuardarFiguritasDoradas(int arrayDeFiguritasDoradas[],int sizeDeDoradas,eFiguritas listaDeFigurita[],int sizeDeLista,int arrayDeFiguritas[],int sizeDeFiguritas,int cantidadDeFiguritas)
{
	int estado;
	int index;
	estado = ERROR;

		if(arrayDeFiguritasDoradas != NULL && sizeDeDoradas >= 0 && sizeDeFiguritas >= 0){

				for(int i=0;i<sizeDeFiguritas;i++){
					cantidadDeFiguritas++;
					index = BuscarPorIdDeFigurita(listaDeFigurita, sizeDeLista, arrayDeFiguritas[i]);

					if(index != ERROR &&  listaDeFigurita[index].estado == OCUPADO && cantidadDeFiguritas %50 == 0
					&& CargarUnaFiguritaEnElAlbum(arrayDeFiguritasDoradas, sizeDeDoradas, listaDeFigurita[index].IdFigurita) != ERROR)
					{
						arrayDeFiguritas[i] = LIBRE;
					}

				}
				estado = OK;
			}
	return estado;
}

int GuardarFiguritasEnELAlbum(int arrayDeFiguritasDelAlbum[],int sizeDeFiguritasDelAlbum,eFiguritas listaDeFigurita[],int sizeDeLista,int arrayDeFiguritas[],int sizeDeFiguritas,int cantidadDeFiguritas)
{
	int estado;
	int index;
		estado = ERROR;

		if(arrayDeFiguritas != NULL && sizeDeFiguritas >= 0 && sizeDeFiguritas >= 0){

				for(int i=0;i<sizeDeFiguritas;i++){
					cantidadDeFiguritas++;
					index = BuscarPorIdDeFigurita(listaDeFigurita, sizeDeLista, arrayDeFiguritas[i]);

					if(index != ERROR &&  listaDeFigurita[index].estado == OCUPADO &&  cantidadDeFiguritas %50 != 0
					&& CargarUnaFiguritaEnElAlbum(arrayDeFiguritasDelAlbum, sizeDeFiguritasDelAlbum, listaDeFigurita[index].IdFigurita) != ERROR)
					{
						arrayDeFiguritas[i] = LIBRE;
					}

				}
				estado = OK;
			}
	return estado;
}

int GuardarFiguritasRepetidas(int arrayDeRepetidas[],int sizeDeRepetidas,eFiguritas listaDeFigurita[],int sizeDeLista,eAlbum* unAlbumDeFiguritas,int arrayDeFiguritas[],int sizeDeFiguritas)
{
	int retorno;
	int index;
	retorno = ERROR;

		if(arrayDeRepetidas != NULL && sizeDeRepetidas >= 0 && sizeDeFiguritas >= 0){
			retorno = OK;
			for(int i=0;i<sizeDeFiguritas;i++){
				index = BuscarPorIdDeFigurita(listaDeFigurita, sizeDeLista, arrayDeFiguritas[i]);

				if(index != ERROR &&  listaDeFigurita[index].estado == OCUPADO)
				{
					CargarUnaFiguritaRepetida(arrayDeRepetidas, sizeDeRepetidas, unAlbumDeFiguritas, listaDeFigurita[index].IdFigurita);
				}
			}
		}

		return retorno;
}

int EstadoDelAlbum(eFiguritas listaDeFigurita[],int sizeDeLista,eAlbum* unAlbum)
{
    int estado;
    int indexDorada;
    int indexFigurita;
    estado = LIBRE;

    if(ContarFiguritasDeUnArray(unAlbum->idFigurita, MAX_FIGURITAS, listaDeFigurita, sizeDeLista) > 0
    || ContarFiguritasDeUnArray(unAlbum->esDorada, MAX_DORADAS, listaDeFigurita, sizeDeLista) > 0)
    {
    	estado = OK;
		for (int i = 0; i < sizeDeLista; i++) {

			indexFigurita = BuscarIdEnElArray(unAlbum->idFigurita, MAX_FIGURITAS, listaDeFigurita[i].IdFigurita);
			indexDorada = BuscarIdEnElArray(unAlbum->esDorada, MAX_DORADAS, listaDeFigurita[i].IdFigurita);

			if(listaDeFigurita[i].estado == OCUPADO && indexFigurita == ERROR && indexDorada == ERROR)
			{
				estado = LIBRE;
				break;
			}

		}
    }

    return estado;
}



int CargarUnaFiguritaRepetida(int arrayDeRepetidas[],int sizeDeRepetidas,eAlbum* unAlbumDeFiguritas,int id)
{
	int indexRepetidas;
	int indexFigurita;
	int indexDorada;
	int estado;
	estado = ERROR;

	if(sizeDeRepetidas >= 0 && id >= 0 )
	{
		indexRepetidas = BuscarEspacioEnElArray(arrayDeRepetidas,sizeDeRepetidas);
		indexDorada = BuscarIdEnElArray(unAlbumDeFiguritas->esDorada,MAX_DORADAS,id);
		indexFigurita = BuscarIdEnElArray(unAlbumDeFiguritas->idFigurita,MAX_FIGURITAS,id);

		if(indexRepetidas != ERROR && (indexFigurita != ERROR || indexDorada != ERROR))
		{
			arrayDeRepetidas[indexRepetidas] = id;
			estado = OK;
		}
	}

	return estado;
}

int InicializarUnArray(int listaDeFiguritas[], int size)
{
	int retorno;

	retorno = ERROR;

	if(listaDeFiguritas != NULL && size >= 0){

		for(int i=0;i<size;i++){
			listaDeFiguritas[i] = LIBRE;
		}

		retorno = OK;
	}

	return retorno;
}

int ContarRepetidas(int listaDeRepetidas[],int size,int idFigurita)
{
    int contador;

    contador = 0;

    for (int i = 0; i < size; i++) {

        if(listaDeRepetidas[i] != LIBRE && listaDeRepetidas[i] == idFigurita)
        {
            contador++;
        }

    }

    return contador;
}

int CargarUnaFiguritaEnElAlbum(int arrayDeFiguritas[],int sizeDeFiguritas,int id)
{
	int indexLibre;
	int indexFigurita;
	int estado;
	estado = ERROR;
	if(sizeDeFiguritas >= 0)
	{
		indexLibre = BuscarEspacioEnElArray(arrayDeFiguritas,sizeDeFiguritas);
		indexFigurita = BuscarIdEnElArray(arrayDeFiguritas,sizeDeFiguritas,id);

		if(indexFigurita == ERROR && indexLibre != ERROR)
		{
			arrayDeFiguritas[indexLibre] = id;
			estado = OK;
		}
	}

	return estado;
}

int ContarFiguritasDeUnArray(int figuritas[],int size,eFiguritas listaDeFiguritas[],int sizeDeFiguritas)
{
	 int contador;
	 contador = ERROR;

	 if(size >= 0 && sizeDeFiguritas  >= 0 )
	 {
		 contador = 0;
	    for (int i = 0; i < size; i++)
	    {
	       if(BuscarPorIdDeFigurita(listaDeFiguritas, sizeDeFiguritas, figuritas[i]) != ERROR)
	       {
	    	   contador++;
	       }
	    }
	 }

	    return contador;
}

int BuscarIdEnElArray(int listaDeFiguritas[],int sizeDefiguritas,int id)
{
    int index;

    index = ERROR;

    for (int i = 0; i < sizeDefiguritas; i++)
    {

       if(listaDeFiguritas[i] == id)
       {
           index = i;
           break;
       }

    }

    return index;
}

int BuscarEspacioEnElArray(int listaDeFiguritas[], int size)
{
	int retorno;

	retorno = -2;

	if(size >= 0){
		retorno = ERROR;
		for(int i=0;i<size;i++){

		    if(listaDeFiguritas[i] == LIBRE)
		    {
		        retorno = i;
		        break;
		    }

		}
	}

	return retorno;
}



