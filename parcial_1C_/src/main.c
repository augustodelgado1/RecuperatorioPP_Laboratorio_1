#include "Nexo.h"


int main(void) {
	setbuf(stdout,NULL);
	srand(time(NULL));

	    eFiguritas listaDeFiguritas[MAX_FIGURITAS];
	    eEquipo listaDeEquipos[MAX_EQUIPOS];
	    eAlbum unAlbumDeFiguritas;
	    eColeccionista unColeccionista;
	    eClubDeFutbol listaDeClubs[MAX_CLUB_DE_FUTBOL];
	    eLiga listaDeLigas[MAX_LIGA];
		int opcion;
		int retorno;
		char respuesta;
		int bandera;
		bandera = 0;

		    if(InicializarListaDeFiguritas(listaDeFiguritas, MAX_FIGURITAS) != ERROR
			&& InicializarListaDeEquipos(listaDeEquipos, MAX_EQUIPOS) != ERROR
			&& InicializarUnArray(unAlbumDeFiguritas.idFigurita, MAX_FIGURITAS) != ERROR
			&& InicializarUnArray(unAlbumDeFiguritas.esDorada, MAX_DORADAS) != ERROR
			&& InicializarUnArray(unColeccionista.idFiguritasRepetidas, MAX_REPETIDAS) != ERROR
			&& InicializarListaDeClubs(listaDeClubs, MAX_CLUB_DE_FUTBOL) != ERROR
			&& InicializarListaDeLigas(listaDeLigas, MAX_LIGA)  != ERROR)
		    {
				do{
																   menu("Menu Principal",
																		  "\n[1].Menu Admistrador"
																		  "\n[2].Menu De Coleccionista"
																		  "\n[3].Carga Forzada"
																		  "\n[4].Salir");
						   retorno = GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida: ",1, 4, 2);
						   if(retorno != ERROR){

							switch(opcion){
								case 1:
									if(SubMenuAdministrador(listaDeFiguritas, MAX_FIGURITAS,listaDeEquipos,MAX_EQUIPOS,listaDeClubs,MAX_CLUB_DE_FUTBOL,listaDeLigas, MAX_LIGA) == ERROR)
									{
										printf("Se produjo un error en el Menu de Administrador");
									}
									break;

								case 2:
									if(CantidadDeFiguritasCargadas(listaDeFiguritas, MAX_FIGURITAS) > 0)
									{
										if(SubmenuColeccionista(listaDeFiguritas, MAX_FIGURITAS,listaDeEquipos,MAX_EQUIPOS,&unAlbumDeFiguritas,&unColeccionista,listaDeClubs,MAX_CLUB_DE_FUTBOL,listaDeLigas, MAX_LIGA) == ERROR)
										{
											printf("Se produjo un error en el Menu de Coleccionista");
										}
									}else{
										printf("Debe Cargar al menos una figurita para acceder al menu del coleccionista");
									}
									break;

								case 3:
									if(bandera == 0 && CargaForzada(listaDeFiguritas, MAX_FIGURITAS,listaDeEquipos,MAX_EQUIPOS,listaDeClubs,MAX_CLUB_DE_FUTBOL,listaDeLigas,MAX_LIGA, 5) != ERROR)
									{
										printf("Se Pudo Realizar la carga Forzada");
										bandera = 1;
									}else{
									   printf("No se pudo Realizar la carga forzada");
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

				}while(respuesta != 's' && retorno != ERROR);
		    }

			return EXIT_SUCCESS;
}

