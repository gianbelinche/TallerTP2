#include "ColaBloqueante.h"
#include "Inventario.h"
#include "Trigo.h"
#include "Carbon.h"
#include "Madera.h"
#include "Hierro.h"
#include <thread>
#include "Recolector.h"
#include "Agricultor.h"
#include "Minero.h"
#include "Lenador.h"
#include "ParseadorTrabajadores.h"
#include "ParseadorMateriasPrimas.h"
#include "Armero.h"
#include "Carpintero.h"
#include "Cocinero.h"
#include "PuntosDeBeneficio.h"


int main(int argc, char* argv[]){
    ColaBloqueante cola_agricultor;
    ColaBloqueante cola_lenador;
    ColaBloqueante cola_minero;
    Trigo* trigo = new(Trigo);
    Madera* madera = new(Madera);
    Carbon* carbon = new(Carbon);
    Hierro* hierro = new(Hierro);
    Inventario inventario;
    PuntosDeBeneficio puntos_de_beneficio;

    ParseadorTrabajadores parseador_trabajadores;
    parseador_trabajadores.parsear(argv[1]);

    std::vector<Cocinero*> vector_cocineros;
    for (int i = 0; i < parseador_trabajadores.cant_cocineros; i++){
        Cocinero* cocinero =
        new Cocinero(std::move(inventario),std::move(puntos_de_beneficio));
        vector_cocineros.push_back(cocinero);
        cocinero->empezar();
    }
    std::vector<Carpintero*> vector_carpinteros;
    for (int i = 0; i < parseador_trabajadores.cant_carpinteros; i++){
        Carpintero* carpintero =
        new Carpintero(std::move(inventario),std::move(puntos_de_beneficio));
        vector_carpinteros.push_back(carpintero);
        carpintero->empezar();
    }
    std::vector<Armero*> vector_armeros;
    for (int i = 0; i < parseador_trabajadores.cant_armeros; i++){
        Armero* armero =
        new Armero(std::move(inventario),std::move(puntos_de_beneficio));
        vector_armeros.push_back(armero);
        armero->empezar();
    }
    std::vector<Agricultor*> vector_agricultores;
    for (int i = 0; i < parseador_trabajadores.cant_agricultores; i++){
        Agricultor* agr = 
        new Agricultor(std::move(cola_agricultor),std::move(inventario));
        vector_agricultores.push_back(agr);
        agr->empezar();
    }
    std::vector<Lenador*> vector_lenadores;
    for (int i = 0; i < parseador_trabajadores.cant_lenadores; i++){
        Lenador* lenador = 
        new Lenador(std::move(cola_lenador),std::move(inventario));
        vector_lenadores.push_back(lenador);
        lenador->empezar();
    }
    std::vector<Minero*> vector_mineros;
    for (int i = 0; i < parseador_trabajadores.cant_mineros; i++){
        Minero* minero =
        new Minero(std::move(cola_minero),std::move(inventario));
        vector_mineros.push_back(minero);
        minero->empezar();
    }

    ParseadorMateriasPrimas parser_materias_primas(std::move(cola_agricultor),
    std::move(cola_lenador),std::move(cola_minero),
    trigo,madera,carbon,hierro);
    parser_materias_primas.parsear(argv[2]);
    cola_agricultor.cerrar();
    cola_lenador.cerrar();
    cola_minero.cerrar();
    for (unsigned int i = 0; i < vector_agricultores.size(); i++){
        vector_agricultores[i]->terminar();
        delete vector_agricultores[i];
    }
    for (unsigned int i = 0; i < vector_lenadores.size(); i++){
        vector_lenadores[i]->terminar();
        delete vector_lenadores[i];
    }
    for (unsigned int i = 0; i < vector_mineros.size(); i++){
        vector_mineros[i]->terminar();
        delete vector_mineros[i];
    }
    inventario.cerrar();
    for (unsigned int i = 0; i < vector_cocineros.size(); i++){
        vector_cocineros[i]->terminar();
        delete vector_cocineros[i];
    }
    for (unsigned int i = 0; i < vector_armeros.size(); i++){
        vector_armeros[i]->terminar();
        delete vector_armeros[i];
    }
    for (unsigned int i = 0; i < vector_carpinteros.size(); i++){
        vector_carpinteros[i]->terminar();
        delete vector_carpinteros[i];
    }
    delete trigo;
    delete madera;
    delete carbon;
    delete hierro;
    inventario.printear();
    puntos_de_beneficio.printear();

    return 0;

}