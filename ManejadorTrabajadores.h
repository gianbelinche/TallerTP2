#ifndef CLASE_MANEJADOR_TRABAJADORES
#define CLASE_MANEJADOR_TRABAJADORES

#include <vector>

class Armero;
class Carpintero;
class Cocinero;
class Recolector;
class ParseadorTrabajadores;
class Inventario;
class ColaBloqueante;
class PuntosDeBeneficio;

class ManejadorTrabajadores {
private:
    std::vector<Cocinero*> vector_cocineros;
    std::vector<Carpintero*> vector_carpinteros;
    std::vector<Armero*> vector_armeros;
    std::vector<Recolector*> vector_agricultores;
    std::vector<Recolector*> vector_lenadores;
    std::vector<Recolector*> vector_mineros; 

public:
    explicit ManejadorTrabajadores(ParseadorTrabajadores& parseador);
    //Inicia las clases que encapsulan los threads con sus
    //correspondientes argumentos
    void iniciarTrabajadores(Inventario& inventario, 
    PuntosDeBeneficio& puntos, ColaBloqueante& cola_agricultor, 
    ColaBloqueante& cola_lenador, ColaBloqueante& cola_minero);    
    //Comunica a los trabajadores que deben esperar a que su
    //respectivo thread termine
    void terminarRecolectores();
    void terminarProductores();
    ~ManejadorTrabajadores() {}
};

#endif
