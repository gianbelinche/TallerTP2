#include "ParseadorMateriasPrimas.h"
#include "Trigo.h"
#include "Madera.h"
#include "Carbon.h"
#include "Hierro.h"
#include "ColaBloqueante.h"
#include <string>

ParseadorMateriasPrimas::ParseadorMateriasPrimas(
ColaBloqueante&& cola_agricultor,
ColaBloqueante&& cola_leniador,ColaBloqueante&& cola_minero,
Trigo* trigo,Madera* madera,Carbon* carbon,Hierro* hierro) : 
    cola_agricultor(std::move(cola_agricultor)),
    cola_leniador(std::move(cola_leniador)),
    cola_minero(std::move(cola_minero)){
        this->trigo = trigo;
        this->madera = madera;
        this->carbon = carbon;
        this->hierro = hierro;
    }

void ParseadorMateriasPrimas::parsear(const std::string nombre_entrada){
    archivo.open(nombre_entrada);
    std::string linea;
    while (getline(archivo,linea)){
        for (unsigned int i = 0; i < linea.length(); i++){
            if (linea[i] == 'T'){
                cola_agricultor.encolar(trigo);
            }
            if (linea[i] == 'M'){
                cola_leniador.encolar(madera);
            }
            if (linea[i] == 'C'){
                cola_minero.encolar(carbon);
            }
            if (linea[i] == 'H'){
                cola_minero.encolar(hierro);
            }
        }
    }
    archivo.close();
}
