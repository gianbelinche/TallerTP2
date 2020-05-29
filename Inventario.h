#ifndef CLASE_INVENTARIO
#define CLASE_INVENTARIO

#include <mutex>
#include "iostream"
#include <condition_variable>
#include "CocineroInterno.h" 
#include "CarpinteroInterno.h" 
#include "ArmeroInterno.h" 
#include "InventarioEstaCerradoException.h"
class CocineroInterno;  //Aunque parezca repetitivo, realizo esto debido a que
class CarpinteroInterno; //por temas de includes en compilacion, necesita
class ArmeroInterno; //saber que existen estan clases 
                     //(por alguna razon no le alcanza con los includes)

class Inventario{
private:
    int cant_trigo;
    int cant_madera;
    int cant_hierro;
    int cant_carbon;
    std::mutex m;
    std::condition_variable cv;
    bool esta_cerrado;    

public:
    Inventario() : cant_trigo(0), cant_madera(0),
    cant_hierro(0), cant_carbon(0), esta_cerrado(false){}
    Inventario(const Inventario& copia) = delete;
    Inventario& operator=(const Inventario& copia) = delete;
    //Agrega al inventario una unidad del respectivo recurso
    void agregarRecurso(const char recurso);
    //Extrae del inventario los recursos que le correspondan a cada productor
    //Si el inventario esta cerrado tira una excepción
    void extraer(const CocineroInterno* cocinero);
    void extraer(const CarpinteroInterno* carpintero);
    void extraer(const ArmeroInterno* armero);
    void extraer(const ProductorInterno* productor) const;

    void printear() const;
    //Pasa el inventario al estado cerrado, que significa que ningun nuevo
    //recurso será almacenado
    void cerrar();
    ~Inventario() {}
};

#endif
