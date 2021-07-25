#ifndef __RUTAS_HPP__
#define __RUTAS_HPP__

#include "ruta.hpp"
#include "aeropuertos.hpp"

#include <string>

namespace bblProgII {
class Rutas {
public:
	// Constructor por defecto.
	// Inicializa la lista de Rutas a lista vacía
	Rutas();

	// Constructor de copia de Rutas.
	// Parámetros:
	//	- otro_objeto (E): objeto Rutas a copiar
	Rutas(const Rutas &otro_objeto);

	// Destructor de la clase
	~Rutas();

	// Devuelve el número de rutas
	unsigned num_rutas() const;

	// Escribe por pantalla las Rutas actuales.
	// Formato de salida por pantalla:
	// <origen>, <destino>, <precio>, <duracion>, <linea_aerea>
	// Por ejemplo:
	// AER, KZN, 344, 151, Aerocondor
	// ASF, KZN, 232, 112, Aerocondor
	// ASF, MRV, 106, 84, Aerocondor
	// ...

	void escribir_rutas() const;

	// Consulta la ruta de la posición 'num' de
	// la lista de Rutas. Si num < num_rutas(),
	// devuelve la ruta correspondiente
	// y 'OK' a través de 'res'. Si no, devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	// 	- num (E): posición de la ruta a consultar
	//	- ruta (S): ruta de la posición 'num'
	//  - res (S): resultado de la operación
	void consultar_ruta(unsigned num,
	                    Ruta &ruta,
	                    Resultado &res) const;

	// Consulta las rutas con un determinado 'origen'
	// y 'destino'. Si existe/n alguna/s ruta/s con ese
	// 'origen' y 'destino' se devuelve/n a través de
	// 'rutas' y se devuelve 'OK' a través de 'res'. Si no,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	// 	- origen (E): aeropuerto de origen de la ruta
	// 	- destino (E): aeropuerto de destino de la ruta
	// 	- rutas (S): lista de rutas con esos aeropuertos de
	//				 origen y destino
	// 	- res (S): resultado de la operación
	void consultar_rutas(const std::string &origen,
	                     const std::string &destino,
	                     Rutas &rutas,
	                     Resultado &res) const;

	// Devuelve un objeto Rutas con la lista de rutas
	// cuyo aeropuerto de origen coincide con el que
	// se pasa como parámetro. Si existe al menos una
	// ruta con ese aeropuerto de origen, se devuelve
	// 'OK' a través de 'res'. Si no, se devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- origen (E): aeropuerto de origen de la ruta
	// 	- rutas (S): lista de rutas con ese aeropuerto
	//				de origen.
	//	- res (S): resultado de la operación.
	void consultar_rutas_origen(const std::string &origen,
	                            Rutas &rutas,
	                            Resultado &res) const;
	// Devuelve un objeto Rutas con la lista de rutas
	// cuyo aeropuerto de destino coincide con el que
	// se pasa como parámetro. Si existe al menos una
	// ruta con ese aeropuerto de destino, se devuelve
	// 'OK' a través de 'res'. Si no, se devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- destino (E): aeropuerto de destino de la ruta
	// 	- rutas (S): lista de rutas con ese aeropuerto
	//				de origen.
	//	- res (S): resultado de la operación.
	void consultar_rutas_destino(const std::string &destino,
	                             Rutas &rutas,
	                             Resultado &res) const;

	// Consulta la lista de rutas que contienen,
	// ya sea como aeropuerto de origen o como aeropuerto de destino,
	// alguno de los 'aeropuertos' que se pasan como parámetro.
	// Si existe al menos una ruta con alguno de esos aeropuertos, se
	// devuelve 'OK' a través de 'res'. Si no, se devuelve 'NO_EXISTE'.
	// Parámetros:
	//	- aeropuertos (E): objeto Aeropuertos con la lista de aeropuertos
	//				cuyas rutas se quieren obtener.
	//	- rutas (S): lista de rutas que contienen esos aeropuertos
	//	- res (S): resultado de la operación
	// PRECONDICIÓN: aeropuertos.num_aeropuertos() > 0
	void consultar_rutas_aeropuertos(const Aeropuertos &aeropuertos,
	                                 Rutas &rutas,
	                                 Resultado &res) const;

	// Devuelve la ruta más barata (menor precio) de la lista de Rutas.
	// Si la lista está vacía, devuelve 'NO_EXISTE' a través
	// de 'RES'. Si no, devuelve OK.
	// Parámetros:
	//	- ruta (S): ruta más barata de la lista
	// 	- res (S: resultado de la operación
	void consultar_mas_barata(Ruta &ruta, Resultado &res) const;

	// Insertar nueva ruta al final de la lista de Rutas.
	// Si la ruta no existe (es decir, no hay una ruta
	// en la lista con los mismos atributos que ésta),
	// se inserta al final de la lista y se devuelve 'OK'
	// a través de 'res'. Si la ruta existe (hay una ruta
	// con los mismos  atributos), se
	// devuelve 'YA_EXISTE' a través de 'res'.
	// Parámetros:
	//	- ruta (E): ruta a insertar en la lista de Rutas.
	//	- res (S): resultado de la operación
	void insertar_ruta(const Ruta &ruta, Resultado &res);

	// Elimina la ruta que se pasa como parámetro de la
	// lista de Rutas.
	// Si la ruta existe, se elimina de la lista de Rutas
	// y se devuelve 'OK' a través de 'res'. Si no, se
	// devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- ruta (E): ruta a eliminar
	//	- res (S): resultado de la operación
	void eliminar_ruta(const Ruta &ruta,
	                   Resultado &res);

	// Elimina todas las rutas de la lista de Rutas que
	// contengan ese aeropuerto como aeropuerto de origen
	// o destino de la ruta. Si se ha eliminado al menos
	// una ruta con ese aeropuerto, se devuelve 'OK' a
	// través de 'res'. Si no, se devuelve 'NO_EXISTE'.
	// Parámetros:
	//	- aeropuerto (E): aeropuerto cuyas rutas se eliminan
	//	- res (S): resultado de la operación
	void eliminar_rutas_aeropuerto(const std::string aeropuerto,
	                               Resultado &res);

	// Elimina todas las rutas que contienen como 'origen'
	// el aeropuerto cuyo nombre se pasa como parámetro.
	// Si se ha eliminado al menos una ruta con ese aeropuerto
	// de origen, se devuelve 'OK' a través de 'res'. Si no,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- origen (E): aeropuerto de origen de las rutas a
	//			eliminar.
	//	- res (S): resultado de la operación.
	void eliminar_rutas_origen(const std::string &origen,
	                           Resultado &res);

	// Elimina todas las rutas que contienen como 'destino'
	// el aeropuerto cuyo nombre se pasa como parámetro.
	// Si se ha eliminado al menos una ruta con ese aeropuerto
	// de destino, se devuelve 'OK' a través de 'res'. Si no,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- destino (E): aeropuerto de destino de las rutas a
	//			eliminar.
	//	- res (S): resultado de la operación.
	void eliminar_rutas_destino(const std::string &destino,
	                            Resultado &res);


	// Lee de 'fichero' la lista de rutas correspondientes
	// a los 'aeropuertos' que se pasan como parámetro
	// (es decir, aquellas con origen Y destino en la lista
	// de aeropuertos) y las inserta al final de la lista
	// de rutas actual.
	// Si la lista de 'aeropuertos' es vacía, lee todas
	// las rutas del fichero y las inserta en la lista
	// de Rutas actual. Si el fichero ha podido abrirse
	// correctamente para lectura, devuelve 'OK' a través
	// de 'res'. Si no, devuelve 'FIC_ERROR'.
	//
	// El formato de fichero de entrada es el siguiente:
	// <origen>,<destino>,<precio>,<duracion>,<linea_aerea>
	// Por ejemplo:
	// AER,KZN,344,151,Aerocondor
	// ASF,KZN,232,112,Aerocondor
	// ASF,MRV,106,84,Aerocondor
	// ...
	// (obsérvese que no hay espacios tras los campos)
	//
	// Parámetros:
	//	- fichero (E): nombre del fichero de lectura.
	// 	- aeropuertos (E): objeto de tipo Aeropuertos con la
	//			lista de aeropuertos para los que obtener rutas.
	//	- res (S): resultado de la operación.
	void obtener_rutas(const std::string &fichero,
	                   const Aeropuertos &aeropuertos,
	                   Resultado &res);

	// Guarda en fichero todas las Rutas. El formato
	// de salida coincide con el de entrada (véase
	// la función miembro obtener_rutas). Si el fichero
	// puede abrirse correctamente para escritura,
	// se guardan en él las rutas y se devuelve 'OK' a
	// través de 'res'. Si no, se devuelve 'FIC_ERROR'.
	// Parámetros:
	//	- fichero (E): nombre del fichero de salida
	// 	- res (S): resultado de la operación.
	void guardar_rutas(const std::string &fichero,
	                   Resultado &res) const;

	// Guarda todas las rutas en el `fichero` cuyo nombre
	// se pasa como parámetro de entrada. (El formato
	// de salida está destinado a generar los billetes
	// correspondientes a un itinerario con escalas
	// entre un aeropuerto de origen--el origen de la
	// primera ruta--y otro de destino--el destino de
	// la última ruta.)
	// Finalmente, escribe en el fichero la suma de los
	// costes totales de todas las rutas que se han
	// escrito en él, el número de rutas - 1 (es
	// decir, las escalas que hay que hacer entre
	// el primer aeropuerto y el último) y la duración
	// total de todos los vuelos.
	//
	// Formato de salida:
	// (ojo, incluye los tres guiones antes y después)
	//
	// ---
	// Flight: <origen> to <destino>
	// Carrier: <linea_aerea>
	// Duration: <duracion> minutes
	// Cost: <precio> euros
	// ---
	// .. (se repite tantas veces como rutas haya)
	// ---
	// Total Cost: <precio total> euros
	// ---
	// Number of Stops: <numero rutas - 1>
	// ---
	// Total Flight Duration: <duracion> minutes
	// ---
	//
	// Si no se puede abrir el fichero, se devuelve
	// `FIC_ERROR` a través de `res`. Si no, se
	// devuelve `Ok`.
	// Parámetros:
	//		- fichero (E): nombre del fichero de salida
	//		- res (S): resultado de la operación
	void guardar_billetes(const std::string &fichero,
	                      Resultado &res);

	// (EJERCICIO DE INVESTIGACIÓN)
	//
	// -- OPCIÓN A - FÁCIL (Y MÍNIMA EXIGIDA)
	// Dado un aeropuerto de 'origen ' y un aeropuerto
	// de 'destino', devuelve la ruta más barata de entre
	// las diferentes rutas existentes entre esos dos
	// aeropuertos. Si existe una ruta entre esos dos
	// aeropuertos, se devuelve insertada en 'itinerario'
	// (como única ruta de la lista) y 'OK' a través de
	// 'res'. Si no existe, se devuelve un 'itinerario'
	// vacío y 'NO_EXISTE' a través de 'res'.
	// --------------------------------------------------
	// Parámetros:
	//	- origen (E): aeropuerto de origen
	//	- destino (E): aeropuerto de destino
	//	- rutas (S): itinerario (rutas) entre origen y destino
	// 	- res (S): resultado de la operación
	void obtener_itinerario(const std::string &origen,
	                        const std::string &destino,
	                        Rutas &itinerario,
	                        Resultado &res) const;

	// ---------------------------------------------------------------
	// OPERADORES SOBRECARGADOS. 
	// Operador de asignación de Rutas
	Rutas & operator=(const Rutas &otro_objeto) {
		if (this != &otro_objeto) {
			borrar_rutas();
			copiar_rutas(otro_objeto);
		}

		return *this;
	}

	// Operador de comparación de igualdad (==).
	bool operator==(const Rutas &otro_objeto) {
		bool iguales = (num_rutas() == otro_objeto.num_rutas());
		Lista ptr1 = lista, ptr2 = otro_objeto.lista;

		while (iguales && ptr1 != nullptr && ptr1->ruta == ptr2->ruta) {
			ptr1 = ptr1->sig;
			ptr2 = ptr2->sig;
		}

		return iguales;
	}

	// Operador de acceso para consulta por índice.
	Ruta operator[](unsigned i) const{
		Lista ptr = lista;
		unsigned pos = 0;

		while(pos < i){
			ptr = ptr->sig;
			++pos;
		}

		return ptr->ruta;
	}
private:

	// Borra todas las rutas de la lista de Rutas
	// Postcondición: lista == nullptr
	struct Nodo{
		Ruta ruta;
		Nodo *sig;
	};
	typedef Nodo *Lista;
	Lista lista;
	

	void borrar_rutas();

	// Copia la lista de rutas del objeto que se pasa como parámetro
	// al final de la lista de rutas actual
	void copiar_rutas(const Rutas &otro_objeto);
};
}

#endif
