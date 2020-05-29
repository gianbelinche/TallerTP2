#include "ParseadorMateriasPrimas.h"
#include "ColaBloqueante.h"
#include <string>
#include <iostream>

ParseadorMateriasPrimas::ParseadorMateriasPrimas(
ColaBloqueante& cola_agricultor,
ColaBloqueante& cola_leniador,ColaBloqueante& cola_minero) : 
    cola_agricultor(cola_agricultor),
    cola_leniador(cola_leniador),
    cola_minero(cola_minero){}

void ParseadorMateriasPrimas::parsear(const std::string nombre_entrada){
    archivo.open(nombre_entrada);
    std::string linea;
    try{
        while (getline(archivo,linea)){
            for (unsigned int i = 0; i < linea.length(); i++){
                if (linea[i] == 'T'){
                    cola_agricultor.encolar(linea[i]);
                }
                if (linea[i] == 'M'){
                    cola_leniador.encolar(linea[i]);
                }
                if (linea[i] == 'C' || linea[i] == 'H'){
                    cola_minero.encolar(linea[i]);
                }
            }
        }
    }catch(...){
        std::cerr << "Error en el parseo de los archivos\n";
    }
    archivo.close();
}
