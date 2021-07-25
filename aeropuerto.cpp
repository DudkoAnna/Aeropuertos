#include "aeropuerto.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include <array>
using namespace std;

namespace bblProgII {

	// Constructor por defecto.
	// Asigna cadenas vacías al nombre y país del aeropuerto.
	// Asigna longitud y latitud 0.0.
	Aeropuerto::Aeropuerto(): nombre(""), pais(""),latitud(0.0), longitud(0.0){
	}

	// Constructor extendido.
	// Asigna valores iniciales a los atributos del objeto.
	// Parámetros:
	//	- nombre_ini (E): valor inicial para nombre
	// 	- pais_ini (E): valor inicial para país
	//	- latitud_ini (E): valor inicial para latitud
	//	- longitud_ini (E): valor inicial para longitud
	Aeropuerto::Aeropuerto(const std::string &nombre_ini,
	           const std::string &pais_ini,
	           double latitud_ini,
	           double longitud_ini): nombre(nombre_ini), pais(pais_ini), latitud(latitud_ini), longitud(longitud_ini){
	}

	// Constructor de copia
	// Parámetros:
	// 	- otro_aeropuerto (E): otro objeto de la clase Aeropuerto
	Aeropuerto::Aeropuerto(const Aeropuerto &otro_aeropuerto): nombre(otro_aeropuerto.nombre), pais(otro_aeropuerto.pais), latitud(otro_aeropuerto.latitud),
				             longitud(otro_aeropuerto.longitud){
				}

	// Asigna nuevo nombre al aeropuerto
	// Parámetros:
	//	- nuevo_nombre (E): nuevo nombre del aeropuerto
	void Aeropuerto::asignar_nombre(const std::string &nuevo_nombre){
		nombre = nuevo_nombre;
	}

	// Asigna nuevo valor para el país del aeropuerto
	// Parámetros:
	//	- nuevo_pais (E): nuevo país del aeropuerto
	void Aeropuerto::asignar_pais(const std::string &nuevo_pais){
		pais=nuevo_pais;
	}

	// Asigna nuevo valor para la latitud
	// de la geo-localización del aeropuerto
	// Parámetros:
	// 	- nueva_latitud (E): nuevo valor de la latitud
	void Aeropuerto::asignar_latitud(double nueva_latitud){
		latitud= nueva_latitud;
	}

	// Asigna nuevo valor para la longitud de la
	// geo-localización del aeropuerto.
	// Parámetros:
	// 	- nueva_longitud (E): nuevo valor de longitud
	void Aeropuerto::asignar_longitud(double nueva_longitud){
		longitud= nueva_longitud;
	}


	// Devuelve el nombre del aeropuerto
	std::string Aeropuerto::consultar_nombre() const{
		return nombre;
	}

	// Devuelve el país donde está situado el
	// aeropuerto
	std::string Aeropuerto::consultar_pais() const{
		return pais;
	}

	// Devuelve el valor de la latitud de la
	// geo-localización del aeropuerto
	double Aeropuerto::consultar_latitud() const{
		return latitud;
	}

	// Devuelve el valor de la longitud de la
	// geo-localización del aeropuerto
	double Aeropuerto::consultar_longitud() const{
		return longitud;
	}

	// Escribe por pantalla la información del
	// aeropuerto en el formato:
	// <nombre>, <pais>, <latitud>, <longitud>
	// Por ejemplo:
	// FUE, Spain, 28.4527, -13.8638
	void Aeropuerto::escribir_aeropuerto() const{
		cout << nombre << ", " << pais << ", " << latitud << ", " << longitud <<", " << endl;
	}

}
