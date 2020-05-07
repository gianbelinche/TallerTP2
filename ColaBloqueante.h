#ifndef COLA_BLOQUEANTE
#define COLA_BLOQUEANTE

#include <mutex>
#include <queue>
#include <condition_variable>
#include "Recurso.h"

class ColaBloqueante {
private:
    bool esta_cerrada;
    std::mutex m;
    std::queue<Recurso> cola;
    std::condition_variable cv;

public:
    ColaBloqueante();
    ColaBloqueante(const ColaBloqueante& copia) = delete;
    ColaBloqueante& operator=(const ColaBloqueante& copia) = delete;
    //ColaBloqueante(ColaBloqueante&& otra) = delete; //No se si tiene que ser asi
    //ColaBloqueante& operator=(const ColaBloqueante&& otra) = delete; //No se si tiene que ser asi
    void encolar(const Recurso& recurso);
    Recurso desencolar();
    void cerrar();
    ~ColaBloqueante();
};

#endif