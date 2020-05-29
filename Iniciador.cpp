#include "Iniciador.h"
#include "ColaBloqueante.h"
#include "Inventario.h"
#include "Trigo.h"
#include "Carbon.h"
#include "Madera.h"
#include "Hierro.h"
#include "ParseadorTrabajadores.h"
#include "ParseadorMateriasPrimas.h"
#include "PuntosDeBeneficio.h"
#include "ManejadorTrabajadores.h"

int Iniciador::iniciar(char* argv[]){
    ColaBloqueante cola_agricultor;
    ColaBloqueante cola_lenador;
    ColaBloqueante cola_minero;
    Trigo trigo;
    Madera madera;
    Carbon carbon;
    Hierro hierro;
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
    &trigo,&madera,&carbon,&hierro);
    parser_materias_primas.parsear(argv[2]);
    cola_agricultor.cerrar();
    cola_lenador.cerrar();
    cola_minero.cerrar();

    manejador_trabajadores.terminarRecolectores();
    inventario.cerrar();
    manejador_trabajadores.terminarProductores();

    inventario.printear();
    puntos_de_beneficio.printear();

    return 0;
}