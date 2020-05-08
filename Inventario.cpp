#include "Inventario.h"
#include <unistd.h>

void Inventario::agregarTrigo(){
    std::unique_lock<std::mutex> lk(m);
    cant_trigo++;
}

void Inventario::agregarCarbon(){
    std::unique_lock<std::mutex> lk(m);
    cant_carbon++;
}

void Inventario::agregarMadera(){
    std::unique_lock<std::mutex> lk(m);
    cant_madera++;
}

void Inventario::agregarHierro(){
    std::unique_lock<std::mutex> lk(m);
    cant_hierro++;
}