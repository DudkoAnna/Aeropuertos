
#include "aeropuertos.hpp"
#include "aeropuerto.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <cassert>
using namespace std;

namespace bblProgII {



// Tipos y constantes auxiliares


// Escribe por pantalla la cadena de caracteres
// correspondiente al error.
// Parámetros:
// 		- res (E): código de error
void escribir_resultado(const Resultado &res){
	switch (res) {
	case OK: cout << " --- OK." << endl;
		break;
	case FIC_ERROR: cout << " --- ERROR DE FICHERO. " << endl;
		break;
	case NO_EXISTE: cout << " --- NO EXISTE. " << endl;
		break;
	default: cout << " --- CÓDIGO DE ERROR DESCONOCIDO." << endl;
	}
}




  	// Constructor por defecto
	// Inicializa la lista de aeropuertos a lista vacía
	Aeropuertos::Aeropuertos(): aeropuertos(), n_aeropuertos(0){
	}

	// Constructor de copia de la clase
	Aeropuertos::Aeropuertos(const Aeropuertos &otro_objeto): aeropuertos(otro_objeto.aeropuertos), n_aeropuertos(otro_objeto.n_aeropuertos){}

	// Destructor del objeto
	Aeropuertos::~Aeropuertos(){}

	// Devuelve un objeto aeropuerto cuyo nombre se pasa
	// como parámetro. Si el aeropuerto está en la lista
	// de Aeropuertos, se devuelve a través del parámetro
	// 'aeropuerto' y se devuelve 'OK' a través de 'res'.
	// Si el aeropuerto no existe en la lista de Aeropuertos,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros;
	//	- nombre (E): nombre del aeropuerto a consultar
	//	- aeropuerto (S): objeto Aeropuerto consultado
	//	- res (S): resultado de la operación.
	void Aeropuertos::consultar_aeropuerto(const std::string &nombre,
	                          Aeropuerto &aeropuerto,
	                          Resultado &res) const{
		unsigned pos = buscar_aeropuerto(nombre);
		if(pos== n_aeropuertos){
			res = NO_EXISTE;
		}else{
			res =OK;
			aeropuerto = aeropuertos[pos];
		}


	}

	// Escribe en pantalla la información de todos los
	// aeropuertos, en el formato:
	// <nombre>, <pais>, <latitud>, <longitud>
	// Por ejemplo:
	// FUE, Spain, 28.4527, -13.8638
	// VDE, Spain, 27.8148, -17.8871
	// SPC, Spain, 28.6265, -17.7556
	// LPA, Spain, 27.9319, -15.3866
	// ACE, Spain, 28.9455, -13.6052
	// ...
	void Aeropuertos::escribir_aeropuertos() const{
		unsigned pos=0;
		while(pos < n_aeropuertos){
			cout << aeropuertos[pos].consultar_nombre() << ", ";
			cout << aeropuertos[pos].consultar_pais() << ", ";
			cout << aeropuertos[pos].consultar_latitud() << ", ";
			cout << aeropuertos[pos].consultar_longitud() << endl;
		}
	}

	// Devuelve el número de aropuertos de la
	// lista de Aeropuetos
	unsigned Aeropuertos::num_aeropuertos() const{
		return n_aeropuertos;
	}

	// Inserta un nuevo aeropuerto en la lista de
	// Aeropuertos. Si el aeropuerto no existe en la lista
	// actual de aeropuertos (es decir, no existe un
	// aeropuerto con el mismo nombre que el aeropuerto
	// que se pasa como parámetro), se inserta al final de ésta y
	// se devuelve 'OK' a través de 'res'. Si el aeropuerto
	// ya existe en la lista, no vuelve a insertarse y se
	// devuelve 'YA_EXISTE' a través de 'res'.
	// Parámetros:
	//	- aeropuerto (E): un aeropuerto a insertar
	//	- res (E): resultado de la operación
	void Aeropuertos::insertar_aeropuerto(const Aeropuerto &aeropuerto,
	                         Resultado &res){
		unsigned pos= buscar_aeropuerto(aeropuerto.consultar_nombre());
		if(pos == n_aeropuertos){
			res=OK;
			aeropuertos[pos] = aeropuerto;
			n_aeropuertos++;
		}else{
			res = YA_EXISTE;
		}

	}

	// Modifica, en la lista actual de Aeropuertos,
	// la información del aeropuerto que se
	// pasa como parámetro. Si el aeropuerto existe en
	// la lista actual de Aeropuertos (es decir, existe
	// un aeropuerto con el mismo nombre que el aeropuerto
	// que se pasa como parámetro), se modifica su
	// información, sustituyéndola por la contenida
	// en el parámetro 'aeropuerto' (es decir, asignando
	// el objeto que se pasa como parámetro al objeto
	// correspondiente contenido en la lista) y se devuelve
	// 'OK' a través de 'res'. Si el aeropuerto no existe,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- aeropuerto (E): aeropuerto a modificar
	//	- res (S): resultado de la operación
	void Aeropuertos::modificar_aeropuerto(const Aeropuerto &aeropuerto,
	                          Resultado &res){
		unsigned pos= buscar_aeropuerto(aeropuerto.consultar_nombre());
		if(pos== n_aeropuertos){
			res= NO_EXISTE;
		}else{
			res = OK;
			aeropuertos[pos]= aeropuerto;
		}
	}

	// Elimina un aeropuerto de la lista de Aeropuertos.
	// Si el aeropuerto cuyo nombre se pasa como parámetro
	// existe en la lista, se elimina de ésta y se devuelve
	// 'OK' a través de 'res'. Si no existe, se devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	// 	- nombre (E): nombre del aeropuerto a eliminar
	// 	- res (S): resultado de la operación
	void Aeropuertos::eliminar_aeropuerto(const std::string &nombre,
	                         Resultado &res){

		unsigned pos = buscar_aeropuerto(nombre);
		if(pos == n_aeropuertos){
			res = NO_EXISTE;
		}else{
			res =OK;
			aeropuertos[pos] = aeropuertos[n_aeropuertos-1];
			n_aeropuertos--;
		}

	}

	// Lee de fichero una lista de aeropuertos
	// correspondiente al 'pais' que se
	// pasa como parámetro y los`inserta en la lista actual de Aeropuertos.
	// Si el país es "cualquiera", lee todos los
	// aeropuertos del fichero.
	//
	// El formato de entrada es el siguiente:
	// <nombre>,<pais>,<latitud>,<longitud>
	// Por ejemplo (nótese que no hay espacios de
	// sepración entres los campos, solo comas):
	// GKA,Papua New Guinea,-6.081689,145.391881
	// MAG,Papua New Guinea,-5.207083,145.7887
	// HGU,Papua New Guinea,-5.826789,144.295861
	// LAE,Papua New Guinea,-6.569828,146.726242
	// POM,Papua New Guinea,-9.443383,147.22005
	// WWK,Papua New Guinea,-3.583828,143.669186
	// UAK,Greenland,61.160517,-45.425978
	// GOH,Greenland,64.190922,-51.678064
	// SFJ,Greenland,67.016969,-50.689325
	// THU,Greenland,76.531203,-68.703161
	//	...
	// Si el fichero puede abrirse para lectura correcta-
	// mente, se devuelve 'OK', a través de 'res'. Si no,
	// se devuelve 'FIC_ERROR' a través de 'res'.
	// Parámetros:
	// 	- fichero (E): nombre del fichero de entrada
	// 	- res (S): resultado de la operación
	void Aeropuertos::obtener_aeropuertos(const std::string &fichero,
	                         const std::string &pais,
	                         Resultado &res){
		ifstream f;
		f.open(fichero);
		std::string nomb, ps;
		double lon, lat;

		if(f.fail()){
			res = FIC_ERROR;
		}else{
			res = OK;
			getline(f, nomb, ',');
			while(!f.eof()){
				getline(f, ps, ',');
				f >> lat;
				f.ignore();
				f >> lon;
				f.ignore();
				if(ps == pais || pais == "cualquiera"){
					aeropuertos[n_aeropuertos]= Aeropuerto(nomb, ps, lat, lon);
					n_aeropuertos++;
				}
				getline(f, nomb, ',');
			}
			f.close();

		}
	    

}


	// Guarda en fichero la lista de Aeropuertos. El
	// formato de salida coincide con el de entrada
	// (véase la función obtener_aeropuertos). Si
	// el fichero puede abrirse, se guardan en él
	// los aeropuertos de la lista actual y se devuelve
	// 'OK' a través de 'res'. Si no, se devuelve
	// 'FIC_ERROR' a través de 'res'.
	// Parámetros:
	// 	- fichero (E): nombre del fichero de entrada
	// 	- res (S): resultado de la operación
    //<nombre>,<pais>,<latitud>,<longitud>
	void Aeropuertos::guardar_aeropuertos(const std::string &fichero,
	                         Resultado &res){
		ofstream f;
		f.open(fichero);
		if(f.fail()){
			res = FIC_ERROR;
		}else{
			res = OK;
			unsigned pos=0;
			while(pos < n_aeropuertos){
				f << aeropuertos[pos].consultar_nombre() << ",";
				f << aeropuertos[pos].consultar_pais() << ",";
				f << aeropuertos[pos].consultar_latitud() << ",";
				f << aeropuertos[pos].consultar_longitud() << endl;
				pos++;
			}
			f.close();
		}
		
	}

	
	unsigned Aeropuertos::buscar_aeropuerto(const std::string &nombre) const{
		assert(n_aeropuertos < aeropuertos.size());
		unsigned pos=0;
		while(pos < n_aeropuertos && aeropuertos[pos].consultar_nombre() != nombre){
			pos++;
		}
		return pos;

	}



}
