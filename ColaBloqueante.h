#ifndef COLA_BLOQUEANTE
#define COLA_BLOQUEANTE

#include "Recurso.h"
#include <mutex>
#include <queue>
#include <condition_variable>


class ColaBloqueante {
private:
    bool esta_cerrada;
    std::mutex m;
    std::queue<const Recurso*> cola;
    std::condition_variable cv;

public:
    ColaBloqueante();
    ColaBloqueante(const ColaBloqueante& copia) = delete;
    ColaBloqueante& operator=(const ColaBloqueante& copia) = delete;
    void encolar(const Recurso* recurso);
    const Recurso* desencolar();
    void cerrar();
    ~ColaBloqueante();
};

#endif
