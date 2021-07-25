#include "ruta.hpp"
#include "aeropuertos.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace bblProgII {
	Ruta::Ruta(): origen(), destino(), precio(0.0), duracion(0), linea_aerea(){}
	// Constructor de copia
	// Parámetros:
	// 	- otro_ruta (E): otro objeto de la clase Ruta
	Ruta::Ruta(const Ruta &otra_ruta): origen(otra_ruta.origen), destino(otra_ruta.destino), precio(otra_ruta.precio),
										duracion(otra_ruta.duracion), linea_aerea(otra_ruta.linea_aerea){}

	// Constructor extendido.
	// Asigna valores iniciales a los atributos del objeto.
	// Parámetros:
	//	- origen_ini (E): valor inicial para origen
	//	- destino_ini (E): valor inicial para destino
	//	- precio_ini (E): valor inicial para precio
	//	- duracion_ini (E): valor inicial para duracion
	//	- linea_aerea_ini (E): valor inicial para linea_aerea
	Ruta::Ruta(const std::string &origen_ini,
	     const std::string &destino_ini,
	     double precio_ini,
	     unsigned duracion_ini,
	     const std::string &linea_aerea_ini): origen(origen_ini), destino(destino_ini), precio(precio_ini),
												duracion(duracion_ini), linea_aerea(linea_aerea_ini){}

	// Asigna nuevo aeropuerto de origen a la ruta
	// Parámetros:
	//	- nuevo_origen (E): nuevo origen de la ruta
	void Ruta::asignar_origen(const std::string &nuevo_origen){
		origen = nuevo_origen;
	}

	// Asigna nuevo aeropuerto de destino a la ruta
	// Parámetros:
	//	- nuevo_destino (E): nuevo aeropuerto de destino
	void Ruta::asignar_destino(const std::string &nuevo_destino){
		destino = nuevo_destino;
	}

	// Asigna nuevo valor para el precio de la ruta
	// Parámetros:
	// 	- nueva_latitud (E): nuevo valor de la latitud
	void Ruta::asignar_precio(double nuevo_precio){
		precio= nuevo_precio;
	}

	// Asigna nuevo valor para la duracion del vuelo
	// Parámetros:
	// 	- nueva_duracion (E): nuevo valor de duracion
	void Ruta::asignar_duracion(unsigned nueva_duracion){
		duracion = nueva_duracion;
	}
	// Asigna nuevo valor para la línea aérea
	// Parámetros:
	// - nueva_linea (E): nuevo valor de línea aérea
	void Ruta::asignar_linea_aerea(const std::string &nueva_linea){
		linea_aerea = nueva_linea;
	}

	// Devuelve el origen de la ruta
	std::string Ruta::consultar_origen() const{
		return origen;
	}

	// Devuelve el destino de la ruta
	std::string Ruta::consultar_destino() const{
		return destino;
	}

	// Devuelve el precio del vuelo/ruta
	double Ruta::consultar_precio() const{
		return precio;
	}

	// Devuelve la duracion del vuelo/ruta
	unsigned Ruta::consultar_duracion() const{
		return duracion;
	}

	// Devuelve la linea_aerea que realiza la ruta
	std::string Ruta::consultar_linea_aerea() const{
		return linea_aerea;
	}

	// Escribe por pantalla la información de la ruta
	// en el formato:
	// <origen>, <destino>, <precio>, <duracion>, <linea_aerea>
	// Por ejemplo:
	// LPA, MAD, 334, 186, American Airlines
	void Ruta::escribir_ruta() const{
		    cout << origen << ",";
			cout << destino << ",";
			cout << precio << ",";
			cout << duracion << ",";
			cout << linea_aerea << endl;
	}
	
}
