#ifndef CLASE_PARSEADOR
#define CLASE_PARSEADOR
#include <iostream>
#include <fstream>
#include <string>

class Parseador{
protected:
    std::ifstream archivo;  
public:
    virtual void parsear(std::string nombre_entrada) = 0;
};

#endif
