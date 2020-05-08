#ifndef CLASE_INVENTARIO
#define CLASE_INVENTARIO

#include <mutex>
#include "iostream"

class Inventario{
private:
    int cant_trigo;
    int cant_madera;
    int cant_hierro;
    int cant_carbon;
    std::mutex m;    
public:
    Inventario() : cant_trigo(0), cant_madera(0),
    cant_hierro(0), cant_carbon(0){}
    Inventario(const Inventario& copia) = delete;
    Inventario& operator=(const Inventario& copia) = delete;

    void agregarTrigo();
    void agregarMadera();
    void agregarHierro();
    void agregarCarbon();

    void print(){
        int total = cant_trigo + cant_madera + cant_hierro + cant_carbon;
        std::cout << total;
    }
    ~Inventario() {}
};


#endif