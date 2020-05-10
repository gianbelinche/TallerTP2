#include "PuntosDeBeneficio.h"
#include <unistd.h>
#include <iostream>

PuntosDeBeneficio::PuntosDeBeneficio() : puntos(0) {}

void PuntosDeBeneficio::aumentarPuntos(const int cant_puntos){
    std::unique_lock<std::mutex> lk(m);
    this->puntos += cant_puntos;
}

void PuntosDeBeneficio::printear() const {
    std::cout << "Puntos de Beneficio acumulados: ";
    std::cout << puntos;
    std::cout << "\n";
}