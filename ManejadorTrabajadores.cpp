#include "ManejadorTrabajadores.h"

ManejadorTrabajadores::ManejadorTrabajadores(ParseadorTrabajadores& parser) :
    vector_cocineros(parser.cant_cocineros), 
    vector_carpinteros(parser.cant_carpinteros),
    vector_armeros(parser.cant_armeros),
    vector_agricultores(parser.cant_agricultores),
    vector_lenadores(parser.cant_lenadores),
    vector_mineros(parser.cant_mineros) {}

void ManejadorTrabajadores::iniciarTrabajadores(Inventario&& inventario, 
PuntosDeBeneficio&& puntos, ColaBloqueante&& cola_agricultor, 
ColaBloqueante&& cola_lenador, ColaBloqueante&& cola_minero){
    for (unsigned int i = 0; i < vector_cocineros.size(); i++){
        Cocinero* cocinero =
        new Cocinero(std::move(inventario),std::move(puntos));
        vector_cocineros[i] = cocinero;
        cocinero->empezar();
    }
    for (unsigned int i = 0; i < vector_carpinteros.size(); i++){
        Carpintero* carpintero =
        new Carpintero(std::move(inventario),std::move(puntos));
        vector_carpinteros[i] = carpintero;
        carpintero->empezar();
    }
    for (unsigned int i = 0; i < vector_armeros.size(); i++){
        Armero* armero =
        new Armero(std::move(inventario),std::move(puntos));
        vector_armeros[i] = armero;
        armero->empezar();
    }
    for (unsigned int i = 0; i < vector_agricultores.size(); i++){
        Agricultor* agr = 
        new Agricultor(std::move(cola_agricultor),std::move(inventario));
        vector_agricultores[i] = agr;
        agr->empezar();
    }
    for (unsigned int i = 0; i < vector_lenadores.size(); i++){
        Lenador* lenador = 
        new Lenador(std::move(cola_lenador),std::move(inventario));
        vector_lenadores[i] = lenador;
        lenador->empezar();
    }
    for (unsigned int i = 0; i < vector_mineros.size(); i++){
        Minero* minero =
        new Minero(std::move(cola_minero),std::move(inventario));
        vector_mineros[i] = minero;
        minero->empezar();
    }
}    

void ManejadorTrabajadores::terminarRecolectores(){
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
}

void ManejadorTrabajadores::terminarProductores(){
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
}
