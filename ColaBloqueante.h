#ifndef COLA_BLOQUEANTE
#define COLA_BLOQUEANTE

#include <mutex>
#include <queue>
#include <condition_variable>


class ColaBloqueante {
private:
    bool esta_cerrada;
    std::mutex m;
    std::queue<char> cola;
    std::condition_variable cv;

public:
    ColaBloqueante();
    ColaBloqueante(const ColaBloqueante& copia) = delete;
    ColaBloqueante& operator=(const ColaBloqueante& copia) = delete;
    //Encola un recurso, se asegura de que no haya problemas si
    //varios threads quieren encolar a la vez
    void encolar(const char recurso);
    //desencola un recurso, en caso de que la cola este cerrada
    //tira una excepcion, se asegura de que varios threads puedan
    //acceder sin superponerse
    const char desencolar();
    //Pone la cola en estado cerrada, lo que significa que ya
    //no se seguira encolando
    void cerrar();
    ~ColaBloqueante();
};

#endif
