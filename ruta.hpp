#ifndef __RUTA_HPP__
#define __RUTA_HPP__

#include <string>

namespace bblProgII {
	class Ruta {
public:
	// Constructor por defecto.
	// Asigna cadenas vacías al origen, destino y linea_aerea de la ruta.
	// Asigna precio 0.0 y duracion 0.
	Ruta();

	// Constructor de copia
	// Parámetros:
	// 	- otro_ruta (E): otro objeto de la clase Ruta
	Ruta(const Ruta &otra_ruta);

	// Constructor extendido.
	// Asigna valores iniciales a los atributos del objeto.
	// Parámetros:
	//	- origen_ini (E): valor inicial para origen
	//	- destino_ini (E): valor inicial para destino
	//	- precio_ini (E): valor inicial para precio
	//	- duracion_ini (E): valor inicial para duracion
	//	- linea_aerea_ini (E): valor inicial para linea_aerea
	Ruta(const std::string &origen_ini,
	     const std::string &destino_ini,
	     double precio_ini,
	     unsigned duracion_ini,
	     const std::string &linea_aerea_ini);

	// Asigna nuevo aeropuerto de origen a la ruta
	// Parámetros:
	//	- nuevo_origen (E): nuevo origen de la ruta
	void asignar_origen(const std::string &nuevo_origen);

	// Asigna nuevo aeropuerto de destino a la ruta
	// Parámetros:
	//	- nuevo_destino (E): nuevo aeropuerto de destino
	void asignar_destino(const std::string &nuevo_destino);

	// Asigna nuevo valor para el precio de la ruta
	// Parámetros:
	// 	- nueva_latitud (E): nuevo valor de la latitud
	void asignar_precio(double nuevo_precio);

	// Asigna nuevo valor para la duracion del vuelo
	// Parámetros:
	// 	- nueva_duracion (E): nuevo valor de duracion
	void asignar_duracion(unsigned nueva_duracion);

	// Asigna nuevo valor para la línea aérea
	// Parámetros:
	// - nueva_linea (E): nuevo valor de línea aérea
	void asignar_linea_aerea(const std::string &nueva_linea);

	// Devuelve el origen de la ruta
	std::string consultar_origen() const;

	// Devuelve el destino de la ruta
	std::string consultar_destino() const;

	// Devuelve el precio del vuelo/ruta
	double consultar_precio() const;

	// Devuelve la duracion del vuelo/ruta
	unsigned consultar_duracion() const;

	// Devuelve la linea_aerea que realiza la ruta
	std::string consultar_linea_aerea() const;

	// Escribe por pantalla la información de la ruta
	// en el formato:
	// <origen>, <destino>, <precio>, <duracion>, <linea_aerea>
	// Por ejemplo:
	// LPA, MAD, 334, 186, American Airlines
	void escribir_ruta() const;

	// Operadores sobrecargados.
	// Operador de comparación de igualdad
	bool operator==(const Ruta &otra_ruta) const {
		return (origen == otra_ruta.origen &&
		        destino == otra_ruta.destino &&
		        precio == otra_ruta.precio &&
		        duracion == otra_ruta.duracion &&
		        linea_aerea == otra_ruta.linea_aerea);
	}
private:
	     std::string origen;
	     std::string destino;
	     double precio;
	     unsigned duracion;
	     std::string linea_aerea;	
};

}

#endif
