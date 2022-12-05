
#include "Nexo.h"

int SubMenuDeListados(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeEquipos,
		eAlbum* unAlbumDeFiguritas,eColeccionista* unColeccionista,int cantidadDeSobres,float dineroGastadoParaCompletarElAlbum,
		eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeligas[],int sizeDeLigas)
{
	    int opcion;
	    int retorno;
	    int indexDeEquipo;
	    int maximo;
	    eAuxiliar arrayAuxiliar[MAX_AUXILIAR];
	    char respuesta;
	    int cantidadDeFigurtasDoradas;
	    int cantidadDeFigurtas;
	    retorno = ERROR;

	    if(unAlbumDeFiguritas != NULL)
	    {

	    do{
																 menu("Menu De Listado",
															  "\n[1].Listado de figuritas pegadas\n"
															  "[2].Listado de figuritas repetidas\n"
															  "[3].Listado de figuritas doradas que estan pegadas en el album\n"
															  "[4].Cuantos sobres tuvo que comprar el coleccionista para llenar el album\n"
															  "[5].Cuanto dinero lleva gastado el coleccionista\n"
															  "[6].Cuanto dinero gasto el coleccionista para completar el album\n"
															  "[7].Listado de todas las figuritas que esten pegadas de un equipo determinado\n"
															  "[8].Informar Porcentaje de Clubs por cada figurita pegada en el Album\n"
															  "[9].Determinar cual/cuales son las ligas que mayor cantidad de figuritas pegadas en el Album\n"
															  "[10].Volver al Menu Principal");

	       retorno = GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida: ",1, 10, 2);
	       if(retorno != ERROR)
	        {
	            switch(opcion)
	            {
	                case 1:
	                	if(ContarFiguritasDeUnArray(unAlbumDeFiguritas->idFigurita, MAX_FIGURITAS, listaDeFiguritas, sizeDeFiguritas) <= 0
	                	|| ImprimirCabecera("\n\t\t\t-- Figuritas Pegadas En Album --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200) == ERROR
						|| MostrarFiguritasDeUnArray(unAlbumDeFiguritas->idFigurita, MAX_FIGURITAS, listaDeFiguritas, sizeDeFiguritas, listaDeEquipos, sizeEquipos,listaDeClubs,sizeDeClubs,listaDeligas,sizeDeLigas) == ERROR)
	                	{
	                		printf("Se produjo un error al intentar mostrar la figuritas del album\n");
	                	}
	                	break;

	                case 2:
	                	if(MostrarListaDeRepetidas(unColeccionista->idFiguritasRepetidas,MAX_REPETIDAS,listaDeFiguritas,sizeDeFiguritas,listaDeEquipos,sizeEquipos,listaDeClubs,sizeDeClubs,listaDeligas,sizeDeLigas) == ERROR)
						{
	                		printf("Se produjo un error al intentar mostrar la figuritas repetidas\n");
						}
	                    break;

	                case 3:
	                	if(ContarFiguritasDeUnArray(unAlbumDeFiguritas->esDorada, MAX_DORADAS, listaDeFiguritas, sizeDeFiguritas) > 0)
	                	{
	                		ImprimirCabecera("\n\t\t\t-- Figuritas Doradas Pegadas  --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200);
	                		MostrarFiguritasDeUnArray(unAlbumDeFiguritas->esDorada, MAX_DORADAS, listaDeFiguritas, sizeDeFiguritas, listaDeEquipos, sizeEquipos,listaDeClubs,sizeDeClubs,listaDeligas,sizeDeLigas);
	                	}else
	                	{
	                		printf("No hay figuritas doradas en el Album");
	                	}
	                	break;

	                case 4:
	                	if(unAlbumDeFiguritas->estado == OCUPADO && cantidadDeSobres > 0)
						{
							printf("La cantidad de sobres tuvo que comprar el coleccionista para llenar el Album es %d",cantidadDeSobres);
						}else{
							printf("El album de figuritas no esta completo todavia");
						}
	                    break;

	                case 5:
	                	if(unColeccionista->cantidadDeDineroGastado > 0)
						{
							printf("La cantidad de dinero que lleva gastado el coleccionista es %.2f",unColeccionista->cantidadDeDineroGastado);
						}
	                	break;

	                case 6:
	                	if(unAlbumDeFiguritas->estado == OCUPADO && dineroGastadoParaCompletarElAlbum > 0)
						{
							printf("La cantidad de dinero que gasto el coleccionista para llenar el Album es %.2f",dineroGastadoParaCompletarElAlbum);
						}else{
							printf("El album de figuritas no esta completo todavia");
						}
	                    break;

	                case 7:
	                	indexDeEquipo = PedirEquipos(listaDeEquipos,sizeEquipos,"ingrese el id del equipo que desea listar: ","Error ingrese un id valido",2);
	                	cantidadDeFigurtas = CantidadDeFiguritasGuardadasDeUnEquipo(listaDeEquipos[indexDeEquipo],listaDeFiguritas,sizeDeFiguritas,unAlbumDeFiguritas->idFigurita,MAX_FIGURITAS);
	                	cantidadDeFigurtasDoradas = CantidadDeFiguritasGuardadasDeUnEquipo(listaDeEquipos[indexDeEquipo],listaDeFiguritas,sizeDeFiguritas,unAlbumDeFiguritas->esDorada,MAX_DORADAS);
	                	if(indexDeEquipo != ERROR && (cantidadDeFigurtas > 0 || cantidadDeFigurtasDoradas > 0))
						{
							if((cantidadDeFigurtas <= 0 || ImprimirCabecera("\n\t\t\t-- Figuritas Pegadas En Album --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200) == ERROR
							||  ListarFiguritasGuardadasDeUnEquipo(listaDeEquipos[indexDeEquipo],listaDeFiguritas,sizeDeFiguritas,unAlbumDeFiguritas->idFigurita,MAX_FIGURITAS,listaDeClubs,sizeDeClubs,listaDeligas,sizeDeLigas) == ERROR)
							&& (cantidadDeFigurtasDoradas <= 0 || ImprimirCabecera("\n\t\t\t-- Figuritas Doradas Pegadas En Album --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200) == ERROR
							|| ListarFiguritasGuardadasDeUnEquipo(listaDeEquipos[indexDeEquipo],listaDeFiguritas,sizeDeFiguritas,unAlbumDeFiguritas->esDorada,MAX_DORADAS,listaDeClubs,sizeDeClubs,listaDeligas,sizeDeLigas) == ERROR))
							{
								printf("Se produjo un error al intentar mostrar la figuritas de ese equipo");
							}
						}else{
							printf("No Hay figuritas de ese equipo en el Album");
						}

						break;

	                case 8:
	                	if(InicializarListaAuxiliar(arrayAuxiliar, MAX_AUXILIAR) != ERROR &&
	                	CantidadDeFiguritasPegadasPorCadaClubs(listaDeClubs, sizeDeClubs, listaDeFiguritas, sizeDeFiguritas,unAlbumDeFiguritas, arrayAuxiliar, MAX_AUXILIAR)  != ERROR &&
	                	CalcularPorcentajeArrayAuxiliar(arrayAuxiliar, MAX_AUXILIAR, CantidadDeClubsCargados(listaDeClubs, sizeDeClubs)) != ERROR)
						{
	                		MostrarPorcentajeDeFigutiasPegadasPorCadaClubs(listaDeFiguritas, sizeDeFiguritas, listaDeEquipos, sizeEquipos, listaDeClubs, sizeDeClubs, listaDeligas, sizeDeLigas, unAlbumDeFiguritas, arrayAuxiliar, MAX_AUXILIAR);
						}else{
							printf("Se produjo un error al intentar mostrar el porcentaje de cada club");
						}
	                	break;

	                case 9:
	                	if(InicializarListaAuxiliar(arrayAuxiliar, MAX_AUXILIAR) != ERROR
	                	&& CantidadDeFiguritasPegadasPorCadaLiga(listaDeligas,sizeDeLigas,listaDeClubs,sizeDeClubs,listaDeFiguritas,sizeDeFiguritas,unAlbumDeFiguritas, arrayAuxiliar,MAX_AUXILIAR) != ERROR
						&& BuscarMayorCantidad(arrayAuxiliar,MAX_AUXILIAR,&maximo) != ERROR)
	                	{
	                		MostrarLigasConMayorCantidad(listaDeFiguritas, sizeDeFiguritas, listaDeEquipos, sizeEquipos, unAlbumDeFiguritas, listaDeClubs, sizeDeClubs,listaDeligas, sizeDeLigas, arrayAuxiliar, MAX_AUXILIAR, maximo);
	                	}else{
							printf("Se produjo un error al intentar determinar la mayor/es ligas ");
						}
	                	break;

	                case 10:
	                	if(ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2) == ERROR)
						{
							printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error\n\n");
						}
	                    break;
	            }
	        }

	    }while(respuesta != 's' && retorno != ERROR);
	    }

	    return retorno;
}

int SubmenuColeccionista(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeEquipos,
		eAlbum* unAlbumDeFiguritas,eColeccionista* unColeccionista,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeligas[],int sizeDeLigas)
{
	int retorno;
	int opcion;
	int cantidadDeFiguritas;
	char respuesta;
	int arrayDeFiguritas[MAX_FIGURITAS];
	int cantidadSobresCompletarElAlbum;
	int indexDeFigurita;
	float dineroGastadoParaCompletarElAlbum;

	unColeccionista->cantidadDeSobres = 0;
	unColeccionista->cantidadDeDineroGastado = 0;
	cantidadDeFiguritas = 0;
	cantidadSobresCompletarElAlbum = 0;
	dineroGastadoParaCompletarElAlbum = 0;

	if(InicializarUnArray(arrayDeFiguritas, MAX_FIGURITAS) != ERROR)
	{

		do{

																			 menu("Menu Principal",
																				  "\n1.Comprar un paquete de figuritas\n"
																				  "2.Intercambiar figuritas\n"
																				  "3.Informes\n"
																				  "4.Salir");

				retorno = GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida: ",1, 4, 2);
				InicializarUnArray(arrayDeFiguritas, MAX_FIGURITAS);
				if(retorno != ERROR)
				{
					switch(opcion)
					{
						case 1:
							if(AbrirSobre(listaDeFiguritas,sizeDeFiguritas, arrayDeFiguritas, MAX_FIGURITAS, 5) != ERROR
							&& ImprimirCabecera("\n\t\t\t-- Figuritas Del Sobre  --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200) != ERROR
							&& MostrarFiguritasDeUnArray(arrayDeFiguritas, MAX_FIGURITAS, listaDeFiguritas, sizeDeFiguritas, listaDeEquipos, sizeEquipos,listaDeClubs,sizeDeClubs, listaDeligas,sizeDeLigas) != ERROR
							&& GuardarFiguritasDoradas(unAlbumDeFiguritas->esDorada,MAX_DORADAS, listaDeFiguritas, sizeDeFiguritas,arrayDeFiguritas,MAX_FIGURITAS,cantidadDeFiguritas) != ERROR
							&& GuardarFiguritasEnELAlbum(unAlbumDeFiguritas->idFigurita,MAX_FIGURITAS, listaDeFiguritas, sizeDeFiguritas,arrayDeFiguritas,MAX_FIGURITAS,cantidadDeFiguritas) != ERROR
							&& GuardarFiguritasRepetidas(unColeccionista->idFiguritasRepetidas,MAX_REPETIDAS, listaDeFiguritas, sizeDeFiguritas,unAlbumDeFiguritas,arrayDeFiguritas,MAX_FIGURITAS) >= 0)
							{
								MostrarListaDeRepetidas(arrayDeFiguritas,MAX_FIGURITAS,listaDeFiguritas,sizeDeFiguritas,listaDeEquipos,sizeEquipos,listaDeClubs,sizeDeClubs,listaDeligas,sizeDeLigas);
								unColeccionista->cantidadDeSobres++;
								cantidadDeFiguritas += ContarFiguritasDeUnArray(arrayDeFiguritas, MAX_FIGURITAS, listaDeFiguritas, sizeDeFiguritas);
								unColeccionista->cantidadDeDineroGastado += 170;

								if(EstadoDelAlbum(listaDeFiguritas, sizeDeFiguritas, unAlbumDeFiguritas) != OCUPADO)
								{
									dineroGastadoParaCompletarElAlbum += unColeccionista->cantidadDeDineroGastado;
									cantidadSobresCompletarElAlbum += unColeccionista->cantidadDeSobres;
								}else{
									unAlbumDeFiguritas->estado = OCUPADO;
									printf("No hay mas espacio en el Album");
								}
							}
							break;

						case 2:

							if(ContarFiguritasDeUnArray(unColeccionista->idFiguritasRepetidas, MAX_REPETIDAS, listaDeFiguritas, sizeDeFiguritas) > 0)
							{
								indexDeFigurita = IntercambiarFiguritas(listaDeFiguritas, sizeDeFiguritas, listaDeEquipos, sizeEquipos,unColeccionista->idFiguritasRepetidas,MAX_REPETIDAS,listaDeClubs, sizeDeClubs, listaDeligas, sizeDeLigas);
									switch(indexDeFigurita)
									{
									case -1:
										printf("Se produjo un error al intentar intercambiar una figurita");
										break;

									case -2:
										printf("Se cancelo el intercambio");
										break;

									default:
										if(CargarUnaFiguritaEnElAlbum(unAlbumDeFiguritas->idFigurita, MAX_FIGURITAS,listaDeFiguritas[indexDeFigurita].IdFigurita)  != ERROR
										|| CargarUnaFiguritaRepetida(unColeccionista->idFiguritasRepetidas, MAX_REPETIDAS, unAlbumDeFiguritas,listaDeFiguritas[indexDeFigurita].IdFigurita) != ERROR)
										{
											printf("Se intercambio con exito la figurita");
										}
										break;
									}
							}else{
								printf("Error -- Debe tener al menos una figurita repetida para poder intercambiala -- Error");
							}

							break;

						case 3:
							if(ContarFiguritasDeUnArray(unAlbumDeFiguritas->idFigurita, MAX_FIGURITAS, listaDeFiguritas, sizeDeFiguritas) > 0
							|| ContarFiguritasDeUnArray(unAlbumDeFiguritas->esDorada, MAX_DORADAS, listaDeFiguritas, sizeDeFiguritas) > 0)
							{
								if(SubMenuDeListados(listaDeFiguritas,sizeDeFiguritas, listaDeEquipos,sizeEquipos,unAlbumDeFiguritas,unColeccionista,cantidadSobresCompletarElAlbum,dineroGastadoParaCompletarElAlbum,listaDeClubs, sizeDeClubs, listaDeligas, sizeDeLigas) == ERROR)
								{
									printf("Error -- Se produjo un error en el Menu de Listados -- Error");
								}
							}
							break;

						case 4:
							if(ValidarChar(&respuesta, "¿Esta seguro que desea volver al menu principal? (s o n): ", "Ingrese una opcion valida (s o n): ", 's', 'n', 2) == ERROR)
							{
								printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error\n\n");
							}
							break;
					}
				}

			}while(respuesta != 's' && retorno != ERROR);
	}


	return retorno;
}


int MostrarLigasConMayorCantidad(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeEquipos,eAlbum* unAlbumDeFiguritas,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas,eAuxiliar arrayAuxiliar[],int sizeAuxiliar,int maximo)
{
    int indexLiga;
    int estado;
    estado = ERROR;

    if(sizeAuxiliar > 0 && sizeDeLigas > 0 && unAlbumDeFiguritas != NULL)
    {
		for (int i = 0; i <sizeAuxiliar; i++)
		{
			indexLiga = BuscarPorIdDeLiga(listaDeLigas, sizeDeLigas, arrayAuxiliar[i].id);

			if(arrayAuxiliar[i].estado == OCUPADO && indexLiga != ERROR && arrayAuxiliar[i].contador == maximo)
			{
			    printf("%4d | %-15s  | %-15d |\n",listaDeLigas[indexLiga].idDeLiga,listaDeLigas[indexLiga].descripsion,arrayAuxiliar[i].contador);
				MostrarUnMensajeRepetidasVeces("-", 60);
				printf("\n");
				MostrarFiguritasPegadaDeCadaLiga(listaDeFiguritas,sizeDeFiguritas,listaDeEquipos,sizeEquipos,listaDeClubs,sizeDeClubs,unAlbumDeFiguritas,listaDeClubs[indexLiga].idDeLiga);
			}
		}
		estado = OK;
    }

    return estado;
}

int MostrarFiguritasPegadaDeCadaLiga(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeEquipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eAlbum* unAlbumDeFiguritas,int idDeLiga)
{
	int estado;
	estado = ERROR;

		   if(sizeDeFiguritas >= 0 && sizeDeClubs > 0 && sizeDeFiguritas >= 0 )
				{
					estado = OK;

					for (int i = 0; i <sizeDeClubs; i++) {

						if(listaDeClubs[i].estado == OCUPADO && listaDeClubs[i].idDeLiga == idDeLiga)
						{
							MostrarUnaFiguritaPegadaDeUnaLiga(listaDeFiguritas,sizeDeFiguritas,listaDeEquipos,sizeEquipos,unAlbumDeFiguritas,listaDeClubs[i]);
						}
					}
				}
			    return estado;
}

int MostrarUnaFiguritaPegadaDeUnaLiga(eFiguritas listaDeFiguritas[],int sizeDeLista,eEquipo listaDeEquipos[],int sizeEquipos,eAlbum* unAlbumDeFiguritas,eClubDeFutbol unClubDeFutbol)
{
	int estado;
	int indexDeFigurita;
	int indexDorada;
	int indexEquipo;
			 estado = ERROR;

		   if(sizeDeLista >= 0 && sizeEquipos > 0 && sizeDeLista >= 0 && unAlbumDeFiguritas != NULL)
				{
					estado = OK;
					for (int i = 0; i <sizeDeLista; i++) {

						indexDeFigurita = BuscarIdEnElArray(unAlbumDeFiguritas->idFigurita, MAX_FIGURITAS, listaDeFiguritas[i].IdFigurita);
						indexDorada = BuscarIdEnElArray(unAlbumDeFiguritas->esDorada, MAX_DORADAS, listaDeFiguritas[i].IdFigurita);
						indexEquipo = BuscarIdDeEquipo(listaDeEquipos, sizeEquipos, listaDeFiguritas[i].idEquipo);

						if((indexDeFigurita != ERROR || indexDorada != ERROR)  && indexEquipo != ERROR &&
						listaDeFiguritas[i].estado == OCUPADO && listaDeFiguritas[i].idDeClub == unClubDeFutbol.idDeClub)
						{

							printf("%-3d| %-24s | %-20s |%-25s | %-25s | %-25s | %-12.2f | %-11.2f | %20d |  %d/%d/%d \n",listaDeFiguritas[i].IdFigurita,
																																															 listaDeFiguritas[i].nombreJugador,
																																															listaDeFiguritas[i].posicion,
																																															listaDeEquipos[indexEquipo].descripcion,
																																															unClubDeFutbol.descripcion,
																																															listaDeEquipos[indexEquipo].directorTecnico,
																																															listaDeFiguritas[i].altura,
																																															listaDeFiguritas[i].peso,
																																															listaDeFiguritas[i].anioIngresoAlaSeleccion,
																																															listaDeFiguritas[i].fechaNacimiento.dia,
																																															listaDeFiguritas[i].fechaNacimiento.mes,
																																															listaDeFiguritas[i].fechaNacimiento.anio);
								MostrarUnMensajeRepetidasVeces("-", 200);
								printf("\n");
						}
					}
				}
			    return estado;
}

int CantidadDeFiguritasPegadasPorCadaLiga(eLiga listaDeLigas[],int sizeDeLigas,eClubDeFutbol listaDeClubs[],int sizeDeClubs,
		eFiguritas listaDeFiguritas[],int sizeDeLista,eAlbum* unAlbumDeFiguritas,eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{
	    int estado;
	    int indexLibre;

	    estado = ERROR;
	    if(unAlbumDeFiguritas != NULL && sizeDeLigas > 0 && sizeDeLista >= 0 && sizeAuxiliar >= 0)
	    {
	    	estado = OK;
	        for (int i = 0; i <sizeDeLigas; i++) {

	        	indexLibre = BuscarLibreAuxiliar(arrayAuxiliar, sizeAuxiliar);

	        	if(listaDeLigas[i].estado == OCUPADO && indexLibre != ERROR)
	        	{
	        		arrayAuxiliar[indexLibre].id = listaDeLigas[i].idDeLiga;
	        		arrayAuxiliar[indexLibre].contador = ContarFiguritasPegadasDeUnaLiga(listaDeFiguritas,sizeDeLista,listaDeClubs,sizeDeClubs,unAlbumDeFiguritas->idFigurita,MAX_FIGURITAS,listaDeLigas[i].idDeLiga);
	        		arrayAuxiliar[indexLibre].contador += ContarFiguritasPegadasDeUnaLiga(listaDeFiguritas,sizeDeLista,listaDeClubs,sizeDeClubs,unAlbumDeFiguritas->esDorada,MAX_DORADAS,listaDeLigas[i].idDeLiga);
	        		arrayAuxiliar[indexLibre].estado = OCUPADO;
	        	}
	        }
	    }

	    return estado;
}

int ContarFiguritasPegadasDeUnaLiga(eFiguritas listaDeFiguritas[],int sizeDeLista,eClubDeFutbol listaDeClubs[],int sizeDeClubs,int arrayDeFiguritas[],int sizeDeFiguritas,int idDeLiga)
{
		    int acumulador;
			acumulador = 0;

				for (int i = 0; i <sizeDeClubs; i++) {

					if(listaDeClubs[i].estado == OCUPADO
					&& listaDeClubs[i].idDeLiga == idDeLiga)
					{
						acumulador += ContarFiguritasPegadasDeUnClub(listaDeFiguritas, sizeDeLista, arrayDeFiguritas, sizeDeFiguritas, listaDeClubs[i].idDeClub);
					}
				}

		 return acumulador;
}


int MostrarPorcentajeDeFigutiasPegadasPorCadaClubs(eFiguritas listaDeFiguritas[],int sizeDeLista,eEquipo listaDeEquipos[],int sizeEquipos,
		eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeligas[],int sizeDeLigas,
		eAlbum* unAlbumDeFiguritas ,eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{

	int estado;
	int indexDeClub;
		 estado = ERROR;

	   if(sizeDeLista >= 0 && sizeDeClubs > 0 && sizeDeLista >= 0 && sizeAuxiliar >= 0)
			{
				estado = OK;
				ImprimirCabecera("\t\t--- Lista De Clubs ---\n","| 	   NOMBRE	 |	PORCENTAJE	|\n","=","-",50);
				for (int i = 0; i <sizeAuxiliar; i++) {

					indexDeClub = BuscarPorIdDeClubDeFutbol(listaDeClubs, sizeDeClubs, arrayAuxiliar[i].id);

					if(indexDeClub != ERROR && arrayAuxiliar[i].estado == OCUPADO && arrayAuxiliar[i].contador > 0)
					{
						printf("%-20s |%-15.2f |\n",listaDeClubs[indexDeClub].descripcion,arrayAuxiliar[i].porcentaje);
						MostrarUnMensajeRepetidasVeces("-", 50);
						printf("\n");
						MostrarUnFiguritaPegadaDeUnClub(listaDeFiguritas,sizeDeLista,listaDeEquipos,sizeEquipos,listaDeligas,sizeDeLigas,unAlbumDeFiguritas,listaDeClubs[indexDeClub]);
					}
				}
			}
		    return estado;

}

int MostrarUnFiguritaPegadaDeUnClub(eFiguritas listaDeFiguritas[],int sizeDeLista,eEquipo listaDeEquipos[],int sizeEquipos,eLiga listaDeligas[],int sizeDeLigas,eAlbum* unAlbumDeFiguritas,eClubDeFutbol unClubDeFutbol)
{
	int estado;
	int indexDeFigurita;
	int indexDorada;
	int indexLiga;
	int indexEquipo;
			 estado = ERROR;

		   if(sizeDeLista >= 0 && sizeEquipos > 0 && sizeDeLista >= 0 && unAlbumDeFiguritas != NULL)
				{
					estado = OK;
					for (int i = 0; i <sizeDeLista; i++) {

						indexDeFigurita = BuscarIdEnElArray(unAlbumDeFiguritas->idFigurita, MAX_FIGURITAS, listaDeFiguritas[i].IdFigurita);
						indexDorada = BuscarIdEnElArray(unAlbumDeFiguritas->esDorada, MAX_DORADAS, listaDeFiguritas[i].IdFigurita);
						indexLiga = BuscarPorIdDeLiga(listaDeligas, sizeDeLigas, unClubDeFutbol.idDeLiga);
						indexEquipo = BuscarIdDeEquipo(listaDeEquipos, sizeEquipos, listaDeFiguritas[i].idEquipo);

						if((indexDeFigurita != ERROR || indexDorada != ERROR) && indexLiga != ERROR && indexEquipo != ERROR &&
						listaDeFiguritas[i].estado == OCUPADO && listaDeFiguritas[i].idDeClub == unClubDeFutbol.idDeClub)
						{
							MostrarUnaFigurita( listaDeFiguritas[i], listaDeEquipos[indexEquipo], unClubDeFutbol, listaDeligas[indexLiga]);
						}
					}
				}
			    return estado;
}

int CantidadDeFiguritasPegadasPorCadaClubs(eClubDeFutbol listaDeClubs[],int sizeDeClubs,eFiguritas listaDeFiguritas[],int sizeDeLista,eAlbum* unAlbum,eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{
	    int estado;
	    int indexLibre;

	    estado = ERROR;
	    if(sizeDeClubs >= 0 && sizeDeLista >= 0 && sizeAuxiliar >= 0 && unAlbum != NULL)
	    {
	    	estado = OK;
	        for (int i = 0; i <sizeDeClubs; i++) {

	        	indexLibre = BuscarLibreAuxiliar(arrayAuxiliar, sizeAuxiliar);

	        	if(listaDeClubs[i].estado == OCUPADO && indexLibre != ERROR)
	        	{
	        		arrayAuxiliar[indexLibre].id = listaDeClubs[i].idDeClub;
	        		arrayAuxiliar[indexLibre].contador = ContarFiguritasPegadasDeUnClub(listaDeFiguritas,sizeDeLista,unAlbum->idFigurita,MAX_FIGURITAS,listaDeClubs[i].idDeClub);
	        		arrayAuxiliar[indexLibre].contador += ContarFiguritasPegadasDeUnClub(listaDeFiguritas,sizeDeLista,unAlbum->esDorada,MAX_DORADAS,listaDeClubs[i].idDeClub);
	        		arrayAuxiliar[indexLibre].estado = OCUPADO;
	        	}
	        }
	    }

	    return estado;
}

int ContarFiguritasPegadasDeUnClub(eFiguritas listaDeFiguritas[],int sizeDeLista,int arrayDeFiguritas[],int sizeDeFiguritas,int idDeClub)
{
			int indexFigurita;
		    int contadorDeFiguritas;
			contadorDeFiguritas = 0;

				for (int i = 0; i <sizeDeFiguritas; i++) {

					indexFigurita = BuscarPorIdDeFigurita(listaDeFiguritas, sizeDeLista, arrayDeFiguritas[i]);

					if(indexFigurita != ERROR  && listaDeFiguritas[indexFigurita].estado == OCUPADO
					&& listaDeFiguritas[indexFigurita].idDeClub == idDeClub)
					{
						contadorDeFiguritas++;
					}
				}

		 return contadorDeFiguritas;
}

int AbrirSobre(eFiguritas listaDeFiguritas[],int size,int arrayDeFiguritas[],int sizeDeFiguritas,int cantidadDeFiguritas)
{
    int index;
    int contadorDeFiguritas;
    int idMinimo;
    int id;

    index = ERROR;
    contadorDeFiguritas = CantidadDeFiguritasCargadas(listaDeFiguritas,size);

    if(size >= 0 && contadorDeFiguritas > 0 && contadorDeFiguritas >= cantidadDeFiguritas && BuscarIdMinimo(listaDeFiguritas, size,&idMinimo) != ERROR)
    {
        for (int i = 0; i <cantidadDeFiguritas; i++) {
        	id = idMinimo + (rand() %contadorDeFiguritas);
            index = BuscarPorIdDeFigurita(listaDeFiguritas,size,id);

            if(index != ERROR && arrayDeFiguritas[i] == LIBRE)
            {
            	arrayDeFiguritas[i] = listaDeFiguritas[index].IdFigurita;
            }
        }
    }


    return index;
}

int MostrarListaDeRepetidas(int listaDeRepetidas[],int sizeDeRepetidas,eFiguritas listaDeFiguritas[],int sizeDeFiguritas,
		eEquipo listaDeEquipos[],int sizeEquipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
    int estado;
    int cantidad;
    int indexDeEquipo;
    int indexRepetida;
    int indexDeClub;
    int indexDeLiga;
    estado = ERROR;

    if(sizeDeRepetidas >= 0 && sizeDeFiguritas >= 0 && ContarFiguritasDeUnArray(listaDeRepetidas, sizeDeRepetidas, listaDeFiguritas, sizeDeFiguritas) > 0)
    {
    	 estado = OK;
    	ImprimirCabecera("\n\t\t\t-- Figuritas Repetidas  --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	  | 	DIRECTOR TECNICO 		|    ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO  | CANTIDAD    \n","=","-",170);
        for (int i = 0; i <sizeDeFiguritas; i++) {

            cantidad = ContarRepetidas(listaDeRepetidas,sizeDeRepetidas,listaDeFiguritas[i].IdFigurita);
            indexDeEquipo = BuscarIdDeEquipo(listaDeEquipos, sizeEquipos, listaDeFiguritas[i].idEquipo);
            indexRepetida = BuscarIdEnElArray(listaDeRepetidas, sizeDeRepetidas, listaDeFiguritas[i].IdFigurita);
            indexDeClub = BuscarPorIdDeClubDeFutbol(listaDeClubs, sizeDeClubs, listaDeFiguritas[i].idDeClub);
            indexDeLiga = BuscarPorIdDeLiga(listaDeLigas, sizeDeLigas, listaDeClubs[indexDeClub].idDeLiga);

            if( indexDeEquipo != ERROR && indexDeClub  != ERROR && indexDeLiga  != ERROR && cantidad > 0 && indexRepetida != ERROR)
            {
            	printf("%-3d| %-24s | %-20s |%-25s | %-27s | %-25s | %-25s | %-12.2f | %-11.2f | %20d |  %d/%d/%-10d | %-10d\n",listaDeFiguritas[i].IdFigurita,
																																																					 listaDeFiguritas[i].nombreJugador,
																																																					 listaDeFiguritas[i].posicion,
																																																					 listaDeEquipos[indexDeEquipo].descripcion,
																																																					 listaDeEquipos[indexDeEquipo].directorTecnico,
																																																					 listaDeClubs[indexDeClub].descripcion
																																																					 ,listaDeLigas[indexDeLiga].descripsion,
																																																					 listaDeFiguritas[i].altura,
																																																					 listaDeFiguritas[i].peso,
																																																					 listaDeFiguritas[i].anioIngresoAlaSeleccion,
																																																					 listaDeFiguritas[i].fechaNacimiento.dia,
																																																					 listaDeFiguritas[i].fechaNacimiento.mes,
																																																					 listaDeFiguritas[i].fechaNacimiento.anio,
																																																					 cantidad);
            	MostrarUnMensajeRepetidasVeces("-", 200);
            	printf("\n");
            }
        }
    }

    return estado;
}
int ContarFiguritasRepetidasDeUnArray(int figuritas[],int size,int figuritasRepetidas[],int sizeDeRepetidas,eFiguritas listaDeFiguritas[],int sizeDeFiguritas)
{
	int indexDeRepetida;
	int cantidadDeRepetidas;
	cantidadDeRepetidas = ERROR;

	    if(sizeDeFiguritas >= 0 )
	    {
	    	cantidadDeRepetidas = 0;
			for (int i = 0; i <sizeDeRepetidas; i++) {
				indexDeRepetida = BuscarIdEnElArray(figuritas, size, figuritasRepetidas[i]);

				if(indexDeRepetida != ERROR &&
				BuscarPorIdDeFigurita(listaDeFiguritas, sizeDeFiguritas, figuritas[indexDeRepetida]) != ERROR )
				{
					cantidadDeRepetidas++;
				}

			}
	    }

	    return cantidadDeRepetidas;
}

int IntercambiarFiguritas(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeEquipos,int arrayDeRepetidas[],int sizeDeRepetidas,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLiga)
{
	    int indexDeRepetida;
	    int indexDeFigurita;
	    int indexFiguritaRepetida;
	    char respuesta;
	    int estado;
	    estado = ERROR;

	    indexDeFigurita = PedirIdDeFigurita(listaDeFiguritas,sizeDeFiguritas,listaDeEquipos,sizeEquipos, listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLiga,"Ingrese un id de la figurita que nesecita: ","ingrese un id Valido: ",2);
	    indexDeRepetida = PedirIdDeFiguritaRepetida(listaDeFiguritas,sizeDeFiguritas,listaDeEquipos,sizeEquipos, listaDeClubs,sizeDeClubs, listaDeLigas, sizeDeLiga,arrayDeRepetidas,sizeDeRepetidas,"Ingrese el id de la figurita que va a intercambiar: ","Reingrese la figurita que va a intercambiar: ",2);

	      if(indexDeFigurita != ERROR && indexDeRepetida != ERROR)
		  {
				  indexFiguritaRepetida = BuscarPorIdDeFigurita(listaDeFiguritas, sizeDeFiguritas, arrayDeRepetidas[indexDeRepetida]);

			  	  if(indexFiguritaRepetida != ERROR)
			  	  {
				  ImprimirCabecera("\n\n\t\t\t\t-- 	Figurita Seleccionada	 --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	 | 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200);
				  MostrarUnaFiguritaCompleta(listaDeFiguritas[indexDeFigurita], listaDeEquipos, sizeEquipos, listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLiga);

				  ImprimirCabecera("\n\n\t\t\t\t--- 	Figurita Que Va a Intercambiar	 ---\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	 | 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200);
				  MostrarUnaFiguritaCompleta(listaDeFiguritas[indexFiguritaRepetida], listaDeEquipos, sizeEquipos, listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLiga);

				  ValidarChar(&respuesta,"¿Esta seguro que desea intercambiar esta figurita? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2);

					switch(respuesta)
					{
						case 's':
						arrayDeRepetidas[indexDeRepetida] = 0;
						estado = indexDeFigurita;
						break;

						case 'n':
						estado = -2;
						break;
					}

			  }
	  }

	  return estado;
}

int PedirIdDeFiguritaRepetida(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeEquipos,
		eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeligas[],
		int sizeDeLigas,int arrayDeRepetida[],int sizeDeRepetidas,char mensaje[],char mensajeError[],int reitentos)
{
	int index;
	int idDeFigurita;

	index = ERROR;
		if(mensaje != NULL && mensajeError != NULL && reitentos >= 0 &&
			MostrarListaDeRepetidas(arrayDeRepetida, sizeDeRepetidas, listaDeFiguritas, sizeDeFiguritas, listaDeEquipos, sizeEquipos,listaDeClubs,sizeDeClubs,listaDeligas,sizeDeLigas) != ERROR
			&& GetNumero(&idDeFigurita, mensaje,mensajeError, 1, 10000, 2) == 0){

				do{
					index = BuscarIdEnElArray(arrayDeRepetida, sizeDeRepetidas, idDeFigurita);
					if(index != ERROR){

						 break;
					}
					GetNumero(&idDeFigurita, mensajeError,mensajeError, 1, 10000, 2);
					reitentos--;
				}while(reitentos >= 0);
		}
		return index;
}

int CargaForzada(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeEquipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLiga,int maximo)
{
    int estado;

    estado = ERROR;
    eLiga listaAuxiliarDeLigas[ ] = {{1,"Liga Espaniola",1979,OCUPADO},{2,"Ligue 1",1978,OCUPADO},{3,"Brasileirao",1788,OCUPADO},{4,"Superliga",5,OCUPADO},{5,"BundesLiga",1979,OCUPADO}};
    eClubDeFutbol listaAuxiliarDeClub[ ] = {{1,"Paris Saint Germain",10,2,OCUPADO},{2,"Atletico De Madrid",5,1,OCUPADO},{3,"Barcelona",14,1,OCUPADO},{4,"Botafogo",3,OCUPADO},{5,"Bayern de Munich",11,5,OCUPADO}};
    eEquipo auxiliarDeEquipo[ ] = {{1,"Lionel Scaloni","Argentina",OCUPADO},{2,"Luis Enrique","Espania",OCUPADO},{3,"Didier Deschamps","Francia",OCUPADO},{4,"Hansi Flick","Alemania",OCUPADO},{5,"Tite","Brasil",OCUPADO}};
    eFiguritas auxiliarDeFiguritas[ ] = {{1,"Di Maria","Delantero",1,1,40,49,1720,{1,2,1990},OCUPADO},
															{2,"Neymar","Delantero",4,1,45,48,1940,{1,2,1990},OCUPADO},
															{3,"Jamal Musiala","Mediocampista",4,5,70,49,1900,{1,2,1990},OCUPADO},
															{4,"Pepe","Delantero",3,3,45,80.2,1970,{1,2,1990},OCUPADO},
															{5,"Messi","Delantero",1,1,45,80.2,1900,{1,2,1990},OCUPADO}};



	if(maximo < sizeDeFiguritas)
	{
	    estado = OK;

        for(int i = 0;i<maximo;i++){

        	if(CargarForzadaDeUnaFigurita(listaDeFiguritas,sizeDeFiguritas,ObtenerID(),auxiliarDeFiguritas[i].nombreJugador,auxiliarDeFiguritas[i].posicion,auxiliarDeFiguritas[i].idDeClub,auxiliarDeFiguritas[i].idEquipo,auxiliarDeFiguritas[i].altura,
        	auxiliarDeFiguritas[i].peso,auxiliarDeFiguritas[i].anioIngresoAlaSeleccion,auxiliarDeFiguritas[i].fechaNacimiento.dia,auxiliarDeFiguritas[i].fechaNacimiento.mes,
			auxiliarDeFiguritas[i].fechaNacimiento.anio) == ERROR || CargaForzadaDeEquipo(listaDeEquipos, sizeEquipos, auxiliarDeEquipo[i].idEquipo, auxiliarDeEquipo[i].directorTecnico, auxiliarDeEquipo[i].descripcion) == ERROR
        	|| CargaForzadaDeClub(listaDeClubs, sizeDeClubs, listaAuxiliarDeClub[i].idDeClub, listaAuxiliarDeClub[i].descripcion, listaAuxiliarDeClub[i].cantidadDeTrofeos,listaAuxiliarDeClub[i].idDeLiga) == ERROR
			|| CargaForzadaDeUnaLiga(listaDeLigas, sizeDeLiga, listaAuxiliarDeLigas[i].idDeLiga,listaAuxiliarDeLigas[i].descripsion,listaAuxiliarDeLigas[i].anioDefundacion) == ERROR)
        	{
        		estado = ERROR;
        	   break;
        	}
        }

    }

    return estado;
}


int MostrarFiguritasDeUnArray(int figuritas[],int size,eFiguritas listaDeFiguritas[],int sizeDeFiguritas,
		eEquipo listaDeEquipos[],int sizeDeEquipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeligas[],int sizeDeLigas)
{
    int index;
    int estado;

    estado = ERROR;
    if(sizeDeFiguritas >= 0)
    {
    	estado = OK;

		for (int i = 0; i <size; i++) {
			index = BuscarPorIdDeFigurita(listaDeFiguritas, sizeDeFiguritas, figuritas[i]);

			if(index != ERROR )
			{
			   MostrarUnaFiguritaCompleta(listaDeFiguritas[index], listaDeEquipos, sizeDeEquipos, listaDeClubs,sizeDeClubs, listaDeligas, sizeDeLigas);
			}
		}
    }

    return estado;
}

int MostrarUnaFiguritaCompleta(eFiguritas listaDeFiguritas,eEquipo listaDeEquipos[],int sizeDeEquipos,eClubDeFutbol listaDeClubs[],int sizeDeClub,eLiga listaDeLigas[],int sizeDeLiga){

    int estado;
    int indexDeEquipos;
    int indexDeClub;
    int indexDeLiga;

    estado = ERROR;

    if(listaDeFiguritas.estado == OCUPADO){

    indexDeEquipos = BuscarIdDeEquipo(listaDeEquipos, sizeDeEquipos, listaDeFiguritas.idEquipo);
    indexDeClub = BuscarPorIdDeClubDeFutbol(listaDeClubs, sizeDeClub, listaDeFiguritas.idDeClub);
    indexDeLiga = BuscarPorIdDeLiga(listaDeLigas, sizeDeLiga, listaDeClubs[indexDeClub].idDeLiga);

        if(indexDeClub != ERROR && indexDeEquipos != ERROR && indexDeLiga != ERROR ){
            MostrarUnaFigurita(listaDeFiguritas, listaDeEquipos[indexDeEquipos],listaDeClubs[indexDeClub],listaDeLigas[indexDeLiga]);
            estado = OK;
        }
    }

    return estado;
}

int OrdenarListaDeFigutasPorEquipo(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipo [],int sizeDeEquipo,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
	int estado;

	estado = ERROR;

	if(sizeDeFiguritas >= 0 && sizeDeEquipo >= 0)
	{
	    ImprimirCabecera("\n\t\t\t\t-- 	Lista De Figuritas	 --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		CLUB DE FUTBOL 		| 	 		LIGA		 	| 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200);

	    for (int i = 0; i < sizeDeEquipo; i++) {

	    	if(listaDeEquipo[i].estado == OCUPADO)
	    	{
	    		MostrarListaDeFiguritasDeUnEquipo(listaDeFiguritas,sizeDeFiguritas,listaDeEquipo[i],listaDeClubs,sizeDeClubs,listaDeLigas,sizeDeLigas);
	    	}

		}

		estado = OK;
	}

	return estado;
}

int MostrarListaDeFiguritasDeUnEquipo(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo unEquipo,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
	int estado;
	int indexDeClub;
	int indexDeLigas;

	estado = ERROR;

	if(listaDeFiguritas != NULL && sizeDeFiguritas >= 0)
	{
		estado = OK;

		for (int i = 0; i < sizeDeFiguritas; i++) {

			indexDeClub = BuscarPorIdDeClubDeFutbol(listaDeClubs, sizeDeClubs, listaDeFiguritas[i].idDeClub);
			indexDeLigas = BuscarPorIdDeLiga(listaDeLigas, sizeDeLigas,listaDeClubs[indexDeClub].idDeLiga);

				if(listaDeFiguritas[i].estado == OCUPADO && listaDeFiguritas[i].idEquipo == unEquipo.idEquipo && indexDeClub != ERROR && indexDeLigas != ERROR)
				{
					MostrarUnaFigurita(listaDeFiguritas[i], unEquipo, listaDeClubs[indexDeClub], listaDeLigas[indexDeLigas]);
				}
		}
	}


	return estado;
}

int PedirIdDeFigurita(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeEquipos,
		eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas,char mensaje[],char mensajeError[],int reitentos)
{
	int index;
	int idDeFigurita;

	index = ERROR;

		if(mensaje != NULL && mensajeError != NULL && reitentos >= 0 &&
		MostraListaDeFiguritas(listaDeFiguritas, sizeDeFiguritas, listaDeEquipos, sizeEquipos,listaDeClubs,sizeDeClubs,listaDeLigas,sizeDeLigas) != ERROR
		 && GetNumero(&idDeFigurita, mensaje,mensajeError, 1, 10000, 2) == 0){

	    	do{
	    		index = BuscarPorIdDeFigurita(listaDeFiguritas, sizeDeFiguritas, idDeFigurita);
	            if(index != ERROR){

	            	 break;
	            }
	            GetNumero(&idDeFigurita, mensajeError,mensajeError, 1, 10000, 2);
	            reitentos--;
	        }while(reitentos >= 0);

		}
		return index;
}

int ListarFiguritasGuardadasDeUnEquipo(eEquipo unEquipo,eFiguritas listaDeFiguritas[],
		int sizeDeFiguritas,int arrayDeFiguritas[],int sizeDelAlbum,eClubDeFutbol listaDeClubs[],int sizeDeClubs,
		eLiga listaDeLigas[],int sizeDeLigas)
{
	int indexDeFigurita;
	int indexDeClub;
	int indexDeLigas;
	int estado;
	estado = ERROR;
	if(CantidadDeFiguritasGuardadasDeUnEquipo(unEquipo,listaDeFiguritas,sizeDeFiguritas,arrayDeFiguritas,sizeDelAlbum) > 0)
	{
		estado = OK;
		for (int i = 0; i < sizeDelAlbum; i++) {

			indexDeFigurita = BuscarPorIdDeFigurita(listaDeFiguritas, sizeDeFiguritas, arrayDeFiguritas[i]);
			indexDeClub = BuscarPorIdDeClubDeFutbol(listaDeClubs, sizeDeClubs, listaDeFiguritas[indexDeFigurita].idDeClub);
			indexDeLigas = BuscarPorIdDeLiga(listaDeLigas, sizeDeLigas,listaDeClubs[indexDeClub].idDeLiga);

			if(indexDeFigurita != ERROR && indexDeLigas != ERROR && indexDeClub != ERROR && listaDeFiguritas[indexDeFigurita].estado == OCUPADO && listaDeFiguritas[indexDeFigurita].idEquipo == unEquipo.idEquipo)
			{
				MostrarUnaFigurita(listaDeFiguritas[i], unEquipo, listaDeClubs[indexDeClub], listaDeLigas[indexDeLigas]);
			}

		}

	}

	return estado;
}

int CantidadDeFiguritasGuardadasDeUnEquipo(eEquipo unEquipo,eFiguritas listaDeFiguritas[],int sizeDeFiguritas,int arrayDeFiguritas[],int sizeDeArray)
{
	int indexDeFigurita;
	int cantidad;
	cantidad = ERROR;
	if(CantidadDeFiguritasCargadas(listaDeFiguritas, sizeDeFiguritas) > 0 &&
	ContarFiguritasDeUnArray(arrayDeFiguritas, sizeDeArray, listaDeFiguritas, sizeDeFiguritas) > 0)
	{
		cantidad = 0;
		for (int i = 0; i < sizeDeArray; i++) {

			indexDeFigurita = BuscarPorIdDeFigurita(listaDeFiguritas, sizeDeFiguritas, arrayDeFiguritas[i]);

			if(indexDeFigurita != ERROR && listaDeFiguritas[indexDeFigurita].estado == OCUPADO && listaDeFiguritas[indexDeFigurita].idEquipo == unEquipo.idEquipo)
			{
				cantidad++;
			}

		}

	}

	return cantidad;
}


