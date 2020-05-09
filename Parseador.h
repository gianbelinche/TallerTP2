#ifndef CLASE_PARSEADOR
#define CLASE_PARSEADOR
#include <iostream>
#include <fstream>
#include "ColaBloqueante.h"

class Parseador{
protected:
    std::ifstream archivo;  
public:
    virtual void parsear(std::string nombre_entrada) = 0;
};

#endif