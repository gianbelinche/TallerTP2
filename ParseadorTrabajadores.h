#ifndef CLASE_PARSEADOR_TRABAJADORES
#define CLASE_PARSEADOR_TRABAJADORES
#include <iostream>
#include <fstream>
#include "Parseador.h"

class ParseadorTrabajadores : public Parseador{  
public:
    int cant_agricultores;
    int cant_lenadores;
    int cant_mineros;
    int cant_cocineros;
    int cant_carpinteros;
    int cant_armeros;  
    void parsear(const std::string nombre_entrada) override;   
};

#endif