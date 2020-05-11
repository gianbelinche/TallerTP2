#ifndef CLASE_INVENTARIO_ESTA_CERRADO_EXCEPTION
#define CLASE_INVENTARIO_ESTA_CERRADO_EXCEPTION

class InventarioEstaCerradoException : public std::exception {
public:
    const char* what() {
        return "El inventario esta cerrado";
    }
};

#endif
