
#include "Nexo.h"

int SubMenuAdministrador(eFiguritas listaDeFiguritas[],int size,eEquipo listaDeEquipos[],int sizeDeEquipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
	    int opcion;
	    int estado;
	    char respuesta;


	    do{
														 menu("Menu Administrador",
															  "\n1.Ingresar una figurita\n"
															  "2.Modificar una figurita\n"
															  "3.Mostrar Lista De Figuritas Ordenada Por Equipos\n"
															  "4.Salir");

	            estado = GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida: ",1, 4, 2);

	       if(estado != ERROR)
	        {
	            switch(opcion)
	            {
	                case 1:
						switch(AltaDeFigurita(listaDeFiguritas, size,listaDeEquipos,sizeDeEquipos,listaDeClubs,sizeDeClubs,listaDeLigas,sizeDeLigas)){
							case -2:
								printf("No hay mas espacio\n\n");
								break;
							case 1:
								printf("Se Cargo con exito.\n\n");
								break;
							default:
								printf("No se pudo realizar el Alta\n\n");
								break;
							}
	                    break;

	                case 2:
	                    if(CantidadDeFiguritasCargadas(listaDeFiguritas, size) > 0)
	        			{
	                    	switch(ModificarUnaFigurita(listaDeFiguritas, size,listaDeEquipos,sizeDeEquipos,listaDeClubs,sizeDeClubs,listaDeLigas,sizeDeLigas)){
									case 0:
										printf("Se Cancelo la modificacion.\n\n");
										break;
									case 1:
										printf("Modificacion exitosa.\n\n");
									  break;
									default:
									printf("No se pudo realizar la modificacion.\n\n");
										break;
									}
	        			}else{
	        			    printf("Debe cargar una figurita para mostrar la lista");
	        			}
	                    break;

	                case 3:
	                    if(CantidadDeFiguritasCargadas(listaDeFiguritas, size) > 0)
	        			{
							if(OrdenarListaDeEquiposAlfeveticamente(listaDeEquipos,sizeDeEquipos) == ERROR
							|| MostrarListaDeFigutasPorOrdenadaPorEquipo(listaDeFiguritas, size,listaDeEquipos,sizeDeEquipos,listaDeClubs,sizeDeClubs,listaDeLigas,sizeDeLigas) == ERROR)
							{
								printf("Hubo un Error al intentar Mostrar la lista de figuritas");
							}
	        			}else{
	        				printf("Debe cargar una figurita para mostrar la lista");
	        			}

	                    break;

	                case 4:
	                	if(ValidarChar(&respuesta, "¿Esta seguro que desea salir del programa? (s o n): ", "Ingrese una opcion valida (s o n): ", 's', 'n', 2) == ERROR)
	                	{
	                		printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error\n\n");
	                	}
	                    break;
	            }
	        }

	    }while(respuesta != 's' && estado != ERROR);

	    return estado;
}

int ObtenerID()
{
    static int idIncremental = 1000;

    return idIncremental++;
}

int OrdenarListaDeFiguritasPorId(eFiguritas listaDeFiguritas[],int size,int order)
{
	int estado;
	eFiguritas unaFigurita;
	estado = ERROR;

	if(CantidadDeFiguritasCargadas(listaDeFiguritas, size) > 0 && (order == 1 || order == 0))
	{
		for (int i = 0;i<size-1;i++) {
					for (int j =i+1;j<size;j++) {

						if((listaDeFiguritas[i].IdFigurita > listaDeFiguritas[j].IdFigurita && order == 1)
						|| (listaDeFiguritas[i].IdFigurita < listaDeFiguritas[j].IdFigurita && order == 0))
						{
							unaFigurita = listaDeFiguritas[i];
							listaDeFiguritas[i] = listaDeFiguritas[j];
							listaDeFiguritas[j] = unaFigurita;
						}
					}
				}
			estado = OK;
	   }

	return estado;
}

int BuscarIdMinimo(eFiguritas listaDeFiguritas[],int size,int* minimo)
{
	int estado;
		estado = ERROR;

		if(minimo != NULL && CantidadDeFiguritasCargadas(listaDeFiguritas, size) > 0)
		{
				for (int i = 0;i<size;i++) {

				if(listaDeFiguritas[i].estado == OCUPADO  && (listaDeFiguritas[i].IdFigurita < (*minimo) || i == 0))
				{
					*minimo = listaDeFiguritas[i].IdFigurita;
				}
			}
		}
				estado = OK;

		return estado;
}

int BuscarIdMaximo(eFiguritas listaDeFiguritas[],int size,int* maximo)
{
	int estado;
		estado = ERROR;

		if(maximo != NULL && CantidadDeFiguritasCargadas(listaDeFiguritas, size) > 0)
		{
				for (int i = 0;i<size;i++) {

				if(listaDeFiguritas[i].estado == OCUPADO && (listaDeFiguritas[i].IdFigurita > (*maximo) || i == 0))
				{
					*maximo = listaDeFiguritas[i].IdFigurita;
				}
			}
		}
				estado = OK;

		return estado;
}

int CantidadDeFiguritasCargadas(eFiguritas listaDeFiguritas[],int size)
{
    int contador;

    contador = 0;

    for (int i = 0; i <size; i++) {

       if(listaDeFiguritas[i].estado == OCUPADO)
       {
           contador++;
       }

    }

    return contador;
}


int InicializarListaDeFiguritas(eFiguritas listaDeFiguritas[], int size)
{
	int retorno;

	retorno = ERROR;

	if(listaDeFiguritas != NULL && size >= 0){

		for(int i=0;i<size;i++){
			listaDeFiguritas[i].estado = LIBRE;
		}

		retorno = OK;
	}

	return retorno;
}

int BuscarFiguritaLibre(eFiguritas listaDeFiguritas[],int size)
{
	int estado;

	estado = ERROR;

	if(listaDeFiguritas != NULL && size >= 0)
	{
		for (int i=0;i<size;i++)
		{
			if(listaDeFiguritas[i].estado == LIBRE)
			{
				estado = i;
				break;
			}
		}
	}

	return estado;
}

int CargarForzadaDeUnaFigurita(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,int IdFigurita,char nombreJugador[],char posicion[],int idDeClub,
		int idEquipo,float altura, float peso, int anioIngresoAlaSeleccion,int  dia,int mes, int anio)
{
	int indexDeFigurita;
	int estado;

	estado = ERROR;
	indexDeFigurita = BuscarFiguritaLibre(listaDeFiguritas, sizeDeFiguritas);

	if(indexDeFigurita != ERROR && IdFigurita >= 0 && nombreJugador != NULL && posicion != NULL && altura > 0 && posicion != NULL && idDeClub > 0 && peso >= 0 && anioIngresoAlaSeleccion >= 0
		&& ValidarFecha(dia, mes, anio) != ERROR)
		{
			listaDeFiguritas[indexDeFigurita].IdFigurita = IdFigurita;
			strcpy(listaDeFiguritas[indexDeFigurita].nombreJugador,nombreJugador);
			strcpy(listaDeFiguritas[indexDeFigurita].posicion,posicion);
			listaDeFiguritas[indexDeFigurita].idEquipo = idEquipo;
			listaDeFiguritas[indexDeFigurita].idDeClub = idDeClub;
			listaDeFiguritas[indexDeFigurita].altura = altura;
			listaDeFiguritas[indexDeFigurita].peso = peso;
			listaDeFiguritas[indexDeFigurita].anioIngresoAlaSeleccion = anioIngresoAlaSeleccion;
			listaDeFiguritas[indexDeFigurita].fechaNacimiento.dia = dia;
			listaDeFiguritas[indexDeFigurita].fechaNacimiento.mes = mes;
			listaDeFiguritas[indexDeFigurita].fechaNacimiento.anio = anio;
			listaDeFiguritas[indexDeFigurita].estado = OCUPADO;
			estado = OK;
		}

	return estado;
}



int AltaDeFigurita(eFiguritas listaDeFiguritas[], int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeDeEquipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
	int index;
	int estado;
	estado = -2;
	index = BuscarFiguritaLibre(listaDeFiguritas,sizeDeFiguritas);

	if(index != ERROR){
	    estado = ERROR;

	    if(PedirUnaFigurita(&listaDeFiguritas[index],listaDeEquipos,sizeDeEquipos,listaDeClubs,sizeDeClubs,listaDeLigas,sizeDeLigas) != ERROR)
	    {
	    	listaDeFiguritas[index].IdFigurita = ObtenerID();
	    	ImprimirCabecera("\n\t\t\t\t-- 	Nueva Figurita --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 |		 CLUB		    |			LIGA 	       |	 NACIONALIDAD 	       	   | 		DIRECTOR TECNICO 	 | 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",300);
	        MostrarUnaFiguritaCompleta(listaDeFiguritas[index], listaDeEquipos, sizeDeEquipos, listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLigas);
	        estado = OK;
	    }
	}

	return estado;
}

int PedirUnaFigurita(eFiguritas* unaFigurita,eEquipo listaDeEquipos[],int sizeDeEqipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
	    eFiguritas unaFiguritaAuxiliar;
	    int estado;
	    int indexEquipo;
	    int indexDeClub;
	    estado = ERROR;

	if(unaFigurita != NULL){

		unaFiguritaAuxiliar.IdFigurita = unaFigurita->IdFigurita;

	        if(GetNombre("Ingrese el nombre: ","Error Ingrese el nombre ",unaFiguritaAuxiliar.nombreJugador,MAX_NOMBRE) == 0
	        && (indexEquipo = PedirEquipos(listaDeEquipos,sizeDeEqipos,"ingrese el id del Equipo: ","Error ingrese un id Valido: ",2)) != ERROR
			&& (indexDeClub = PedirUnClub(listaDeClubs, sizeDeClubs,listaDeLigas,sizeDeLigas, "Ingrese el id del club: ", "Error ingrese un id de club valido: ", 2))  != ERROR
			&& PedirPosicion(unaFiguritaAuxiliar.posicion,MAX_POSICION) != ERROR
			&& GetNumeroFlotante(&unaFiguritaAuxiliar.altura, "Ingrese la altura (cm): ","Error ingrese un numero valido: ",1,205,2) == 0
			&& GetNumeroFlotante(&unaFiguritaAuxiliar.peso, "Ingrese la peso: ","Error ingrese un numero valido: ",1,49,2) == 0
			&& GetNumero(&unaFiguritaAuxiliar.anioIngresoAlaSeleccion,"ingrese el anio de ingreso a la seleccion: ","Error ingrese un anio valido: ",1700,2023,3) == 0
			&& Pedir_fecha(&unaFiguritaAuxiliar.fechaNacimiento) != ERROR)
	        {
	        	unaFiguritaAuxiliar.idEquipo = listaDeEquipos[indexEquipo].idEquipo;
	        	unaFiguritaAuxiliar.idDeClub = listaDeClubs[indexDeClub].idDeClub;
	        	unaFiguritaAuxiliar.estado = OCUPADO;
	           estado = OK;
	          *unaFigurita = unaFiguritaAuxiliar;
	        }
		}

	return estado;
}

int MostraListaDeFiguritas(eFiguritas listaDeFiguritas[],int size,eEquipo listaDeEquipos[],int sizeDeEquipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
	int estado;

	estado = ERROR;

	if(CantidadDeFiguritasCargadas(listaDeFiguritas, size) > 0)
	{
	    ImprimirCabecera("\n\t\t\t\t-- Lista De Figuritas	 --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 |		 CLUB		    |			LIGA 	       | 		DIRECTOR TECNICO 	 | 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",300);
		for (int i = 0;i<size;i++) {

				 if(listaDeFiguritas[i].estado == OCUPADO){
					 MostrarUnaFiguritaCompleta(listaDeFiguritas[i], listaDeEquipos, sizeDeEquipos, listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLigas) ;
				 }
		}

		estado = OK;

	}

	return estado;
}

int BuscarPorIdDeFigurita(eFiguritas listaDeFiguritas[], int size,int id)
{
	int estado;

	 estado = ERROR;

	if(size > 0)
	{
		for (int i = 0;i<size;i++) {

    		if (listaDeFiguritas[i].estado == OCUPADO && listaDeFiguritas[i].IdFigurita == id) {
    			estado = i;
    			break;
    		}
    	}
	}

	return estado;
}

int ModificarUnaFigurita(eFiguritas listaDeFiguritas[], int size,eEquipo listaDeEquipos[],int sizeDeEqipos,eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas)
{
	int index;
	int estado;
	int opcion;
	int retorno;
	int contadorDeCambios;
	int indexEquipo;
	int indexDeClub;
	char respuesta;
	eFiguritas unaFigurita;

	index = PedirIdDeFigurita(listaDeFiguritas, size, listaDeEquipos, sizeDeEqipos, listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLigas,"Ingrese el id que desea Modificar: ", "Ingrese un id valido: ", 2);
	estado = ERROR;
	contadorDeCambios = 0;

		if(index >= 0 && listaDeFiguritas[index].estado == OCUPADO){

				unaFigurita = listaDeFiguritas[index];

			do{

																				menu("Menu De Modificaciones"
																				,"\n¿Que Quiere modificar?"
																				 "\n\n[1].Modificar el nombre "
																				 "\n[2].Modificar la equipo"
																				 "\n[3].Modificar el posicion"
																				 "\n[4].Modificar la altura"
																				 "\n[5].Modificar el peso"
																				 "\n[6].Modificar el anio ingreso a la seleccion"
																				 "\n[7].Modificar fecha de Nacimiento"
																				 "\n[8].Modificar el Club"
																				 "\n[9].Volver Al Menu Principal ");

				if(!GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida: ",1, 9, 2))
				{
					switch(opcion)
					{
						case 1:
						retorno = GetNombre("ingrese el nuvo nombre ","Error ingrese un nombre valido: ",unaFigurita.nombreJugador,MAX_NOMBRE);
						    break;

						case 2:
							indexEquipo = PedirEquipos(listaDeEquipos,sizeDeEqipos,"ingrese el id del Equipo: ","Error ingrese un id Valido: ",2);
							retorno = ERROR;
							if(indexEquipo != ERROR)
							{
									unaFigurita.idEquipo = listaDeEquipos[indexEquipo].idEquipo;
									retorno = OK;
							}
						    break;

						case 3:
						 retorno = PedirPosicion(unaFigurita.posicion,MAX_POSICION);
							break;

						case 4:
						 retorno = GetNumeroFlotante(&unaFigurita.altura, "Ingrese la altura (cm): ","Error ingrese un numero valido: ",1,205,2);
						    break;

						case 5:
						retorno = GetNumeroFlotante(&unaFigurita.peso, "Ingrese la peso: ","Error ingrese un numero valido: ",1,49,2);
						    break;

						case 6:
						retorno = GetNumero(&unaFigurita.anioIngresoAlaSeleccion,"ingrese el anio Ingreso Ala Seleccion:  ","Error ingrese un anio valido ",1700,2023,3);
						    break;

						case 7:
						retorno = Pedir_fecha(&unaFigurita.fechaNacimiento);
						    break;

						case 8:
							indexDeClub = PedirUnClub(listaDeClubs, sizeDeClubs,listaDeLigas,sizeDeLigas, "Ingrese el id del nuvo club: ", "Error ingrese un id de club valido: ", 2);
							retorno = ERROR;
							if(indexDeClub != ERROR)
							{
									unaFigurita.idDeClub = listaDeClubs[indexDeClub].idDeClub;
									retorno = OK;
							}
							break;

						case 9:
    						if(contadorDeCambios > 0)
    						{
    							ImprimirCabecera("\n\t\t\t\t-- 	Figurita Anterior	 --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200);
    						    MostrarUnaFiguritaCompleta(listaDeFiguritas[index], listaDeEquipos, sizeDeEqipos, listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLigas);

    						    ImprimirCabecera("\n\t\t\t\t-- 	Figurita Actulizada	 --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200);
                        		MostrarUnaFiguritaCompleta(unaFigurita, listaDeEquipos, sizeDeEqipos, listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLigas);

                        		retorno = ValidarChar(&respuesta,"¿Esta seguro que desea  guadar los cambios? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2);
    						}
						    break;
					    }


					if(retorno != ERROR && opcion != 9)
					{
					    printf("Se modifico exitosamente!!!!!!");
					    ImprimirCabecera("\n\t\t\t\t-- 	Figurita Actualizada	 --\n","ID  |   NOMBRE DE JUGADOR      |       POCISION       |       	  EQUIPO       	 | 		DIRECTOR TECNICO 	| 	ALTURA    |    PESO     |   ANIO DE INGRESO    |    FECHA DE NACIMIENTO      \n","=","-",200);
						MostrarUnaFiguritaCompleta(unaFigurita, listaDeEquipos, sizeDeEqipos,listaDeClubs, sizeDeClubs, listaDeLigas, sizeDeLigas);
					    contadorDeCambios++;
					}else{

					    if(retorno == ERROR && opcion != 9)
					    {
					        printf("No se pudo realizar la modificacion\n");
					    }
					}

				}

		}while(opcion != 9);

    		switch(respuesta)
    		{
        		case 's':
        		listaDeFiguritas[index] = unaFigurita;
    		    estado = OK;
        		break;

        		case 'n':
        		estado = 0;
        		break;
    		}

		}


	return estado;
}

void MostrarUnaFigurita(eFiguritas unaFigurita,eEquipo unEquipo,eClubDeFutbol unClub,eLiga unaLiga)
{
	printf("%-3d| %-24s | %-20s |%-25s | %-32s | %-25s | %-35s | %-14.2f | %-11.2f | %20d |  %d/%d/%d \n",unaFigurita.IdFigurita,
																																											     unaFigurita.nombreJugador,
																																												unaFigurita.posicion,
																																												unEquipo.descripcion,
																																												unClub.descripcion,
																																												unaLiga.descripsion,
																																												unEquipo.directorTecnico,
																																												unaFigurita.altura,
																																												unaFigurita.peso,
																																												unaFigurita.anioIngresoAlaSeleccion,
																																												unaFigurita.fechaNacimiento.dia,
																																												unaFigurita.fechaNacimiento.mes,
																																												unaFigurita.fechaNacimiento.anio);
	MostrarUnMensajeRepetidasVeces("-", 300);
	printf("\n");
}

int PedirPosicion(char posicion[],int size){

	int auxiliar;
	int estado;

	estado = ERROR;

	ImprimirCabecera("\t\t\t\t -- Seleccione una Posicion -- \n","\t\t\n1.Arquero"
																							 "\t\t\n2.Defensor"
																							 "\t\t\n3.Mediocampista"
																							 "\t\t\n4.Delantero\n", "*", "*", 40);

	if(!GetNumero(&auxiliar,"Ingrese la posicion: ", "Error ingrese una posicion Valida: ", 1,4, 2)){

		switch(auxiliar){
		case 1:
			strncpy(posicion,"Arquero",size);
			break;
		case 2:
			strncpy(posicion,"Defensor",size);
			break;
		case 3:
			strncpy(posicion,"Mediocampista",size);
			break;
		case 4:
		    strncpy(posicion,"Delantero",size);
		    break;
		}

		estado = OK;

	}

	return estado;

}

int Pedir_fecha(eFecha* unaFecha){
    eFecha auxiliarDeFecha;
    int estado;

    estado = ERROR;

    if(GetNumero(&auxiliarDeFecha.dia,"ingrese el dia de nacimiento del jugador: ","Error ingrese un dia valido ",1,31,3) == 0 &&
       GetNumero(&auxiliarDeFecha.mes,"ingrese el mes de nacimiento del jugador: ","Error ingrese un mes valido ",1,12,3) == 0 &&
       GetNumero(&auxiliarDeFecha.anio,"ingrese el anio de nacimiento del jugador: ","Error ingrese un anio valido ",1700,2023,3) == 0){


           while(ValidarFecha(auxiliarDeFecha.dia,auxiliarDeFecha.mes,auxiliarDeFecha.anio) == ERROR){

            GetNumero(&auxiliarDeFecha.dia,"Ingrese un dia valido: ","Error ingrese un dia valido: ",1,31,3);
            }

           *unaFecha= auxiliarDeFecha;
           estado = OK;
        }


    return estado;
}




