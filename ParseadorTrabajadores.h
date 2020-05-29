#ifndef CLASE_PARSEADOR_TRABAJADORES
#define CLASE_PARSEADOR_TRABAJADORES

#include <string>
#include <fstream>

class ParseadorTrabajadores{  
public:
    std::ifstream archivo;
    int cant_agricultores;
    int cant_lenadores;
    int cant_mineros;
    int cant_cocineros;
    int cant_carpinteros;
    int cant_armeros;  
    //Se encarga de procesar el archivo con nombre_entrada y
    //inicializar las cantidades de los trabajadores
    void parsear(const std::string nombre_entrada);   
};

#endif
