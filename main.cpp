#include "ColaBloqueante.h"
#include "Inventario.h"
#include "Trigo.h"
#include "Carbon.h"
#include "Madera.h"
#include "Hierro.h"
//#include <thread>
#include "Recolector.h"

#include "ParseadorTrabajadores.h"
#include "ParseadorMateriasPrimas.h"
/*
#include "Agricultor.h"
#include "Minero.h"
#include "Lenador.h"
#include "Armero.h"
#include "Carpintero.h"
#include "Cocinero.h"
*/
#include "PuntosDeBeneficio.h"
#include "ManejadorTrabajadores.h"


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

    ManejadorTrabajadores manejador_trabajadores(parseador_trabajadores);
    manejador_trabajadores.iniciarTrabajadores(std::move(inventario),
    std::move(puntos_de_beneficio), std::move(cola_agricultor),
    std::move(cola_lenador),std::move(cola_minero));


    ParseadorMateriasPrimas parser_materias_primas(std::move(cola_agricultor),
    std::move(cola_lenador),std::move(cola_minero),
    trigo,madera,carbon,hierro);
    parser_materias_primas.parsear(argv[2]);
    cola_agricultor.cerrar();
    cola_lenador.cerrar();
    cola_minero.cerrar();

    manejador_trabajadores.terminarRecolectores();
    inventario.cerrar();
    manejador_trabajadores.terminarProductores();
    
    delete trigo;
    delete madera;
    delete carbon;
    delete hierro;
    inventario.printear();
    puntos_de_beneficio.printear();

    return 0;

}