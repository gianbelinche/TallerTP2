#ifndef CLASE_PARSEADOR_MATERIAS_PRIMAS
#define CLASE_PARSEADOR_MATERIAS_PRIMAS
#include "Parseador.h"
#include <string>

class ColaBloqueante;
class Trigo;
class Madera;
class Carbon;
class Hierro;


class ParseadorMateriasPrimas : public Parseador{
private:
    ColaBloqueante&& cola_agricultor;
    ColaBloqueante&& cola_leniador;
    ColaBloqueante&& cola_minero;
    Trigo* trigo;
    Madera* madera;
    Carbon* carbon;
    Hierro* hierro;   
public:
    ParseadorMateriasPrimas(ColaBloqueante&& cola_agricultor,
    ColaBloqueante&& cola_leniador,ColaBloqueante&& cola_minero,
    Trigo* trigo,Madera* madera,Carbon* carbon,Hierro* hierro);
    //Se encarga de procesar el archivo con nombre_entrada,
    //Y encolar los recursos a las colas correspondientes
    void parsear(const std::string nombre_entrada) override;
    ~ParseadorMateriasPrimas() {}   
};

#endif
