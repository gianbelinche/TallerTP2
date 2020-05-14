#ifndef CLASE_RECURSO
#define CLASE_RECURSO

class Inventario;
class Recurso{
private:    
public:
    Recurso() {}
    Recurso(const Recurso& copia) = default;
    Recurso& operator=(Recurso& copia);
    Recurso(Recurso&& recurso);
    Recurso& operator=(Recurso&& recurso);

    //Se encarga de comunicarle al inventario que debe agregar un recurso
    //Cada clase derivada reimplementara esta función, para que se agregue
    //el recurso correspondiente
    virtual void agregarAInventario(Inventario&& inventario) const {}
    ~Recurso() {}
};

#endif
