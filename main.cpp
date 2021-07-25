#include <iostream>
#include "aeropuerto.hpp"
#include "aeropuertos.hpp"
#include "ruta.hpp"
#include "rutas.hpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
using namespace bblProgII;
int main(){
    Resultado res, res1;
    Aeropuertos aero;
    Rutas rut, it;
    string orig, dest, nom_fichero;
    ofstream file;
    aero.obtener_aeropuertos("localizacion.txt", "Spain", res);
    rut.obtener_rutas("localizacion.txt", aero, res1);
    while(true){
            cout<< "Introduzca código del aeropuerto de origen: "<< orig<<endl;
            cout<< "Introduzca código del aeropuerto de destino: " << dest << endl;
            cout << "\n\n Buscando vuelo de " << orig << "a " << dest << "... \n";
            rut.obtener_itinerario(orig, dest, it, res);
            it.escribir_rutas();
            cout << "Generando billetes en fichero " << orig << "_" << dest << ".txt... \n";
            nom_fichero= orig + "_" + dest;
            file.open(nom_fichero.c_str(), ios::out);
            it.guardar_billetes(nom_fichero.c_str(), res);

    }




}

