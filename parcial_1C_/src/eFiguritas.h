#ifndef EFIGURITAS_H_
#define EFIGURITAS_H_

#include "Menu.h"

#define  ERROR -1
#define  LIBRE 0
#define  OCUPADO 1
#define  OK 1
#define  MAX_FIGURITAS 40
#define  MAX_NOMBRE 40
#define  MAX_DORADAS 15
#define  MAX_EQUIPOS_DESCRIPCION 30
#define  MAX_EQUIPOS 10
#define  MAX_POSICION 20
#define  MAX_DIRECTOR_TECNICO 40
#define  MAX_REPETIDAS 100
#define  MAX_CLUB_DE_FUTBOL 40
#define  MAX_NOMBRE_CLUB 50
#define MAX_LIGA_NOMBRE 40
#define MAX_AUXILIAR 50
#define  MAX_LIGA 10

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idDeLiga;
    char descripsion[MAX_LIGA_NOMBRE];
    int anioDefundacion;
    int estado;
}eLiga;

typedef struct
{
    int idDeClub;
    char descripcion[MAX_NOMBRE_CLUB];
    int cantidadDeTrofeos;
    int idDeLiga;
    int estado;
}eClubDeFutbol;

typedef struct
{
    int idEquipo;
    char directorTecnico[MAX_DIRECTOR_TECNICO];
    char descripcion[MAX_EQUIPOS_DESCRIPCION];
    int estado;
}eEquipo;

typedef struct
{
    int id;
    int contador;
    float acumulador;
    float porcentaje;
    int estado;
}eAuxiliar;

typedef struct
{
	int idFiguritasRepetidas[MAX_REPETIDAS];
    int cantidadDeSobres;
    float cantidadDeDineroGastado;
    int estado;
}eColeccionista;

typedef struct
{
	int IdFigurita;
	char nombreJugador[MAX_NOMBRE];
	char posicion[MAX_POSICION];
	int idEquipo;
	int idDeClub;
	float altura;
	float peso;
	int anioIngresoAlaSeleccion;
	eFecha fechaNacimiento;
	int estado;
}eFiguritas;

typedef struct
{
	int idFigurita[MAX_FIGURITAS];// (int[])
	int esDorada[MAX_DORADAS];// (int[])
	int estado;
}eAlbum;//55

/// @fn int CargarForzadaDeUnaFigurita(eFiguritas[], int, int, char[], char[], int, int, float, float, int, int, int, int)
/// @brief Permite cargar una figurita validando que los datos a guardar sea validos
///
/// @return [-1] si hubo error en los parametros ,[1] si esta ok
int CargarForzadaDeUnaFigurita(eFiguritas listaDeFiguritas[],int sizeDeFiguritas,int IdFigurita,char nombreJugador[],char posicion[],int idDeClub,
		int idEquipo,float altura, float peso, int anioIngresoAlaSeleccion,int  dia,int mes, int anio);

/// @fn int Pedir_fecha(eFecha* unaFecha);
/// @brief Permite pedir una fecha validando que se ingres una fecha valida
///
/// @param eFecha* el puntero a una fecha
/// @return[-1] si hubo error ,[1] si esta ok
int Pedir_fecha(eFecha* unaFecha);

/// @fn int ModificarUnaFigurita(eFiguritas[], int, eEquipo[], int)
/// @brief Permite Modificar cualquier campo de una figurita, validando que se ingresen correctamente
/// Todos los datos
///
/// @return [-1] si hubo error , [0] si se cancelo la modificacion,[1] si se modifico algun dato
int ModificarUnaFigurita(eFiguritas listaDeFiguritas[],int size,eEquipo listaDeEquipos[],int sizeDeEquipos,eClubDeFutbol[],int,eLiga[],int);

/// @fn int PedirPosicion(char[], int)
/// @brief Permite pedir una Posicion validando que se ingres una Posicion valida
///
/// @param posicion
/// @param size
/// @return [-1] si hubo error ,[1] si no hubo error
int PedirPosicion(char posicion[],int size);

/// @fn int SubMenuAdministrador(eFiguritas[], int, eEquipo[], int)
/// @brief Mustra el submenu De Administrador
///
/// @param eFiguritas[] el array de eFiguritas
/// @param int el tamaño del array de eFiguritas
/// @param eEquipo[] el array de eEquipo
/// @param int el tamaño del array de eEquipo
int SubMenuAdministrador(eFiguritas listaDeFiguritas[],int size,eEquipo listaDeEquipos[],int sizeDeEquipos,
		eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas);

/// @fn int InicializarLista(eFiguritas[], int)
/// @brief Inicializa la lista de figuritas
///
/// @param eFiguritas[] la lista
/// @param int el tamaño del array
/// @return [-1] si hubo error ,[1] si no hubo error
int InicializarListaDeFiguritas(eFiguritas listaDeFiguritas[], int size);

/// @fn int CantidadDeFiguritasCargadas(eFiguritas[], int)
/// @brief Cuenta cuntas figuritas hay cargadas y devulve la cantidad
///
/// @param eFiguritas[] la lista
/// @param int el tamaño del array
/// @return la cantidad de figuritas cargadas
int CantidadDeFiguritasCargadas(eFiguritas listaDeFiguritas[],int size);

/// @fn int BuscarIdMinimo(eFiguritas[], int, int*)
/// @brief Reccorre la lista y busca el id minimo de la lista
///
/// @param eFiguritas[] la lista
/// @param int el tamaño del array
/// @param int* donde se va a guardar el id minimo
/// @return [-1] si hubo error ,[1] si no hubo error
int BuscarIdMinimo(eFiguritas listaDeFiguritas[],int size,int* minimo);

/// @fn int BuscarFiguritaLibre(eFiguritas listaDeFiguritas[],int size);
/// @brief Busca un espacio libre en el array
///
/// @param eFiguritas[] la lista
/// @param int el tamaño del array
/// @return [-1] si no encontro espacio , sino devulve el indice del primer espacio libre del array
int  BuscarFiguritaLibre(eFiguritas listaDeFiguritas[],int size);

/// @fn int BuscarPorId(eFiguritas[], int, int)
/// @brief Busca en el array el id que concide con el id pasado por parametro
///
/// @param eFiguritas[] el array de figuritas
/// @param int el tamanio del array de figuritas
/// @param int el id a buscar
/// @return [-1] si no encontro el id, [INDICE] el indice del array donde se encuntra ese id
int BuscarPorIdDeFigurita(eFiguritas listaDeFiguritas[], int size,int id);


/// @fn int AltaDeFigurita(eFiguritas[], int, eEquipo[], int)
/// @brief Permite guardar una figurita en el array de figuritas, validando que halla en el array espacio y
/// que se ingresen los datos correctamente
///
///
/// @param eFiguritas[] el array de figuritas
/// @param int el tamanio del array de figuritas
/// @param eEquipo[] el array de Equipos
/// @param  int el tamanio del array de Equipos
/// @return [-2] si no hay espacio en el array ,[-1] si no se pudo ingresar correctamente todos los campos, [1] si esta ok
int AltaDeFigurita(eFiguritas listaDeFiguritas[], int sizeDeFiguritas,eEquipo listaDeEquipos[],int sizeDeEquipos,
		eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas);

/// @fn int PedirUnaFigurita(eFiguritas*, eEquipo[], int)
/// @brief Permite pedir una figurita validadndo que se ingrese todos los parametros correctamente
///
/// @param eFiguritas* el puntero a una Figurita
/// @param eEquipo[] el array de Equipos
/// @param  int el tamanio del array de Equipos
/// @return [-1] si no se pudo ingresar correctamente , [1] si se ingreso correctamente
int PedirUnaFigurita(eFiguritas* unaFigurita,eEquipo listaDeEquipos[],int sizeDeEqipos,
		eClubDeFutbol listaDeClubs[],int sizeDeClubs,eLiga listaDeLigas[],int sizeDeLigas);


/// @fn int MostraLista(eFiguritas[], int, eEquipo[], int)
/// @brief Mustra la lista de figuritas
///
/// @param eFiguritas[] el array de figuritas
/// @param int el tamanio del array de figuritas
/// @param eEquipo[] el array de Equipos
/// @param  int el tamanio del array de Equipos
///  @return [-1] si la lista esta vacia, [1] esta ok
int MostraListaDeFiguritas(eFiguritas listaDeFiguritas[],int size,eEquipo listaDeEquipos[],int sizeDeEquipos,eClubDeFutbol[],int,eLiga[],int);

/// @fn int OrdenarListaDeFiguritasPorId(eFiguritas[], int, int)
/// @brief Ordena la lista de figuritas por id
///
/// @param eFiguritas[] el array de figuritas
/// @param int el tamanio del array de figuritas
/// @param int  [1] ordenar de forma ascendente , [0] ordenar de forma decendente
/// @return [-1] si hubo error en los parametros , [1] esta ok
int OrdenarListaDeFiguritasPorId(eFiguritas listaDeFiguritas[],int size,int order);

/// @fn void MostrarUnaFigurita(eFiguritas unaFigurita,eEquipo unEquipo,eClubDeFutbol unClub,eLiga unaLiga);
/// @brief Muestra Una figuritas
///
void MostrarUnaFigurita(eFiguritas unaFigurita,eEquipo unEquipo,eClubDeFutbol unClub,eLiga unaLiga );

/// @fn int ObtenerID()
/// @brief Permite obtener el id de forma automatica
///
/// @return el incremnto del id
int ObtenerID();


#endif /* EFIGURITAS_H_ */
