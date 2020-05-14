#ifndef CLASE_PUNTOS_DE_BENEFICIO
#define CLASE_PUNTOS_DE_BENEFICIO

#include <mutex>

class PuntosDeBeneficio {
private:
    int puntos;
    std::mutex m;
public:
    PuntosDeBeneficio();
    PuntosDeBeneficio(const PuntosDeBeneficio& copia) = delete;
    PuntosDeBeneficio& operator=(const PuntosDeBeneficio& copia) = delete;
    //Aumenta la cantidad de puntos de beneficio en la cantidad especificada
    void aumentarPuntos(const int cant_puntos);
    void printear() const;
    ~PuntosDeBeneficio() {}     
};

#endif
