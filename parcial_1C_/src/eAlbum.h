
#ifndef EALBUM_H_
#define EALBUM_H_
#include "eFiguritas.h"



/// @fn int InicializarUnArray(int[], int)
/// @brief Inicializa todos los indice de un array en 0
///
/// @param int[] un array
/// @param  int la longuitud del array
/// @return [-1] si hubo error , [1] si esta ok
int InicializarUnArray(int listaDeFiguritas[], int size);

/// @fn int InicializarUnArray(int[], int)
/// @brief Recorre el array y cuentas las figuritas repetidas y devuelve la cantidad que conto
///
/// @param int[] un array
/// @param  int la longuitud del array
/// @param int la figurita que se va a contar cuantas veces se repite
/// @return [-1] si hubo error , [la cantidad de figuritas repetidas]
int ContarRepetidas(int listaDeRepetidas[],int size,int idFigurita);

/// @fn int CargarUnaFiguritaEnElAlbum(int[], int, int)
/// @brief Guarda en el array de figuritas, el figurita pasada por parametro
/// validando que esa  figurita no este array de figuritas y que haya espacion en el array
///
/// @param int[] un array
/// @param  int la longuitud del array
/// @param int la figurita que se va a guardar
/// @return [-1] si hubo error , [1] si esta ok
int CargarUnaFiguritaEnElAlbum(int arrayDeFiguritas[],int sizeDeFiguritas,int id);

/// @fn int EstadoDelAlbum(eFiguritas[], int, eAlbum*)
/// @brief Verifica si todas las figuritas de la lista estan pegadas en el Album
///
/// @param eFiguritas[] la lista De Figuritas
/// @param  int la longuitud del array
/// @param eAlbum* el puntero al album donde se va a verificar si esta esas figuritas
/// @return [0] si todavia faltan figuritas para completar el album ,[1] si ya esta lleno
int EstadoDelAlbum(eFiguritas listaDeFigurita[],int sizeDeLista,eAlbum* unAlbum);

/// @fn int BuscarEspacioEnElArray(int[], int)
/// @brief Busca el primer  indice libre en el array y devuelve el indice donde lo encontro
///
/// @param eFiguritas[] la lista De Figuritas
/// @param  int la longuitud del array
/// @return [-1] si no hay espacio,[indice] si encontro espacio
int BuscarEspacioEnElArray(int listaDeFiguritas[], int size);

/// @fn int BuscarPorId(eFiguritas[], int, int)
/// @brief Busca en el array el id que concide con el id pasado por parametro
///
/// @param int[] el array de figuritas
/// @param int el tamanio del array de figuritas
/// @param int el id a buscar
/// @return [-1] si no encontro el id, [INDICE] el indice del array donde se encuntra ese id
int BuscarIdEnElArray(int listaDeFiguritas[],int sizeDefiguritas,int id);

/// @fn int CantidadDeFiguritasCargadas(eFiguritas[], int)
/// @brief Cuenta cuntas figuritas hay en el album
///
/// @param eFiguritas[] la lista De Figuritas
/// @param int el tamaño del array
/// @return [-1] si no hubo error en los parametros,la cantidad que hay en el album
int ContarFiguritasDeUnArray(int figuritasDelAlbum[],int sizeDelAlbum,eFiguritas listaDeFiguritas[],int sizeDeFiguritas);

/// @fn int CargarUnaFiguritaRepetida(int[], int, int)
/// @brief Guarda en el array de repetidas, la figurita pasada por parametro
/// validando que esa  figurita este array en el album  y que haya espacion en el array De Repetidas
///
/// @param int[] un array
/// @param  int la longuitud del array
/// @param int la figurita que se va a guardar
/// @return [-1] si hubo error , [1] si esta ok
int CargarUnaFiguritaRepetida(int arrayDeRepetidas[],int sizeDeRepetidas,eAlbum* unAlbumDeFiguritas,int id);

/// @fn int CargarUnaFiguritaRepetida(int[], int, int)
/// @brief Guarda en el array de repetidas, las figurita del array pasado por parametro
/// validando que esa  figurita este array en el album  y que haya espacion en el array De Repetidas
///
/// @param int[] un array
/// @param  int la longuitud del array
/// @param int la figurita que se va a guardar
/// @return [-1] si hubo error , [1] si esta ok
int GuardarFiguritasRepetidas(int arrayDeRepetidas[],int sizeDeRepetidas,eFiguritas[],int,eAlbum* unAlbumDeFiguritas,int [],int );

/// @fn int CargarUnaFiguritaRepetida(int[], int, int)
/// @brief Guarda en el array de figuritas , las figurita del array pasado por parametro
/// validando que esa  figurita no este array en el album, que haya espacion en el array  y
/// que sea una figurita que pertenesca  a la lista de figuritas
///
/// @param int[] un array
/// @param  int la longuitud del array
/// @param int la figurita que se va a guardar
/// @return [-1] si hubo error , [1] si esta ok
int GuardarFiguritasEnELAlbum(int arrayDeFiguritas[],int sizeDeFiguritas,eFiguritas[],int,int [],int ,int );

/// @fn int CargarUnaFiguritaRepetida(int[], int, int)
/// @brief Guarda en el array de figuritas doradas, las del array de figurita pasado por parametro
/// validando que esa  figurita no este array en el album, que haya espacion en el array De  doradas y
/// que sea una figurita de la que pertenesca  a la lista de figuritas
///
/// @param int[] un array
/// @param  int la longuitud del array
/// @param int la figurita que se va a guardar
/// @return [-1] si hubo error , [1] si esta ok
int GuardarFiguritasDoradas(int arrayDeFiguritasDoradas[],int sizeDeDoradas,eFiguritas[],int,int [],int ,int );

#endif /* EALBUM_H_ */
