#ifndef CLASE_COLA_ESTA_CERRADA_EXCEPTION
#define CLASE_COLA_ESTA_CERRADA_EXCEPTION

class ColaEstaCerradaException : public std::exception {
public:
    const char* what() {
        return "La cola esta cerrada";
    }    
};

#endif
