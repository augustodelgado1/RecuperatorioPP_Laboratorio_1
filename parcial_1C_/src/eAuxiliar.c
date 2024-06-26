
#include "Nexo.h"

int InicializarListaAuxiliar(eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{
	int estado;

	estado = ERROR;

	if(arrayAuxiliar != NULL && sizeAuxiliar >= 0)
	{

	  for (int i = 0; i <sizeAuxiliar; i++) {
		  arrayAuxiliar[i].estado = LIBRE;
	  }

	  estado = OK;
	}

	return estado;

}

int BuscarLibreAuxiliar(eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{
    int index;

    index = ERROR;

    if(arrayAuxiliar != NULL && sizeAuxiliar >= 0)
    {
		for (int i = 0; i <sizeAuxiliar; i++)
		{
			if(arrayAuxiliar[i].estado == LIBRE)
		   {
			   index = i;
			   break;
		   }

		}
    }

    return index;

}

int CalcularPorcentajeArrayAuxiliar(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,int cantidad)
{
	float resultado;
	int estado;

	estado = ERROR;

	if(arrayAuxiliar != NULL && sizeAuxiliar >= 0)
	{
		for (int i = 0; i <sizeAuxiliar; i++) {

			arrayAuxiliar[i].porcentaje = 0;
			 if(arrayAuxiliar[i].estado == OCUPADO && arrayAuxiliar[i].contador > 0)
			 {
				 resultado = (float) arrayAuxiliar[i].contador * 100;
				 arrayAuxiliar[i].porcentaje = ((float) resultado / cantidad);
			 }
		}
		estado = OK;
	}

	return estado;
}

int BuscarMayorCantidad(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,int* maximo)
{
    int estado;
    estado = ERROR;

    if(arrayAuxiliar != NULL && sizeAuxiliar >= 0 && maximo != NULL)
    {
        for (int i = 0; i <sizeAuxiliar; i++) {

          if(arrayAuxiliar[i].estado == OCUPADO && (arrayAuxiliar[i].contador > (*maximo) || i == 0))
          {
               *maximo = arrayAuxiliar[i].contador;
          }
        }
        estado = OK;
    }

    return estado;

}

int BuscarMayorAcumulado(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,int* maximo)
{
    int estado;
    estado = ERROR;

    if(arrayAuxiliar != NULL && sizeAuxiliar >= 0 && maximo != NULL)
    {
        for (int i = 0; i <sizeAuxiliar; i++)
        {
          if(arrayAuxiliar[i].estado == OCUPADO && (arrayAuxiliar[i].acumulador > (*maximo) || i == 0) )
          {
               *maximo = arrayAuxiliar[i].acumulador;
          }
        }
        estado = OK;
    }

    return estado;

}

int OrdenarContadorDeArrayAuxiliar(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,int order)
{
	int estado;
	eAuxiliar auxiliar;
	 estado = ERROR;

	if(sizeAuxiliar > 0 && (order == 1 || order == 0))
	{
		 for (int i = 0; i <sizeAuxiliar-1; i++)
		{
			 for (int j = i+1; j < sizeAuxiliar; j++) {

				 if((arrayAuxiliar[i].contador > arrayAuxiliar[j].contador && order == 1)
				 || (arrayAuxiliar[i].contador < arrayAuxiliar[j].contador && order == 0))
				 {
					 auxiliar = arrayAuxiliar[i];
					 arrayAuxiliar[i] = arrayAuxiliar[j];
					 arrayAuxiliar[j] = auxiliar;
				 }

			}

		}
		        estado = OK;
	}

	  return estado;

}
