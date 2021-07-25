#include "rutas.hpp"
#include "ruta.hpp"
#include "aeropuertos.hpp"
#include "aeropuerto.hpp"
#include <string>
#include <iostream>
#include <string>
#include <array>
#include <cassert>
using namespace std;

namespace bblProgII {


// Constructor por defecto.
// Inicializa la lista de Rutas a lista vacía
Rutas::Rutas(): lista(nullptr) {}

// Constructor de copia de Rutas.
// Parámetros:
//	- otro_objeto (E): objeto Rutas a copiar
Rutas::Rutas(const Rutas &otro_objeto): lista(nullptr) {
	lista = nullptr;
	copiar_rutas(otro_objeto);
}

// Destructor de la clase
Rutas::~Rutas() {
	borrar_rutas();
}

// Devuelve el número de rutas
unsigned Rutas::num_rutas() const {
	Lista ptr;
	unsigned num = 0;
	if (lista == nullptr) {
		num = 0;
	} else {
		ptr = lista;
		while (ptr != nullptr) {
			num++;
			ptr = ptr->sig;
		}
	}
	return num;
}

// Escribe por pantalla las Rutas actuales.
// Formato de salida por pantalla:
// <origen>, <destino>, <precio>, <duracion>, <linea_aerea>
// Por ejemplo:
// AER, KZN, 344, 151, Aerocondor
// ASF, KZN, 232, 112, Aerocondor
// ASF, MRV, 106, 84, Aerocondor
// ...

void Rutas::escribir_rutas() const {
	Lista ptr = lista;
	while (ptr != nullptr) {
		ptr->ruta.escribir_ruta();
		ptr = ptr->sig;
	}
}

// Consulta la ruta de la posición 'num' de
// la lista de Rutas. Si num < num_rutas(),
// devuelve la ruta correspondiente
// y 'OK' a través de 'res'. Si no, devuelve
// 'NO_EXISTE' a través de 'res'.
// Parámetros:
// 	- num (E): posición de la ruta a consultar
//	- ruta (S): ruta de la posición 'num'
//  - res (S): resultado de la operación
void Rutas::consultar_ruta(unsigned num,
                           Ruta &ruta,
                           Resultado &res) const {
	if (num >= num_rutas()) {
		res = NO_EXISTE;
	} else {
		res = OK;
		Lista ptr = lista; //es un puntero auxiliar que va recorriendo la lista
		unsigned pos = 0; //Creamos un numero auxiliar que nos indica el numero de la posicion de ptr
		while (ptr != 0 && pos < num) {
			ptr = ptr->sig;
			pos++;
		}
		ruta = ptr->ruta;
	}
}

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
void Rutas::consultar_rutas(const std::string &origen,
                            const std::string &destino,
                            Rutas &rutas,
                            Resultado &res) const {
	rutas.lista = nullptr;
	Lista ptr = lista;
	while (ptr != nullptr) {
		if (ptr->ruta.consultar_origen() == origen && ptr->ruta.consultar_destino() == destino) {
			rutas.insertar_ruta(ptr->ruta, res);

			ptr = ptr->sig;
		} else {
			ptr = ptr->sig;
		}
	}
	if (rutas.num_rutas() == 0) {
		res = NO_EXISTE;
	} else {
		res = OK;
	}
}

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
void Rutas::consultar_rutas_origen(const std::string &origen,
                                   Rutas &rutas,
                                   Resultado &res) const {
	Lista ptr = lista;
	rutas.lista = nullptr;
	Resultado res1;
	if (lista != nullptr) {
		ptr = lista;
		while (ptr != nullptr) {
			if (ptr->ruta.consultar_origen() == origen ) {
				rutas.insertar_ruta(ptr->ruta, res1);
				ptr = ptr->sig;
			} else {
				ptr = ptr->sig;
			}
		}
		if (rutas.num_rutas() == 0) {
			res = NO_EXISTE;
		} else {
			res = OK;
		}
	} else {
		res = NO_EXISTE;
	}


}
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
void Rutas::consultar_rutas_destino(const std::string &destino,
                                    Rutas &rutas,
                                    Resultado &res) const {
	Lista ptr = lista;
	rutas.lista = nullptr;
	while (ptr != nullptr) {
		if (ptr->ruta.consultar_destino() != destino) {
			ptr = ptr->sig;
		} else {
			rutas.insertar_ruta(ptr->ruta, res);

			ptr = ptr->sig;
		}
	}
	if (rutas.num_rutas() == 0) {
		res = NO_EXISTE;
	} else {
		res = OK;
	}
}

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
void Rutas::consultar_rutas_aeropuertos(const Aeropuertos &aeropuertos,
                                        Rutas &rutas,
                                        Resultado &res) const {
	assert(aeropuertos.num_aeropuertos() > 0);
	Aeropuerto aereo_aux;
	rutas.borrar_rutas();
	Resultado res1, res2;
	if (lista != nullptr) {
		Lista ptr = lista;
		while (ptr != nullptr) {
			aeropuertos.consultar_aeropuerto(ptr->ruta.consultar_origen(), aereo_aux, res1);
			aeropuertos.consultar_aeropuerto(ptr->ruta.consultar_destino(), aereo_aux, res2);
			if (res1 == OK || res2 == OK) {
				rutas.insertar_ruta(ptr->ruta, res);
				res = OK;
				ptr = ptr->sig;
			} else {
				ptr = ptr->sig;
			}
		}

		if (rutas.num_rutas() == 0) {
			res = NO_EXISTE;
		} else {
			res = OK;
		}

	} else {
		res = NO_EXISTE;
	}


}

// Devuelve la ruta más barata (menor precio) de la lista de Rutas.
// Si la lista está vacía, devuelve 'NO_EXISTE' a través
// de 'RES'. Si no, devuelve OK.
// Parámetros:
//	- ruta (S): ruta más barata de la lista
// 	- res (S: resultado de la operación
void Rutas::consultar_mas_barata(Ruta &ruta, Resultado &res) const {
	Lista ptr;
	Ruta aux;
	if (lista == nullptr) {
		res = NO_EXISTE;
	} else {
		ptr = lista;
		if (ptr->ruta.consultar_precio() < ptr->sig->ruta.consultar_precio()) {
			aux = ptr->ruta;
			ptr = ptr->sig;
		}
		while (ptr->sig != nullptr) {
			if (aux.consultar_precio() > ptr->ruta.consultar_precio()) {
				aux = ptr->ruta;
				ptr = ptr->sig;
			} else {
				ptr = ptr->sig;
			}

		}
		ruta = aux;
		res = OK;

	}

}

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
void Rutas::insertar_ruta(const Ruta &ruta, Resultado &res) {
	Lista ptr;

	if (lista != nullptr) {
		ptr = lista;
		while (ptr->sig != nullptr && !(ptr->ruta == ruta)) {
			ptr = ptr->sig;

		}
		if (ptr->ruta == ruta) {
			res = YA_EXISTE;
		} else {
			res = OK;
			ptr->sig = new Nodo;
			ptr->sig->ruta = ruta;
			ptr->sig->sig = nullptr;
		}


	} else if (lista == nullptr) {
		lista = new Nodo;
		lista->ruta = ruta;
		lista->sig = nullptr;

		res = OK;
	}


}


// Elimina la ruta que se pasa como parámetro de la
// lista de Rutas.
// Si la ruta existe, se elimina de la lista de Rutas
// y se devuelve 'OK' a través de 'res'. Si no, se
// devuelve 'NO_EXISTE'a través de 'res'.
// Parámetros:
//	- ruta (E): ruta a eliminar
//	- res (S): resultado de la operación
void Rutas::eliminar_ruta(const Ruta &ruta,
                          Resultado &res) {
	Lista ptr;
	Lista aux = nullptr;
	unsigned num = num_rutas();
	if (lista == nullptr) {
		res = NO_EXISTE;
	} else {
		ptr = lista;
		while (ptr != nullptr && !(ptr->ruta == ruta)) { ///// PROFESOR: while(ptr !=nullptr && ...)
			aux = ptr;
			ptr = ptr->sig;

		}
		if (ptr != nullptr) { ///// PROFESOR: if (ptr != nullptr)
			if (aux == nullptr) {
				lista = ptr->sig;
				delete ptr;
				res = OK;
			} else {
				aux->sig = ptr->sig;
				delete ptr;
				res == OK;
			}
		} else {
			res = NO_EXISTE;
		}




	}
}

// Elimina todas las rutas de la lista de Rutas que
// contengan ese aeropuerto como aeropuerto de origen
// o destino de la ruta. Si se ha eliminado al menos
// una ruta con ese aeropuerto, se devuelve 'OK' a
// través de 'res'. Si no, se devuelve 'NO_EXISTE'.
// Parámetros:
//	- aeropuerto (E): aeropuerto cuyas rutas se eliminan
//	- res (S): resultado de la operación
void Rutas::eliminar_rutas_aeropuerto(const std::string aeropuerto,
                                      Resultado &res) {
	Lista ptr, aux = nullptr;
	unsigned n_aux = num_rutas();
	if (lista != nullptr) {
		ptr = lista;
		while (ptr != nullptr) {
			if (ptr->ruta.consultar_origen() == aeropuerto || ptr->ruta.consultar_destino() == aeropuerto) {
				if (aux == nullptr) {
					lista = lista->sig;
					delete ptr;
					ptr = lista;

					res = OK;
				} else {
					aux->sig = ptr-> sig;
					aux = ptr->sig;
					delete ptr;
					ptr = aux->sig;

					res = OK;
				}

			} else {
				aux = ptr;
				ptr = ptr->sig;
			}
		}
		if (n_aux == num_rutas()) {
			res = NO_EXISTE;
		}
	}
}

// Elimina todas las rutas que contienen como 'origen'
// el aeropuerto cuyo nombre se pasa como parámetro.
// Si se ha eliminado al menos una ruta con ese aeropuerto
// de origen, se devuelve 'OK' a través de 'res'. Si no,
// se devuelve 'NO_EXISTE' a través de 'res'.
// Parámetros:
//	- origen (E): aeropuerto de origen de las rutas a
//			eliminar.
//	- res (S): resultado de la operación.
void Rutas::eliminar_rutas_origen(const std::string &origen,
                                  Resultado &res) {
	Lista ptr, aux = nullptr;
	if (lista != nullptr) {
		ptr = lista;

		 while (ptr != nullptr) {
			if(ptr->ruta.consultar_origen() == origen){

                if(aux == nullptr){
                    lista = ptr->sig;
                    delete ptr;
                    ptr = lista;
                    res = OK;
                }else{
                    aux->sig = ptr->sig;
                    delete ptr;
                    ptr = aux->sig;
                    res = OK;
                    }
			}else{
			    aux = ptr;
			    ptr = ptr->sig;
			}
		}
		if(res != OK){
            res = NO_EXISTE;
		}

	}
	else {

		res = NO_EXISTE;
	}
}

// Elimina todas las rutas que contienen como 'destino'
// el aeropuerto cuyo nombre se pasa como parámetro.
// Si se ha eliminado al menos una ruta con ese aeropuerto
// de destino, se devuelve 'OK' a través de 'res'. Si no,
// se devuelve 'NO_EXISTE' a través de 'res'.
// Parámetros:
//	- destino (E): aeropuerto de destino de las rutas a
//			eliminar.
//	- res (S): resultado de la operación.
void Rutas::eliminar_rutas_destino(const std::string &destino,
                                   Resultado &res) {
	Lista ptr, aux = nullptr;
	if (lista != nullptr) {
		ptr = lista;

		 while (ptr != nullptr) {
			if(ptr->ruta.consultar_destino() == destino){

                if(aux == nullptr){
                    lista = ptr->sig;
                    delete ptr;
                    ptr = lista;
                    res = OK;
                }else{
                    aux->sig = ptr->sig;
                    delete ptr;
                    ptr = aux->sig;
                    res = OK;
                    }
			}else{
			    aux = ptr;
			    ptr = ptr->sig;
			}
		}
		if(res != OK){
            res = NO_EXISTE;
		}

	}
	else {

		res = NO_EXISTE;
	}
}


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
void Rutas::obtener_rutas(const std::string &fichero,
                          const Aeropuertos &aeropuertos,
                          Resultado &res) {
	ifstream f;
	f.open(fichero);
	Aeropuerto aero;
	Resultado res1, res2, res6;
	string orig, dest, lin;
	double pre;
	unsigned dur;
	if(f.fail()){
		res = FIC_ERROR;

	}else {
		res = OK;
		getline(f, orig, ',');
		while (!f.eof()) {

			getline(f, dest, ',');
			f >> pre;
			f.ignore();
			f >> dur;
			f.ignore();
			getline(f, lin);
			if (aeropuertos.num_aeropuertos() == 0) {
				    insertar_ruta(Ruta(orig, dest, pre, dur, lin), res6);
			} else {
				aeropuertos.consultar_aeropuerto(orig, aero, res1);
				aeropuertos.consultar_aeropuerto(dest, aero, res2);

				if(res1 == OK && res2== OK){
                    insertar_ruta(Ruta(orig, dest, pre, dur, lin), res6);
				}
					}
					getline(f, orig, ',');
				}
				f.close();
			}
		}




// Guarda en fichero todas las Rutas. El formato
// de salida coincide con el de entrada (véase
// la función miembro obtener_rutas). Si el fichero
// puede abrirse correctamente para escritura,
// se guardan en él las rutas y se devuelve 'OK' a
// través de 'res'. Si no, se devuelve 'FIC_ERROR'.
// Parámetros:
//	- fichero (E): nombre del fichero de salida
// 	- res (S): resultado de la operación.
void Rutas::guardar_rutas(const std::string &fichero,
                          Resultado &res) const {
	ofstream f;
	f.open(fichero);
	Lista ptr = lista;
	if (f.fail()) {
		res = FIC_ERROR;
	} else {
		res = OK;
		while (ptr != nullptr) {
			f << ptr->ruta.consultar_origen() << ",";
			f << ptr->ruta.consultar_destino() << ",";
			f << ptr->ruta.consultar_precio() << ",";
             f<< ptr->ruta.consultar_duracion() << ",";
			f << ptr->ruta.consultar_linea_aerea() << endl;
			ptr = ptr->sig;
		}
		f.close();
	}
}

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
void Rutas::guardar_billetes(const std::string &fichero,
                             Resultado &res) {
	ofstream f;
	f.open(fichero);
	Lista ptr = lista;
	double precio_t = 0;
	unsigned dur_t = 0;
	unsigned numm = num_rutas();

	if (f.fail()) {
		res = FIC_ERROR;
	} else {
		res = OK;
		while (ptr != nullptr) {
			f << "---" << endl;
			f << "Flight: " << ptr -> ruta.consultar_origen() << "to " << ptr->ruta.consultar_destino() << endl;
			f << "Carrier: " << ptr->ruta.consultar_linea_aerea() << endl;
			f << "Duration " << ptr-> ruta.consultar_duracion() << endl;
			f << "Cost: " << ptr-> ruta.consultar_precio() << endl;
			f << "---" << endl;
			precio_t = precio_t + ptr->ruta.consultar_precio();
			dur_t = dur_t + ptr->ruta.consultar_duracion();
			ptr = ptr->sig;
		}
		f << "Total Cost: " << precio_t << "euros" << endl;
		f << "---" << endl;
		f << "Number of Stops: " << (numm - 1) << endl;
		f << "---" << endl;
		f << "Total Flight Duration: " << dur_t << endl;
		f << "---" << endl;

	}
	f.close();

}


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
void Rutas::obtener_itinerario(const std::string &origen,
                               const std::string &destino,
                               Rutas &itinerario,
                               Resultado &res) const {
	Rutas rutas_origen, rutas_aux;
	itinerario.borrar_rutas();
	Lista ptr;
	Ruta rutax;
	Resultado res_o, res_d, resm, res1, res3;
	Rutas rutas_destino;
	consultar_rutas_origen(origen, rutas_origen, res_o);
	consultar_rutas_destino(destino, rutas_destino, res_d);
	if (res_o == OK && res_d == OK) {
		ptr = rutas_origen.lista;
		while (ptr != nullptr) {
			if ( ptr->ruta.consultar_destino() == destino) {
				rutas_aux.insertar_ruta(ptr->ruta, res3);
				ptr = ptr->sig;
			} else {
				ptr = ptr->sig;
			}
		}
		rutas_aux.consultar_mas_barata(rutax, resm);
		itinerario.insertar_ruta(rutax, res1);

		if(itinerario.num_rutas() == 0){
            res = NO_EXISTE;
		}else{
		    res = OK;
		}

}
}


void Rutas::borrar_rutas() {
	Lista ptr; // Puntero auxiliar
	while (lista != nullptr) {
		ptr = lista;
		lista = lista->sig;
		delete ptr;
	}

}

// Copia la lista de rutas del objeto que se pasa como parámetro
// al final de la lista de rutas actual
void Rutas::copiar_rutas(const Rutas &otro_objeto) {
	Lista ptr = otro_objeto.lista;
	Resultado res;
	while (ptr != nullptr) {
		insertar_ruta(ptr->ruta, res);
		ptr = ptr->sig;

	}

}

}


