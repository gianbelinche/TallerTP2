#include "Inventario.h"
#include <unistd.h>

void Inventario::agregarTrigo(){
    std::unique_lock<std::mutex> lk(m);
    cant_trigo++;
    cv.notify_all();
}

void Inventario::agregarCarbon(){
    std::unique_lock<std::mutex> lk(m);
    cant_carbon++;
    cv.notify_all();
}

void Inventario::agregarMadera(){
    std::unique_lock<std::mutex> lk(m);
    cant_madera++;
    cv.notify_all();
}

void Inventario::agregarHierro(){
    std::unique_lock<std::mutex> lk(m);
    cant_hierro++;
    cv.notify_all();
}

void Inventario::extraer(const CocineroInterno* cocinero){
    std::unique_lock<std::mutex> lk(m);
    while (!(cant_carbon >= 1 && cant_trigo >= 2)){
        if (esta_cerrado){
            throw InventarioEstaCerradoException();
        }
        cv.wait(lk);
    }
    cant_trigo -= 2;
    cant_carbon -= 1;
}

void Inventario::extraer(const CarpinteroInterno* carpintero){
    std::unique_lock<std::mutex> lk(m);
    while (!(cant_madera >= 3 && cant_hierro >= 1)){
        if (esta_cerrado){
            throw InventarioEstaCerradoException();
        }
        cv.wait(lk);
    }
    cant_madera -= 3;
    cant_hierro -= 1;
}

void Inventario::extraer(const ArmeroInterno* armero){
    std::unique_lock<std::mutex> lk(m);
    while (!(cant_carbon >= 2 && cant_hierro >= 2)){
        if (esta_cerrado){
            throw InventarioEstaCerradoException();
        }
        cv.wait(lk);
    }
    cant_carbon -= 2;
    cant_hierro -= 2;
}

void Inventario::extraer(const ProductorInterno* productor) const {}

void Inventario::cerrar(){
    std::unique_lock<std::mutex> lk(m);
    esta_cerrado = true;
    cv.notify_all();
}

void Inventario::printear() const {
    std::cout << "Recursos restantes:\n";
    std::cout << "  - Trigo: " << cant_trigo << "\n";
    std::cout << "  - Madera: " << cant_madera << "\n";
    std::cout << "  - Carbon: " << cant_carbon << "\n";
    std::cout << "  - Hierro: " << cant_hierro << "\n";
    std::cout << "\n";
}


