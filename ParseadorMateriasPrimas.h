#ifndef CLASE_PARSEADOR_MATERIAS_PRIMAS
#define CLASE_PARSEADOR_MATERIAS_PRIMAS
#include <fstream>
#include <string>

class ColaBloqueante;
class Trigo;
class Madera;
class Carbon;
class Hierro;


class ParseadorMateriasPrimas{
private:
    std::ifstream archivo;
    ColaBloqueante& cola_agricultor;
    ColaBloqueante& cola_leniador;
    ColaBloqueante& cola_minero;  
public:
    ParseadorMateriasPrimas(ColaBloqueante& cola_agricultor,
    ColaBloqueante& cola_leniador,ColaBloqueante& cola_minero);
    //Se encarga de procesar el archivo con nombre_entrada,
    //Y encolar los recursos a las colas correspondientes
    void parsear(const std::string nombre_entrada);
    ~ParseadorMateriasPrimas() {}   
};

#endif
