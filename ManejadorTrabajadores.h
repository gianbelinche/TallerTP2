#ifndef CLASE_MANEJADOR_TRABAJADORES
#define CLASE_MANEJADOR_TRABAJADORES
#include "Agricultor.h"
#include "Minero.h"
#include "Lenador.h"
#include "Armero.h"
#include "Carpintero.h"
#include "Cocinero.h"
#include <vector>
#include "ParseadorTrabajadores.h"

class ManejadorTrabajadores {
private:
    std::vector<Cocinero*> vector_cocineros;
    std::vector<Carpintero*> vector_carpinteros;
    std::vector<Armero*> vector_armeros;
    std::vector<Agricultor*> vector_agricultores;
    std::vector<Lenador*> vector_lenadores;
    std::vector<Minero*> vector_mineros; 

public:
    explicit ManejadorTrabajadores(ParseadorTrabajadores& parseador);
    void iniciarTrabajadores(Inventario&& inventario, 
    PuntosDeBeneficio&& puntos, ColaBloqueante&& cola_agricultor, 
    ColaBloqueante&& cola_lenador, ColaBloqueante&& cola_minero);    
    void terminarRecolectores();
    void terminarProductores();
};

#endif
