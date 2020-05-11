#ifndef CLASE_PARSEADOR_MATERIAS_PRIMAS
#define CLASE_PARSEADOR_MATERIAS_PRIMAS
#include "Parseador.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ColaBloqueante.h"
#include "Trigo.h"
#include "Madera.h"
#include "Carbon.h"
#include "Hierro.h"

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
    void parsear(const std::string nombre_entrada) override;
    ~ParseadorMateriasPrimas() {}   
};

#endif
