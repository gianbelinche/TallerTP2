#include "ParseadorTrabajadores.h"

void ParseadorTrabajadores::parsear(const std::string nombre_entrada){
    archivo.open(nombre_entrada);
    std::string linea;
    while (getline(archivo,linea)){
        if (linea.find("Agricultores") != std::string::npos){
            cant_agricultores = std::stoi(linea.substr(13));
        }
        if (linea.find("Leniadores") != std::string::npos){
            cant_lenadores = std::stoi(linea.substr(11));
        }
        if (linea.find("Mineros") != std::string::npos){
            cant_mineros = std::stoi(linea.substr(8));
        }
        if (linea.find("Cocineros") != std::string::npos){
            cant_cocineros = std::stoi(linea.substr(10));
        }
        if (linea.find("Carpinteros") != std::string::npos){
            cant_carpinteros = std::stoi(linea.substr(12));
        }
        if (linea.find("Armeros") != std::string::npos){
            cant_armeros = std::stoi(linea.substr(8));
        }
    }
    archivo.close();
}