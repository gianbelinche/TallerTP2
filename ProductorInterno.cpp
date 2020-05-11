#include "ProductorInterno.h"

void ProductorInterno::producir() {}

void ProductorInterno::operator()(){
    this->producir();
}
